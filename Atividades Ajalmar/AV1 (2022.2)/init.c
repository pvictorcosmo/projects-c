#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "init.h"
#include "pessoa.h"
#include "pet.h"
void start(){
  for (i= 0; i < tam; i++) {
    livres[i] = 1;
    for(j=0;j<pets;j++){
      livres_pet[i][j]=1;
    }
    /*Nesse laço eu to preenchendo todos os valores de livres com 0, pra quando houver 
    alguma coisa pra preencher o indice, mudar pra 1*/
  }
  for(i=0;i<tam;i++){
    cod[i]= 100+rand()%900;
  }
  for(i=0;i<=120;i++){
    codpet[i]=100+rand()%900;
  }
}
