#include<stdio.h>
#include<stdlib.h>
int main(int argc,char*argv[]){
    for (int i = 1; atoi( argv[i] ) >= 1 ; i++){
      static int b = 1;
        for (int fat=1; atoi(argv[i]) > fat ;fat++){
          b = b * (fat+1);
        }
      printf("Resultado de fatorial de %i = %i\n",atoi(argv[i]),b);
      b = 1;

    }
}