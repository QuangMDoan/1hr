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

char x[10][9] = {"11010111", 
                 "00010100",
                 "11001101", 
                 "01011101",
                 "00011110",
                 "01011011",
                 "11011010",
                 "00010101", 
                 "11011111",
                 "01011111", 
                 };



void loop(){
  for (int x = 89; x < 2026; x++) 
    displayDigitsFor(x, 500);
}