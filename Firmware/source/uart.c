#include <uart.h>
#include <reg52.h>
#include <intrins.h>
#include <parameter.h>


#define FOSC 11059200L      //System frequency
#define BAUD 115200         //UART baudrate

/*Define UART parity mode*/
#define NONE_PARITY     0   //None parity
#define ODD_PARITY      1   //Odd parity
#define EVEN_PARITY     2   //Even parity
#define MARK_PARITY     3   //Mark parity
#define SPACE_PARITY    4   //Space parity

#define PARITYBIT NONE_PARITY   //Testing even parity

/*Declare SFR associated with the UART2 */
sfr AUXR  = 0x8e;           //Auxiliary register
sfr S2CON = 0x9a;           //UART2 control register
sfr S2BUF = 0x9b;           //UART2 data buffer
sfr BRT   = 0x9c;           //Baudrate generator
sfr IE2   = 0xaf;           //Interrupt control 2

#define S2RI  0x01          //S2CON.0
#define S2TI  0x02          //S2CON.1
#define S2RB8 0x04          //S2CON.2
#define S2TB8 0x08          //S2CON.3

bit busy;
bit uartReceiveOK = 0;

BYTE uartBuffer[15] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};

BYTE receiveSteps = 0; 	// 0: û�����ݽ���
						// 1: ���յ�5A
						// 2�����յ�A5
						// 3�����յ����ݳ���
						// 4: ��������
						// 5��ȷ��ָ���
BYTE dataIndex = 0;
BYTE dataLength = 0;
  
void SendData(BYTE dat);
void SendString(char *s);
void ReceiveData(BYTE dat);
void anyData();

void uart_init()
{
#if (PARITYBIT == NONE_PARITY)
    S2CON = 0x50;           //8-bit variable UART
#elif (PARITYBIT == ODD_PARITY) || (PARITYBIT == EVEN_PARITY) || (PARITYBIT == MARK_PARITY)
    S2CON = 0xda;           //9-bit variable UART, parity bit initial to 1
#elif (PARITYBIT == SPACE_PARITY)
    S2CON = 0xd2;           //9-bit variable UART, parity bit initial to 0
#endif

    BRT = -(FOSC/32/BAUD);  //Set auto-reload vaule of baudrate generator
    AUXR = 0x14;            //Baudrate generator work in 1T mode
    IE2 = 0x01;             //Enable UART2 interrupt
    EA = 1;                 //Open master interrupt switch

    //SendString("STC12C5A60S2\r\nUart2 Test !\r\n");
    //while(1);
}

/*----------------------------
UART2 interrupt service routine
----------------------------*/
void Uart2() interrupt 8 using 1
{
    if (S2CON & S2RI)
    {
        S2CON &= ~S2RI;     //Clear receive interrupt flag
        ReceiveData(S2BUF);
		//P2 = S2BUF;         //P0 show UART data
        //P2 = (S2CON & S2RB8);//P2.2 show parity bit
    }
    if (S2CON & S2TI)
    {
        S2CON &= ~S2TI;     //Clear transmit interrupt flag
        busy = 0;           //Clear transmit busy flag
    }
}

/*----------------------------
Send a byte data to UART
Input: dat (data to be sent)
Output:None
----------------------------*/
void SendData(BYTE dat)
{
    while (busy);           //Wait for the completion of the previous data is sent
    ACC = dat;              //Calculate the even parity bit P (PSW.0)
    if (P)                  //Set the parity bit according to P
    {
#if (PARITYBIT == ODD_PARITY)
        S2CON &= ~S2TB8;    //Set parity bit to 0
#elif (PARITYBIT == EVEN_PARITY)
        S2CON |= S2TB8;     //Set parity bit to 1
#endif
    }
    else
    {
#if (PARITYBIT == ODD_PARITY)
        S2CON |= S2TB8;     //Set parity bit to 1
#elif (PARITYBIT == EVEN_PARITY)
        S2CON &= ~S2TB8;    //Set parity bit to 0
#endif
    }
    busy = 1;
    S2BUF = ACC;            //Send data to UART2 buffer
}

/*----------------------------
Send a string to UART
Input: s (address of string)
Output:None
----------------------------*/
void SendString(char *s)
{
    while (*s)              //Check the end of the string
    {
        SendData(*s++);     //Send current char and increment string ptr
    }
}

void SendDataToScreen(WORD address, WORD dat)
{
	SendData(0x5A);
	SendData(0xA5);
	SendData(0x05);
	SendData(0x82);
	SendData(address>>8);
	SendData(address);
	SendData(dat>>8);
	SendData(dat);
}

void ChangeScreenPage(WORD page)
{
	SendData(0x5A);
	SendData(0xA5);
	SendData(0x04);
	SendData(0x80);
	SendData(0x03);
	SendData(page>>8);
	SendData(page);
}

