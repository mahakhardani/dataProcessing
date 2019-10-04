#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "em_device.h"
#include "em_chip.h"
#include "segmentlcd.h"
#include "em_lcd.h"
#include "em_i2c.h"
#include "em_cmu.h"
#include "em_emu.h"

uint8_t i2c_txBuffer[] = {0x10,0x78};
uint8_t i2c_rxBuffer[]={0,0};


void performI2CTransfer(void)
{
I2C_TransferSeq_TypeDef i2cTransfer;
i2cTransfer.addr          = 0xD6;
i2cTransfer.flags         = I2C_FLAG_WRITE_WRITE;
 i2cTransfer.buf[0].data   = i2c_txBuffer;
 i2cTransfer.buf[0].len    = 2;
 i2cTransfer.buf[1].data   = i2c_rxBuffer;
 i2cTransfer.buf[1].len    = 2;

 I2C_TransferInit(I2C1, &i2cTransfer);
 while (I2C_Transfer(I2C1) == i2cTransferInProgress){;}
}



void performI2CRead(void){
I2C_TransferSeq_TypeDef i2cTransfer;
i2cTransfer.addr          = 0xD6;
i2cTransfer.flags         = I2C_FLAG_WRITE_READ;
i2cTransfer.buf[0].data   = i2c_txBuffer;
i2cTransfer.buf[0].len    = 1;
i2cTransfer.buf[1].data   = i2c_rxBuffer;
i2cTransfer.buf[1].len    = 1;

I2C_TransferInit(I2C1, &i2cTransfer);
while (I2C_Transfer(I2C1) == i2cTransferInProgress){;}
}

void Delayms(unsigned long time)
{
unsigned long i;
while (time>0)
{
i=133333;
while (i>0)
{i--;}
time--;
}
}

int main(void)
{

CHIP_Init();
CMU_ClockEnable(cmuClock_GPIO,true);
CMU_ClockEnable(cmuClock_LCD,true);
SegmentLCD_Init(true);
CMU_ClockEnable(cmuClock_I2C1,true);
I2C_Init_TypeDef I2C1init = I2C_INIT_DEFAULT;
GPIO_PinModeSet(gpioPortC, 5, gpioModeWiredAndPullUpFilter, 1);
GPIO_PinModeSet(gpioPortC, 4, gpioModeWiredAndPullUpFilter, 1);
I2C1->ROUTE = I2C_ROUTE_SDAPEN | I2C_ROUTE_SCLPEN | I2C_ROUTE_LOCATION_LOC0;


I2C_Init(I2C1, &I2C1init);

//Delayms(12);

i2c_txBuffer[0]=0x20;
i2c_txBuffer[1]=0x00;

performI2CTransfer();

Delayms(6);

i2c_txBuffer[0]=0x10;
i2c_txBuffer[1]=0x78;

performI2CTransfer();

char str[5]="";
int i=0;
int sum=8;
int temp;
SegmentLCD_Write("Ready");
Delayms(30);

while (1)
{

	i2c_txBuffer[0]=0x19;
	performI2CRead();
	sum =i2c_rxBuffer[0];

  	/** if(i<100)
  	  {
  		sum+= i2c_rxBuffer[0];
  		i++;
  	  }
  	  else
  	  {
  		i=0;
  		sum=(int)(sum/100);
  		//sum= i2c_rxBuffer[0];
  		//temp=sum+25;



		//sum =i2c_rxBuffer[0];
  		//itoa(sum,str,16);



  		sum=0;

  	  }**/
  	itoa(sum,str,16);
  	SegmentLCD_Write(str);
	}

}