#include<stdio.h>
#include<stdlib.h>
int main(int argc,char*argv[]){
  for (int i = 1; atoi( argv[i] ) >= 1 ; i++){
    static int b = 1;
      //Se o argumento colocado na compilação for maior ou igual a 1, ele vai executar e criar a variavel estatica
  for (int fat=1; atoi(argv[i]) > fat ;fat++){
    b = b * (fat+1);
      //Enquanto o numero de argv[] for menor que fat ele vai rodar este código, onde fat aumenta 1 numero a cada vez, ou seja, ele vai fazer a multiplicação de cada numero até chegar no numero de argv[]
  }
    printf("Resultado de fatorial de %i = %i\n",atoi(argv[i]),b);
      b = 1;
        //Print do resultado final dentro do for para printar quantos argumentos tiver

  }
}