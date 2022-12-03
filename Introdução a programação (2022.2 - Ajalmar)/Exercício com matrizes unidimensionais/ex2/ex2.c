#include<stdio.h>
#define tam 10
int main(){
  int i,I,maior;
  int num[tam];
  for(i=0;i<tam;i++){
    printf("digite o numero:");
    scanf("%d", &num[i]);
  }
  maior=num[0];
  for(i=0;i<tam;i++){
    if(num[i]>maior){
      maior=num[i];
      I=i;
    }
  }
  printf("o maior eh: %d e sua posicao eh [%d]",maior,I);
}