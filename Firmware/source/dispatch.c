#include <reg52.h>
#include <parameter.h>
#include <intrins.h>
#include <dispatch.h>

unsigned char ManiDispatchSteps = 20;

unsigned char SubDispatchSteps = 20; 	
								//0����ʼ״̬
								//1��������ǰ����
								//2���������ó���15%��������ǰ����
								//3���������ó���85%��������ǰ����
								//4���������ó���100%���а����
								//5���а��·���Ӧ
								//6���а��Ϸ���Ӧ�����̽���
								//20������״̬

unsigned char currentSettingIndex = 20;
unsigned char currentSettingBoardNum = 20;


void ManiDispatch(void)
{

}

//0����ʼ״̬
//1��������ǰ����
//2���������ó���15%��������ǰ����
//3���������ó���85%��������ǰ����
//4���������ó���100%���а����
//5���а��·���Ӧ
//6���а��Ϸ���Ӧ�����̽���
//20������״̬
void SubDispatch(void)
{

}