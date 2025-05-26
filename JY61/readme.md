# JY61 陀螺仪模块
```1``` 相较于mpu6050 jy61通过滤波算法能够解决z轴漂移的问题，故使用作为小车陀螺仪模块。

## 程序概述
```1``` 引脚说明 jy61 rx引脚接A2 tx引脚接A3 usart1作为与电脑的连接串口。
```2``` 解算完成的欧拉三角位于函数 void SendAngleData(int16_t angle1, int16_t angle2, int16_t angle3)中 数据包为buffer。Send_CMD_Calibration();	//Z轴校准为z轴校准函数。