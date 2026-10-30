#include <stdlib.h> // USES
#include <stdio.h> // USES
#include <math.h> // USES

#define SCALAR double
//#define SCALAR float

#define TOLERANCJA 1e-12

#define SMALL_NUMBER 1.e-20 // czy wystarczy jedna wartość dla float i dla double?

// Konstrukcje sterujące (nazwy zmiennych, zakresy widoczności i czas życia)
int main(void)
{
  // rozwiązanie równania kwadratowego ax^2 + bx + c = 0

  printf("\nProgram rozwiązywania równania kwadratowego ax^2 + bx + c = 0\n");

  // prosta wersja: int a, b, c;
  SCALAR a, b, c;
  // rozważania o kontrakcie... (czy uwzględnia skończoną precyzję?)
  // input - uodpornianie na błędy wczytywania danych 
  printf("\nPodaj parametr a: "); scanf("%lf",&a); // adres! (miejsce na wpisanie wartości)
  printf("Podaj parametr b: "); scanf("%lf", &b); // uwaga: inny format dla float!
  printf("Podaj parametr c: "); scanf("%lf", &c);

  // if(a==0 && b==0){ // alternatywa: if( a==0 || b==0 ) - zależnie od kontraktu
  if( fabs(a)<SMALL_NUMBER && fabs(b)<SMALL_NUMBER ){ // poprawnie
    printf("Błędne dane: a i b równe 0 (zbyt bliskie 0). Przerwanie programu.\n");
    exit(-1);
  }
  else{
    if(fabs(a)<TOLERANCJA) { // równanie liniowe
      //co mówi kontrakt? - czy należy rozważyć liczby a bliskie 0 ?
      printf("Funkcja linjowa, Nie licze\n");
    }
    else{
      SCALAR delta;  // zakres widoczności nazwy - powiązanie z czasem życia  
      delta = b*b - 4*a*c; // czy delta = b*b (w skończonej precyzji)?
      if(delta<0){
	printf("Dwa pierwiastki zespolone - nie umiem obliczyć\n");
      } else if (delta == 0){
	printf("Jeden pierwiastek rzeczywisty: x = %20.15lf\n", -b/(2*a) );
	// ile cyfr znaczacych daje dzielenie dla float i dla double?
	// kiedy dzielenie dużej liczby przez małą liczbę da w efekcie śmieci?
	if((a*pow(-b/(2*a),2))+b*(-b/(2*a))+c==0) {
	  printf("pierwiastek jest poprawny\n");
	}
	
      } else {
	SCALAR temp = sqrt(delta);
	printf("Dwa pierwiastki rzeczywiste: x1 = %20.15lf, x2 = %20.15lf\n",
	       (-b-temp)/(2*a), (-b+temp)/(2*a) );
	       
	if((a*pow((-b-temp)/(2*a), 2))+b*((-b-temp)/(2*a))+c==0) {
	  printf("pierwiastek jest poprawny\n");
	}
	else if((a*pow((-b+temp)/(2*a),2))+b*((-b+temp)/(2*a))+c==0) {
	  printf("pierwiastek jest poprawny\n");
	}
      }  
    } // znaczenie wcięć i nawiasów klamrowych dla zwiekszenia czytelności kodu
  }

  return(0);
}

// Lab 
// Uzupełnienie programu o obsługę wszystkich przypadków liczbowych danych wejściowych
// Różne przypadki kontraktu - uwzględniające lub nie skończoną precyzję
