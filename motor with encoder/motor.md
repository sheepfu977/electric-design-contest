# mpu6050驱动电机模块
## 接线
```1``` PA0接AIN1 PA1接AIN2 PE9 接PWM1 同时mpu6050需要5V供电。
```2``` 电机接AM1和AM2即可 
## cubemax配置
```1``` F4主频168MHz（主频不一致时定时器内容同样需要调整）最终时钟输出：SYSCLK = 168 MHz APB1 = 42 MHz (定时器时钟为 84 MHz) APB2 = 84 MHz（时钟树相关知识，定时器所获得的时钟信号是源自AHB的）
```2``` PA1,PA0输出高电平 
```3``` 选择任意高级定时器 例如TIM1 开启一个PWM波输出通道 设置Prescaler = 84-1        // 输入时钟分频：84MHz/84 = 1MHz Counter Period = 1000-1 // PWM频率 = 1MHz/1000 = 1kH Pulse = 0               // 初始占空比为0%
## 程序内容
```1``` 需要引入模块程序 motor.c与motor.h 
```2``` 核心函数motor_setspeed(int motor1) 修改motor1的值即可控制电机   HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1); // Start PWM on TIM1 Channel 1初始化定时器输出pwm波

## 此程序仅为单路电机控制，多路控制请自行修改程序
## 电机和mpu6050连接时为了程序编写方便需要一个反接一个正接。

# 编码器测速
## cubemax配置
```1```  设置任意高级定时器的combined Channels为Encoder Mode其余参数默认即可。
```2``` 需要引入编码器相关文件encoder.c encoder.h 并在主文件中声明。
```3``` HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL); // 开启编码器模式\
```4``` 解码后的数据包为display_buffer 读取函数为 read().

