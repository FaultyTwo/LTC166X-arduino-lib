// LTC1660 Specification
#include "LTC166X.h"

LTC1660::LTC1660(int cs){
  _cs = cs;
  pinMode(_cs,OUTPUT);
  digitalWrite(_cs,HIGH);
}

void LTC1660::setDac(uint8_t ctrl, uint16_t code){
  // implement beginTransaction later
  
  uint8_t data[1];

  if(ctrl > 0x0F){ //one byte only
    ctrl = 0x00;
  }
  
  if(code > 1023){ //10-bit limit
    code = 1023;
  }
  
  data[0] = (ctrl << 4) | (code >> 6); // 
  data[1] = (code << 2);

  _spi->beginTransaction(setting);
  digitalWrite(_cs,LOW);
  _spi->transfer(data[0]);
  _spi->transfer(data[1]);
  digitalWrite(_cs,HIGH);
  _spi->endTransaction();
  
  // endTransaction here
}
