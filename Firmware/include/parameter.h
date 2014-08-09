/***************************************************************************/
// ������ϴ�豸������
// ģ�飺����ͷ�ļ�
// �ļ���parameter.h
// ���ߣ������D
// �汾��V0.02
// ���ڣ�2013��11��8��
// ���ܣ�����ͷ�ļ�
// оƬ��STC12C5A60S2
// ���룺Keil uVision3 V3.90
/***************************************************************************/

#ifndef __PARAMETER_H__
#define __PARAMETER_H__

#include <reg52.h>

/***************************************************************************/
// ���Ŷ���
/***************************************************************************/
//����
sbit sensorIn1 = P0^0; //������1
sbit sensorIn2 = P0^1; //������2
sbit sensorIn3 = P0^2; //������3
sbit sensorIn4 = P0^3; //������4
sbit sensorIn5 = P0^4; //������5
sbit sensorIn6 = P0^5; //������6
sbit sensorIn7 = P0^6; //������7
sbit sensorIn8 = P0^7; //������8
sbit sensorIn9 = P2^0; //������9
sbit sensorIn10 = P2^1; //������10

sbit KeyStart = P2^2; //��ʼ��ť
sbit KeyStop = P2^3; //��ͣ��ť

//���
sbit cylinderOut1 = P1^0; //����1
sbit cylinderOut2 = P1^1; //����2
sbit cylinderOut3 = P2^4; //����3
sbit cylinderOut4 = P2^5; //����4
sbit cylinderOut5 = P1^4; //����5
sbit montorOut = P1^5;		//������
sbit systemAlarmOut = P1^6; //ϵͳ����

sbit TestOut = P2^6;

/***************************************************************************/
// ��������
/***************************************************************************/
void parameter_init();
unsigned char parameter_save();

extern unsigned char runMode; //����ģʽ	0���ֶ�ģʽ(ֹͣ)  1���Զ�ģʽ(ֹͣ) 2���ֶ�ģʽ(����) 3���Զ�ģʽ(����)   ��������0xEE
extern unsigned char montorMode; //���״̬	0�����ֹͣ   1���������  ��������0xEE
extern unsigned char alarmMode; //����״̬	0������   1������
extern unsigned char sensor1; //������1	0����Ч  1����Ч  2������
extern unsigned char sensor2; //������2	0����Ч  1����Ч  2������
extern unsigned char sensor3; //������3	0����Ч  1����Ч  2������
extern unsigned char sensor4; //������4	0����Ч  1����Ч  2������
extern unsigned char sensor5; //������5	0����Ч  1����Ч  2������
extern unsigned char sensor6; //������6	0����Ч  1����Ч  2������
extern unsigned char sensor7; //������7	0����Ч  1����Ч  2������
extern unsigned char sensor8; //������8	0����Ч  1����Ч  2������
extern unsigned char sensor9; //������9	0����Ч  1����Ч  2������
extern unsigned char sensor10; //������10	0����Ч  1����Ч  2������

extern unsigned char cylinder1; //����1	0����Ч  1����Ч  2������
extern unsigned char cylinder2; //����2	0����Ч  1����Ч  2������
extern unsigned char cylinder3; //����3	0����Ч  1����Ч  2������
extern unsigned char cylinder4; //����4	0����Ч  1����Ч  2������
extern unsigned char cylinder5; //����5	0����Ч  1����Ч  2������

extern unsigned char intervalTimer1; //ʱ������1	��(int) ���9.9
extern unsigned char intervalTimer2; //ʱ������1	��(int) ���9.9
extern unsigned char intervalTimer3; //ʱ������1	��(int) ���9.9
extern unsigned char intervalTimer4; //ʱ������1	��(int) ���9.9
extern unsigned char intervalTimer5; //ʱ������1	��(int) ���9.9
extern unsigned char intervalTimer6; //ʱ������1	��(int) ���9.9
extern unsigned char intervalTimer7; //ʱ������1	��(int) ���9.9

extern unsigned int cylinderAlarm1; //�������� ����1	��(int)
extern unsigned int cylinderAlarm2; //�������� ����1	��(int)
extern unsigned int cylinderAlarm3; //�������� ����1	��(int)
extern unsigned int cylinderAlarm4; //�������� ����1	��(int)
extern unsigned int cylinderAlarm5; //�������� ����1	��(int)

extern unsigned int pieceCount; //�Ƽ�����	��(int)

extern unsigned char refreshDisplay; //ˢ����Ļ��־λ 0 ��ˢ�� 1ˢ��

#endif
