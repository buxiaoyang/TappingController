#include <reg52.h>
#include <intrins.h>
#include <parameter.h>
#include <key.h>
#include <dispatch.h>


void Key_Scan(void);

unsigned char Key_Scan_Steps = 0; 		//0����ʼ״̬ ����а������������1
										//1���ӳ�10ms
										//2���������ȷʵ���������3
										//3��ȷ������
										//4����������ͷ������0

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
			if(KeyStart == 0) //��ʼ��������
			{
				if(runMode == 1)
				{
					runMode = 3;
					refreshDisplay = 1;
				}
			}
			if(KeyStop == 0) //��ͣ��������
			{
				runMode = 1;
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