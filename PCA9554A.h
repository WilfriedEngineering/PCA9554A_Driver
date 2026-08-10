
#ifndef PCA9554A_H
#define PCA9554A_H

 #include "BUS_I2C.h"
 

  typedef struct PCA9554A_DATA{
      BUS_I2C *pbus; 
      char addr;
  }PCA9554A_DATA;
  typedef struct PCA9554A_FUNCTION {
       void (*Write) ( PCA9554A_DATA *, char);
       void (*Config_Or_Inverse) ( PCA9554A_DATA *, char, char);
       char (*Read_Port) ( PCA9554A_DATA *);
       char (*Read_Reg) (PCA9554A_DATA *, char);
   }PCA9554A_FUNCTION;
   
   typedef struct PCA9554A{
        PCA9554A_DATA *pcad;
        PCA9554A_FUNCTION *pcaf;
     }PCA9554A;
   
    void PCA9554A_Write( PCA9554A_DATA *, char );
    void PCA9554A_Config_Or_Inverse( PCA9554A_DATA *, char, char );
    char PCA9554A_Read_Port( PCA9554A_DATA *);
    char PCA9554A_Read_Reg( PCA9554A_DATA *, char);

   extern const char PCA9554A_REG0;
   extern const char PCA9554A_REG1;
   extern const char PCA9554A_REG2;
   extern const char PCA9554A_REG3;
   extern const char PCA9554A_FIXED_ADDRESS;
   extern const char PCA9554A_CONFIG;
   extern const char PCA9554A_INVERSE;
   


#endif