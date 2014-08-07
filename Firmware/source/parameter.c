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

/***************************************************************************/
// ��������	
/***************************************************************************/
unsigned char runMode; //����ģʽ	0���ֶ�ģʽ(ֹͣ)  1���Զ�ģʽ(ֹͣ) 2���ֶ�ģʽ(����) 3���Զ�ģʽ(����)   ��������0xEE
unsigned char montorMode; //���״̬	0�����ֹͣ   1���������  ��������0xEE
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

/***************************************************************************/
// ��ȡ����
// ��������
// ����ֵ��0ʧ�� 1�ɹ�	
/***************************************************************************/
unsigned char parameter_read()
{
	unsigned char result = 1;
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
	montorMode = 1; //���״̬	0�����ֹͣ   1���������  ��������0xEE
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
	
	intervalTimer1 = 0; //ʱ������1	��(int) ���9.9
	intervalTimer2 = 0; //ʱ������1	��(int) ���9.9
	intervalTimer3 = 0; //ʱ������1	��(int) ���9.9
	intervalTimer4 = 0; //ʱ������1	��(int) ���9.9
	intervalTimer5 = 0; //ʱ������1	��(int) ���9.9
	intervalTimer6 = 0; //ʱ������1	��(int) ���9.9
	intervalTimer7 = 0; //ʱ������1	��(int) ���9.9
	
	cylinderAlarm1 = 0; //�������� ����1	��(int)
	cylinderAlarm2 = 0; //�������� ����1	��(int)
	cylinderAlarm3 = 0; //�������� ����1	��(int)
	cylinderAlarm4 = 0; //�������� ����1	��(int)
	cylinderAlarm5 = 0; //�������� ����1	��(int)

	pieceCount = 0;
}

/***************************************************************************/
// �������浽eeprom
// ��������
// ����ֵ��0ʧ�� 1�ɹ�	
/***************************************************************************/
unsigned char parameter_save()
{
	unsigned char result = 1;
	return result;
}


