#include <stdio.h> //biblioteca padrão da linguagem C
#include "pico/stdlib.h" //subconjunto central de bibliotecas do SDK Pico
#include "hardware/pwm.h" //biblioteca para controlar o hardware de PWM
#include "pico/time.h"  

#define PWM_PIN_22 12 //GPIO 22 que sera usado como pwm

const float PWM_DIVISOR = 125.0;  // Divisor do clock para atingir 50 Hz
const uint16_t WRAP_PERIOD = 20000;  // Período para 20ms (50 Hz)

const uint16_t DUTY_CYCLE_2400US = 2400; // Ciclo ativo para 180 graus
const uint16_t DUTY_CYCLE_1470US = 1470; // Ciclo ativo para 90 graus
const uint16_t DUTY_CYCLE_500US = 500;   // Ciclo ativo para 0 graus

//direcao do movimento e duty do movimento
int direcao = 1;
uint16_t DUTY_ROTINA = DUTY_CYCLE_500US;

//função para configurar o módulo PWM
void pwm_setup() {
    gpio_set_function(PWM_PIN_22, GPIO_FUNC_PWM);  // Configura GPIO 22 como PWM

    uint slice_num = pwm_gpio_to_slice_num(PWM_PIN_22);  // Obtém o slice do GPIO

    pwm_set_clkdiv(slice_num, PWM_DIVISOR);  // Define o divisor de clock
    pwm_set_wrap(slice_num, WRAP_PERIOD);  // Define o período (20 ms)

    pwm_set_gpio_level(PWM_PIN_22, DUTY_CYCLE_2400US);  // Define duty cycle inicial de 2400Us
    pwm_set_enabled(slice_num, true);  // Habilita o PWM
}

void rotina_movimento(){
    pwm_set_gpio_level(PWM_PIN_22, DUTY_ROTINA);
    sleep_ms(10);
    if (direcao == 1){        
        DUTY_ROTINA += 5;
        if (DUTY_ROTINA == DUTY_CYCLE_2400US){
            direcao = 0;
        }
    } 
    else {
        DUTY_ROTINA -= 5;
        if (DUTY_ROTINA == DUTY_CYCLE_500US){
            direcao = 1;
        }
    }    
}

//função principal
int main()
{
    stdio_init_all(); //inicializa o sistema padrão de I/O

    pwm_setup(); //configura o PWM

    printf("Posição: 180 graus (%d us)\n",DUTY_CYCLE_2400US);
    sleep_ms(5000);  // Mantém 5 segundos em 180 graus

    printf("Mudando para 90 graus (%d us)\n",DUTY_CYCLE_1470US);
    pwm_set_gpio_level(PWM_PIN_22, DUTY_CYCLE_1470US);
    sleep_ms(5000);

    printf("Mudando para 0 graus (%d us)\n",DUTY_CYCLE_500US);
    pwm_set_gpio_level(PWM_PIN_22, DUTY_CYCLE_500US);
    sleep_ms(5000);

    //loop principal
    while (true) {
        rotina_movimento();
        printf("Ciclo ativo:%d\n", DUTY_ROTINA);//imprimir ciclo ativo do PWM      

    }
}
