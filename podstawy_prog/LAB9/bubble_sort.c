#include <stdio.h>
#include <stdlib.h>

#define SCALAR int

void sortowanie_babelkowe(SCALAR tablica[], int rozmiar);
void przestaw(SCALAR *pointer1, SCALAR *pointer2);

int main( void ) {
  int rozmiar;
  printf("podaj rozmiar talicy losowej"); scanf(" %i", &rozmiar);
  
  int tablica[rozmiar] = {0};
  
  for(int i = 0; i < rozmiar; i++) {
    tablica[i] = 1+(int) (10.0*rand()/(10+1.0));
  }
  
  
  

  return 0;
}


void sortowanie_babelkowe(SCALAR tablica[], int rozmiar) {
 int i, j;
 for (i = 0; i<rozmiar-1; i++){
 for (j=0; j<rozmiar-1-i; j++){
 if (tablica[j] > tablica[j+1]) przestaw(&tablica[j], &tablica[j+1]);
} } }

void przestaw(SCALAR *scalar_1_p, SCALAR *scalar_2_p);
{
SCALAR temp = *scalar_1_p;
*scalar_1_p = *scalar_2_p;
*scalar_2_p = temp;
}
