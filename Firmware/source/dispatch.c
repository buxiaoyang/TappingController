#include <reg52.h>
#include <parameter.h>
#include <intrins.h>
#include <dispatch.h>

/*
��������ť��
����λ�þ����� ��������1������
����2�Ÿ�Ӧ������������2������
����4�Ÿ�Ӧ�����н�����3������
����6�Ÿ�Ӧ������������2�رա�
����3�Ÿ�Ӧ������������1�رա�
����1�Ÿ�Ӧ������������4������
����8�Ÿ�Ӧ������������4�رա�
����7�Ÿ�Ӧ�����н�����3�رա�
*/

unsigned int intervalTimerCount = 0;
unsigned int cylinderAlarmCount = 0;

unsigned char ManiDispatchSteps = 20;	// 1��1 3 5 7�Ÿ�Ӧ����Ч�����ӳ�
										// 2���ӳ�ʱ�䵽����������1����
										// 3������2�Ÿ�Ӧ�������ӳ�
										// 4���ӳ�intervalTimer1ʱ�䵽����������2����
										// 5������4�Ÿ�Ӧ�������ӳ�
										// 6���ӳ�intervalTimer2ʱ�䵽���н�����3����
										// 7������6�Ÿ�Ӧ�������ӳ�
										// 8���ӳ�intervalTimer3ʱ�䵽����������2�ر�
										// 9������3�Ÿ�Ӧ�������ӳ�
										// 10���ӳ�intervalTimer4ʱ�䵽����������1�ر�
										// 11������1�Ÿ�Ӧ�������ӳ�
										// 12���ӳ�intervalTimer5ʱ�䵽����������4����
										// 13������8�Ÿ�Ӧ�������ӳ�
										// 14���ӳ�intervalTimer6ʱ�䵽����������4�ر�
										// 15������7�Ÿ�Ӧ�������ӳ�
										// 16���ӳ�intervalTimer7ʱ�䵽���н�����3�ر�
										// 20���ղ���

