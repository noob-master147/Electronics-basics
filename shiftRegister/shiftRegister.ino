/* **********************************************************************
   Shift Register 74HC595 with 16 LEDs
     back to back shift registers

   Circuit:
                                          ____________________
           LED  D12       D11             |            LED   |        D11
       5V   0   MISO GND  MOSI  D9   5V   |        5V   8    |   GND  MOSI  D9   5V
       |    |    |    |    |    |    |    |        |    |    |    |    |    |    |    |
    |--|----|----|----|----|----|----|----|--|  |--|----|----|----|----|----|----|----|--|
    |  VCC  Q0   DS  OE  ST_CP SH_CP MR  Q7' |  |  VCC  Q0   DS  OE  ST_CP SH_CP MR  Q7' |
    |                                        |  |                                        |
    |  Q1   Q2   Q3  Q4    Q5   Q6   Q7  GND |  |  Q1   Q2   Q3  Q4    Q5   Q6   Q7  GND |
    |--|----|----|----|----|----|----|----|--|  |--|----|----|----|----|----|----|----|--|
       |    |    |    |    |    |    |    |        |    |    |    |    |    |    |    |
      LED  LED  LED  LED  LED  LED  LED  GND      LED  LED  LED  LED  LED  LED  LED  GND
       1    2    3    4    5    6    7             9    10   11   12   13   14   15

   https://www.arduino.cc/reference/en/language/functions/bits-and-bytes/bitset/
   https://www.arduino.cc/reference/en/language/functions/advanced-io/shiftout/
 ********************************************************************* */

/* ***************************************************
                  Global Constants
 *************************************************** */
const int tDelay   = 100;     // delay between LED switching
const int dataPin  = 12;      //    DS - data serial
const int latchPin = 11;      // ST_CP - storage register, latch clock pin
const int clockPin = 9;       // SH_CP - shift register clock pin
int hours = 0;

const uint8_t zero  = 0B11111100;
const uint8_t one   = 0B01100000;
const uint8_t two   = 0B11011010;
const uint8_t three = 0B11110010;
const uint8_t four  = 0B01100110;
const uint8_t five  = 0B10110110;
const uint8_t six   = 0B10111110;
const uint8_t seven = 0B11100000;
const uint8_t eight = 0B11111110;
const uint8_t nine  = 0B11110110;

const uint8_t digit[10] = {zero, one, two, three, four, five, six, seven, eight, nine};
/* ***************************************************
                  Global Variables
 *************************************************** */
bool DirectionState = 0;

/* ***************************************************
                     Functions
 *************************************************** */
void updateShiftRegister(unsigned int high, unsigned int low, bool isMSBFIRST = true) {
  /*  Performs all the necessary work to serial load
        two shift registers.  Direction controlled by
        isMSBFIRST
      Paramters:
        leds       - insigned 16-bit number {required}
        isMSBFISRT - boolean for direction
                     true  = MSBFIRST
                     false = LSBFIRST
      called by void loop                           */

  /*         Local variables            */
  /* example:    Higher byte Lower byte
      16-bit word = 00000000 00000000   */
  byte lowLED  = low;      // extacts the lower byte, right most byte, from a 16-bit word or unsigned integer
  byte highLED = high;     // extracts the higher byte, left most byte, from a 16-bit word or unsigned integer

  digitalWrite(latchPin, LOW);
  if (isMSBFIRST == false) {
    // LEDs move from right to left
    shiftOut(dataPin, clockPin, LSBFIRST, lowLED);   // shiftout only works with a byte value
    shiftOut(dataPin, clockPin, LSBFIRST, highLED);
  } else {
    // LEDs move from left to right
    shiftOut(dataPin, clockPin, MSBFIRST, highLED);
    shiftOut(dataPin, clockPin, MSBFIRST, lowLED);
  }
  digitalWrite(latchPin, HIGH);
}



void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin,  OUTPUT);
  pinMode(clockPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), callback, RISING);
}

void callback() {
  if(hours == 9)
  hours = 0;
  hours++;
}

void loop() {
  
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      unsigned int high = digit[i];
      unsigned int low = digit[hours];
      updateShiftRegister(low, high);
      delay(tDelay);
    }
  }
}
