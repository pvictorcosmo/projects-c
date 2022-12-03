#include<stdio.h>
#include<stdlib.h>
float B;
float neg,pos;
float med= 0;
float medn= 0;
float medp= 0;
int main (int argc, char * argv []){
  for(int i=1;i<=10;i++){
    static float p= 0.0, n=0.0;
    med = atoi ( argv[i] ) + ( med );
    if (atoi (argv[i]) > 0) {
      p=p+1.0;
      medp=atoi(argv[i])+(medp);
    }
    else if (atoi (argv[i]) < 0) {
      n = n+1.0;
      medn=atoi(argv[i])+(medn);
    }
      //Esse laço procura argumentos ate 10, depois testa pra ver se eles são pares ou impares enquanto coloca os valores deles pra media geral, dependendo do tipo (par ou ímpar) eles tem uma variavel de count específica pra eles
    pos = p;
    neg = n;
  }  
  med=med/10.0;
  medp=medp/pos;
  medn=medn/neg;   
    //faz a media dos valores negativos, positivos e geral
  printf ("media geral: %.2f\n", med );
  printf ("media dos valores positivos: %.2f\n", medp );
  printf ("media dos valores negativos: %.2f\n", medn );
  printf ("Tem %.1f numeros positivos\n", pos );
  printf ("tem %.1f numeros negativos\n", neg );
  pos= ( pos/10 ) *100;
  neg= ( neg/10 ) *100;
    //Faz os percentuais dos valores positivos e negativos
  printf ("Tem %.1f%% numeros positivos\n", pos );
  printf ("tem %.1f%% numeros negativos", neg );
 
}