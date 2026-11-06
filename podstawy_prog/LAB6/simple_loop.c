#include <stdio.h>
#include <stdlib.h>

#define ROZMIAR_TABLICY 10

void main(void)
{

  

  // 1. inicjowanie tablicy w momencie definowania:

  // a. wszystkie wartości
  
  int tablica_int[ROZMIAR_TABLICY] = {0};
  

  // b. początkowe wartości
  
  int tablica_int2[2] = {12,68};

  // 2. nadanie wartości w pętli

  // a. zależnych od wartości zmiennej sterujacej
  
  /*
  for(int i =0;i<ROZMIAR_TABLICY;i++) {
  
    tablica_int[i] = 2*i;
  
  }
  
  */
  
  // b. wczytywanych z klawiatury za pomocą scanf
  
  /*
  
  int liczba;
  
  for(int i =0;i<ROZMIAR_TABLICY;i++) {
  
    printf("podaj liczbe: "); scanf("%i",&liczba);
    tablica_int[i] = liczba;
  
  }

  */
  
  // 3. zamiana pętli for nadawania wartości na pętlę while
  
  int i = 0;
  while(i<ROZMIAR_TABLICY) {
    
    tablica_int[i] = i*i*10;
    i++;
  
  }

  // 4. zamiana poniższej pętli for na pętlę do
  // (jak zwykle najlepiej wykomentować starą pętlę i wpisać poniżej nową pętlę)

  /*

  for(int i=0; i<ROZMIAR_TABLICY; i++){

    printf("Iteracja %d: tablica_int[%d] = %d\n", i, i, tablica_int[i]);

  }
  
  */

  i = 0;
  
  do {
    // printf("Iteracja %d: tablica_int[%d] = %d\n", i, i, tablica_int[i]);
    i++;
  } while(i < ROZMIAR_TABLICY);

  // 5. wyszukiwanie wartości maksymalnej w tablicy (pętla for)
  
  
  int max = 0;
  for(int i=0; i<ROZMIAR_TABLICY; i++){

    if(tablica_int[i]>max) {
      max=tablica_int[i];
    }

  }
  //printf("Maksymalna wartosc tablicy: %i\n", max);
  
  // 6. obliczanie sumy elementów tablicy (pętla while)
  
  i = 0;
  int suma = 0;
  while(i < ROZMIAR_TABLICY) {
  
    suma=suma+tablica_int[i];
    i++;
  
  };
  //printf("Suma wartosc tablicy: %i\n", suma);

  //-------------------------------- 3.0 ------------------------------------

  // 7. tablica z wartościami losowymi i wyszukiwanie zadanych wartości

  // a. nowa definicja tablicy (np. tablicy znaków)
  
  char tablica_znakow[ROZMIAR_TABLICY] = {'a'};

  // b. nadawanie wartości losowych wyrazom tablicy
  //    (np. liczby z zakresu 33-126, czyli odpowiadające znakom ASCII)
  //    -> odpowiednie wydruki
  
  for(int i = 0;i < ROZMIAR_TABLICY;i++) {
  
    tablica_znakow[i] = (char)(33 + rand()%(126 - 33 + 1));
    
  };

  // c. sprawdzenie losowości - obliczenie wartości średniej w tablicy
  //    (w odpowiedniej pętli) - porównanie z teoretyczną średnią
  //    -> odpowiednie wydruki
  
  float suma_srednia = 0;
  
  for(int i = 0;i < ROZMIAR_TABLICY;i++) {
  
    suma_srednia = suma_srednia + (int)tablica_znakow[i];
    
  };
  
  printf("srednia wartosci to: %f\n", suma_srednia/ROZMIAR_TABLICY);
  
  // srednia zbliza sie do 81.300000000000000 wraz z wyzszymi wartosciami
  

  // d. wyszukiwanie zadanej wartości
  //    -> odpowiednie wydruki w momencie znalezienia wartości
  //    np. "Znaleziono wartość %.. w %d elemencie tablicy\n", ...

  //  d1. wyszukanie tylko jednej (pierwszej) wartości - pętla while
  //      (lub pętla for i break)
  
  char znak;
  printf("wpisz szukany znak: "); scanf(" %c", &znak);
  
  /*
  for(int i = 0;i<ROZMIAR_TABLICY;i++){
     
    if(znak==tablica_znakow[i]){
      printf("ZNALEZIONO WARTOSC %c, w %d ELEMENCIE TABLICY\n", znak, i);
      break;
    }
    
  }
  */

  //  d2. wyszukanie (i wypisanie) wszytskich wartości - pętla for
  //      (lub pętla while)

  for(int i = 0;i<ROZMIAR_TABLICY;i++){
     
    if(znak==tablica_znakow[i]){
      printf("ZNALEZIONO WARTOSC %c, w %d ELEMENCIE TABLICY\n", znak, i);
    }
    
  }



  //-------------------------------- 4.0 ------------------------------------

   i = 0;
  
  do {
    printf("Iteracja %d: tablica_int[%d] = %c\n", i, i, tablica_znakow[i]);
    i++;
  } while(i < ROZMIAR_TABLICY);

  
}
