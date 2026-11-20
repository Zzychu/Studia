#include <stdio.h>
#include <limits.h>

// funkcja oblicza potęgę całkowitą liczby całkowitej
int potega_int(int m, int n);

int oblicz_wielomian_int(int tab_wsp[4], int argument);
int oblicz_wielomian_int_Horner(int tab_wsp[4], int argument);
int oblicz_wielomian_int_Horner(int tab_wsp[4], int argument, int stopien);

int main (void)
{
  int i;
  for (i = 0; i < 10; i++){
    printf("i = %d \t2^i = %d \t(-3)^i = %d\n", 
	   i, potega_int(2,i), potega_int(-3,i));
  }
  int tab_wsp[4] = {8, 5, 3, 2};
  int stopien = 3;
  int argument = 2;
  int wynik = oblicz_wielomian_int(tab_wsp, argument);
  printf("wynik obliczanie wielomianu: %d dla argumentu: %d i liczb: %d %d %d %d \n", wynik, argument, tab_wsp[0], tab_wsp[1], tab_wsp[2], tab_wsp[3]);
  int wynik_horner = oblicz_wielomian_int_Horner(tab_wsp, argument);
   printf("wynik obliczanie wielomianu hornera: %d dla argumentu: %d i liczb: %d %d %d %d \n", wynik_horner, argument, tab_wsp[0], tab_wsp[1], tab_wsp[2], tab_wsp[3]);
   int wynik_horner_dowolny = oblicz_wielomian_int_Horner(tab_wsp, argument);
   printf("wynik obliczanie wielomianu hornera: %d dla argumentu: %d i liczb: %d %d %d %d \n", wynik_horner_dowolny, argument, tab_wsp[0], tab_wsp[1], tab_wsp[2], tab_wsp[3]);
}

// funkcja oblicza potęgę całkowitą liczby całkowitej
int potega_int( // funkcja zwraca wartość potegi podstawa^wykładnik
	      int podstawa, // [in]: zadana podstawa 
	      int wykladnik // [in]: zadany wykładnik 
	       )
{
  int potega = 1;
  for (int i = 1; i <= wykladnik; i++){
    potega *= podstawa;
  }
  return potega;
}

int oblicz_wielomian_int(int a[4], int x) {
  
  return a[0] + a[1]*potega_int(x,1) + a[2]*potega_int(x,2) + a[3]*potega_int(x,3) + a[4]*potega_int(x,4);
  
  
}

int oblicz_wielomian_int_Horner(int a[4], int x) {

  return a[0] + x*( a[1] + x*( a[2] + x*( a[3] + x*a[4]) ) );

}

int oblicz_wielomian_int_Horner_dowolny(int a[4], int x, int stopien) {
  int wynik = 1;
  for(int i = stopien; i > 0; i--) {
      // wynik = wynik*
  }

}



// modyfikacje potega_int_1 - sprawdzanie w trakcie obliczeń czy obliczane wartości 
//                           nie przekraczają zakresu liczb całkowitych INT_MAX
//                           (zdefiniowane w pliku limits.h)


// Przypadek schematu Hornera dla wielomianu 4 stopnia
// a[0] + a[1]*x + a[2]*x^2 + a[3]*x^3 + a[4]*x^4: KLASYCZNY
//
// a[0] + x*( a[1] + x*( a[2] + x*( a[3] + x*a[4]) ) ) HORNER
//
