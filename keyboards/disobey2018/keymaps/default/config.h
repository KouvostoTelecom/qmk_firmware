#pragma once


#ifdef OLED_DRIVER_ENABLE
  #define SSD1306OLED
  #define OLED_DISPLAY_128X64
#endif

#define I2C_DRIVER I2CD1
#define I2C1_SCL_BANK GPIOB
#define I2C1_SDA_BANK GPIOB
#define I2C1_SCL 8
#define I2C1_SDA 9
#define I2C1_SCL_PAL_MODE 1
#define I2C1_SDA_PAL_MODE 1
#define ENCODERS_PAD_A { B4 }
#define ENCODERS_PAD_B { A2 }
#define ENCODER_RESOLUTION 4
