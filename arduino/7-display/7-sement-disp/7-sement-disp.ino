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

char x[13][9] = { "11010111", "00010100", "11001101", "01011101",   // encoding 0,1,2,3
                  "00011110", "01011011", "11011010", "00010101",   // encoding 4,5,6,7
                  "11011111", "01011111", "00001000",   // encoding 8, 9, and minus "-"
                  "11001011", /* encoding "E" for "Err" */ "10001000" // encoding "r" 
                 };

void setup() {
  for(int i = MIN_PIN; i <= CATH_4; i++) pinMode(i , OUTPUT);
  Serial.begin(9600);
}

void displayDigit(int digit, int pos, int decPlace = 5){
  for (int i = 0; i < 4; i++)
    digitalWrite(CATH_1 + i, pos != i);
  
  for (int i = 0; i < 8; i++) 
    digitalWrite(MIN_PIN + i, x[digit][i] - '0');

  if (pos == decPlace) {
    digitalWrite(4, 1);
  }
}

void displayErr(){
  displayDigit(12, 0); // show x[12][i] segments for letter "r"
  delay(4);
  displayDigit(12, 1); // show x[12][i] segments for letter "r"
  delay(4);
  displayDigit(11, 2); // show x[11][i] segments for letter "E"
  delay(4);
}

void displayDigits(double x) {  
  if (x <= -1000 || x >= 10000) {
    displayErr();
    return;
  }

  bool neg = x < 0.0;
  x = abs(x);
  int decPlace = 10;

  if(x>=1000.0){
    x = x;
  }
  else if (x > 100.0) {
    decPlace = 1;
    x = x*10;
    if(neg){
      decPlace = -1;
    }
  } else if (x > 10.0) {
    decPlace = 2;
    x = x*100;
  } else if (x > 1.0) {
    decPlace = 3;
    x = x*1000;
  }

  if(neg) {
    x = x/10;
    decPlace = decPlace-1;
  }
  int pos = 0;
  int xd = (int) x;
  while (pos < 4) {  
    Serial.println(xd);
    displayDigit(xd%10, pos, decPlace);
    delay(4);
    xd /= 10;
    pos++;
    if (xd == 0) break;
  }

  if(neg){
    displayDigit(10, pos);
    delay(4);
  }
}

void displayDigits(int x) {
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

void displayDigitsFor(int x, int ms){
  uint32_t start = millis();
  while ((millis() - start) < ms) displayDigits(x);
}

void displayDigitsFor(double x, int ms){
  uint32_t start = millis();
  while ((millis() - start) < ms) displayDigits(x);
}

void loop(){
  displayDigitsFor(1.434, 1000);
  displayDigitsFor(3.141592, 1000); // expecting 3.141
  displayDigitsFor(20.12345, 1000); // expecting 20.12
  displayDigitsFor(1234.567, 1000); // expecting 1234 
  displayDigitsFor(-50.988,  1000); // expecting -50.9
  displayDigitsFor(-14.5, 1000);    // expecting -14.5
  displayDigitsFor(-1.43, 1000);    // expecting -1.43
  displayDigitsFor(-999.1, 1000);   // expecting -999
}
