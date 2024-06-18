#include <stm32f10x.h>
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
uint16_t Num;
int main()
{
    OLED_Init();
    Timer_Init();

    while (1) {
        OLED_ShowNum(1, 1, Num, 5);
        OLED_ShowNum(2, 1, Timer_GetCounter(), 5);
    }
}
void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET) {
        Num++;
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}