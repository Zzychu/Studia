#include <stdio.h>

#define ROZMIAR 6

int main( void ) // program kopiowania z stdin na stdout
{
  /*
  int c;
  c = getchar();
  while (c != EOF) {
    putchar(c);
    c = getchar ();
  }
  */
  // 1. zamiana programu jak wyżej na program wykorzystujący formę skrótową 
  // (po sprawdzeniu działania programu oryginalnego, należy go wykomentować w całości,
  // a następnie napisać (odkomentować) wersję skróconą (poniżej)
  // while( (c = getchar()) != EOF) { putchar(c); }
  // - po sprawdzeniu poprawności działania wprowadzenie kończenia wczytywania
  //   po wpisaniu znaku końca linii
  int c;
  // while ((c = getchar()) != EOF) { putchar(c); };
  // while ((c = getchar()) != EOF && c != '\n') { putchar(c); };
  /*
  while((c = getchar()) != EOF) {
    putchar(c);
    if (c=='\n') {
      break;
    }
  
  }
  */
  // 2. Dodanie wczytywania do tablicy znaków
  //    - definicja tablicy przed pętlą (z zadaną maksymalna długością napisu)
  //    - po wczytaniu do zmiennej c i wypisaniu na ekranie, podstawienie do tablicy
  //    - uwaga na zakończenie tablicy:
  //       - długość nie może być zbyt duża (wprowadzenie nowych warunków)
  //       - koniec musi byc zawsze zgodny z konwencją
  
  char tablica_znakow[ROZMIAR];
  for(int i=0;i<ROZMIAR-1;i++) {
    printf("wpisz znak: "); scanf(" %c", &tablica_znakow[i]); 
  }
  tablica_znakow[ROZMIAR-1] = '\0';
  
  for(int i=0;i<ROZMIAR-1;i++) {
    printf("%c\t", tablica_znakow[i]);
  }
  printf("\n");
  
  // 3. Dodanie wypisywania wczytanych znaków jako liczb całkowitych
  
  for(int i=0;i<ROZMIAR-1;i++) {
    printf("%d\t", tablica_znakow[i]);
  }
  printf("\n");
  
  
  
  
  
  

  // Program switch.c - w innym pliku

  //-------------------------------- 3.0 ------------------------------------

  // 5. Wpisanie kodu (na podstawie wykładu) zliczającego liczbę znaków w tablicy
  //    - ewentualna zamiana pętli for na while
  
  // 6. Wpisanie kodu (na podstawie wykładu) przepisującego zawartość jednej tablicy
  //    znaków do drugiej (ewentualna zamiana pętli while na do)

  // 7. Wpisanie kodu (na podstawie wykładu) porównującego zawartość dwóch tablic
  //    - ewentualna zamiana pętli do na while lub for


  //-------------------------------- 4.0 ------------------------------------

  // 8. Napisanie kodu tworzenia tablicy o okreslonej długości i wypełniania
  //     losowymi znakami ( z tablicy ASCII - od 0 do 127, lub dla wybranego
  //     podzbioru znaków, np. małych liter lub t.p.)

  // 9. Napisanie kodu tworzenia histogramu dla otrzymanej tablicy
  //    ( for(....) histogram[ tablica[i] - pierwszy_znak ] ++; )

  // 10. graficzna prezentacja histogramu
  
  //-------------------------------- 5.0 ------------------------------------

 

}

