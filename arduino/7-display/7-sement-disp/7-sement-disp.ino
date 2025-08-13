#define SEG_E 2
#define SEG_D 3
#define SEG_C 4
#define SEG_DP 5
#define SEG_B 6 
#define SEG_A 7
#define SEG_F 8
#define SEG_G 9 

#define MIN_PIN 2 
#define MAX_PIN 9

char x[10][9] = {"11101110"}

void setup() {
  for(int i = MIN_PIN; i <= MAX_PIN; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 8 ) {

  }
}