/* LTC166X-test
 * Author: Chawin 'FaultyTwo' Treesugol
 * Date: 10/08/2024
 * FROM: https://github.com/FaultyTwo/LTC166X-arduino-lib
 * 
 * Desc: This is a sketch for testing DAC outputs in LTC1660 or LTC1665.
 * 
 * Enjoy!
 */
 
#include "LTC166X.h"

#define DAC_LIMIT 1023

LTC1660 dac(9);

void setup() {
  // put your setup code here, to run once:
  dac.begin();
  delay(100);
  for(unsigned int i = 1; i < 9; i++){
    for(unsigned int j = 0; j < DAC_LIMIT; j++){
      delayMicroseconds(300);
      dac.setDac(i,j);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
