// LTC1665 Specification
#include "LTC166X.h"

LTC1665::LTC1665(int cs){
  _cs = cs;
  pinMode(_cs,OUTPUT);
  digitalWrite(_cs,HIGH);
}

void LTC1665::setDac(uint8_t ctrl, uint8_t dac_value){
  // implement beginTransaction later
  
  uint8_t data[1];

  if(ctrl > 0x0F){ //one byte only
    ctrl = 0x00;
  }
  
  if(dac_value > 255){ //8-bit limit
    dac_value = 255;
  }
  
  data[0] = (ctrl << 4) | (dac_value >> 4);
  data[1] = (dac_value << 4);

  _spi->beginTransaction(setting);
  digitalWrite(_cs,LOW);
  _spi->transfer(data[0]);
  _spi->transfer(data[1]);
  digitalWrite(_cs,HIGH);
  _spi->endTransaction();
  
  // endTransaction here
}
