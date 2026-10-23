#include <stdio.h>
#include <math.h>

#define TOLERANCE 1e-12

int main(void) {
  // 1. deklaracje definicje
  
  int n;
  char znak_do_testowania;
  
  znak_do_testowania='a';
  n = 7;
  printf("\nwartość zmiennej n = %d, wartość zmiennej znak_do_testowania = %c\n",n, znak_do_testowania );
  
  float przecinkowa;
  przecinkowa=0.5;
  float przecinkowa2 = 0.6;
  // printf("przecinkowa=%f, zle zforamtowana:%d",przecinkowa,przecinkowa); // Wywala blad w compilerze
  printf("przecinkowa=%f, przecinkowa2=%f\n",przecinkowa, przecinkowa2);
  double przecinkowa_long;
  przecinkowa_long=0.0005;
  printf("przecinkowa_long=%f\n",przecinkowa_long);
  long dluga;
  dluga = 100010101001;
  printf("dluga=%li\n", dluga);
  short krotka;
  // krotka=10001010; overflow
  krotka=100;
  printf("krotka=%i\n", krotka);
  unsigned nieoznaczona;
  nieoznaczona=100;
  printf("nieoznaczona=%u\n",nieoznaczona);
  nieoznaczona='a';
  printf("nieoznaczona=%c, zly format = %i\n",nieoznaczona, nieoznaczona);
  
  // 2. PROSTE OPERACJE
  
  int m;
  m = 2 * n + 3;
  int o = 2 * (n + 3);
  printf("\nn = %d, (2 * n + 3) = %d != (2 * (n + 3)) = %d\n", n, m, o);
  
  // wlasne
  
  int zad1_1 = (2 * 3 + n) * n;
  int zad1_2 = (2 * (3 + n)) * n;
  int zad2_1 = (12 + n) * (12 + n);
  int zad2_2 = (12 + n) * 12 + n;
  int zad3_1 = 12 * n + n;
  int zad3_2 = 12 * (n + n);
  printf("zad1: %d != %d, zad2: %d != %d, zad3: %d != %d\n",zad1_1,zad1_2,zad2_1,zad2_2,zad3_1,zad3_2);
  
  int p = n++;  
  n--;
  int q = ++n;  
  n--;
  printf("\nn = %d, wynik podstawienia: 'p = n++;' - %d, wynik podstawienia: 'q = ++n;' - %d\n",n, p, q);
  
  // wlasne
  
  zad1_1 = ++n - n;
  zad1_2 = n++ - n;
  zad2_1 = 1 + zad1_1++ - 2;
  zad2_2 = 1 + ++zad1_1 -2;
  printf("zad1: %d != %d, zad2: %d != %d\n",zad1_1, zad1_2, zad2_1,zad2_2);
  n = 7;
  
  n = 1574;
  m = n % 7;
  o = n / 7;
  printf("\nn = %d, n/7 = %d, reszta - n7 = %d, n = (n/7)*7 + (n7) = %d\n",n, o, m, o*7+m);
  
  int l1 = 888;
  int d1 = 8;
  int l2 = 2020;
  int d2 = 3;
  printf("zad1: cal: %d, reszta: %d, pierw: %d zad2: cal: %d, reszta: %d, pierw: %d\n", l1/d1, l1%d1, (l1/d1)*d1 + l1%d1,  l2/d2, l2%d2, (l2/d2)*d2 + l2%d2);
  
  // 3 STALE SYMBOLE
  
  #define SIEDEM 7
  int r = SIEDEM; 
  printf("\nr = %d, stała SIEDEM = %d\n", r, SIEDEM); 
  
  // wlasne
  
  #define war1 101010
  #define war2 'a'  
  #define war3 0.5

  int liczba = war1;
  char znak2 = war2;
  float float2 = war3;
  
  printf("zad1: %d = %d, zad2: %c = %c, zad3 %f = %f\n",liczba,war1,znak2,war2,float2,war3);
  
  // 4 ZMIENNE ZMIENNOPRZECINKOWE
  
  float f = 1.0f/3.0f;  // zapis stałej float z literką f
  float g = 1.0f/3.0; 
  double d = 1.0/3.0; 
  double e = 1.0f/3.0; 

  
  printf("\nliczby zmiennoprzecinkowe:\n");
  printf("float  -  f = 1.0f/3.0f = %f  (dokładnie: %20.15f)\n", f, f);
  printf("float  -  g = 1.0f/3.0  = %f  (dokładnie: %20.15f)\n", g, g);
  printf("double -  d =  1.0/3.0  = %lf  (dokładnie: %20.15lf)\n", d, d);
  printf("double -  e = 1.0f/3.0  = %lf  (dokładnie: %20.15lf)\n", e, e);
  int s = 1/3;
  printf("(liczba całkowita s = 1/3 = %d - dzielenie całkowite)\n", s);
  int t = 1.0/3.0;
  printf("(liczba całkowita t = 1.0/3.0 = %d - obcięcie przy konwersji)\n", t);
  printf("\n");
  printf("float  -  f = 1.0f/3.0f = %e  (dokładnie: %20.15e)\n", f, f);
  printf("double -  d =  1.0/3.0  = %le  (dokładnie: %20.15le)\n", d, d);
  
  // wlasne 
  
  float f1 = 1.5f/0.04f;
  float f2 = 1.5/0.04;
  float f3 = 1.0/533.0;
  double f4 = 1.0/533.0;
  
  printf("f1: %f %20.15f,\n f2: %f %20.15f,\nf3: %f %20.15f,\nf4: %lf %20.15f\n",f1,f1,f2,f2,f3,f3,f4,f4);
  
  
  printf("\nProgram dotarł do końca\n");
  return(0);
}
