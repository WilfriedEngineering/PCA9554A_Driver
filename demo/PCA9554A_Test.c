#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "BUS_I2C.h"
#include "PCA9554A.h"

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 20000000 

BUS_I2C mbus={BUS_I2C_Init,BUS_I2C_Start,BUS_I2C_Repeated_Start,BUS_I2C_Write,BUS_I2C_Read, BUS_I2C_Stop}; // Defining of functions operating on the I2C bus
PCA9554A_DATA d1={&mbus,0x07};
PCA9554A_FUNCTION mypca={PCA9554A_Write, PCA9554A_Config_Or_Inverse, PCA9554A_Read_Port, PCA9554A_Read_Reg};


int main(int argc, char** argv) {

    mbus.Init(20000000,100000); // initialize the clock frequency of the bus of 100KHz
    mypca.Config_Or_Inverse(&d1,PCA9554A_CONFIG, 0x0f);
    mypca.Write(&d1,0x00);
    
    while(1){
        mypca.Write(&d1, (char)( mypca.Read_Port(&d1) <<4) );
        __delay_ms(1000);
    }
    
    
    return (EXIT_SUCCESS);
}

