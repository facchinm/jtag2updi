/*
   updi_io.cpp

   Created: 18-11-2017 10:36:54
    Author: JMR_2
*/

// Includes
#include <Arduino.h>
#include <avr/io.h>
#include "updi_io.h"
#include "sys.h"

// Functions
/* Sends regular characters through the UPDI link */
uint8_t UPDI_io::put(char c) {
  Serial1.write(c);
  Serial1.flush();
  Serial1.read();
  //delayMicroseconds(10);
  return c;
}

/* Sends special sequences through the UPDI link */
uint8_t UPDI_io::put(ctrl c)
{
  Serial1.end();
  Serial1.begin(350, SERIAL_8N1);
  switch (c) {
    case double_break:
      Serial1.write((uint8_t)0x00);
      Serial1.flush();
      Serial1.write((uint8_t)0x00);
      Serial1.flush();
      //Serial1.read();
      //Serial1.read();
      break;
    case single_break:
      Serial1.write((uint8_t)0x00);
      Serial1.flush();
      //Serial1.read();
      break;
    default:
      break;
  }
  while (Serial1.available()) {
    Serial1.read();
  }
  Serial1.end();
  Serial1.begin(115200, SERIAL_8E2);
  return 0;
}

uint8_t UPDI_io::get() {
  uint8_t c;
  Serial1.flush();
  //Serial1.end();

  for (volatile int i = 0; i < 5; i++) {
    asm("");
  }

  //Serial1.begin(230400, SERIAL_8E2);
  while (!Serial1.available()) {
  }
  c = Serial1.read();

  return c;
}

void UPDI_io::init(void)
{
  Serial1.begin(115200, SERIAL_8E2);
}
