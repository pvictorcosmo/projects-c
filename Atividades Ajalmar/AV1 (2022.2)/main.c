#include "init.h"
#include "pessoa.h"
#include "pet.h"

int main() {

  
  srand(time(NULL));

  start();

  printf("Seja bem vindo!\nPara acessar cadastro precisamos dos dados\n");
  printf("Digite 'n' para adicionar um novo usuario!:");
  scanf("%s",&init);
  system("cls");
if(init=='n'){
  do{
    insert_user_ui();
    insert_pets_ui();    
    list_clients_ui();
  }while(resp=='s');
  system("cls");
  do{
    clients_ui();
    funcs_clients_ui();
  }while(resp!='n' || resp!='s');
  
  /*O código vai funcionar enquanto a resposta for s, a nao ser que a pessoa ja tenha um cadastro, se a resposta for n, o código vai mostrar todos listados*/
  
}else if(init=='c'){
}
  
return 0;
system("pause");
}

