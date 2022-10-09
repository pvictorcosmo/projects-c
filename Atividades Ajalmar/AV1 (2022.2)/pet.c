#include "init.h"
#include "pet.h"
#include "pessoa.h"

void list_pets(){
  for(i=0;i<tam;i++){
    for(j=0;j<pets;j++){
      if(livres_pet[i][j]==0){
        printf("   DADOS DO SEU PET:\nCodigo: %i\nNome: %s\nTipo: %s\nData de nascimento:%s\n",codpet[i][j],nome_pet[i][j],type_pet[i][j],datanascpet[i][j]);

      }
    }
  }
}


void insert_pets(char nome_pets[],char type_pets[],char datanascpets[]){

  static int indextam = -1;
  static int indexpet = -1;
  for (i= 0; i < tam; i++){
    if(livres_pet[i][0]==1){
      indextam = i;
      break;
    }
  }

  strcpy(datanascpet[indextam][0], datanascpets);
  strcpy(type_pet[indextam][0], type_pets);
  strcpy(nome_pet[indextam][0], nome_pets);
  livres_pet[i][0]=0;
  printf("[0pet]=%i [1pet]=%i [0][1]=%i", livres_pet[0][0],livres_pet[1][0],livres_pet[0][1]);

}

void insert_pets_ui(){

  char *type_pets=malloc(sizeof(char)*20);
  char *nome_pets=malloc(sizeof(char)*255);
  char *datanascpets=malloc(sizeof(char)*9);

  printf("Ok, agora vamos perguntar sobre o seu pet:\n");
  printf("Qual o nome do seu pet?:");
  fflush(stdin);
  fgets(nome_pets,255,stdin);
  printf("Qual o tipo do seu pet?:");
  fflush(stdin);
  fgets(type_pets,25,stdin);
  printf("Qual a data de nascimento do seu pet?:");
  fflush(stdin);
  fgets(datanascpets,8,stdin);
    //fgets é pra pegar as strings com espaço, o fflush serve pra tirar todo o lixo da string
  datanascpets[strcspn(datanascpets,"\n")]=0;
  nome_pets[strcspn(nome_pets,"\n")]=0;
  type_pets[strcspn(type_pets,"\n")]=0;
    //Esses comandos são para o comando fgets ignorar o \n, pois ele normalmente adiciona um \n na string, mas a gente quer que elas não tenham tanto espaço

  insert_pets(nome_pets,type_pets,datanascpets);  

}

void delete_pet(int codtest){
  for(i=0;i<tam;i++){
    for(j=0;j<pets;j++){
      if(livres_pet[i][j]==0){
        if(codtest==codpet[i][j]) {
          livres_pet[i][j]=1;
          printf("Pet excluido com sucesso!");
          break;    
        }
      }
    }
  }
}

void test_type(char type_test[]){
  for(i=0;i<tam;i++){
    for(j=0;j<pets;j++){
      if(livres_pet[i][j]==0){
        if(strcmp(type_test,type_pet[i][j])==0){
          printf("######### DADOS DO CLIENTE ##########");
          printf("\nCodigo: [%i]\nRG:%s\nCPF:%s\nNome:%s\nEndereco:%s\nData de nascimento:%s\nRendimenNo:%s\nTelefone:%s\n",cod[i], rgs[i],cpfs[i], nomes[i], end[i],datanasc[i],rend[i],fones[i]);
          printf("######### DADOS DO SEU PET ##########");
          printf("\nCodigo: %i\nNome: %s\nTipo: %s\nData de nascimento:%s\n",codpet[i][j],nome_pet[i][j],type_pet[i][j],datanascpet[i][j]);
          space();
            //Testa o tipo do pet pra mostrar eles depois
        }
      }
    }
  }
}
/*
void alt_insert_pets(){


  static int indextam = -1;
  static int indexpet = -1;
  for (i= 0; i < tam; i++){
    for(j=0;j<pets;j++){
      if(livres_pet[i][j]==1){
      indextam = i;
      indexpet=j;
      break;
      }
    }
    break;
  }

  strcpy(datanascpet[indextam][indexpet], datanascpets);
  strcpy(type_pet[indextam][indexpet], type_pets);
  strcpy(nome_pet[indextam][indexpet], nome_pets);
  livres_pet[i][j]=0;
  printf("[0pet]=%i [1pet]=%i [0][1]=%i", livres_pet[0][0],livres_pet[1][0],livres_pet[0][1]);

}

void order_alf_pets(){

  for (i = 1; i < tam; i++) { /* 3 = qtde de palavras 
    for (j = 1; j < tam; j++) {
      // verifica se tem que ser depois, se for troca de posição
      if (strcmp(nomes[j - 1], nomes[j]) > 0) {
         strcpy(aux_user, nomes[j - 1]);
         strcpy(nomes[j - 1], nomes[j]);
         strcpy(nomes[j], aux_user);
      }
    }
  }
for(i=0;i<tam;i++){
  printf("  DADOS DO CLIENTE:\ncodigo: %i\nRG:%s\nCPF:%s\nnome:%s\nendereco:%s\nSua data de nascimento:%s\nrendimento:%s\ntelefone:%s\n",cod[i], rgs[i],cpfs[i], nomes[i], end[i],datanasc[i],rend[i],fones[i]);
  space();
  list_pets();

}
}
*/