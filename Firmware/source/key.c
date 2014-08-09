#include <reg52.h>
#include <intrins.h>
#include <parameter.h>
#include <key.h>
#include <dispatch.h>


void Key_Scan(void);

unsigned char Key_Scan_Steps = 0; 		//0：初始状态 如果有按键按下则进入1
										//1：延迟10ms
										//2：如果按键确实按下则进入3
										//3：确定按键
										//4：如果按键释放则进入0

void Key_Scan(void)
{
	switch(Key_Scan_Steps)
	{
		case 0:
			if(KeyStart == 0 || KeyStop == 0)
			{
			   	Key_Scan_Steps = 1;
			}
		break;
		case 1:
			if(KeyStart == 0 || KeyStop == 0)
			{
			   	Key_Scan_Steps = 2;
			}
			else
			{
				Key_Scan_Steps = 0;
			}
		break;
		case 2:
			if(KeyStart == 0) //开始按键按下
			{
				if(runMode == 1)
				{
					runMode = 3;
					ManiDispatchSteps = 1;
					cylinder1 = 0;
					cylinder2 = 0;
					cylinder3 = 0;
					cylinder4 = 0;
					cylinder5 = 0;
					cylinderOut1 = 1;
					cylinderOut2 = 1;
					cylinderOut3 = 1;
					cylinderOut4 = 1;
					cylinderOut5 = 1;
					refreshDisplay = 1;
				}
			}
			if(KeyStop == 0) //急停按键按下
			{
				runMode = 1;
				cylinder1 = 0;
				cylinder2 = 0;
				cylinder3 = 0;
				cylinder4 = 0;
				cylinder5 = 0;
				cylinderOut1 = 1;
				cylinderOut2 = 1;
				cylinderOut3 = 1;
				cylinderOut4 = 1;
				cylinderOut5 = 1;
				refreshDisplay = 1;	
			}
			Key_Scan_Steps = 3;
		break;
		case 3:
			if(KeyStart == 1 && KeyStop == 1)
			{
			   	Key_Scan_Steps = 0;
			}
		break;
		default:
			 _nop_();
	}
}