#include <stdio.h>

int main(void) {
  //zadanie 1 konwersja jawna
  
  int l1 = 4;
  int l2 = 3;
  
  double wynik = l1/l2;
  double wynik_jawny = (double)l1/(double)l2;
  
  printf("%.2lf\n", wynik);
  printf("%.2lf\n", wynik_jawny);
  
  
  
  // zadanie 2 suma roznica iloczyn
  
  int a = 3;
  int b = 1;
  int c = 7;
  
  unsigned suma = a+b+c;
  unsigned roznica = a-b-c;
  unsigned mnozenie = a*b*c;
  
  printf("suma: %d, roznica: %d, mnozenie: %d\n", suma, roznica, mnozenie);
  
  float srednia = ((float)a + (float)b + (float)c)/3;
  printf("srednia: %.2f\n", srednia);
  
  
  return 0;
}
