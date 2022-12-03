#include<stdio.h>
#define tam 10
int main(){
  int i,I,menor;
  int num[tam];
  for(i=0;i<tam;i++){
    printf("digite o numero:");
    scanf("%d", &num[i]);
  }
  menor=num[0];
  for(i=0;i<tam;i++){
    if(num[i]<menor){
      menor=num[i];
      I=i;
    }
  }
  printf("o menor eh: %d e sua posicao eh [%d]",menor,I);
}