#include<stdio.h>
#define tam 9

void ordenar(int vet[], int n){ 
  int i,j,menor,aux;
  for(i=0;i<n;i++){
    menor=i;
    for(j=i+1;j<tam;j++){
      if(vet[menor]>vet[j]){
        menor=j;
      }

    }
    if(i!=menor){
        aux=vet[i];
        vet[i]=vet[menor];
        vet[menor]=aux;
    }

  }

}
int main(){
  int i,n;
  int num[tam];
  for(i=0;i<tam;i++){
    printf("Digite o numero:");
    scanf("%d",&num[i]);
  }

  printf("Qual o n de menor valor?:");
  scanf("%d", &n); 
  ordenar(num,n);
  for(i=0;i<n;i++){
    printf("Aqui esta o [%d] menor:%d\n", i,num[i]);
  }
}