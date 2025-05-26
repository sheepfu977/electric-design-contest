/**
 * @par
 * @file         walkline.h
 * @author       fuyang
 * @version      V1.0
 * @date         2025.5.5
 * @brief        四路红外循迹头文件
 * @details
 * @par History  见如下说明
 *
 * version:	2025.5.5 fuyang
 * /*

    从车身后面往前看： 左侧到右边巡线传感器顺序为  L1 L2 |黑线| R1  R2	  对应原理图 IN2 IN1 |黑线| IN3 IN4

*/


#ifndef __WALKLINE_H
#define __WALKLINE_H

#include "main.h"
#include "usart.h"

    void app_LineWalking(void);
void bsp_GetLineWalking(int *p_iL1, int *p_iL2, int *p_iR1, int *p_iR2);

#define LineWalk_L1_PIN GPIO_PIN_6
#define LineWalk_L2_PIN GPIO_PIN_5
#define LineWalk_R1_PIN GPIO_PIN_4
#define LineWalk_R2_PIN GPIO_PIN_3

#define LineWalk_L1_PORT GPIOG
#define LineWalk_L2_PORT GPIOG
#define LineWalk_R1_PORT GPIOG
#define LineWalk_R2_PORT GPIOG

#define LOW 0
#define HIGH 1

#endif
