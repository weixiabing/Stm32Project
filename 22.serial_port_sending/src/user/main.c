#include <stm32f10x.h>
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
int main()
{
    OLED_Init();
    Serial_Init();
    // Serial_SendByte(0x41);
    // Serial_SendString("HelloWorld");
    //Serial_SendNumber(12345,5);
    printf("Hello%d\n",666);
    Serial_Printf("你好世界Num=%d\n",666);
     while (1) {}
}
