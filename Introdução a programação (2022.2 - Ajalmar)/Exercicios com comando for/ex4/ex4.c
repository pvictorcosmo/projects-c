#include<stdio.h>
#include<stdlib.h>
int P1,P2,P3,P4;
int main(int argc, char*argv[]){      
  for(int i=1;i<=20;i++){
    static int p1=0,p2=0,p3=0,p4=0;
    if(atoi(argv[i])>=0 && atoi(argv[i])<=15){
      p1++;
    }
    else if(atoi(argv[i])>=16 && atoi(argv[i])<=30){
      p2++;
    }
    else if(atoi(argv[i])>=31 && atoi(argv[i])<=50){
      p3++;
    }
    else if(atoi(argv[i])>=51 && atoi(argv[i])<=100){
      p4++;
    }
      //Looping que pega os valores de argv[] de 1 por 1
      //Testa os valores, se os valores estiverem dentro dos intervalos ele vai incrementar uma variavel pra cada intervalo
    P1=p1;
    P2=p2;
    P3=p3;
    P4=p4;
  }
  printf("Os numeros no intervalo de [0.15] entre sao:%i\n",P1);
  printf("Os numeros no intervalo de [16,30] entre sao:%i\n",P2);
  printf("Os numeros no intervalo de [31,50] entre sao:%i\n",P3);  
  printf("Os numeros no intervalo de [51,100] entre sao:%i",P4);  
    //Printar os resultados de acordo com o valor de cada variavel
}