void ReceiveData(BYTE dat)
{
	// 0: ���յ�5A
	// 1�����յ�A5
	// 2�����յ����ݳ���
	// 3: ��������
	// 4��ȷ��ָ���
	switch(receiveSteps)
	{
		case 0:
			if(dat == 0x5A)
			{
				receiveSteps ++;
			}
		break;
		case 1:
			if(dat == 0xA5)
			{
				receiveSteps ++;
			}
			else
			{
			  	receiveSteps = 0;
			}
		break;
		case 2:
			dataLength = dat;
			dataIndex = 0;
			receiveSteps ++;
		break;
		case 3:
			uartBuffer[dataIndex] = dat;
			dataIndex ++;
			if(dataIndex >= dataLength)
			{
				anyData();
				receiveSteps = 0;
			}
		break;
		default:
			_nop_();
			receiveSteps = 0;
	}
}

void anyData()
{
	WORD dat = ((uartBuffer[4]<<8) | uartBuffer[5]);
	refreshDisplay = 1;
	if(uartBuffer[2] == 0x00)//����ģʽ	0���ֶ�ģʽ(ֹͣ)  1���Զ�ģʽ(ֹͣ) 2���ֶ�ģʽ(����) 3���Զ�ģʽ(����)   ��������0xEE
	{
		if(runMode == 0 || runMode == 2)
		{
			runMode = 1;	
		}
		else
		{
			runMode = 0;
		}
	}
	else if(uartBuffer[2] == 0x01)	//���״̬	0�����ֹͣ   1���������  ��������0xEE
	{
		if(montorMode == 0)
		{
			montorMode = 1;
		}
		else
		{
			montorMode = 0;
		}
	}
	else if(uartBuffer[2] == 0x11) 	//ʱ������1	��(int) ���9.9
	{
		intervalTimer1 = dat;
		parameter_save();
	}
	else if(uartBuffer[2] == 0x12)	//ʱ������2	��(int)
	{
		intervalTimer2 = dat;
		parameter_save();
	}
	else if(uartBuffer[2] == 0x13)	//ʱ������3	��(int)
	{
		intervalTimer3 = dat;
		parameter_save();
	}
	else if(uartBuffer[2] == 0x14)	//ʱ������4	��(int)
	{
		intervalTimer4 = dat;
		parameter_save();
	}
	else if(uartBuffer[2] == 0x15)	//ʱ������5	��(int)
	{
		intervalTimer5 = dat;
		parameter_save();
	}
	else if(uartBuffer[2] == 0x16)	//ʱ������6	��(int)
	{
		intervalTimer6 = dat;
		parameter_save();
	}
	else if(uartBuffer[2] == 0x17)	//ʱ������7	��(int)
	{
	   	intervalTimer7 = dat;
		parameter_save();
	}
	else if(uartBuffer[2] == 0x18)	//�������� ����1	��(int)
	{
		cylinderAlarm1 = dat;
		parameter_save();	
	}
	else if(uartBuffer[2] == 0x19) 	//�������� ����2	��(int)
	{
		cylinderAlarm2 = dat;
		parameter_save();
	}
	else if(uartBuffer[2] == 0x1A)	//�������� ����3	��(int)
	{
		cylinderAlarm3 = dat;
		parameter_save();
	}
	else if(uartBuffer[2] == 0x1B)	//�������� ����4	��(int)
	{
		cylinderAlarm4 = dat;
		parameter_save();
	}
	else if(uartBuffer[2] == 0x1C)	//�������� ����5	��(int)
	{
		cylinderAlarm5 = dat;
		parameter_save();
	}
	else if(uartBuffer[2] == 0x1D)	//��λ������ť	��������0xEE
	{
		pieceCount = 0;
	}
	else if(uartBuffer[2] == 0x1E)	//�ֶ�ģʽ ��ť ����1 	0���ر�  1������
	{
		if(cylinder1)
		{
			cylinder1 = 0;
		}
		else
		{
			cylinder1 = 1;	
		}
	}
	else if(uartBuffer[2] == 0x1F)	//�ֶ�ģʽ ��ť ����2	0���ر�  1������
	{
		if(cylinder2)
		{
			cylinder2 = 0;
		}
		else
		{
			cylinder2 = 1;	
		}
	}
	else if(uartBuffer[2] == 0x20)	//�ֶ�ģʽ ��ť ����3	0���ر�  1������
	{
		if(cylinder3)
		{
			cylinder3 = 0;
		}
		else
		{
			cylinder3 = 1;	
		}
	}
	else if(uartBuffer[2] == 0x21)	//�ֶ�ģʽ ��ť ����4	0���ر�  1������
	{
		if(cylinder4)
		{
			cylinder4 = 0;
		}
		else
		{
			cylinder4 = 1;	
		}
	}
	else if(uartBuffer[2] == 0x22)	//�ֶ�ģʽ ��ť ����5	0���ر�  1������
	{
		if(cylinder5)
		{
			cylinder5 = 0;
		}
		else
		{
			cylinder5 = 1;	
		}
	}
	else if(uartBuffer[2] == 0x24)	//���������ť	��������0xEE
	{
		alarmMode = 0;
	}
	uartReceiveOK = 1;	
}
