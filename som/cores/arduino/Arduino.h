/*
  Copyright (c) 2016 hathatehack  All right reserved.
  Copyright (c) 2012 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef Arduino_h
#define Arduino_h

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// some libraries and sketches depend on this
// AVR stuff, assuming Arduino.h or WProgram.h
// automatically includes it...
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

#include "binary.h"

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

// Includes ST CMSIS
#include <chip.h>

#include "wiring_constants.h"

#define cli() __asm__ __volatile__("CPSID I")
#define sei() __asm__ __volatile__("CPSIE I")

#define clockCyclesPerMicrosecond() ( SystemCoreClock / 1000000L )
#define clockCyclesToMicroseconds(a) ( ((a) * 1000L) / (SystemCoreClock / 1000L) )
#define microsecondsToClockCycles(a) ( (a) * (SystemCoreClock / 1000000L) )

#define SetLedRunDefault() do{ledruntime = 2000;}while(0)
#define SetLedRuntime(t) do{ledruntime = (uint16_t)(t);}while(0)
extern volatile uint32_t ledruntime;

void yield(void);

/* sketch */
extern void setup( void ) ;
extern void loop( void ) ;
extern void TimeTick_Increment( void ) ;
//void SysTick_Handler(void);

//// Get the bit location within the hardware port of the given virtual pin.
//// This comes from the pins_*.c file for the active board configuration.
#define digitalPinToPort(P)        (PinInfo[ulPin].ulPort)
#define digitalPinToBitMask(P)     (PinInfo[ulPin].ulPin)
#define digitalPinToTimer(P)       (PinInfo[ulPin].ulTimerPeripheral)
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   (&(port->ODR))
#define portInputRegister(port)    (&(port->IDR))  /* (&(port)->IDR) *//////////////////////////////////////////////
#define analogInputToDigitalPin(p) A(p)


//#define NOT_A_PIN 0  // defined in pio.h/EPioType
#define NOT_A_PORT           0

typedef void (*voidFuncPtr)( void ) ;

/* Define attribute */
#if defined   ( __CC_ARM   ) /* Keil uVision 4 */
    #define WEAK (__attribute__ ((weak)))
#elif defined ( __ICCARM__ ) /* IAR Ewarm 5.41+ */
    #define WEAK __weak
#elif defined (  __GNUC__  ) /* GCC CS */
    #define WEAK __attribute__ ((weak))
#endif

/* Definitions and types for pins */
/*
typedef enum _EAnalogChannel
{
  NO_ADC=-1,
  ADC0=0,
  ADC1,
  ADC2,
  ADC3,
  ADC4,
  ADC5,
  ADC6,
  ADC7,
  ADC8,
  ADC9,
  ADC10,
  ADC11,
  ADC12,
  ADC13,
  ADC14,
  ADC15,
  DA0,
  DA1
} EAnalogChannel ;
*/

#define ADC_CHANNEL_NUMBER_NONE 0xffffffff

// Definitions for PWM channels
typedef enum _EPWMChannel
{
  NOT_ON_PWM=-1,
  PWM_CH0=0,
  PWM_CH1,
  PWM_CH2,
  PWM_CH3,
  PWM_CH4,
  PWM_CH5,
  PWM_CH6,
  PWM_CH7
} EPWMChannel ;

// Definitions for TC channels
typedef enum _ETCChannel
{
  NOT_ON_TIMER=-1,
  TC0_CHA0=0,
  TC0_CHB0,
  TC0_CHA1,
  TC0_CHB1,
  TC0_CHA2,
  TC0_CHB2,
  TC1_CHA3,
  TC1_CHB3,
  TC1_CHA4,
  TC1_CHB4,
  TC1_CHA5,
  TC1_CHB5,
  TC2_CHA6,
  TC2_CHB6,
  TC2_CHA7,
  TC2_CHB7,
  TC2_CHA8,
  TC2_CHB8
} ETCChannel ;

/**
 * Pin Attributes to be OR-ed
 */
#define PIN_ATTR_COMBO         (1UL<<0)
#define PIN_ATTR_ANALOG        (1UL<<1)
#define PIN_ATTR_DIGITAL       (1UL<<2)
#define PIN_ATTR_PWM           (1UL<<3)
#define PIN_ATTR_TIMER         (1UL<<4)

///* Types used for the tables below */
//typedef struct _PinDescription
//{
//  GPIO_TypeDef* pPort ;
//  uint32_t ulPin ;
//  uint32_t ulPeripheral ;
//  /*
//  EPioType ulPinType ;
//  uint32_t ulPinConfiguration ;
//  uint32_t ulPinAttribute ;
//  */
//  /*
//  EAnalogChannel ulAnalogChannel ; *//* Analog pin in the Arduino context (label on the board) */
//  uint8_t ulADCChannelNumber ; /* ADC Channel number in the SAM device */
//  TIM_TypeDef* ulTimerPeripheral;
//  uint16_t ulTimerChannel;
//  /*
//  EPWMChannel ulPWMChannel ;
//  ETCChannel ulTCChannel ;
//  */
//} PinDescription ;
typedef struct _PinInfo
{
  GPIO_TypeDef *ulPort;
  uint16_t      ulPin;
  uint32_t      ulPeripheral;
  uint8_t       ulADCChannelNum;
  TIM_TypeDef  *ulTimerPeripheral;
  uint16_t      ulTimerChannelNum;
}PinInfo;
//
///* Pins table to be instanciated into variant.cpp */
extern const PinInfo pInfo[];

#ifdef __cplusplus
} // extern "C"

#include "WCharacter.h"
#include "WString.h"
#include "Tone.h"
#include "WMath.h"
#include "HardwareSerial.h"
//#include "wiring_pulse.h"
//#include "HardwareTimer.h"

#endif // __cplusplus

// Include board variant
#include "variant.h"

#include "wiring.h"
#include "wiring_digital.h"
#include "wiring_analog.h"
#include "wiring_shift.h"
//#include "WInterrupts.h"



//// USB Device
//#define USB_VID            0x2341 // arduino LLC vid
//#define USB_PID_LEONARDO   0x0034
//#define USB_PID_MICRO      0x0035
//#define USB_PID_DUE        0x003E
//#include "USB/USBDesc.h"
//#include "USB/USBCore.h"
//#include "USB/USBAPI.h"

#endif // Arduino_h
