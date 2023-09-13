// Adafruit_NeoMatrix example for single NeoPixel Shield.
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
#define PSTR // Make Arduino Due happy
#endif
#define PIN 52 //Where to plug into in the Arduino

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN, //Create the Matirx here
  NEO_MATRIX_BOTTOM     + NEO_MATRIX_RIGHT +
  NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

const uint16_t colors[] = {
matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) }; //(R,G,
void setup() {
  matrix.begin();
  matrix.setTextWrap(true);
  matrix.setBrightness(5);
  matrix.setTextColor(colors[0]);
  Serial.begin(9600);  
}

int x    = matrix.width();
int pass = 0;

void loop() {

  Serial.println("Enter your name. ");  
  while (Serial.available() == 0)   
  {}  
  name = Serial.readString();
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  matrix.print("Name"); // Scrolls 'Howdy' across the matrix in a portrait (vertical) orientation.
  if(--x < -36) {
    x = matrix.width();
    if(++pass >= 3) pass = 0;
    matrix.setTextColor(colors[pass]);
  }
  matrix.show();
  delay(100);
}