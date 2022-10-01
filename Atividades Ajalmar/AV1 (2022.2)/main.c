#include<stdio.h>
#include "init.h"
#include "pessoa.h"
#include "pet.h"

int main() {
  srand(time(NULL));

  start();

  printf("Seja bem vindo!\nPara acessar cadastro precisamos dos dados\n");
  printf("Digite 'n' para adicionar um novo usuario!:  [");
  scanf("%s",&init);
  printf("]");

if(init=='n'){
  do{
    insert_clients();
    insert_pets();
    list_clients();
  }while(resp=='s');
  do{
    register_users();
    space();
    list_pets();
    funcs_users_pets();
  }while(resp=='s');
  
  /*O código vai funcionar enquanto a resposta for s, a nao ser que a pessoa ja tenha um cadastro, se a resposta for n, o código vai mostrar todos listados
  */
}else if(init=='c'){
}
  
return 0;
system("pause");
}