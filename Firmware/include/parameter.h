/***************************************************************************/
// 程序：清洗设备控制器
// 模块：参数头文件
// 文件：parameter.h
// 作者：卜晓旸
// 版本：V0.02
// 日期：2013年11月8日
// 功能：参数头文件
// 芯片：STC12C5A60S2
// 编译：Keil uVision3 V3.90
/***************************************************************************/

#ifndef __PARAMETER_H__
#define __PARAMETER_H__

#include <reg52.h>

/***************************************************************************/
// 引脚定义
/***************************************************************************/
//输入
sbit EncoderCounting		= P3^2;  	// 编码器计数（绿色）

sbit EncoderDirection		= P2^4;  	// 编码器方向（白色）

sbit HydClamInductorTop		= P0^0;  	// 液压剪刀上方感应器(系统在工作之前，根据液压剪刀是否在上的位置（常亮）
										// 来判定是否可以正常工作。)

sbit HydClamInductorBottom	= P0^1;  	// 液压剪刀下方感应器

sbit KeyStart				= P0^2;  	// 启动按钮，启动按钮只有在自动状态下才有效，启动之后，电机开始输出，
										// 单片机开始接收编码器信号。

sbit KeyAutoManual			= P0^3;  	// 手动状态下，启动按钮、系统停止按钮无效，编码器接收信号无效。
										// 自动状态下 ，液压剪刀按钮无效。（高电平自动，低电平手动）

sbit KeyStop				= P0^4;  	// 停止按钮

sbit KeyHydClam				= P0^5;  	// 液压剪刀按钮，只有下手动状态下才有效。

//输出
sbit MotorForwardFast  		= P1^5;  //	电机前进快速
sbit MotorBackFast  		= P1^6;  // 电机后退快速
sbit MotorForwardSlow  		= P1^0;  //	电机前进慢速
sbit MotorBackSlow  		= P1^1;  //	电机后退慢速
sbit HydClamOut  			= P1^4;  //	液压剪刀输出
sbit TestOut		  		= P2^7;  //	测试输出


/***************************************************************************/
// 参数定义
/***************************************************************************/
struct Board  //板材结构体
{
	unsigned int boardLength;   //板材长度
	unsigned int boardNumber;	//板材数量
};


/***************************************************************************/
// 参数声明
/***************************************************************************/
void parameter_init();
unsigned char parameter_save();

extern unsigned char runMode; //运行模式	0：手动模式(停止)  1：自动模式(停止) 2：手动模式(启动) 3：自动模式(启动)   返回数据0xEE
extern unsigned char montorMode; //电机状态	0：电机停止   1：电机启动  返回数据0xEE
extern unsigned char sensor1; //传感器1	0：无效  1：有效  2：错误
extern unsigned char sensor2; //传感器2	0：无效  1：有效  2：错误
extern unsigned char sensor3; //传感器3	0：无效  1：有效  2：错误
extern unsigned char sensor4; //传感器4	0：无效  1：有效  2：错误
extern unsigned char sensor5; //传感器5	0：无效  1：有效  2：错误
extern unsigned char sensor6; //传感器6	0：无效  1：有效  2：错误
extern unsigned char sensor7; //传感器7	0：无效  1：有效  2：错误
extern unsigned char sensor8; //传感器8	0：无效  1：有效  2：错误
extern unsigned char sensor9; //传感器9	0：无效  1：有效  2：错误
extern unsigned char sensor10; //传感器10	0：无效  1：有效  2：错误

extern unsigned char cylinder1; //气缸1	0：无效  1：有效  2：错误
extern unsigned char cylinder2; //气缸2	0：无效  1：有效  2：错误
extern unsigned char cylinder3; //气缸3	0：无效  1：有效  2：错误
extern unsigned char cylinder4; //气缸4	0：无效  1：有效  2：错误
extern unsigned char cylinder5; //气缸5	0：无效  1：有效  2：错误

extern unsigned char intervalTimer1; //时间设置1	字(int) 最大9.9
extern unsigned char intervalTimer2; //时间设置1	字(int) 最大9.9
extern unsigned char intervalTimer3; //时间设置1	字(int) 最大9.9
extern unsigned char intervalTimer4; //时间设置1	字(int) 最大9.9
extern unsigned char intervalTimer5; //时间设置1	字(int) 最大9.9
extern unsigned char intervalTimer6; //时间设置1	字(int) 最大9.9
extern unsigned char intervalTimer7; //时间设置1	字(int) 最大9.9

extern unsigned char cylinderAlarm1; //报警设置 气缸1	字(int)
extern unsigned char cylinderAlarm2; //报警设置 气缸1	字(int)
extern unsigned char cylinderAlarm3; //报警设置 气缸1	字(int)
extern unsigned char cylinderAlarm4; //报警设置 气缸1	字(int)
extern unsigned char cylinderAlarm5; //报警设置 气缸1	字(int)

extern unsigned int pieceCount; //计件计数	字(int)

#endif
