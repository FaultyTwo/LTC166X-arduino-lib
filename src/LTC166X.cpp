#include "LTC166X.h"

void LTC166X::begin(SPIClass &spi){
  _spi = &spi;
  _spi->begin();
}

void LTC166X::beginTransactionConfig(uint32_t _clock, uint8_t _bitOrder, uint8_t _dataMode){
  setting = SPISettings(_clock,_bitOrder,_dataMode);
}

void LTC166X::beginTransactionConfig(SPISettings _setting){
  setting = _setting;
}