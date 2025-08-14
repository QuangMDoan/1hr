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

char x[13][9] = {"11010111",    // 0
                  "00010100",   // 1
                  "11001101",   // 2
                  "01011101",   // 3
                  "00011110",   // 4
                  "01011011",   // 5
                  "11011010",   // 6
                  "00010101",   // 7
                  "11011111",   // 8
                  "01011111",   // 9
                  "00001000",  // - 
                  "11001011",  // E for Err
                  "10001000"  // r for Err
                 };

void setup() {
  for(int i = MIN_PIN; i <= CATH_4; i++) pinMode(i , OUTPUT);
  Serial.begin(9600);
}

void displayDigit(int digit, int pos){
  for(int i = 0; i < 4; i++) {
    digitalWrite(CATH_1 + i, pos != i);
  } 

  for(int i = 0; i < 8; i++) {
    digitalWrite(MIN_PIN + i, x[digit][i] - '0');
  }
}

void displayErr(){
  displayDigit(12, 0);
  delay(4);
  displayDigit(12, 1);
  delay(4);
  displayDigit(11, 2);
  delay(4);
}

void displayDigits(int32_t x) {

  if (x < -999 || x > 9999) {
    displayErr();
    return;
  }

  bool neg = x < 0;
  x = abs(x);
  int pos = 0;

  while (pos < 4) {
    displayDigit(x%10, pos);
    delay(4);
    x /= 10;

    pos++;
    if (x == 0) break;
  }

  if(neg){
    displayDigit(10, pos);
    delay(4);
  }
}

void displayDigitsFor(int32_t x, int ms){
  uint32_t start = millis();
  while ((millis() - start) < ms) displayDigits(x);
}

void loop(){
  displayDigitsFor(-800, 1000);
  displayDigitsFor(0, 1000);
  displayDigitsFor(-1, 1000);

  // Outside range (-999 to 9999)
  displayDigitsFor(-2025, 1000); 
  displayDigitsFor(-77, 1000);

  displayDigitsFor(-1000, 1000); 
  displayDigitsFor(2025, 1000);

  displayDigitsFor(10000, 1000); 
  displayDigitsFor(9999, 1000);

  displayDigitsFor(77, 1000);
}
