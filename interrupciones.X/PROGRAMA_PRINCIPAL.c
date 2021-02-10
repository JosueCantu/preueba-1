/*
 * File:   PROGRAMA_PRINCIPAL.c
 * Author: josue
 *
 * Created on 4 de febrero de 2021, 12:36 PM
 */


#include <xc.h>
#include "CONFIGURACION.h"
#include "interrupciones.h"
#include <stdint.h>

extern uint8_t x;

void main (void) {
    Int_Init();
   
    TRISD = 0x00;//configurarlo salida 
    LATD = 0x00;
   
    /*este while dice que si esto es verdadero manten el programa aqui para no reinicio 
     * o no vuelva a configuracion y se mantenga en la parte del programa*/ 
    
    while(1){
        
        if (x==1){
            LATD = 0xAA;
        }
        if (x==2){
            LATD = 0x55;
            
        }
            
    }
    return;
}
