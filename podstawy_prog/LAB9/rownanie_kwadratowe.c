#include <stdlib.h> // USES
#include <stdio.h> // USES
#include <math.h> // USES

// sposób na łatwą zmianę typu dla wszystkich zmiennych w programie
#define SCALAR double
//#define SCALAR float

#define SMALL_NUMBER 1.e-20 // czy wystarczy jedna wartość dla float i dla double?


int rownanie_kwadratowe(SCALAR a, SCALAR b, SCALAR c, double *pointer1, double *pointer2);
// Testowanie: konstrukcji sterujących (a także nazw zmiennych,
// zakresów widoczności i czasu życia)
int main(void)
{
  // rozwiązanie równania kwadratowego ax^2 + bx + c = 0

  printf("\nProgram rozwiązywania równania kwadratowego ax^2 + bx + c = 0\n");

  // typ a, b, c ustalany poprzez symbol SCALAR
  SCALAR a, b, c;
  // rozważania o kontrakcie... (czy uwzględnia skończoną precyzję?)
  // input - uodpornianie na błędy wczytywania danych 
  printf("\nPodaj parametr a: "); scanf("%lf",&a); // adres! (miejsce na wpisanie wartości)
  printf("Podaj parametr b: "); scanf("%lf", &b); // uwaga: inny format dla float!
  printf("Podaj parametr c: "); scanf("%lf", &c);

  // if(a==0 && b==0){ // alternatywa: if( a==0 || b==0 ) - zależnie od kontraktu
  double x1, x2;
  double *x1Ptr = &x1;
  double *x2Ptr = &x2;

  int ilosc_pierwiastkow = rownanie_kwadratowe(a,b,c, x1Ptr, x2Ptr);

  if(ilosc_pierwiastkow == 1) {
    printf("Jeden pierwiastek rzeczywisty: x = %.12le\n", x1);
  } else {
    printf("Dwa pierwiastki rzeczywiste: x1 = %.12le, x2 = %.12le\n",
	     x1, x2 );
  }
  

  return(0);
};


int rownanie_kwadratowe(SCALAR a, SCALAR b, SCALAR c, double *x1, double *x2) {
  if( fabs(a)<SMALL_NUMBER && fabs(b)<SMALL_NUMBER ){ // poprawnie

    printf("Błędne dane: a i b równe 0 (zbyt bliskie 0). Przerwanie programu.\n");
    exit(-1);

  }
  else {
  
   if(a==0) { // równanie liniowe

      //co mówi kontrakt? - czy należy rozważyć liczby a bliskie 0 ?

    }
    else{

      SCALAR delta;  // zakres widoczności nazwy - powiązanie z czasem życia  
      delta = b*b - 4*a*c; // problem jeśli delta bliskie b*b (w skończonej precyzji)
                           // wtedy odejmowanie b i sqrt(delta) traci cyfry znaczące

      if(delta<0){

	printf("Dwa pierwiastki zespolone - nie umiem obliczyć\n");

      } else if (delta == 0){
          *x1 = -b/(2*a);
	// printf("Jeden pierwiastek rzeczywisty: x = %.12le\n", -b/(2*a) );
        return 1;
      } else {

	SCALAR temp = sqrt(delta);
	*x1 = (-b-temp)/(2*a);
	*x2 = (-b+temp)/(2*a);
	//printf("Dwa pierwiastki rzeczywiste: x1 = %.12le, x2 = %.12le\n",
	//       (-b-temp)/(2*a), (-b+temp)/(2*a) );
        return 2;
      }  
    } // znaczenie wcięć i nawiasów klamrowych dla zwiekszenia czytelności kodu !
  }
  
};

