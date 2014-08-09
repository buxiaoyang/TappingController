/***************************************************************************/
// ������ϴ�豸������
// ģ�飺����
// �ļ���parameter.c
// ���ߣ������D
// �汾��V0.02
// ���ڣ�2013��11��8��
// ���ܣ�����
// оƬ��STC12C5A60S2
// ���룺Keil uVision3 V3.90
/***************************************************************************/

#include <parameter.h>
#include <eeprom.h>
#include <basefunc.h>

/***************************************************************************/
// ��������	
/***************************************************************************/
unsigned char runMode; //����ģʽ	0���ֶ�ģʽ(ֹͣ)  1���Զ�ģʽ(ֹͣ) 2���ֶ�ģʽ(����) 3���Զ�ģʽ(����)   ��������0xEE
unsigned char montorMode; //���״̬	0�����ֹͣ   1���������  ��������0xEE
unsigned char alarmMode; //����״̬	0������   1������
unsigned char sensor1; //������1	0����Ч  1����Ч  2������
unsigned char sensor2; //������2	0����Ч  1����Ч  2������
unsigned char sensor3; //������3	0����Ч  1����Ч  2������
unsigned char sensor4; //������4	0����Ч  1����Ч  2������
unsigned char sensor5; //������5	0����Ч  1����Ч  2������
unsigned char sensor6; //������6	0����Ч  1����Ч  2������
unsigned char sensor7; //������7	0����Ч  1����Ч  2������
unsigned char sensor8; //������8	0����Ч  1����Ч  2������
unsigned char sensor9; //������9	0����Ч  1����Ч  2������
unsigned char sensor10; //������10	0����Ч  1����Ч  2������

unsigned char cylinder1; //����1	0����Ч  1����Ч  2������
unsigned char cylinder2; //����2	0����Ч  1����Ч  2������
unsigned char cylinder3; //����3	0����Ч  1����Ч  2������
unsigned char cylinder4; //����4	0����Ч  1����Ч  2������
unsigned char cylinder5; //����5	0����Ч  1����Ч  2������

unsigned char intervalTimer1; //ʱ������1	��(int) ���9.9
unsigned char intervalTimer2; //ʱ������1	��(int) ���9.9
unsigned char intervalTimer3; //ʱ������1	��(int) ���9.9
unsigned char intervalTimer4; //ʱ������1	��(int) ���9.9
unsigned char intervalTimer5; //ʱ������1	��(int) ���9.9
unsigned char intervalTimer6; //ʱ������1	��(int) ���9.9
unsigned char intervalTimer7; //ʱ������1	��(int) ���9.9

unsigned int cylinderAlarm1; //�������� ����1	��(int)
unsigned int cylinderAlarm2; //�������� ����1	��(int)
unsigned int cylinderAlarm3; //�������� ����1	��(int)
unsigned int cylinderAlarm4; //�������� ����1	��(int)
unsigned int cylinderAlarm5; //�������� ����1	��(int)

unsigned int pieceCount; //�Ƽ�����	��(int)

unsigned char refreshDisplay; //ˢ����Ļ��־λ 0 ��ˢ�� 1ˢ��

/***************************************************************************/
// ��ȡ����
// ��������
// ����ֵ��0ʧ�� 1�ɹ�	
/***************************************************************************/
unsigned char parameter_read()
{
	unsigned char result = 1;
	delay_ms(10); 
	if(IapReadByte(IAP_ADDRESS+200) == 0xEE)
	{
		intervalTimer1 = IapReadByte(IAP_ADDRESS+0);
		intervalTimer2 = IapReadByte(IAP_ADDRESS+1);
		intervalTimer3 = IapReadByte(IAP_ADDRESS+2);
		intervalTimer4 = IapReadByte(IAP_ADDRESS+3);
		intervalTimer5 = IapReadByte(IAP_ADDRESS+4);
		intervalTimer6 = IapReadByte(IAP_ADDRESS+5);
		intervalTimer7 = IapReadByte(IAP_ADDRESS+6);	
		cylinderAlarm1 = ((IapReadByte(IAP_ADDRESS+20) << 8) | IapReadByte(IAP_ADDRESS+21));
		cylinderAlarm2 = ((IapReadByte(IAP_ADDRESS+22) << 8) | IapReadByte(IAP_ADDRESS+23));
		cylinderAlarm3 = ((IapReadByte(IAP_ADDRESS+24) << 8) | IapReadByte(IAP_ADDRESS+25));
		cylinderAlarm4 = ((IapReadByte(IAP_ADDRESS+26) << 8) | IapReadByte(IAP_ADDRESS+27));
		cylinderAlarm5 = ((IapReadByte(IAP_ADDRESS+28) << 8) | IapReadByte(IAP_ADDRESS+29));
		result = 1;
	}
	else
	{
		result = 0;
	}
	return result;
}

