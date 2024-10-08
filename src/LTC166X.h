/* 
   LTC166X - Arduino library for LTC1660 and LTC1665, Octal 8-bit and 10-bit DACs.
   By: Chawin 'FaultyTwo' Treesugol
*/

#ifndef ft_LTC166X
#define ft_LTC166X

#include "Arduino.h"
#include "SPI.h"

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
      /// @brief Initial a LTC166X device
      /// @param spi the "CS" pin to use
      void begin(SPIClass &spi = SPI);
      /// @brief Configure a SPI transaction of a LTC166X device
      /// @param _clock Maximum speed of transaction
      /// @param _bitOrder MSBFIRST or LSBFIRST
      /// @param _dataMode SPI_MODE0, SPI_MODE1, SPI_MODE2, or SPI_MODE3
      /// @note https://www.arduino.cc/reference/en/language/functions/communication/spi/spisettings/
      void beginTransactionConfig(uint32_t _clock, uint8_t _bitOrder, uint8_t _dataMode);
      /// @brief Configure a SPI transaction of a LTC166X device
      /// @param _setting An instance of "SPISettings" class
      void beginTransactionConfig(SPISettings _setting);
   protected:
      int _cs;
      SPIClass *_spi;
      SPISettings setting = SPISettings(); //use default parameter provided by each hardwares
};

/// @brief A LTC1660 class
class LTC1660 : public LTC166X{
  public:
      /// @brief Initial a LTC1660
      /// @param cs the "CS" pin to use
      LTC1660(int cs);
      ///@brief Set a DAC output
      ///@param ctrl The address/control code
      ///@param code The value of DAC output
      void setDac(uint8_t ctrl, uint16_t dac_value = 0x00); 
};

/// @brief A LTC1665 class
class LTC1665 : public LTC166X{
  public:
      /// @brief Initial a LTC1660
      /// @param cs Specify the "CS" pin
      LTC1665(int cs);
      ///@brief Set a DAC output
      ///@param ctrl The address/control code
      ///@param code The value of DAC output
      void setDac(uint8_t ctrl, uint8_t dac_value = 0x00); 
};

#endif
