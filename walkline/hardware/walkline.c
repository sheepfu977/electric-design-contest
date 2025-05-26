#include "walkline.h"

/**
 * Function       app_LineWalking
 * @author        fuyang
 * @date          2025.5.5
 * @brief         开始循迹
 * @param[in]     void
 * @param[out]    void
 * @retval        void
 * @par History   无
 */
void app_LineWalking(void)
{
    int LineL1 = 1, LineL2 = 1, LineR1 = 1, LineR2 = 1;

    bsp_GetLineWalking(&LineL1, &LineL2, &LineR1, &LineR2); // 获取黑线检测状态

    // if ((LineL1 == LOW || LineL2 == LOW) && LineR2 == LOW) // 左大弯
    // {
        
        
    // }
    // else if (LineL1 == LOW && (LineR1 == LOW || LineR2 == LOW)) // 右大弯
    // {
        
        
    // }
    // else if (LineL1 == LOW) // 左最外侧检测
    // {
        
    // }
    // else if (LineR2 == LOW) // 右最外侧检测
    // {
        
    // }
    // else if (LineL2 == LOW && LineR1 == HIGH) // 中间黑线上的传感器微调车左转
    // {
        
    // }
    // else if (LineL2 == HIGH && LineR1 == LOW) // 中间黑线上的传感器微调车右转
    // {
        
    // }
    // else if (LineL2 == LOW && LineR1 == LOW) // 都是黑色, 加速前进
    // {
        
    // }
    if (LineL1 == LOW)
    {
       HAL_UART_Transmit(&huart1, "L1", 2, 100);
        HAL_Delay(100);
    }
    else if (LineL2 == LOW)
    {
        HAL_UART_Transmit(&huart1, "L2", 2, 100);
        HAL_Delay(100);
    }
    else if (LineR1 == LOW)
    {
        HAL_UART_Transmit(&huart1, "R1", 2, 100);
        HAL_Delay(100);
    }
    else if (LineR2 == LOW)
    {
        HAL_UART_Transmit(&huart1, "R2", 2, 100);
        HAL_Delay(100);
    }
    
   
   

}

/**
 * Function       bsp_GetLineWalking
 * @author        fuyang
 * @date          2025.5.5
 * @brief         获取循迹传感器状态
 * @param[in]     int *p_iL1, int *p_iL2, int *p_iR1, int *p_iR2
 * @param[out]    void
 * @retval        void
 * @par History   无
 */
void bsp_GetLineWalking(int *p_iL1, int *p_iL2, int *p_iR1, int *p_iR2)
{
    *p_iL1 = HAL_GPIO_ReadPin(LineWalk_L1_PORT, LineWalk_L1_PIN);
    *p_iL2 = HAL_GPIO_ReadPin(LineWalk_L2_PORT, LineWalk_L2_PIN);
    *p_iR1 = HAL_GPIO_ReadPin(LineWalk_R1_PORT, LineWalk_R1_PIN);
    *p_iR2 = HAL_GPIO_ReadPin(LineWalk_R2_PORT, LineWalk_R2_PIN);
}
