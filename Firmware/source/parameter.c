/***************************************************************************/
// 程序：清洗设备控制器
// 模块：参数
// 文件：parameter.c
// 作者：卜晓旸
// 版本：V0.02
// 日期：2013年11月8日
// 功能：参数
// 芯片：STC12C5A60S2
// 编译：Keil uVision3 V3.90
/***************************************************************************/

#include <parameter.h>
#include <eeprom.h>
#include <basefunc.h>

/***************************************************************************/
// 参数定义	
/***************************************************************************/
unsigned char runMode; //运行模式	0：手动模式(停止)  1：自动模式(停止) 2：手动模式(启动) 3：自动模式(启动)   返回数据0xEE
unsigned char montorMode; //电机状态	0：电机停止   1：电机启动  返回数据0xEE
unsigned char alarmMode; //报警状态	0：正常   1：报警
unsigned char sensor1; //传感器1	0：无效  1：有效  2：错误
unsigned char sensor2; //传感器2	0：无效  1：有效  2：错误
unsigned char sensor3; //传感器3	0：无效  1：有效  2：错误
unsigned char sensor4; //传感器4	0：无效  1：有效  2：错误
unsigned char sensor5; //传感器5	0：无效  1：有效  2：错误
unsigned char sensor6; //传感器6	0：无效  1：有效  2：错误
unsigned char sensor7; //传感器7	0：无效  1：有效  2：错误
unsigned char sensor8; //传感器8	0：无效  1：有效  2：错误
unsigned char sensor9; //传感器9	0：无效  1：有效  2：错误
unsigned char sensor10; //传感器10	0：无效  1：有效  2：错误

unsigned char cylinder1; //气缸1	0：无效  1：有效  2：错误
unsigned char cylinder2; //气缸2	0：无效  1：有效  2：错误
unsigned char cylinder3; //气缸3	0：无效  1：有效  2：错误
unsigned char cylinder4; //气缸4	0：无效  1：有效  2：错误
unsigned char cylinder5; //气缸5	0：无效  1：有效  2：错误

unsigned char intervalTimer1; //时间设置1	字(int) 最大9.9
unsigned char intervalTimer2; //时间设置1	字(int) 最大9.9
unsigned char intervalTimer3; //时间设置1	字(int) 最大9.9
unsigned char intervalTimer4; //时间设置1	字(int) 最大9.9
unsigned char intervalTimer5; //时间设置1	字(int) 最大9.9
unsigned char intervalTimer6; //时间设置1	字(int) 最大9.9
unsigned char intervalTimer7; //时间设置1	字(int) 最大9.9

unsigned int cylinderAlarm1; //报警设置 气缸1	字(int)
unsigned int cylinderAlarm2; //报警设置 气缸1	字(int)
unsigned int cylinderAlarm3; //报警设置 气缸1	字(int)
unsigned int cylinderAlarm4; //报警设置 气缸1	字(int)
unsigned int cylinderAlarm5; //报警设置 气缸1	字(int)

unsigned int pieceCount; //计件计数	字(int)

unsigned char refreshDisplay; //刷新屏幕标志位 0 不刷新 1刷新



/***************************************************************************/
// 读取参数
// 参数：无
// 返回值：0失败 1成功	
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
// 参数初始化函数
// 参数：无
// 返回值：无	
/***************************************************************************/
void parameter_init()
{
	runMode = 1; //运行模式	0：手动模式(停止)  1：自动模式(停止) 2：手动模式(启动) 3：自动模式(启动)   返回数据0xEE
	montorMode = 0; //电机状态	0：电机停止   1：电机启动  返回数据0xEE
	alarmMode = 0;
	sensor1 = 0; //传感器1	0：无效  1：有效  2：错误
	sensor2 = 0; //传感器2	0：无效  1：有效  2：错误
	sensor3 = 0; //传感器3	0：无效  1：有效  2：错误
	sensor4 = 0; //传感器4	0：无效  1：有效  2：错误
	sensor5 = 0; //传感器5	0：无效  1：有效  2：错误
	sensor6 = 0; //传感器6	0：无效  1：有效  2：错误
	sensor7 = 0; //传感器7	0：无效  1：有效  2：错误
	sensor8 = 0; //传感器8	0：无效  1：有效  2：错误
	sensor9 = 0; //传感器9	0：无效  1：有效  2：错误
	sensor10 = 0; //传感器10	0：无效  1：有效  2：错误
	
	cylinder1 = 0; //气缸1	0：无效  1：有效  2：错误
	cylinder2 = 0; //气缸2	0：无效  1：有效  2：错误
	cylinder3 = 0; //气缸3	0：无效  1：有效  2：错误
	cylinder4 = 0; //气缸4	0：无效  1：有效  2：错误
	cylinder5 = 0; //气缸5	0：无效  1：有效  2：错误
	
	if(!parameter_read())
	{
		intervalTimer1 = 40; //时间设置1	字(int) 最大9.9
		intervalTimer2 = 40; //时间设置1	字(int) 最大9.9
		intervalTimer3 = 40; //时间设置1	字(int) 最大9.9
		intervalTimer4 = 40; //时间设置1	字(int) 最大9.9
		intervalTimer5 = 40; //时间设置1	字(int) 最大9.9
		intervalTimer6 = 40; //时间设置1	字(int) 最大9.9
		intervalTimer7 = 40; //时间设置1	字(int) 最大9.9
		
		cylinderAlarm1 = 10; //报警设置 气缸1	字(int)
		cylinderAlarm2 = 15; //报警设置 气缸1	字(int)
		cylinderAlarm3 = 20; //报警设置 气缸1	字(int)
		cylinderAlarm4 = 25; //报警设置 气缸1	字(int)
		cylinderAlarm5 = 30; //报警设置 气缸1	字(int)	
	}
	pieceCount = 0;

	refreshDisplay = 1;
}

/***************************************************************************/
// 参数保存到eeprom
// 参数：无
// 返回值：0失败 1成功	
/***************************************************************************/
unsigned char parameter_save()
{
	unsigned char result = 1;
    delay_ms(10);                      //Delay
	IapEraseSector(IAP_ADDRESS); //擦除EEPROM

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
	IapProgramByte(IAP_ADDRESS+200, 0xEE); //写入标志位
	refreshDisplay = 0;
	return result;
}


