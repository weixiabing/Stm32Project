#include <stm32f10x.h>
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "Key.h"
uint8_t KeyNum;
float Speed;
int main()
{
    OLED_Init();
   Motor_Init();
    Key_Init();
    OLED_ShowString(1, 1, "Speed:");
    while (1) {
        KeyNum = Key_GetNum();
        if (KeyNum == 2 ) {
         Speed += 30;

            if ( Speed > 180) {
             Speed = 0;
            }

            Motor_SetSpeed (Speed);
            OLED_ShowNum(1, 7, Speed, 3);
        }
    }
}
