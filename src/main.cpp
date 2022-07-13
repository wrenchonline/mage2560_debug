#include "Arduino.h"
#include "avr8-stub.h"

void setup()
{
  // initialize GDB stub
  debug_init();
  Serial.begin(115200); // 打开串口，并设置波特率为 9600 bps
}

int incomingByte = 0; // 定义变量用于接收串口数据

void loop()
{

  // 检测缓冲区中是否有可读数据
  if (Serial.available() > 0)
  {
    breakpoint();
    // 有可读数据，读取1字节
    incomingByte = Serial.read();

    // 看看你收到的数据是什么
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }
}