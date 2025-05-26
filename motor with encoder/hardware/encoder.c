# include "encoder.h"

int32_t encoder_count = 0;              // 编码器累计计数值
uint16_t last_counter = 0;              // 上一次定时器计数值
int read_speed(TIM_HandleTypeDef *htim) //16位计数器为0——65535 无法记负数故要强转为负数变量
{
    int temp;
    temp = (short)__HAL_TIM_GET_COUNTER(htim); // Get the current counter value
    __HAL_TIM_SET_COUNTER(htim, 0); // 计数器清零
    return temp; // Return the speed value
    
}