void ManiDispatch(void)
{
	switch(ManiDispatchSteps)
	{
		case 1:  // 1��1 3 5 7�Ÿ�Ӧ����Ч����������1����
			if(sensor1 == 1 && sensor3 == 1 && sensor5 == 1 && sensor7 == 1)
			{
				intervalTimerCount = 0;
				ManiDispatchSteps ++;	
			}
			else if(cylinderAlarmCount > cylinderAlarm3)
			{
				alarmMode = 1;
				cylinder3 = 2;
				systemAlarmOut = 0;
				refreshDisplay = 1;
			}
		break;
		case 2:  // 2���ӳ�2sʱ�䵽����������1����
			if(intervalTimerCount> 40)
			{
				cylinderOut1 = 0;
				cylinder1 = 1;
				refreshDisplay = 1;
				cylinderAlarmCount = 0;
				ManiDispatchSteps ++;	
			}
		break;
		case 3:  // 3������2�Ÿ�Ӧ�������ӳ� 
			if(sensor2 == 1)
			{
				intervalTimerCount = 0;
				ManiDispatchSteps ++;	
			}
			else if(cylinderAlarmCount > cylinderAlarm1)
			{
				alarmMode = 1;
				cylinder1 = 2;
				systemAlarmOut = 0;
				refreshDisplay = 1;
			}
		break;
		case 4:  // 4���ӳ�intervalTimer1ʱ�䵽����������2����
			if(intervalTimerCount> intervalTimer1)
			{
				cylinderOut2 = 0;
				cylinder2 = 1;
				refreshDisplay = 1;
				cylinderAlarmCount = 0;
				ManiDispatchSteps ++;	
			}
		break;
		case 5:  // 5������4�Ÿ�Ӧ�������ӳ�
			if(sensor4 == 1)
			{
				intervalTimerCount = 0;
				ManiDispatchSteps ++;	
			}
			else if(cylinderAlarmCount > cylinderAlarm2)
			{
				alarmMode = 1;
				cylinder2 = 2;
				systemAlarmOut = 0;
				refreshDisplay = 1;
			}
		break;
		case 6: // 6���ӳ�intervalTimer2ʱ�䵽���н�����3����
			if(intervalTimerCount > intervalTimer2)
			{
				cylinderOut3 = 0;
				cylinder3 = 1;
				refreshDisplay = 1;
				cylinderAlarmCount = 0;
				ManiDispatchSteps ++;	
			}
		break;
		case 7: // 7������6�Ÿ�Ӧ�������ӳ�
			if(sensor6 == 1)
			{
				intervalTimerCount = 0;
				ManiDispatchSteps ++;	
			}
			else if(cylinderAlarmCount > cylinderAlarm3)
			{
				alarmMode = 1;
				cylinder3 = 2;
				systemAlarmOut = 0;
				refreshDisplay = 1;
			}
		break;
		case 8:  // 8���ӳ�intervalTimer3ʱ�䵽����������2�ر�
			if(intervalTimerCount > intervalTimer3)
			{
				cylinderOut2 = 1;
				cylinder2 = 0;
				refreshDisplay = 1;
				cylinderAlarmCount = 0;
				ManiDispatchSteps ++;	
			}
		break;
		case 9: // 9������3�Ÿ�Ӧ�������ӳ�
			if(sensor3 == 1)
			{
				intervalTimerCount = 0;
				ManiDispatchSteps ++;	
			}
			else if(cylinderAlarmCount > cylinderAlarm2)
			{
				alarmMode = 1;
				cylinder2 = 2;
				systemAlarmOut = 0;
				refreshDisplay = 1;
			}
		break;
		case 10:  // 10���ӳ�intervalTimer4ʱ�䵽����������1�ر�
			if(intervalTimerCount > intervalTimer4)
			{
				cylinderOut1 = 1;
				cylinder1 = 0;
				refreshDisplay = 1;
				cylinderAlarmCount = 0;
				ManiDispatchSteps ++;	
			}
		break;
		case 11:  // 11������1�Ÿ�Ӧ�������ӳ�
			if(sensor1 == 1)
			{
				intervalTimerCount = 0;
				ManiDispatchSteps ++;	
			}
			else if(cylinderAlarmCount > cylinderAlarm1)
			{
				alarmMode = 1;
				cylinder1 = 2;
				systemAlarmOut = 0;
				refreshDisplay = 1;
			}
		break;
		case 12: // 12���ӳ�intervalTimer5ʱ�䵽����������4����
			if(intervalTimerCount > intervalTimer5)
			{
				cylinderOut4 = 0;
				cylinder4 = 1;
				refreshDisplay = 1;
				cylinderAlarmCount = 0;
				ManiDispatchSteps ++;	
			}
		break;
		case 13: // 13������8�Ÿ�Ӧ�������ӳ�
			if(sensor8 == 1)
			{
				intervalTimerCount = 0;
				ManiDispatchSteps ++;	
			}
			else if(cylinderAlarmCount > cylinderAlarm4)
			{
				alarmMode = 1;
				cylinder4 = 2;
				systemAlarmOut = 0;
				refreshDisplay = 1;
			}
		break;
		case 14:  // 14���ӳ�intervalTimer6ʱ�䵽����������4�ر�
			if(intervalTimerCount > intervalTimer6)
			{
				cylinderOut4 = 1;
				cylinder4 = 0;
				refreshDisplay = 1;
				cylinderAlarmCount = 0;
				ManiDispatchSteps ++;	
			}
		break;
		case 15: // 15������7�Ÿ�Ӧ�������ӳ�
			if(sensor7 == 1)
			{
				intervalTimerCount = 0;
				ManiDispatchSteps ++;	
			}
			else if(cylinderAlarmCount > cylinderAlarm4)
			{
				alarmMode = 1;
				cylinder4 = 2;
				systemAlarmOut = 0;
				refreshDisplay = 1;
			}
		break;
		case 16: // 16���ӳ�intervalTimer7ʱ�䵽���н�����3�ر�
			if(intervalTimerCount > intervalTimer7)
			{
				cylinderOut3 = 1;
				cylinder3 = 0;
				refreshDisplay = 1;
				ManiDispatchSteps = 1;
				cylinderAlarmCount = 0;
				pieceCount ++;	
			}
		break;
	}
}
