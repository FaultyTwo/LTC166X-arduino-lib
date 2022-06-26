# LTC166X
An Arduino library for LTC1660 and LTC1665, Octal 8-bit and 10-bit DACs.

## Overview
LTC166X is an Arduino library for controlling LTC1660 (Octal 8-bit DACs) and LTC1665 (Octal 10-bit DACs).

Both ICs contain 8 DACs (A to H) which can be interfaced with SPI protocol.

## DAC Outputs Calculation
DAC outputs can be calculated through the following transfer function:<br>
- LTC1660 : Vout = (k/256) \* Vref
	- 'k' value should be in range of 0 to 255 (8-bit range).
- LTC1665 : Vout = (k/1024) \* Vref
	- 'k' value should be in range of 0 to 1023 (10-bit range).

## How To Use The Library
Include the library, then simply create an object accordingly to each devices number:
```C
#include "LTC166X.h"

LTC1665 ten(6);
LTC1660 eight(7);

```
Constructor's parameter should be a digital pin number you use for **"CS (Chip Select)"** pin.<br>

To use this library with other SPI ports, you can simply create a "SPIClass" object then parse them into the 'begin' method:
```C
//ESP32 DEVKIT V1 DEVELOPMENT BOARD SPI PINS
#define MOSI 13
#define SCK 14
#define SS 4

SPIClass esp = SPIClass(HSPI); //HSPI or VSPI
LTC1665 ten(SS);

void setup(){
	//either leave SS as -1 or use SS pin number. 
	//it won't affect the library.
	esp.begin(SCK,-1,MOSI,SS); 
	ten.begin(&esp)
}
```
**^Note that each boards use different SPI pinout. Make sure to check that before coding.**<br>

# Methods
```C
void begin(SPIClass &spi = SPI);
```
Initiate the LTC166X library.

Can be configured to use other SPI ports using 'SPIClass' object.<br>
For default SPI port, just leave the parameter blank.

```C
void beginTransactionConfig(uint32_t _clock, uint8_t _bitOrder, uint8_t _dataMode);
```
Configure the SPI transaction options.

For more info. Check 'SPISettings' in Arduino website.

```C
void setDac(uint8_t ctrl, uint16_t code = 0x00);
```
Set a DAC output where 'ctrl' is address/control and 'code' is the DAC output.

'address/control' Table:
| 'ctrl' 		 | Literals | DAC Status 				  |  Sleep Status  |
|----------------|----------|-----------------------------|----------------|
|  0x00  		 | DAC_WAKE | No Change  				  | WAKE           |
|  0x01  		 | DAC_A    | Load DAC A 				  | WAKE		   |
|  0x02  		 | DAC_B    | Load DAC B 				  | WAKE		   |
|  0x03  		 | DAC_C    | Load DAC C 				  | WAKE		   |
|  0x04  		 | DAC_D    | Load DAC D 				  | WAKE		   |
|  0x05  		 | DAC_E    | Load DAC E 				  | WAKE		   |
|  0x06  		 | DAC_F    | Load DAC F 				  | WAKE		   |
|  0x07  	 	 | DAC_G    | Load DAC G 				  | WAKE		   |
|  0x08  		 | DAC_H    | Load DAC H 				  | WAKE		   |
|  0x09 to 0x0D  |    -     | No Change					  | WAKE		   |
|  0x0E    	     | DAC_SLP  | No Change                   | SLEEP		   |
|  0x0F          | DAC_ALL  | Load All DACs with same code| WAKE 		   |

**^For LTC1660: 'code' parameter shouldn't exceed 255, otherwise will be set back to 255.**<br>
**^For LTC1665: 'code' parameter shouldn't exceed 1023, otherwise will be set back to 1023.**



