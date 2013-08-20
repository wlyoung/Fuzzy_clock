#include <Adafruit_NeoPixel.h>

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, 6, NEO_GRB + NEO_KHZ800);

// You can optionally use hardware SPI for faster writes, just leave out
// the data and clock pin parameters.  But this does limit use to very
// specific pins on the Arduino.  For "classic" Arduinos (Uno, Duemilanove,
// etc.), data = pin 11, clock = pin 13.  For Arduino Mega, data = pin 51,
// clock = pin 52.  For 32u4 Breakout Board+ and Teensy, data = pin B2,
// clock = pin B1.  For Leonardo, this can ONLY be done on the ICSP pins.
//LPD8806 strip = LPD8806(nLEDs);

int i, j, k;
int startHour ;
int startMinutes;
int setMinutes;
int waitTime;

void setup() {
  startHour = 10;
  startMinutes = 46;
  setMinutes = startMinutes * 2;
  
  // Start up the LED strip
  strip.begin();

  // Update the strip, to start they are all 'off'
  strip.show();
}


void loop() {
   waitTime = 29990;
   //waitTime = 50;
  // Send a simple pixel chase in...

  // Start by turning all pixels off:
  for(i=0; i<strip.numPixels(); i++) strip.setPixelColor(i, 0);
   
  // Then display one pixel at a time:
  for(i=startHour; i<(strip.numPixels()); i++) {
   for(k=0; k<strip.numPixels(); k++) strip.setPixelColor(k, 0);
    for (j=setMinutes; j<120; j++){
     if (i < (strip.numPixels()-1))
    { 
    strip.setPixelColor(i, 0,0,120-j); 
    strip.setPixelColor(i+1, j ,0, 0); 
    
    } 
    else  // start at 12 again
    {
      strip.setPixelColor(i, 0,0,120-j); 
      strip.setPixelColor(0, j,0,0); 
      
    }
    strip.show(); 
    delay(waitTime); // modify this to change timing
  }

  setMinutes = 0;
  
  }
  startHour = 0;
  strip.show(); // Refresh to turn off last pixel 
  
  
}


