#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
#include "Encoder.h"
uint16_t Speed;
int main()
{
    OLED_Init();
  Timer_Init();
    Encoder_Init();
    while (1) {
        OLED_ShowSignedNum(1,1,Speed,5);
        
    }
}
void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET) {
        Speed=Encoder_Get();
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}
