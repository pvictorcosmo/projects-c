#include<stdio.h>
#define tam 10
void ordenarb(int num[]){
    int i,j,aux;
    for(i=0;i<tam;i++){
      for(j=0;j<tam;j++){
        if(num[j]>num[j+1]){
            aux=num[j];
            num[j]=num[j+1];
            num[j+1]=aux;
        }
      }    
    }
};

int main(){
  int num[tam],i;
  for(i=0;i<tam;i++){
    printf("Digite um numero:");
    scanf("%d", &num[i]);
  }
  ordenarb(num);

  for(i=0;i<tam;i++){
    printf("O numero [%d] eh:%d\n",i,num[i]);
  }


}