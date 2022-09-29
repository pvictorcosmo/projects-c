#include "init.h"
#include "pet.h"

void list_pets(){
  for(i=0;i<tam;i++){
    for(j=0;j<pets;j++){
      if(livres_pet[i][j]==0){
        printf("   DADOS DO SEU PET:\nCodigo: %i\nNome: %s\nTipo: %s\nData de nascimento:%s\n",codpet[i],nome_pet[i],type_pet[i],datanascpet[i]);
      }
    }
  }
}

void inserir_pet(){
  char type_pets[25];
  char nome_pets[255];
  char datanascpets[8];

  static int index = -1;
  for (i= 0; i < tam; i++){
    for(j=0;j<pets;j++){
      if(livres_pet[i][j]==1){
      index = i;
      break;
      }
    }
  }
  printf("Qual o nome do seu pet?:");
  scanf("%s", &nome_pets);
  printf("Qual o tipo do seu pet?:");
  scanf("%s", &type_pets);
  printf("Qual a data de nascimento do seu pet?:");
  scanf("%s", &datanascpets);
  strcpy(datanascpet[index], datanascpets);
  strcpy(type_pet[index], type_pets);
  strcpy(nome_pet[index],nome_pets);
  printf("index: %i", index);
  printf("index: %i", index);
  livres_pet[i][j]=0;
  printf("Deseja fazer outro cadastro?(s/n):");
  scanf("%s", &resp);
}

void funcs_pets(){
    int i,codtest;
    char type_test[25];
    printf("Funcionalidades do pet:\nDigite 'p' para excluir um pet\nDigite 'l' para alterar um pet\n");
    scanf("%s",&resp3);
    if(resp3=='p'){
      printf("Digite o codigo do usuario ou do pet que deseja alterar:");    
      scanf("%i", &codtest);
      for(i=0;i<tam;i++){
        for(j=0;j<pets;j++){
          if(livres_pet[i][j]==0){
            if(codtest==codpet[i]) {
              printf("pet excluido com sucesso!");
              livres_pet[i][j]=1;
              break;
            }
          }
        }      
      }  
    }
    if(resp3=='l'){
      printf("Digite o codigo do pet que deseja alterar:");    
      scanf("%i", &codtest);
      for(i=0;i<tam;i++){
        for(j=0;j<pets;j++){
          if(livres_pet[i][j]==0){
            if(codpet[i]==codtest){
              livres_pet[i][j]=1;
              inserir_pet();
            }
          }
        }   
      }
    }

 printf("Deseja mostrar todos os cadastros?:");
 scanf("%s", &resp);
}