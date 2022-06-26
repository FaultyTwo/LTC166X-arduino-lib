#ifndef ft_LTC166X
#define ft_LTC166X

#include "Arduino.h"
#include "SPI.h"

// SPIClass for real class, don't use extern 'SPI'

// literals damage
#define DAC_WAKE 0x00
#define DAC_A 0x01
#define DAC_B 0x02
#define DAC_C 0x03
#define DAC_D 0x04
#define DAC_E 0x05
#define DAC_F 0x06
#define DAC_G 0x07
#define DAC_H 0x08
#define DAC_SLP 0x0E
#define DAC_ALL 0x0F

class LTC166X{
   public:
      void begin(SPIClass &spi = SPI);
      // add beginTransactions method here later
      // 1660 use 12-bit data
      // 1665 use 8-bit data
      // class seperation? yes.
      void beginTransactionConfig(uint32_t _clock, uint8_t _bitOrder, uint8_t _dataMode);
   protected:
      int _cs;
      SPIClass *_spi;
      SPISettings setting = SPISettings(); //use default parameter provided by each hardwares
};

class LTC1660 : public LTC166X{
  public:
      LTC1660(int cs);
      void setDac(uint8_t ctrl, uint16_t code = 0x00); 
};

class LTC1665 : public LTC166X{
  public:
      LTC1665(int cs);
      void setDac(uint8_t ctrl, uint8_t code = 0x00); 
};

#endif
