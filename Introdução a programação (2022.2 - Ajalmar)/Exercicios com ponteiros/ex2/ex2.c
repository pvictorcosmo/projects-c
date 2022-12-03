#include<stdio.h>
#include<stdlib.h>
#define tam 5
int i,j;
void ordenar(int *pnum){
  int *aux;
  int *menor;
  menor=malloc(sizeof(int));
  aux=malloc(sizeof(int));
  for(i=0;i<tam;i++){
    *menor=i;
    for(j=i+1;j<tam;j++){
      if(pnum[*menor]>pnum[j]){
        *menor=j;
      }
      if(i!=*menor){
        *aux=pnum[i];
        pnum[i]=pnum[*menor];
        pnum[*menor]=*aux;
        }
      }    
    }
    free(aux);
    free(menor);   

}

int main(){
  int *pnum;
  int *soma;
  int *menor;
  int *aux;
  aux=(int*)malloc(sizeof(int));
  pnum=(int*)malloc(sizeof(int)*tam);
  soma=(int*)malloc(sizeof(int));
  *soma=0;

  for (i = 0; i < tam; i++)
  {
    printf("Digite um numero:");
    scanf("%d",aux);
    pnum[i]=*aux;
    *soma=*soma+*aux;
    printf("%d\n",*soma);
  }
  free(aux);
  
  printf("Valores antes da ordenação:\n");
  for (i = 0; i < tam; i++)
  {
    printf("O numero [%d] era:%d\n",i,pnum[i]);
  }
  
  ordenar(pnum);

  printf("Valores depois da ordenação:\n");
  for (i = 0; i < tam; i++)
  {
    printf("O numero [%d] eh:%d\n",i,pnum[i]);
  }

  printf("Valor da soma:%d",*soma);

}