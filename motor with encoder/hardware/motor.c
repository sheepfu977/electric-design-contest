#include "motor.h"
extern TIM_HandleTypeDef htim1; //定时器句柄
int abs (int x) //取绝对值函数，电机输入值的正负仅代表转动方向
{
    return x > 0 ? x : -x;
}

void motor_setspeed(int motor1)  //-1000~1000，0为停转 1000为100%正转
{
	if(motor1<0)//电机反转状态，
    {
        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_SET); //AIN1高电平
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET); // AIN2低电平
    }
    else //电机正转状态
    {
        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_RESET); //AIN1低电平
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); // AIN2高电平
    }

     __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, abs(motor1));
}
