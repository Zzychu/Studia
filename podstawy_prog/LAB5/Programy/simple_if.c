#include <stdio.h>

void main(void)
{
  char c;
  for(;;){
    printf("\nWprowadź cyfrę od 1 do 5: \n");  
    scanf("%c",&c);
    if(c=='1'){
      printf("1\n");
    }
    else if(c=='2'){
      printf("2\n");
    }
    else if(c=='3'){
      printf("3\n");
    }
    else if(c=='4'){
      printf("4\n");
    }
    else if(c=='5'){
      printf("5\n");
    }
    else if(c=='0'){
      printf("koniec\n");
      break;
    }
    else {
      printf("zly znak\n");
    }
    
  }

}
