 #include "PCA9554A.h"

const char PCA9554A_REG0 = 0x00;
const char PCA9554A_REG1 = 0x01;
const char PCA9554A_REG2 = 0x02;
const char PCA9554A_REG3 = 0x03;
const char PCA9554A_FIXED_ADDRESS=0x70;
const char PCA9554A_CONFIG = 0x01;
const char PCA9554A_INVERSE = 0x00;

 


void PCA9554A_Config_Or_Inverse(PCA9554A_DATA *ptr, char act, char x_reg){
  ptr->pbus->Start();
  ptr->pbus->Write( (char)(ptr->addr<<1)|PCA9554A_FIXED_ADDRESS);
  if(act == PCA9554A_CONFIG) ptr->pbus->Write(PCA9554A_REG3);
  else ptr->pbus->Write(PCA9554A_REG2);
  ptr->pbus->Write(x_reg);
  ptr->pbus->Stop();
}

void PCA9554A_Write(PCA9554A_DATA *ptr, char x_data){
  ptr->pbus->Start();
  ptr->pbus->Write((char)(ptr->addr<<1)|PCA9554A_FIXED_ADDRESS)  ;
  ptr->pbus->Write(PCA9554A_REG1);
  ptr->pbus->Write(x_data);
  ptr->pbus->Stop();
 }

 char PCA9554A_Read_Port(PCA9554A_DATA *ptr){
  char x_Rd;
  ptr->pbus->Start();
  ptr->pbus->Write((char)(ptr->addr<<1)|PCA9554A_FIXED_ADDRESS);
  ptr->pbus->Write(0x00);
  ptr->pbus->Repeated_Start();
  ptr->pbus->Write((char)(ptr->addr<<1)|PCA9554A_FIXED_ADDRESS|0x01);
  x_Rd= ptr->pbus->Read(0);
  ptr->pbus->Stop();
  return x_Rd;
}

char PCA9554A_Read_Reg(PCA9554A_DATA *ptr, char n_reg){
  char x_Rd;
  ptr->pbus->Start();
  ptr->pbus->Write((char)(ptr->addr<<1)|PCA9554A_FIXED_ADDRESS);
  ptr->pbus->Write(n_reg);
  ptr->pbus->Repeated_Start();
  ptr->pbus->Write((char)(ptr->addr<<1)|PCA9554A_FIXED_ADDRESS|0x01);
  x_Rd=ptr->pbus->Read(0);
  ptr->pbus->Stop();
  return x_Rd;
}