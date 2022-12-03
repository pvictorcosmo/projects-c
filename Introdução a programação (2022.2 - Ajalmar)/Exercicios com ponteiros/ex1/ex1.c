#include<stdio.h>
#include<stdlib.h>
#define tam 5

int main(){
  int i,*pnum,*soma,*aux;
  pnum=malloc(sizeof(int)*tam);
  soma=malloc(sizeof(int));
  aux=malloc(sizeof(int));
  *soma=0;

  for(i=0;i<tam;i++){
    printf("Digite um numero:");
    scanf("%d", aux);
    pnum[i]=*aux;
    *soma=*soma+*pnum;
  }

  printf("Soma eh igual a:%d",*soma);
  free(pnum);
  free(soma);
}