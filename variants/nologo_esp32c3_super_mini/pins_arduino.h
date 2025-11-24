#pragma once
#include <stdint.h>

// Variant for Nologo ESP32C3 SuperMini (generic ESP32-C3 mapping)
// Minimal set of definitions required by Arduino core.

#define EXTERNAL_NUM_INTERRUPTS 22
#define NUM_DIGITAL_PINS        22
#define NUM_ANALOG_INPUTS       6

// Digital pins
static const uint8_t D0  = 0;
static const uint8_t D1  = 1;
static const uint8_t D2  = 2;
static const uint8_t D3  = 3;
static const uint8_t D4  = 4;
static const uint8_t D5  = 5;
static const uint8_t D6  = 6;
static const uint8_t D7  = 7;
static const uint8_t D8  = 8;
static const uint8_t D9  = 9;
static const uint8_t D10 = 10;
static const uint8_t D11 = 11;
static const uint8_t D12 = 12;
static const uint8_t D13 = 13;
static const uint8_t D14 = 14;
static const uint8_t D15 = 15;
static const uint8_t D16 = 16;
static const uint8_t D17 = 17;
static const uint8_t D18 = 18;
static const uint8_t D19 = 19;
static const uint8_t D20 = 20;
static const uint8_t D21 = 21;

// Analog inputs (ADC1 on ESP32-C3 supports GPIO0-5)
static const uint8_t A0 = 0;
static const uint8_t A1 = 1;
static const uint8_t A2 = 2;
static const uint8_t A3 = 3;
static const uint8_t A4 = 4;
static const uint8_t A5 = 5;
#define ADC_RESOLUTION 12

// Built-in LED (many ESP32C3 SuperMini boards have LED on GPIO8; adjust if different)
#define LED_BUILTIN 8

// SPI defaults (adjust if board uses different wiring)
#define SS    7
#define MOSI  6
#define MISO  2
#define SCK   5

// I2C defaults (common for ESP32-C3)
#define SDA 8
#define SCL 9

// UART defaults (GPIO20=RXD0, GPIO21=TXD0 on ESP32-C3)
#define RX 20
#define TX 21

// Convenience aliases matching typical Arduino naming
static const uint8_t SDA_PIN = SDA;
static const uint8_t SCL_PIN = SCL;
static const uint8_t SS_PIN  = SS;
static const uint8_t MOSI_PIN = MOSI;
static const uint8_t MISO_PIN = MISO;
static const uint8_t SCK_PIN  = SCK;

// Map used by analogRead internally (identity for simplicity)
static const uint8_t analogChannelToDigitalPinMap[NUM_ANALOG_INPUTS] = {0,1,2,3,4,5};
