#include <reg52.h>
#include <parameter.h>
#include <intrins.h>
#include <dispatch.h>

/*
按启动按钮，
气缸位置就绪， 送料气缸1启动，
碰到2号感应器，打料气缸2启动。
碰到4号感应器，夹紧气缸3启动。
碰到6号感应器，打料气缸2关闭。
碰到3号感应器，送料气缸1关闭。
碰到1号感应器，进刀气缸4启动。
碰到8号感应器，进刀气缸4关闭。
碰到7号感应器，夹紧气缸3关闭。
*/

unsigned int intervalTimerCount = 0;
unsigned int cylinderAlarmCount = 0;

unsigned char ManiDispatchSteps = 20;	// 1，1 3 5 7号感应器有效进入延迟
										// 2，延迟时间到，送料气缸1启动
										// 3，碰到2号感应器进入延迟
										// 4，延迟intervalTimer1时间到，打料气缸2启动
										// 5，碰到4号感应器进入延迟
										// 6，延迟intervalTimer2时间到，夹紧气缸3启动
										// 7，碰到6号感应器进入延迟
										// 8，延迟intervalTimer3时间到，打料气缸2关闭
										// 9，碰到3号感应器进入延迟
										// 10，延迟intervalTimer4时间到，送料气缸1关闭
										// 11，碰到1号感应器进入延迟
										// 12，延迟intervalTimer5时间到，进刀气缸4启动
										// 13，碰到8号感应器进入延迟
										// 14，延迟intervalTimer6时间到，进刀气缸4关闭
										// 15，碰到7号感应器进入延迟
										// 16，延迟intervalTimer7时间到，夹紧气缸3关闭
										// 20，空操作

void ManiDispatch(void)
{
	switch(ManiDispatchSteps)
	{
		case 1:  // 1，1 3 5 7号感应器有效，送料气缸1启动
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
		case 2:  // 2，延迟2s时间到，送料气缸1启动
			if(intervalTimerCount> 40)
			{
				cylinderOut1 = 0;
				cylinder1 = 1;
				refreshDisplay = 1;
				cylinderAlarmCount = 0;
				ManiDispatchSteps ++;	
			}
		break;
		case 3:  // 3，碰到2号感应器进入延迟 
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
		case 4:  // 4，延迟intervalTimer1时间到，打料气缸2启动
			if(intervalTimerCount> intervalTimer1)
			{
				cylinderOut2 = 0;
				cylinder2 = 1;
				refreshDisplay = 1;
				cylinderAlarmCount = 0;
				ManiDispatchSteps ++;	
			}
		break;
		case 5:  // 5，碰到4号感应器进入延迟
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
		case 6: // 6，延迟intervalTimer2时间到，夹紧气缸3启动
			if(intervalTimerCount > intervalTimer2)
			{
				cylinderOut3 = 0;
				cylinder3 = 1;
				refreshDisplay = 1;
				cylinderAlarmCount = 0;
				ManiDispatchSteps ++;	
			}
		break;
		case 7: // 7，碰到6号感应器进入延迟
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
		case 8:  // 8，延迟intervalTimer3时间到，打料气缸2关闭
			if(intervalTimerCount > intervalTimer3)
			{
				cylinderOut2 = 1;
				cylinder2 = 0;
				refreshDisplay = 1;
				cylinderAlarmCount = 0;
				ManiDispatchSteps ++;	
			}
		break;
		case 9: // 9，碰到3号感应器进入延迟
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
		case 10:  // 10，延迟intervalTimer4时间到，送料气缸1关闭
			if(intervalTimerCount > intervalTimer4)
			{
				cylinderOut1 = 1;
				cylinder1 = 0;
				refreshDisplay = 1;
				cylinderAlarmCount = 0;
				ManiDispatchSteps ++;	
			}
		break;
		case 11:  // 11，碰到1号感应器进入延迟
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
		case 12: // 12，延迟intervalTimer5时间到，进刀气缸4启动
			if(intervalTimerCount > intervalTimer5)
			{
				cylinderOut4 = 0;
				cylinder4 = 1;
				refreshDisplay = 1;
				cylinderAlarmCount = 0;
				ManiDispatchSteps ++;	
			}
		break;
		case 13: // 13，碰到8号感应器进入延迟
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
		case 14:  // 14，延迟intervalTimer6时间到，进刀气缸4关闭
			if(intervalTimerCount > intervalTimer6)
			{
				cylinderOut4 = 1;
				cylinder4 = 0;
				refreshDisplay = 1;
				cylinderAlarmCount = 0;
				ManiDispatchSteps ++;	
			}
		break;
		case 15: // 15，碰到7号感应器进入延迟
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
		case 16: // 16，延迟intervalTimer7时间到，夹紧气缸3关闭
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
