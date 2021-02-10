#include <xc.h>
#include "interrupciones.h"
#include <stdint.h>

uint8_t x = 0;


//int8_t x=0;
//int-> 8 bits y unsigned 
//int-> 16 bits
//int-> 32 bits

void Int_Init(void){
    TRISBbits.RB0 = 1;//lo señalamos como entrada
    TRISBbits.RB1 = 1;
    INTCONbits.INT0IE = 1;//habilitando Int0
    INTCON3bits.INT1E = 1;//habilitando Int1
    INTCONbits.INT0IF = 0;//limpiar flag INT0
    INTCON3bits.INT1F = 0;//habilitando Int1
    INTCON2bits.INTEDG0 = 0;//DESCENDENTE 
    INTCON2bits.INTEDG1 = 0;//DESCENDENTE 
    RCONbits.IPEN= 1;
    INTCON3bits.INT1P = 0;//PRIORIDAD BAJA 
    INTCONbits.PEIE = 1;//Int perifericos 
    INTCONbits.GIE = 1;//Int Globales 
    
    
}  
//FUNCION (vector de interrupcion)
void  __interrupt(high_priority) INT0_ISR(void){
     x=1;
     //LATDbits.LATD0 = ~LATDbits.LATD0;
     
    INTCONbits.INT0IF = 0;//limpiar flag INT0
             
}
//FUNCION (vector de interrupcion)
void  __interrupt(low_priority) INT1_ISR(void){
    x=2;
     //LATDbits.LATD1 = ~LATDbits.LATD1;
     
     INTCON3bits.INT1F = 0;//limpiar flag INT0
             
}