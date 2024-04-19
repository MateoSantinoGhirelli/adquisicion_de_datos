// Inclusion de bibliotecas
#include <stdio.h>
#include <math.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

/*
 * @brief Programa principal
 */ 
int main() {
    // Variable para almacenar el resultado del ADC
    uint16_t adc_value = 0;
    // Variable para guardar el valor de temperatura
    float temperatura = 0.0;
    // Constante de proporcionalidad del termistor
    const uint16_t beta = 4000;
    // Habilito USB
    stdio_init_all();
    // Inicializo ADC
    adc_init();
    // Inicializo GPIO26 como entrada analogicaS
    adc_gpio_init(26);
    // Selecciono canal analogico
    adc_select_input(0);
    while(true) {
        // Leer NTC
        // Calculo temperatura
    
        
        int i = 0;
        temperatura = 0;
        for (i=0; i<10; i++) {
            adc_value= adc_read();
            float vx = (adc_value*3.3)/4095;
            float rt = 3300.0/((3.3/vx)-1);
            float temp = (((beta*298.15)) / ((298*log(rt/2200)) + beta)) - 273;
           temperatura += temp;
        }
        temperatura = temperatura / 10;
        //printf("Valor el adc es %d \n",adc_value);
        //printf("El valor de la tension es %.2f\n",vx);
        //printf("El valor de resistencia es %.2f\n",rt);
        printf("La temperatura es %.2f\n\n",temperatura);
        // Espero 500 ms
        sleep_ms(500);   
    }
    return 0;
}