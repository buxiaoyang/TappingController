/***************************************************************************/
// ������ϴ�豸������
// ģ�飺������	
// �ļ���main.c
// ���ߣ������D
// �汾��V0.02
// ���ڣ�2013��11��8��
// ���ܣ�������
// оƬ��STC12C5A60S2
// ���룺Keil uVision3 V3.90
/***************************************************************************/

#include <reg52.h>
#include <basefunc.h>
#include <parameter.h>
#include <uart.h>
//#include <timer.h>
#include <key.h>
#include <dispatch.h>

void parameter_send_screen()
{
	SendDataToScreen(0x0000,runMode); //����ģʽ	0���ֶ�ģʽ(ֹͣ)  1���Զ�ģʽ(ֹͣ) 2���ֶ�ģʽ(����) 3���Զ�ģʽ(����)   ��������0xEE
	//�л�ҳ��
	if(alarmMode == 0)
	{
		if(runMode == 0 || runMode == 2)
		{
			ChangeScreenPage(0x02);
		}
		else
		{
			ChangeScreenPage(0x00);
		}
	}
	else
	{
		 ChangeScreenPage(0x08);
	}
	SendDataToScreen(0x0001,montorMode); //���״̬	0�����ֹͣ   1���������  ��������0xEE

	SendDataToScreen(0x0002,sensor1); //������1	0����Ч  1����Ч  2������
	SendDataToScreen(0x0003,sensor2); //������2	0����Ч  1����Ч  2������
	SendDataToScreen(0x0004,sensor3); //������3	0����Ч  1����Ч  2������
	SendDataToScreen(0x0005,sensor4); //������4	0����Ч  1����Ч  2������
	SendDataToScreen(0x0006,sensor5); //������5	0����Ч  1����Ч  2������
	SendDataToScreen(0x0007,sensor6); //������6	0����Ч  1����Ч  2������
	SendDataToScreen(0x0008,sensor7); //������7	0����Ч  1����Ч  2������
	SendDataToScreen(0x0009,sensor8); //������8	0����Ч  1����Ч  2������
	SendDataToScreen(0x000A,sensor9); //������9	0����Ч  1����Ч  2������
	SendDataToScreen(0x000B,sensor10); //������10	0����Ч  1����Ч  2������

	SendDataToScreen(0x000C,cylinder1); //����1	0����Ч  1����Ч  2������
	SendDataToScreen(0x000D,cylinder2); //����2	0����Ч  1����Ч  2������
	SendDataToScreen(0x000E,cylinder3); //����3	0����Ч  1����Ч  2������
	SendDataToScreen(0x000F,cylinder4); //����4	0����Ч  1����Ч  2������
	SendDataToScreen(0x0010,cylinder5); //����5	0����Ч  1����Ч  2������
	
	SendDataToScreen(0x0011,intervalTimer1); //ʱ������1	��(int) ���9.9
	SendDataToScreen(0x0012,intervalTimer2); //ʱ������2	��(int) ���9.9
	SendDataToScreen(0x0013,intervalTimer3); //ʱ������3	��(int) ���9.9
	SendDataToScreen(0x0014,intervalTimer4); //ʱ������4	��(int) ���9.9
	SendDataToScreen(0x0015,intervalTimer5); //ʱ������5	��(int) ���9.9
	SendDataToScreen(0x0016,intervalTimer6); //ʱ������6	��(int) ���9.9
	SendDataToScreen(0x0017,intervalTimer7); //ʱ������7	��(int) ���9.9
	
	SendDataToScreen(0x0018,cylinderAlarm1); //�������� ����1	��(int)
	SendDataToScreen(0x0019,cylinderAlarm2); //�������� ����2	��(int)
	SendDataToScreen(0x001A,cylinderAlarm3); //�������� ����3	��(int)
	SendDataToScreen(0x001B,cylinderAlarm4); //�������� ����4	��(int)
	SendDataToScreen(0x001C,cylinderAlarm5); //�������� ����5	��(int)

	SendDataToScreen(0x0023,pieceCount); 

}

