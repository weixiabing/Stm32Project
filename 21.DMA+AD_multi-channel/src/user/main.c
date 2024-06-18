#include <stm32f10x.h>
#include "Delay.h"
#include "OLED.h"
#include "AD.h"

float Voltage0, Voltage1, Voltage2, Voltage3;
int main()
{
    OLED_Init();
    AD_Init();
    OLED_ShowString(1, 1, "V0:0.00V");
    OLED_ShowString(2, 1, "V1:0.00V");
    OLED_ShowString(3, 1, "V2:0.00V");
    OLED_ShowString(4, 1, "V3:0.00V");
    while (1) {
     
        OLED_ShowNum(1, 10, AD_Value[0], 5);
        OLED_ShowNum(2, 10, AD_Value[1], 5);
        OLED_ShowNum(3, 10, AD_Value[2], 5);
        OLED_ShowNum(4, 10, AD_Value[3], 5);
        Voltage0 = (float)AD_Value[0] / 4095 * 3.3;
        Voltage1 = (float)AD_Value[1] / 4095 * 3.3;
        Voltage2 = (float)AD_Value[2]/ 4095 * 3.3;
        Voltage3 = (float)AD_Value[3]/ 4095 * 3.3;
        OLED_ShowNum(1, 4, Voltage0, 1);
        OLED_ShowNum(2, 4, Voltage1, 1);
        OLED_ShowNum(3, 4, Voltage2, 1);
        OLED_ShowNum(4, 4, Voltage3, 1);
        OLED_ShowNum(1, 6, (uint16_t)(Voltage0 * 100) % 100, 2);
        OLED_ShowNum(2, 6, (uint16_t)(Voltage1 * 100) % 100, 2);
        OLED_ShowNum(3, 6, (uint16_t)(Voltage2 * 100) % 100, 2);
        OLED_ShowNum(4, 6, (uint16_t)(Voltage3 * 100) % 100, 2);
        Delay_ms(100);
    }
}
