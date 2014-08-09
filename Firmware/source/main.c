/***************************************************************************/
// 程序：清洗设备控制器
// 模块：主函数	
// 文件：main.c
// 作者：卜晓旸
// 版本：V0.02
// 日期：2013年11月8日
// 功能：主函数
// 芯片：STC12C5A60S2
// 编译：Keil uVision3 V3.90
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
	SendDataToScreen(0x0000,runMode); //运行模式	0：手动模式(停止)  1：自动模式(停止) 2：手动模式(启动) 3：自动模式(启动)   返回数据0xEE
	//切换页面
	if(alarmMode == 0)
	{
		if(runMode == 0 || runMode == 3)
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
	SendDataToScreen(0x0001,montorMode); //电机状态	0：电机停止   1：电机启动  返回数据0xEE

	SendDataToScreen(0x0002,sensor1); //传感器1	0：无效  1：有效  2：错误
	SendDataToScreen(0x0003,sensor2); //传感器2	0：无效  1：有效  2：错误
	SendDataToScreen(0x0004,sensor3); //传感器3	0：无效  1：有效  2：错误
	SendDataToScreen(0x0005,sensor4); //传感器4	0：无效  1：有效  2：错误
	SendDataToScreen(0x0006,sensor5); //传感器5	0：无效  1：有效  2：错误
	SendDataToScreen(0x0007,sensor6); //传感器6	0：无效  1：有效  2：错误
	SendDataToScreen(0x0008,sensor7); //传感器7	0：无效  1：有效  2：错误
	SendDataToScreen(0x0009,sensor8); //传感器8	0：无效  1：有效  2：错误
	SendDataToScreen(0x000A,sensor9); //传感器9	0：无效  1：有效  2：错误
	SendDataToScreen(0x000B,sensor10); //传感器10	0：无效  1：有效  2：错误

	SendDataToScreen(0x000C,cylinder1); //气缸1	0：无效  1：有效  2：错误
	SendDataToScreen(0x000D,cylinder2); //气缸2	0：无效  1：有效  2：错误
	SendDataToScreen(0x000E,cylinder3); //气缸3	0：无效  1：有效  2：错误
	SendDataToScreen(0x000F,cylinder4); //气缸4	0：无效  1：有效  2：错误
	SendDataToScreen(0x0010,cylinder5); //气缸5	0：无效  1：有效  2：错误
	
	SendDataToScreen(0x0011,intervalTimer1); //时间设置1	字(int) 最大9.9
	SendDataToScreen(0x0012,intervalTimer2); //时间设置2	字(int) 最大9.9
	SendDataToScreen(0x0013,intervalTimer3); //时间设置3	字(int) 最大9.9
	SendDataToScreen(0x0014,intervalTimer4); //时间设置4	字(int) 最大9.9
	SendDataToScreen(0x0015,intervalTimer5); //时间设置5	字(int) 最大9.9
	SendDataToScreen(0x0016,intervalTimer6); //时间设置6	字(int) 最大9.9
	SendDataToScreen(0x0017,intervalTimer7); //时间设置7	字(int) 最大9.9
	
	SendDataToScreen(0x0018,cylinderAlarm1); //报警设置 气缸1	字(int)
	SendDataToScreen(0x0019,cylinderAlarm2); //报警设置 气缸2	字(int)
	SendDataToScreen(0x001A,cylinderAlarm3); //报警设置 气缸3	字(int)
	SendDataToScreen(0x001B,cylinderAlarm4); //报警设置 气缸4	字(int)
	SendDataToScreen(0x001C,cylinderAlarm5); //报警设置 气缸5	字(int)

	SendDataToScreen(0x0023,pieceCount); 

}

/***************************************************************************/
// 主函数
// 参数：无
// 返回值：无	
/***************************************************************************/
void main()
{
	uart_init();
	//timer_init();
	parameter_init();
	while(1)
	{	
		if(refreshDisplay)
		{
			parameter_send_screen();
			refreshDisplay = 0;
		}
		TestOut = ! TestOut;
		//电机输出
		if(montorMode)
		{
			montorOut = 0;
		}
		else
		{
			montorOut = 1;
		} 
		Key_Scan();
		ManiDispatch();
		SubDispatch();
		//delay_ms(100);
	}   
}








