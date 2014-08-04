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
	SendDataToScreen(0x0000,runMode); //运行模式	0：手动模式(停止)  1：自动模式(停止) 2：手动模式(启动) 3：自动模式(启动)   返回数据0xEE
	
	SendDataToScreen(0x0001,montorMode); //电机状态	0：电机停止   1：电机启动  返回数据0xEE

	/*
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




