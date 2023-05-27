#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 144 
#define TURNING_LEDS 20

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 6
#define TURN_R_PIN 3
#define TURN_L_PIN 4

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
	FastLED.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
	FastLED.setBrightness(84);

  pinMode(TURN_R_PIN, INPUT_PULLUP); 
  pinMode(TURN_L_PIN, INPUT_PULLUP); 
}

void loop() {
  //EVERY_N_MILLISECONDS(100){
    /*for(int i(0); i<NUM_LEDS;i++){
      leds[i] = CRGB::HotPink;
      FastLED.show(); 
    }
 // }

  for(int i(0); i<NUM_LEDS;i++){
    leds[i] = CRGB::Black;
    FastLED.show(); 
    delay(10);
  }*/

  if(digitalRead(TURN_R_PIN)==LOW){
    for(int i(0); i<TURNING_LEDS ;i++){
      leds[i] = CRGB::HotPink;
      FastLED.show(); 
    }
    for(int i(0); i<TURNING_LEDS;i++){
      leds[i] = CRGB::Black;
      FastLED.show(); 
      delay(10);
    }
  }

  if(digitalRead(TURN_L_PIN)==LOW){
    for(int i(NUM_LEDS-TURNING_LEDS); i<NUM_LEDS ;i++){
      leds[i] = CRGB::HotPink;
      FastLED.show(); 
    }
    for(int i(NUM_LEDS-TURNING_LEDS); i<NUM_LEDS ;i++){
      leds[i] = CRGB::Black;
      FastLED.show(); 
      delay(10);
    }
  }

}
