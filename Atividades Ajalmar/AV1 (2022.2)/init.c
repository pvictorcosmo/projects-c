
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
    testcode=cod[i];
    for(j=0;j<tam;j++){
    if(testcode==cod[j]){
    cod[j]= 100+rand()%900;

    }
    }

  }
  for(i=0;i<tam;i++){
    for(j=0;j<pets;j++){
    codpet[i][j]=100+rand()%900;
    testcode=codpet[i][j];
    for(g=0;g<tam;g++){
        for(h=0;h<pets;h++){
            if(testcode==codpet[g][h]){
                codpet[g][h]=100+rand()%900;
            }
        }
    }
    }
  }

}

void space(){
  printf("##################################\n");
}

