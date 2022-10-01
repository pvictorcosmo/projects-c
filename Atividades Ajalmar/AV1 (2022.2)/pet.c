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

void insert_pets(){
  char type_pets[25];
  char nome_pets[255];
  char datanascpets[8];

  static int indextam = -1;
  static int indexpet = -1;
  for (i= 0; i < tam; i++){
    for(j=0;j<pets;j++){
      if(livres_pet[i][j]==1){
      indextam= i;
      indexpet= j;
      break;
      }
    }
    break;
  }
  printf("indextam=%i\nindexpet=%i", indextam,indexpet);
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
  strcpy(datanascpet[indextam][indexpet], datanascpets);
  strcpy(type_pet[indextam][indexpet], type_pets);
  strcpy(nome_pet[indextam][indexpet], nome_pets);
  livres_pet[i][j]=0;
}
