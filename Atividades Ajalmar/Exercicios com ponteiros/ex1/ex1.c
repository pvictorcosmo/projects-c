#include<stdio.h>
#include<stdlib.h>
#define tam 5
int i;
void somar(int *pnum,int *soma){   
  *soma=0;
  for(i=0;i<tam;i++){
    *pnum=i;
    *soma=*soma+*pnum;
  }


}

int main(){
  int *pnum;
  int *soma;
  pnum=malloc(sizeof(char)*tam);
  soma=malloc(sizeof(char));

  for(i=0;i<tam;i++){
    printf("Digite um numero:");
    scanf("%d", pnum);
  }
  
  somar(pnum,soma);

  printf("Soma eh igual a:%d",*soma);
  free(pnum);
  free(soma);
}