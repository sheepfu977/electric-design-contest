#include "JY61.h"

struct SAcc 		stcAcc;
struct SGyro 		stcGyro;
struct SAngle 	stcAngle;

char YAWCMD[3] = {0XFF,0XAA,0X52};
char ACCCMD[3] = {0XFF,0XAA,0X67};
char SLEEPCMD[3] = {0XFF,0XAA,0X60};
char UARTMODECMD[3] = {0XFF,0XAA,0X61};
char IICMODECMD[3] = {0XFF,0XAA,0X62};

//CopeSerialDataΪ����2�жϵ��ú���������ÿ�յ�һ�����ݣ�����һ�����������
void CopeSerial2Data(unsigned char ucData)
{
	static unsigned char ucRxBuffer[250];
	static unsigned char ucRxCnt = 0;	
	
	ucRxBuffer[ucRxCnt++]=ucData;	//���յ������ݴ��뻺������
	if (ucRxBuffer[0]!=0x55) //����ͷ���ԣ������¿�ʼѰ��0x55����ͷ
	{
		ucRxCnt=0;
		return;
	}
	if (ucRxCnt<11) {return;}//���ݲ���11�����򷵻�
	else
	{
		switch(ucRxBuffer[1])//�ж��������������ݣ�Ȼ���俽������Ӧ�Ľṹ���У���Щ���ݰ���Ҫͨ����λ���򿪶�Ӧ������󣬲��ܽ��յ�������ݰ�������
		{
			//memcpyΪ�������Դ����ڴ濽��������������"string.h"�������ջ��������ַ����������ݽṹ�����棬�Ӷ�ʵ�����ݵĽ�����
			case 0x51:	memcpy(&stcAcc,&ucRxBuffer[2],8);break;
			case 0x52:	memcpy(&stcGyro,&ucRxBuffer[2],8);break;
			case 0x53:	memcpy(&stcAngle,&ucRxBuffer[2],8);break;

		}
		ucRxCnt=0;//��ջ�����
	}
}

void Send_CMD_Calibration()	//Z��У׼
{
	HAL_UART_Transmit(&huart2, (uint8_t *)&ACCCMD, 3, 0xFFFF); //���ٶ�У׼
	HAL_Delay(100);
	HAL_UART_Transmit(&huart2, (uint8_t *)&YAWCMD, 3, 0xFFFF); //Z������
}
