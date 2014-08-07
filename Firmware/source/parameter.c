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

/***************************************************************************/
// 参数定义	
/***************************************************************************/
unsigned char runMode; //运行模式	0：手动模式(停止)  1：自动模式(停止) 2：手动模式(启动) 3：自动模式(启动)   返回数据0xEE
unsigned char montorMode; //电机状态	0：电机停止   1：电机启动  返回数据0xEE
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

/***************************************************************************/
// 读取参数
// 参数：无
// 返回值：0失败 1成功	
/***************************************************************************/
unsigned char parameter_read()
{
	unsigned char result = 1;
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
	montorMode = 1; //电机状态	0：电机停止   1：电机启动  返回数据0xEE
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
	
	intervalTimer1 = 0; //时间设置1	字(int) 最大9.9
	intervalTimer2 = 0; //时间设置1	字(int) 最大9.9
	intervalTimer3 = 0; //时间设置1	字(int) 最大9.9
	intervalTimer4 = 0; //时间设置1	字(int) 最大9.9
	intervalTimer5 = 0; //时间设置1	字(int) 最大9.9
	intervalTimer6 = 0; //时间设置1	字(int) 最大9.9
	intervalTimer7 = 0; //时间设置1	字(int) 最大9.9
	
	cylinderAlarm1 = 0; //报警设置 气缸1	字(int)
	cylinderAlarm2 = 0; //报警设置 气缸1	字(int)
	cylinderAlarm3 = 0; //报警设置 气缸1	字(int)
	cylinderAlarm4 = 0; //报警设置 气缸1	字(int)
	cylinderAlarm5 = 0; //报警设置 气缸1	字(int)

	pieceCount = 0;
}

/***************************************************************************/
// 参数保存到eeprom
// 参数：无
// 返回值：0失败 1成功	
/***************************************************************************/
unsigned char parameter_save()
{
	unsigned char result = 1;
	return result;
}


