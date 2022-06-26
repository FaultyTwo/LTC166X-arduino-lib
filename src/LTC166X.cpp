#include "LTC166X.h"

void LTC166X::begin(SPIClass &spi){
  // from looking at the library source
  // it seems like object parsing method should work
  _spi = &spi;
  _spi->begin();
}

void LTC166X::beginTransactionConfig(uint32_t _clock, uint8_t _bitOrder, uint8_t _dataMode){
  setting = SPISettings(_clock,_bitOrder,_dataMode); // im not sure this will work or not
}
