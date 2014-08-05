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
sbit EncoderCounting		= P3^2;  	// ��������������ɫ��

sbit EncoderDirection		= P2^4;  	// ���������򣨰�ɫ��

sbit HydClamInductorTop		= P0^0;  	// Һѹ�����Ϸ���Ӧ��(ϵͳ�ڹ���֮ǰ������Һѹ�����Ƿ����ϵ�λ�ã�������
										// ���ж��Ƿ��������������)

sbit HydClamInductorBottom	= P0^1;  	// Һѹ�����·���Ӧ��

sbit KeyStart				= P0^2;  	// ������ť��������ťֻ�����Զ�״̬�²���Ч������֮�󣬵����ʼ�����
										// ��Ƭ����ʼ���ձ������źš�

sbit KeyAutoManual			= P0^3;  	// �ֶ�״̬�£�������ť��ϵͳֹͣ��ť��Ч�������������ź���Ч��
										// �Զ�״̬�� ��Һѹ������ť��Ч�����ߵ�ƽ�Զ����͵�ƽ�ֶ���

sbit KeyStop				= P0^4;  	// ֹͣ��ť

sbit KeyHydClam				= P0^5;  	// Һѹ������ť��ֻ�����ֶ�״̬�²���Ч��

//���
sbit MotorForwardFast  		= P1^5;  //	���ǰ������
sbit MotorBackFast  		= P1^6;  // ������˿���
sbit MotorForwardSlow  		= P1^0;  //	���ǰ������
sbit MotorBackSlow  		= P1^1;  //	�����������
sbit HydClamOut  			= P1^4;  //	Һѹ�������
sbit TestOut		  		= P2^7;  //	�������


/***************************************************************************/
// ��������
/***************************************************************************/
struct Board  //��Ľṹ��
{
	unsigned int boardLength;   //��ĳ���
	unsigned int boardNumber;	//�������
};


/***************************************************************************/
// ��������
/***************************************************************************/
void parameter_init();
unsigned char parameter_save();

extern unsigned char runMode; //����ģʽ	0���ֶ�ģʽ(ֹͣ)  1���Զ�ģʽ(ֹͣ) 2���ֶ�ģʽ(����) 3���Զ�ģʽ(����)   ��������0xEE
extern unsigned char montorMode; //���״̬	0�����ֹͣ   1���������  ��������0xEE
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

extern unsigned char cylinderAlarm1; //�������� ����1	��(int)
extern unsigned char cylinderAlarm2; //�������� ����1	��(int)
extern unsigned char cylinderAlarm3; //�������� ����1	��(int)
extern unsigned char cylinderAlarm4; //�������� ����1	��(int)
extern unsigned char cylinderAlarm5; //�������� ����1	��(int)

extern unsigned int pieceCount; //�Ƽ�����	��(int)

#endif
