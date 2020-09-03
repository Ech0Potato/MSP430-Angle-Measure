
#ifndef ADXL345_H_
#define ADXL345_H_

#define SlaveAddress 0xA6

void Single_Write_ADXL345(unsigned char REG_Address,unsigned char REG_data);
unsigned char Single_Read_ADXL345(unsigned char REG_Address);
void Multiple_read_ADXL345(int *x,int *y,int*z);
void Init_ADXL345();

void B_Single_Write_ADXL345(unsigned char REG_Address,unsigned char REG_data);
unsigned char B_Single_Read_ADXL345(unsigned char REG_Address);
void B_Multiple_read_ADXL345(int *x,int *y,int*z);


#endif /* ADXL345_H_ */
