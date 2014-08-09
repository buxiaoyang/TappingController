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
sbit sensorIn1 = P0^0; //传感器1
sbit sensorIn2 = P0^1; //传感器2
sbit sensorIn3 = P0^2; //传感器3
sbit sensorIn4 = P0^3; //传感器4
sbit sensorIn5 = P0^4; //传感器5
sbit sensorIn6 = P0^5; //传感器6
sbit sensorIn7 = P0^6; //传感器7
sbit sensorIn8 = P0^7; //传感器8
sbit sensorIn9 = P2^0; //传感器9
sbit sensorIn10 = P2^1; //传感器10

sbit KeyStart = P2^2; //开始按钮
sbit KeyStop = P2^3; //急停按钮

//输出
sbit cylinderOut1 = P1^0; //气缸1
sbit cylinderOut2 = P1^1; //气缸2
sbit cylinderOut3 = P2^4; //气缸3
sbit cylinderOut4 = P2^5; //气缸4
sbit cylinderOut5 = P1^4; //气缸5
sbit montorOut = P1^5;		//电机输出
sbit systemAlarmOut = P1^6; //系统警报

sbit TestOut = P2^6;

/***************************************************************************/
// 参数声明
/***************************************************************************/
void parameter_init();
unsigned char parameter_save();

extern unsigned char runMode; //运行模式	0：手动模式(停止)  1：自动模式(停止) 2：手动模式(启动) 3：自动模式(启动)   返回数据0xEE
extern unsigned char montorMode; //电机状态	0：电机停止   1：电机启动  返回数据0xEE
extern unsigned char alarmMode; //报警状态	0：正常   1：报警
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

extern unsigned int cylinderAlarm1; //报警设置 气缸1	字(int)
extern unsigned int cylinderAlarm2; //报警设置 气缸1	字(int)
extern unsigned int cylinderAlarm3; //报警设置 气缸1	字(int)
extern unsigned int cylinderAlarm4; //报警设置 气缸1	字(int)
extern unsigned int cylinderAlarm5; //报警设置 气缸1	字(int)

extern unsigned int pieceCount; //计件计数	字(int)

extern unsigned char refreshDisplay; //刷新屏幕标志位 0 不刷新 1刷新

#endif