void getSensorStatus()
{
	//1
	if(sensorIn1 == 0)
	{
		if(sensor1 == 0)
		{
			refreshDisplay = 1;
		}
		sensor1 = 1;
	}
	if(sensorIn1 == 1)
	{
		if(sensor1 == 1)
		{
			refreshDisplay = 1;
		}
		sensor1 = 0;
	}
	//2
	if(sensorIn2 == 0)
	{
		if(sensor2 == 0)
		{
			refreshDisplay = 1;
		}
		sensor2 = 1;
	}
	if(sensorIn2 == 1)
	{
		if(sensor2 == 1)
		{
			refreshDisplay = 1;
		}
		sensor2 = 0;
	}
	//3
	if(sensorIn3 == 0)
	{
		if(sensor3 == 0)
		{
			refreshDisplay = 1;
		}
		sensor3 = 1;
	}
	if(sensorIn3 == 1)
	{
		if(sensor3 == 1)
		{
			refreshDisplay = 1;
		}
		sensor3 = 0;
	}
	//4
	if(sensorIn4 == 0)
	{
		if(sensor4 == 0)
		{
			refreshDisplay = 1;
		}
		sensor4 = 1;
	}
	if(sensorIn4 == 1)
	{
		if(sensor4 == 1)
		{
			refreshDisplay = 1;
		}
		sensor4 = 0;
	}
	//5
	if(sensorIn5 == 0)
	{
		if(sensor5 == 0)
		{
			refreshDisplay = 1;
		}
		sensor5 = 1;
	}
	if(sensorIn5 == 1)
	{
		if(sensor5 == 1)
		{
			refreshDisplay = 1;
		}
		sensor5 = 0;
	}
	//6
	if(sensorIn6 == 0)
	{
		if(sensor6 == 0)
		{
			refreshDisplay = 1;
		}
		sensor6 = 1;
	}
	if(sensorIn6 == 1)
	{
		if(sensor6 == 1)
		{
			refreshDisplay = 1;
		}
		sensor6 = 0;
	}
	//7
	if(sensorIn7 == 0)
	{
		if(sensor7 == 0)
		{
			refreshDisplay = 1;
		}
		sensor7 = 1;
	}
	if(sensorIn7 == 1)
	{
		if(sensor7 == 1)
		{
			refreshDisplay = 1;
		}
		sensor7 = 0;
	}
	//8
	if(sensorIn8 == 0)
	{
		if(sensor8 == 0)
		{
			refreshDisplay = 1;
		}
		sensor8 = 1;
	}
	if(sensorIn8 == 1)
	{
		if(sensor8 == 1)
		{
			refreshDisplay = 1;
		}
		sensor8 = 0;
	}
	//9
	if(sensorIn9 == 0)
	{
		if(sensor9 == 0)
		{
			refreshDisplay = 1;
		}
		sensor9 = 1;
	}
	if(sensorIn9 == 1)
	{
		if(sensor9 == 1)
		{
			refreshDisplay = 1;
		}
		sensor9 = 0;
	}
	//10
	if(sensorIn10 == 0)
	{
		if(sensor10 == 0)
		{
			refreshDisplay = 1;
		}
		sensor10 = 1;
	}
	if(sensorIn10 == 1)
	{
		if(sensor10 == 1)
		{
			refreshDisplay = 1;
		}
		sensor10 = 0;
	}
}

/***************************************************************************/
// ������
// ��������
// ����ֵ����	
/***************************************************************************/
void main()
{
	//unsigned int timeCount10ms = 0;
	unsigned char timeCount100ms = 0;
	unsigned char timeCount1s = 0;
	delay_ms(500);
	parameter_init();
	uart_init();
	//timer_init();
	while(1)
	{
		delay_us(3600);
		if(saveSetting)
		{
			ChangeScreenPage(0x0A);
			parameter_save();
			if(saveSetting == 2)
			{
				ChangeScreenPage(0x04);
			}
			else
			{
				ChangeScreenPage(0x00);
			}
			saveSetting = 0;
		}
		//��ʱ
		//timeCount10ms ++;
		//if(timeCount10ms == 950)//10ms
		//{
			//timeCount10ms = 0;
		   	TestOut = ! TestOut;
			//����ɨ��
			Key_Scan();
			//100ms��1s��ʱ
			timeCount100ms++;
			if(timeCount100ms == 10) //100ms
			{
				timeCount100ms = 0;
				//TestOut = ! TestOut;
				intervalTimerCount ++;
				timeCount1s ++;
				if(timeCount1s == 10)
				{
					timeCount1s = 0;
					//TestOut = ! TestOut;
					cylinderAlarmCount ++;	
				}
			 }
		//}
		//ˢ����ʾ	
		if(refreshDisplay)
		{
			parameter_send_screen();
			refreshDisplay = 0;
		}
		//������
		if(montorMode)
		{
			montorOut = 0;
		}
		else
		{
			montorOut = 1;
		} 
		//ˢ�´�����״̬
		getSensorStatus();
		//��������
		if(runMode == 3 && alarmMode == 0)
		{
			ManiDispatch();
		}
	}   
}








