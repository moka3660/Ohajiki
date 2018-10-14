#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 2

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 0
//#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
       FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
  // Turn the LED on, then pause
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(500);
  // Turn the LED on, then pause
  leds[1] = CRGB::Blue;
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[1] = CRGB::Black;
  FastLED.show();
  delay(500);
}
