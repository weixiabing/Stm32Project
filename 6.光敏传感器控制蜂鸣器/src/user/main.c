#include <stm32f10x.h>
#include "Delay.h"
#include "Buzzer.h"
#include "LightSensor.h"

uint8_t KeyNum;
int main()
{
    Buzzer_Init();
    LightSensor_Init();
    while (1) {
        if (LightSensor_Read() == 1) {
            Buzzer_ON();
        } else {
            Buzzer_OFF();
        }
    }
}
