#include <uart.h>
#include <reg52.h>
#include <intrins.h>
#include <parameter.h>

#define FOSC 11059200L      //System frequency
#define BAUD 9600           //UART baudrate

/*Define UART parity mode*/
#define NONE_PARITY     0   //None parity
#define ODD_PARITY      1   //Odd parity
#define EVEN_PARITY     2   //Even parity
#define MARK_PARITY     3   //Mark parity
#define SPACE_PARITY    4   //Space parity

#define PARITYBIT NONE_PARITY   //Testing even parity

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
    SCON = 0x50;            //8-bit variable UART
#elif (PARITYBIT == ODD_PARITY) || (PARITYBIT == EVEN_PARITY) || (PARITYBIT == MARK_PARITY)
    SCON = 0xda;            //9-bit variable UART, parity bit initial to 1
#elif (PARITYBIT == SPACE_PARITY)
    SCON = 0xd2;            //9-bit variable UART, parity bit initial to 0
#endif

    TMOD = 0x20;            //Set Timer1 as 8-bit auto reload mode
    TH1 = TL1 = -(FOSC/12/32/BAUD); //Set auto-reload vaule
    TR1 = 1;                //Timer1 start run
    ES = 1;                 //Enable UART interrupt
    EA = 1;                 //Open master interrupt switch

    //SendString("STC12C5A60S2\r\nUart2 Test !\r\n");
    //while(1);
}

/*----------------------------
UART interrupt service routine
----------------------------*/
void Uart_Isr() interrupt 4 using 1
{
    if (RI)
    {
        RI = 0;             //Clear receive interrupt flag
        //P0 = SBUF;          //P0 show UART data
		ReceiveData(SBUF); 
    }
    if (TI)
    {
        TI = 0;             //Clear transmit interrupt flag
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
    busy = 1;
    SBUF = ACC;             //Send data to UART buffer
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
			//TestOut = ~TestOut;
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
	TestOut = ~TestOut;
	if(uartBuffer[2] == 0x00)		//����ģʽ
	{
		if(runMode == 0 || runMode == 2)
		{
			runMode = 0;
		}
		else
		{
			runMode = 1;
		}
	}
	else if(uartBuffer[2] == 0x01)	////���״̬
	{
		if(montorMode)
		{
			montorMode = 0;
		}
		else
		{
			montorMode = 1;
		}
	}
	else if(uartBuffer[2] == 0x11) 	
	{
		intervalTimer1 = uartBuffer[5];
	}
	else if(uartBuffer[2] == 0x07)	//ϵͳ����4
	{

	}
	else if(uartBuffer[2] == 0x09)	//ϵͳ����5
	{

	}
	else if(uartBuffer[2] == 0x0B)	//��Ĳ���_�峤1
	{

	}
	else if(uartBuffer[2] == 0x0D)	//��Ĳ���_����1	
	{

	}
	else if(uartBuffer[2] == 0x0F)	//��Ĳ���_�峤2
	{

	}
	else if(uartBuffer[2] == 0x11)	//��Ĳ���_����2
	{

	}
	else if(uartBuffer[2] == 0x13)	//��Ĳ���_�峤3
	{

	}
	else if(uartBuffer[2] == 0x15) 	//��Ĳ���_����3
	{

	}
	else if(uartBuffer[2] == 0x17)	//��Ĳ���_�峤4
	{

	}
	else if(uartBuffer[2] == 0x19)	//��Ĳ���_����4
	{

	}
	else if(uartBuffer[2] == 0x23)	//�ֶ�����_ǰ��
	{

	}
	else if(uartBuffer[2] == 0x24)	//�ֶ�����_����
	{
		
	}
	else if(uartBuffer[2] == 0x25)	//�ֶ�����_����
	{
		
	}
	else if(uartBuffer[2] == 0x26)	//�ֶ�����_�ж���
	{
		
	}
	else if(uartBuffer[2] == 0x27)	//�ֶ�����_�ж���
	{
		
	}
	else if(uartBuffer[2] == 0x28)	//���л���_��λ��ť
	{
		
	}
	uartReceiveOK = 1;	
}
