#include<stdio.h>
#include<stdlib.h>
int n1=0,ci=0,cp=0,y,pr=0;
int primo(int x){
  int div=0;
  for(int i=1;i<=x;i++){
    if(x%i==0){
      div++;
    }
  }
  if(div==2){
    return 1;
  }
    //Função que testa se o valor é primo, ou seja, testa todos os divisores daquele numero, se houver apenas 2 ele retorna o valor booleano 1
    
}
int pi(int x){
  if(x%2==0){
    return 1;
  }
  else{
    return 0;
  }
    //Testa se é par e retorna 1 ou 0
}
int main(){
  printf("Qual seu numero?:");
  scanf("%i", &n1);
  while(n1){
    y=n1%10;
    printf("Valor:%i\n", y);
    if(primo(y)==1){
      pr++;
    }
    if(pi(y)==1){
      cp++;
    }
    if(pi(y)==0){
      ci++;
    }
    n1=n1/10;
    //Testa todas as possibilidades e coloca em suas respectivas variaveis de count
  }
  printf("O numeros de primos sao:%i\n", pr);
  printf("O numeros de pares sao:%i\n",cp);
  printf("O numeros de impares sao:%i\n",ci);
}