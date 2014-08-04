/*------------------------------------------------------------------*/
/* --- STC MCU Limited ---------------------------------------------*/
/* --- STC12C5Axx Series MCU UART (8-bit/9-bit)Demo ----------------*/
/* --- Mobile: (86)13922805190 -------------------------------------*/
/* --- Fax: 86-755-82905966 ----------------------------------------*/
/* --- Tel: 86-755-82948412 ----------------------------------------*/
/* --- Web: www.STCMCU.com -----------------------------------------*/
/* If you want to use the program or the program referenced in the  */
/* article, please specify in which data and procedures from STC    */
/*------------------------------------------------------------------*/

#include <reg52.h>
#include <basefunc.h>
#include <parameter.h>
#include <uart.h>
#include <timer.h>
#include <key.h>
#include <dispatch.h>

void parameter_send_screen()
{
	SendDataToScreen(0x0000,runMode); //����ģʽ	0���ֶ�ģʽ(ֹͣ)  1���Զ�ģʽ(ֹͣ) 2���ֶ�ģʽ(����) 3���Զ�ģʽ(����)   ��������0xEE
	
	SendDataToScreen(0x0001,montorMode); //���״̬	0�����ֹͣ   1���������  ��������0xEE

	/*
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
	*/
}

void main()
{
	uart_init();
	//timer_init();
	parameter_init();
	while(1)
	{	
		parameter_send_screen();
		  
		if(KeyAutoManual == 1)
		{
			runMode = 1;
		}
		else
		{
			runMode = 0;
		} 
		Key_Scan();
		ManiDispatch();
		SubDispatch();
		delay_ms(50);
	}   
}




