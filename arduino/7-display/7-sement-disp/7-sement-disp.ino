#define SEG_E 2
#define SEG_D 3
#define SEG_DP 4 
#define SEG_C 5
#define SEG_G 6
#define SEG_B 7 
#define SEG_F 8 
#define SEG_A 9 
#define CATH_1 10
#define CATH_2 11 
#define CATH_3 12 
#define CATH_4 13

#define MIN_PIN 2

char x[10][9] = {"11010111", "00010100", "11001101", "01011101", "00011110", 
                 "01011011", "11011010", "00010101", "11011111", "01011111" };

void setup(){
  for(int pin = MIN_PIN; pin <= CATH_4; pin++) pinMode(pin, OUTPUT);
}

void displayDigit(uint8_t pos, uint8_t digit) {
  for (int i = 0; i < 4; i++) 
    digitalWrite(CATH_1+i, pos != i);
  
  for (int i = 0; i < 8; i++)
    digitalWrite(MIN_PIN + i, x[digit][i] - '0');
}

void displayDigits(int32_t digits) {
  for (int pos = 0; pos < 4; pos++) {
    displayDigit(pos, digits % 10);
    delay(4);
    digits = digits / 10;
  }  
}

void displayDigitsFor(int32_t digits, int ms) {
  unsigned long startTime = millis();
  while ((millis() - startTime) < ms) displayDigits(digits);
}

void loop(){
  for (int x = 89; x < 2026; x++) displayDigitsFor(x, 500);
}