#include <avr/pgmspace.h>
#include "anim.h"

#include <FastLED.h>
#define NUM_LEDS 19
#define PIN 1

CRGB leds[NUM_LEDS];

// cTrix said I should make circles, I say he should play Horses
// C's out for cTrix

void setup() {
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
}

void loop(){
  //uint8_t rando = random(10);
  //if(rando < 4){
    animate();
  //}
  //delay(500);
}

void animate() {
  uint8_t i, j, r, g, b;
  for (i = 0; i < len; i++) {
    for (j = 0; j < 19; j++) {
      r = pgm_read_word_near(&(anim[i][j][0]));
      g = pgm_read_word_near(&(anim[i][j][1]));
      b = pgm_read_word_near(&(anim[i][j][2]));
      leds[j] = CRGB(r, g, b);
    }
    FastLED.setBrightness(10);
    FastLED.delay(100);
  }
}

