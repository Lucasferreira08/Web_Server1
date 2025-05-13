#include "buzzer.h"

#include "global_manage.h"
#include "hardware/pwm.h"       // API de PWM para controle de sinais sonoros
#include "hardware/clocks.h"    // API de clocks do RP2040

void ativar_pwm_buzzer()
{
    // while (get_buzzer()==BUZZER_ATIVADO) 
    // {
    //     pwm_set_gpio_level(BUZZER_PIN, 2048);
    //     sleep_ms(200);  
    //     pwm_set_gpio_level(BUZZER_PIN, 0);
    //     sleep_ms(200); 
    // }

    for (int i=0;i<8;i++) 
    {
        gpio_put(RED_PIN, 0);
        gpio_put(BLUE_PIN, 1);
        pwm_set_gpio_level(BUZZER_PIN, 2048);
        sleep_ms(200);  

        gpio_put(BLUE_PIN, 0);
        gpio_put(RED_PIN, 1);
        pwm_set_gpio_level(BUZZER_PIN, 0);
        sleep_ms(200); 
        gpio_put(RED_PIN, 0);
    }
}