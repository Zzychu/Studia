#include <stdio.h>



int main(void) {

  // zadanie 1

  int liczba;
  printf("podaj liczbe calkowita: "); scanf(" %i",&liczba);
  
  if(liczba>0){
    printf("\njest dodatnia");
  }
  else if(liczba<0) {
    printf("\njest ujemna");
  }
  else {
    printf("\njest rowna 0");
  }
  
  
  // zadanie 2
  
  int wiek;
  
  printf("podaj wiek: "); scanf(" %i", &wiek);
  
  if(0<=wiek && wiek<=12) {
    printf("dziecko\n");
  }
  else if(13<=wiek && wiek<=17) {
    printf("nastolatek");
  }
  else if(18<=wiek && wiek<=64) {
    printf("dorosly");
  }
  else if(65<=wiek) {
    printf("senior");
  }
  
  // zadanie 3
  
  
  
  
  
  





  return 0;  
}
