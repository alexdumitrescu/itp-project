#include <FastLED.h>

#define NUM_LEDS_PER_STRIP 50
CRGB led1[NUM_LEDS_PER_STRIP];
CRGB led2[NUM_LEDS_PER_STRIP];
CRGB led3[NUM_LEDS_PER_STRIP];
CRGB led4[NUM_LEDS_PER_STRIP];
CRGB led5[NUM_LEDS_PER_STRIP];
CRGB led6[NUM_LEDS_PER_STRIP];
CRGB led7[NUM_LEDS_PER_STRIP];
CRGB led8[NUM_LEDS_PER_STRIP];
CRGB led9[NUM_LEDS_PER_STRIP];
CRGB led10[NUM_LEDS_PER_STRIP];

int color=0, color2=0;
int s=0, s2=0, s3, s4, s5, s6, s7, s8, s9, s10;
int b=0, b2=0, b3, b4, b5, b6, b7, b8, b9, b10;
int incomingData;
String stringOne;

int potPin0 = A0;    // select the input pin for the potentiometer
int potPin1 = A1; 
int potPin2 = A2; 
int potPin3 = A3; 
int val0 = 0;       // variable to store the value coming from the sensor
int val1 = 0;
int val2 = 0;
int val3 = 0;

int analogval0 = 0;  //mapped values between 0 and 255
int analogval1 = 0;
int analogval2 = 0;
int analogval3 = 0;

void setupStrip() {
  for(uint16_t i = 0; i < NUM_LEDS_PER_STRIP; i += 1){
    led1[i] = CRGB::Blue;
    led2[i] = CRGB::Red;
  }
}

void setup() {
  FastLED.addLeds<WS2811, 2>(led1, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2811, 3>(led2, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2811, 4>(led3, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2811, 5>(led4, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2811, 6>(led5, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2811, 7>(led6, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2811, 8>(led7, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2811, 9>(led8, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2811, 10>(led9, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2811, 11>(led10, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  pinMode(potPin0, INPUT);  // declare the ledPin as an OUTPUT
  pinMode(potPin1, INPUT);
  pinMode(potPin2, INPUT);
  pinMode(potPin3, INPUT);
  //attachInterrupt(0, ledArrays, CHANGE);
  //attachInterrupt(0, analogInputs, CHANGE);
  //Serial.begin(19200);

  FastLED.setBrightness(245);
  setupStrip();
  FastLED.show();
}

void loop() {
  ledArrays();
  analogInputs();
  delay(3);
}

void analogInputs(){
  Serial.begin(9600);
  analogval0 = analogRead(potPin0);    // read the value from the sensor
  analogval1 = analogRead(potPin1);
  analogval2 = analogRead(potPin2);
  analogval3 = analogRead(potPin3);
//  Serial.print(analogval1);
//  Serial.print(";");

  val0 = map(analogval0, 0, 1023, 0, 600);  // map analog values to range between 0 and 255
  val1 = map(analogval1, 0, 1023, 0, 600);
  val2 = map(analogval2, 0, 1023, 50, 600);
  val3 = map(analogval3, 0, 1023, 1, 20);
  
//  Serial.print(val0);
//  Serial.print(",");
//  delay(1);
//  Serial.print(val1);
//  Serial.print(",");
//  delay(1);
//  Serial.print(val2);
//  Serial.print(",");
//  delay(1);
//  Serial.print(val3);
//  Serial.print(",");
//  Serial.println();
}

void ledArrays(){
  //Serial.println(analogval1);
  color= map(analogval1, 0, 1023, 0, 290);
  color2= map(analogval1, 0, 1023, 180, 470);
  Serial.print("Color2");
  Serial.print(color2);
  s = 255;
  s2 = 204;
  s3 = 153;
  s4 = 102;
  s5 = 80;
  s6 = 80;
  s7 = 102;
  s8 = 153;
  s9 = 204;
  s10 = 255;
  
  b = 255;  
  b2 = 229.5;
  b3 = 204;
  b4= 178.5;
  b5= 153;
  b6 = 153;
  b7= 178.5;
  b8= 204;
  b9 = 229.5;
  b10 = 255;
  
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    // set our current dot to red, green, and blue
    
    led1[i] = CHSV( color, s, b);
    led2[i] = CHSV( color, s2, b2);
    led3[i] = CHSV( color, s3, b3);
    led4[i] = CHSV( color, s4, b4);
    led5[i] = CHSV( color, s5, b5);
    led6[i] = CHSV( color2, s6, b6);
    led7[i] = CHSV( color2, s7, b7);
    led8[i] = CHSV( color2, s8, b8);
    led9[i] = CHSV( color2, s9, b9);
    led10[i] = CHSV( color2, s10, b10);
//    Serial.print(color);
//    Serial.print(",");
//    Serial.print(s9);
//    Serial.print(",");
//    Serial.println(b9);
//    Serial.print("\t");
//    Serial.print("S10:");
//    Serial.print(s10);
//    Serial.print("\t");
//    Serial.print("B10:");
//    Serial.print(b10);
//    Serial.print("\t");

  FastLED.show();
  }
}