/***************************************************************************/
// ������ʼ������
// ��������
// ����ֵ����	
/***************************************************************************/
void parameter_init()
{
	runMode = 1; //����ģʽ	0���ֶ�ģʽ(ֹͣ)  1���Զ�ģʽ(ֹͣ) 2���ֶ�ģʽ(����) 3���Զ�ģʽ(����)   ��������0xEE
	montorMode = 0; //���״̬	0�����ֹͣ   1���������  ��������0xEE
	alarmMode = 0;
	sensor1 = 0; //������1	0����Ч  1����Ч  2������
	sensor2 = 0; //������2	0����Ч  1����Ч  2������
	sensor3 = 0; //������3	0����Ч  1����Ч  2������
	sensor4 = 0; //������4	0����Ч  1����Ч  2������
	sensor5 = 0; //������5	0����Ч  1����Ч  2������
	sensor6 = 0; //������6	0����Ч  1����Ч  2������
	sensor7 = 0; //������7	0����Ч  1����Ч  2������
	sensor8 = 0; //������8	0����Ч  1����Ч  2������
	sensor9 = 0; //������9	0����Ч  1����Ч  2������
	sensor10 = 0; //������10	0����Ч  1����Ч  2������
	
	cylinder1 = 0; //����1	0����Ч  1����Ч  2������
	cylinder2 = 0; //����2	0����Ч  1����Ч  2������
	cylinder3 = 0; //����3	0����Ч  1����Ч  2������
	cylinder4 = 0; //����4	0����Ч  1����Ч  2������
	cylinder5 = 0; //����5	0����Ч  1����Ч  2������
	
	if(!parameter_read())
	{
		intervalTimer1 = 32; //ʱ������1	��(int) ���9.9
		intervalTimer2 = 43; //ʱ������1	��(int) ���9.9
		intervalTimer3 = 55; //ʱ������1	��(int) ���9.9
		intervalTimer4 = 65; //ʱ������1	��(int) ���9.9
		intervalTimer5 = 75; //ʱ������1	��(int) ���9.9
		intervalTimer6 = 87; //ʱ������1	��(int) ���9.9
		intervalTimer7 = 99; //ʱ������1	��(int) ���9.9
		
		cylinderAlarm1 = 60; //�������� ����1	��(int)
		cylinderAlarm2 = 70; //�������� ����1	��(int)
		cylinderAlarm3 = 80; //�������� ����1	��(int)
		cylinderAlarm4 = 90; //�������� ����1	��(int)
		cylinderAlarm5 = 100; //�������� ����1	��(int)	
	}
	pieceCount = 0;

	refreshDisplay = 1;
}

/***************************************************************************/
// �������浽eeprom
// ��������
// ����ֵ��0ʧ�� 1�ɹ�	
/***************************************************************************/
unsigned char parameter_save()
{
	unsigned char result = 1;
	EA = 0;
    delay_ms(10);                      //Delay
	IapEraseSector(IAP_ADDRESS); //����EEPROM

	IapProgramByte(IAP_ADDRESS+0, (BYTE)intervalTimer1);
	IapProgramByte(IAP_ADDRESS+1, (BYTE)intervalTimer2);
	IapProgramByte(IAP_ADDRESS+2, (BYTE)intervalTimer3);
	IapProgramByte(IAP_ADDRESS+3, (BYTE)intervalTimer4);
	IapProgramByte(IAP_ADDRESS+4, (BYTE)intervalTimer5);
	IapProgramByte(IAP_ADDRESS+5, (BYTE)intervalTimer6);
	IapProgramByte(IAP_ADDRESS+6, (BYTE)intervalTimer7);

   	IapProgramByte(IAP_ADDRESS+20, (BYTE)(cylinderAlarm1>>8));
	IapProgramByte(IAP_ADDRESS+21, (BYTE)cylinderAlarm1);
	IapProgramByte(IAP_ADDRESS+22, (BYTE)(cylinderAlarm2>>8));
	IapProgramByte(IAP_ADDRESS+23, (BYTE)cylinderAlarm2);
	IapProgramByte(IAP_ADDRESS+24, (BYTE)(cylinderAlarm3>>8));
	IapProgramByte(IAP_ADDRESS+25, (BYTE)cylinderAlarm3);
	IapProgramByte(IAP_ADDRESS+26, (BYTE)(cylinderAlarm4>>8));
	IapProgramByte(IAP_ADDRESS+27, (BYTE)cylinderAlarm4);
	IapProgramByte(IAP_ADDRESS+28, (BYTE)(cylinderAlarm5>>8));
	IapProgramByte(IAP_ADDRESS+29, (BYTE)cylinderAlarm5);
	IapProgramByte(IAP_ADDRESS+200, 0xEE); //д���־λ
	refreshDisplay = 0;
	EA = 1;
	return result;
}


