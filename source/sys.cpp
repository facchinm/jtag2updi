/*
   sys.cpp

   Created: 02-10-2018 13:07:52
    Author: JMR_2
*/

#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "sys.h"

void SYS::setLED(void) {
  digitalWrite(LED_BUILTIN, HIGH);
}

void SYS::clearLED(void) {
  digitalWrite(LED_BUILTIN, LOW);
}
