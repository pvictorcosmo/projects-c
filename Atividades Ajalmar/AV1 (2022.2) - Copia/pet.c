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

void list_pets_index(int index){
    for(j=0;j<pets;j++){
      if(livres_pet[index][j]==0){
        printf("   DADOS DO SEU PET:\nCodigo: %i\nNome: %s\nTipo: %s\nData de nascimento:%s\n",codpet[index][j],nome_pet[index][j],type_pet[index][j],datanascpet[i][j]);

      }
    }
  }


void insert_pets(char nome_pets[],char type_pets[],char datanascpets[]){
  
  static int indextam = -1;
  for ( i= 0; i < tam; i++ ){
      if(livres_pet[i][0]==1){
        indextam=i;
        break;
      }
  }
  type_pet[indextam][0]=malloc(sizeof(char)*20);
  datanascpet[indextam][0]=malloc(sizeof(char)*9);
  
  strcpy(datanascpet[indextam][0], datanascpets);
  strcpy(type_pet[indextam][0], type_pets);
  strcpy(nome_pet[indextam][0], nome_pets);

  livres_pet[indextam][0]=0;
  
  free(type_pets);
  free(datanascpets);
  free(nome_pets);
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
  fgets(datanascpets,9,stdin);
    //fgets é pra pegar as strings com espaço, o fflush serve pra tirar todo o lixo da string
  datanascpets[strcspn(datanascpets,"\n")]=0;
  nome_pets[strcspn(nome_pets,"\n")]=0;
  type_pets[strcspn(type_pets,"\n")]=0;
    //Esses comandos são para o comando fgets ignorar o \n, pois ele normalmente adiciona um \n na string, mas a gente quer que elas não tenham tanto espaço

  insert_pets(nome_pets,type_pets,datanascpets);  
  printf("pets1=%i pets12=%i pets2=%i",livres_pet[0][0],livres_pet[0][1],livres_pet[1][0]);

}

void insert_new_pets(char nome_pets[],char type_pets[],char datanascpets[]){
  static int indexpet = -1;
    for(j=0;j<pets;j++){
      if(livres_pet[I][j]==1){
        indexpet=j;
        break;
      }
    }
  type_pet[I][indexpet]=malloc(sizeof(char)*20);
  datanascpet[I][indexpet]=malloc(sizeof(char)*9);
  
  strcpy(datanascpet[I][indexpet], datanascpets);
  strcpy(type_pet[I][indexpet], type_pets);
  strcpy(nome_pet[I][indexpet], nome_pets);

  livres_pet[I][indexpet]=0;
  
  free(type_pets);
  free(datanascpets);
  free(nome_pets);
}

void insert_new_pets_ui(){

  char *type_pets=malloc(sizeof(char)*20);
  char *nome_pets=malloc(sizeof(char)*255);
  char *datanascpets=malloc(sizeof(char)*9);

  printf("Digite os dados do seu novo pet:\n");
  printf("Qual o nome do seu pet?:");
  fflush(stdin);
  fgets(nome_pets,255,stdin);
  printf("Qual o tipo do seu pet?:");
  fflush(stdin);
  fgets(type_pets,25,stdin);
  printf("Qual a data de nascimento do seu pet?:");
  fflush(stdin);
  fgets(datanascpets,9,stdin);
    //fgets é pra pegar as strings com espaço, o fflush serve pra tirar todo o lixo da string
  datanascpets[strcspn(datanascpets,"\n")]=0;
  nome_pets[strcspn(nome_pets,"\n")]=0;
  type_pets[strcspn(type_pets,"\n")]=0;
    //Esses comandos são para o comando fgets ignorar o \n, pois ele normalmente adiciona um \n na string, mas a gente quer que elas não tenham tanto espaço
   
  insert_new_pets(nome_pets,type_pets,datanascpets); 
}

void alt_pets(char nome_pets[],char type_pets[],char datanascpets[]){

  datanascpet[I][J]=malloc(sizeof(char)*9);
  type_pet[I][J]=malloc(sizeof(char)*25);
  strcpy(datanascpet[I][J], datanascpets);
  strcpy(type_pet[I][J], type_pets);
  strcpy(nome_pet[I][J], nome_pets);
  livres_pet[I][J]=0;

}

void alt_pets_ui(){

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
  alt_pets(nome_pets,type_pets,datanascpets);
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


void order_alf_pets(){
  
  for(i=0;i<tam;i++){
   char size[255];
   size=nome_pet[i][0];
   for(j=0;j<pets;j++){
    if(strcmp(nome_pet[i][j],size)>0){
      list_pets_index(j);
      size=nome_pet[i][j];
    }
   }

  }

}
  /*int index = 0;
    int all_index[pets];
    char *nome_pets[pets];
    for(int i = 0; i < tam; ++i) {
      for(int j=0;j<pets;++j){
        if(livres_pet[i][j] != -1) {
            nome_pets[index] = Str(nome_pet[i][j]);
            strcpy(nome_pets[index], nome_pet[i][j]);
            all_index[index] = j;
            index++;
        }
      }
    }

    int total = index;
    for(int i = 0; i < total; ++i)
        Upper(nome_pets[i]);

    char size[255];
    while(index--) {
        strcpy(size, "z");
        int size_in = 0;
        int size_inpet=0;

        for(int i = 0; i < total; ++i) {
            if(strcmp(nome_pets[i], size) < 0) {
                strcpy(size, nome_pets[i]);
                size_in = i;
                size_inpet=j;
            }
        }
        strcpy(nome_pets[size_in], "z");
        list_pets_index(all_index[size_in]);
    }

    for(int i = 0; i < total; ++i){
        free(nome_pets[i]);
    }
    }*/



