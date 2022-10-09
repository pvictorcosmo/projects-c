#include "init.h"
#include "pessoa.h"
#include "pet.h"

void insert_clients(char rg[],char cpf[],char nome[],char ends[],char datanascs[],char fone[],char rends[]){
  static int index=-1;
  for (i= 0; i < tam; i++) {
    if(livres[i] == 1){
      index = i;
      break;
    }
  }

  printf("index=%i",index);

  nomes[index]=malloc(sizeof(char)*255);
  rgs[index]=malloc(sizeof(char)*12);
  end[index]=malloc(sizeof(char)*255);
  rend[index]=malloc(sizeof(char)*20);
  datanasc[index]=malloc(sizeof(char)*8);
  fones[index]=malloc(sizeof(char)*20);
  cpfs[index]=malloc(sizeof(char)*12);

  strcpy(nomes[index], nome);
  strcpy(rgs[index], rg);
  strcpy(end[index], ends);
  strcpy(rend[index], rends);
  strcpy(datanasc[index], datanascs);
  strcpy(fones[index], fone);                 
  strcpy(cpfs[index],cpf);
  printf("nome=%s", nomes[0]);
  printf("index=%i",index);
  printf("aux=%i", aux);
 if(strlen(cpf)==0 || strlen(nome)==0 || strlen(datanascs)==0){
    aux=1;
      //Esse bloco testa e diz se as informações estiverem erradas
  }
  //Perguntando as informações do usuário

  livres[index] = 0;
  printf("livres=%i",livres[0]);

  free(datanascs);
  free(rg);
  free(cpf);
  free(nome);
  free(ends);
  free(fone);
  free(rends);
  
}

void list_clients_ui(){ 
  for(i=0;i<tam;i++){  
    if(livres[i] == 0){
      printf("[0]=%i [1]=%i", livres[0],livres[1]);
        system("cls");
        
        printf("\nSeu cadastro foi feito com sucesso!\n");
        printf("Deseja fazer outro cadastro?(s/n):");
        scanf("%s", &resp);
          //Fazendo cadastro da pessoa e printando as informações na tela
          /*Perceber que essa informação só vai ser verdadeira se o numero de caracteres de cpf, nome e data de nascimento forem maior que 0*/
      }
    }
  }
void clients_ui(){
  printf("aux=%i",aux);
  printf("iivres=%i",livres[0]);
  printf("CADASTROS ##################\n\n");
  for(i=0;i<tam;i++){
    if(livres[i]==0){
      printf("######### DADOS DO CLIENTE ##########");
      printf("\nCodigo: [%i]\nRG:%s\nCPF:%s\nNome:%s\nEndereco:%s\nData de nascimento:%s\nRendimenNo:%s\nTelefone:%s\n",cod[i], rgs[i],cpfs[i], nomes[i], end[i],datanasc[i],rend[i],fones[i]);
      
      for(j=0;j<pets;j++){
        if(livres_pet[i][j]==0){  
          printf("######### DADOS DO SEU PET ##########");
          printf("\nCodigo: %i\nNome: %s\nTipo: %s\nData de nascimento:%s\n",codpet[i][j],nome_pet[i][j],type_pet[i][j],datanascpet[i][j]);
          space();
        }
      }
    }
  }
}

/*void order_alf_user(){

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
}*/
int delete_user(int codtest){

  for(i=0;i<tam;i++){
    if(livres[i]==0){
      if(codtest==cod[i]){
        return 1;
        livres[i]=1;
        break;  
      }
    }
  }

}

void alt_user(char rg[],char cpf[],char nome[],char ends[],char datanascs[],char fone[],char rends[]){

  nomes[I]=malloc(sizeof(char)*255);
  rgs[I]=malloc(sizeof(char)*12);
  end[I]=malloc(sizeof(char)*255);
  rend[I]=malloc(sizeof(char)*20);
  datanasc[I]=malloc(sizeof(char)*8);
  fones[I]=malloc(sizeof(char)*20);
  cpfs[I]=malloc(sizeof(char)*12);

  strcpy(nomes[I], nome);
  strcpy(rgs[I], rg);
  strcpy(end[I], ends);
  strcpy(rend[I], rends);
  strcpy(datanasc[I], datanascs);
  strcpy(fones[I], fone);                 
  strcpy(cpfs[I],cpf);
  printf("nome=%s", nomes[0]);
  printf("aux=%i", aux);
 if(strlen(cpf)==0 || strlen(nome)==0 || strlen(datanascs)==0){
    aux=1;
      //Esse bloco testa e diz se as informações estiverem erradas
  }
  //Perguntando as informações do usuário

  livres[I] = 0;
  printf("livres=%i",livres[0]);

  free(datanascs);
  free(rg);
  free(cpf);
  free(nome);
  free(ends);
  free(fone);
  free(rends);
  

}

void alt_user_ui(){
  aux=0;

  char *rg=malloc(sizeof(char)*12);
  char *cpf=malloc(sizeof(char)*12);
  char *nome=malloc(sizeof(char)*255);
  char *ends=malloc(sizeof(char)*255);
  char *datanascs=malloc(sizeof(char)*9);
  char *fone=malloc(sizeof(char)*20);
  char *rends=malloc(sizeof(char)*20);
   
  printf("Qual seu RG?:");
  fflush(stdin);
  fgets(rg,12,stdin);
  printf("Qual seu CPF?:");
  fflush(stdin);
  fgets(cpf,12,stdin);
  printf("Qual seu Nome?:");
  fflush(stdin);
  fgets(nome,255,stdin);
  printf("Qual seu Endereco?:");
  fflush(stdin);
  fgets(ends,255,stdin);
  printf("Qual sua data de nascimento?:");
  fgets(datanascs,9,stdin);
  printf("Qual seu telefone?:");
  fflush(stdin);
  fgets(fone,20,stdin);
  printf("Qual seu rendimento?:");
  fflush(stdin);
  fgets(rends,20,stdin);
    //fgets é pra pegar as strings com espaço, o fflush serve pra tirar todo o lixo da string
  datanascs[strcspn(datanascs,"\n")]=0;
  rends[strcspn(rends,"\n")]=0;
  ends[strcspn(ends,"\n")]=0;
  rg[strcspn(rg,"\n")]=0;
  cpf[strcspn(cpf,"\n")]=0;
  nome[strcspn(nome,"\n")]=0;
  fone[strcspn(fone,"\n")]=0; 
    //Esses comandos são para o comando fgets ignorar o \n, pois ele normalmente adiciona um \n na string, mas a gente quer que elas não tenham tanto espaço

  alt_user(rg,cpf,nome,ends,datanascs,fone,rends); 

  J=0;

}
void list_client(int codtest){
  for(i=0;i<tam;i++){
    if(livres[i]==0){
      if(cod[i]==codtest){
        printf("Estes sao dos dados do cliente [%i]:\n ", cod[i]);
        printf("######### DADOS DO CLIENTE ##########");
        printf("\nCodigo: [%i]\nRG:%s\nCPF:%s\nNome:%s\nEndereco:%s\n Data de nascimento:%s\nRendimenNo:%s\nTelefone:%s\n",cod[i], rgs[i],cpfs[i], nomes[i], end[i],datanasc[i],rend[i],fones[i]);
        space();
      }
    }
  }
}

void funcs_clients_ui(){
    char type_pets[25];
    char nome_pets[255];
    char datanascpets[8];
    int i;
    char type_test[25];
    printf("Funcionalidades do usuario:\n1 - para excluir um usuario\n2 - para alterar um usuario\n3 - para buscar um cadastro pelo codigo\n4 - Para mostrar cadastros que tenham um tipo especifico de pet\n5 - para listar os cadastros em ordem alfabetica\n");
    space();
    printf("Funcionalidades do pet:\n6 - para excluir um pet\n7 - para alterar um pet\n8 - para adicionar um novo pet\n9 - para mostrar cadastros com base no codigo do pet\n10 - para mostrar os pets em ordem alfabetica\n");
    scanf("%i",&resp3);

    switch(resp3){
      case 1:
        printf("Digite o codigo do usuario que deseja excluir:");    
        scanf("%i", &codtest);
        if(delete_user(codtest)==1){
          printf("Usuário excluido com sucesso");
        }
      break;

      case 2:
        printf("Digite o codigo do usuario que deseja alterar:");    
        scanf("%i", &codtest);
        for(i=0;i<tam;i++){
          if(livres[i]==0){
            if(cod[i]==codtest){
              livres[i]=1;
              I=i;
              alt_user_ui();
            }
          }          
        }
      break;

      case 3:
        printf("Digite o codigo do usuario acessar:");    
        scanf("%i", &codtest);
        list_client(codtest);
      break;

      case 4:
        printf("Digite o tipo pet para acessar:");    
        scanf("%s", &type_test);
        test_type(type_test);
      break;  

      case 6:
        printf("Digite o codigo do usuario ou do pet que deseja excluir:");    
        scanf("%i", &codtest);
        delete_pet(codtest);
      break;  

    }
      printf("\nDeseja mostrar todos os cadastros?:");
 
    scanf("%s", &resp);
    /*
    if(resp3==5){
      order_alf_user();
    }
    if(resp3==6){
    printf("Digite o codigo do usuario ou do pet que deseja excluir:");    
    scanf("%i", &codtest);
    
        }
      }      
    }  
  }
  if(resp3==7){
    printf("Digite o codigo do pet que deseja alterar:");    
    scanf("%i", &codtest);
    for(i=0;i<tam;i++){
      for(j=0;j<pets;j++){
        if(livres_pet[i][j]==0){
          if(codpet[i][j]==codtest){
            livres_pet[i][j]=1;
            alt_insert_pets();
          }
        }
      }   
    }
  }
  if(resp3==8){
    printf("Digite o codigo do usuario que deseja adicionar um novo pet:");    
    scanf("%i", &codtest);
    for(i=0;i<tam;i++){
      if(cod[i]==codtest){
        alt_insert_pets();
      }    
    }
  }
  if(resp3==9){
    printf("Digite o codigo do pet que deseja mostrar o cadastro:");    
    scanf("%i", &codtest);
    for(i=0;i<tam;i++){
      for(j=0;j<pets;j++){
        if(codtest==codpet[i][j]){
          printf("Estes sao dos dados do pet [%i]:\n ", codpet[i][j]);
          printf("  DADOS DO CLIENTE:\ncodigo: %i\nRG:%s\nCPF:%s\nnome:%s\nendereco:%s\nSua data de nascimento:%s\nrendimento:%s\ntelefone:%s\n",cod[i], rgs[i],cpfs[i], nomes[i], end[i],datanasc[i],rend[i],fones[i]);
          printf("   DADOS DO SEU PET:\nCodigo: %i\nNome: %s\nTipo: %s\nData de nascimento:%s\n",codpet[i][j],nome_pet[i][j],type_pet[i][j],datanascpet[i][j]);
          break;
        }
      }
    }
  }
  if(resp3==10){
    
    if(livres_pet==0){
    order_alf_pets();
    }

  }*/


    
}


void insert_user_ui(){
  aux=0;
  char *rg=malloc(sizeof(char)*12);
  char *cpf=malloc(sizeof(char)*12);
  char *nome=malloc(sizeof(char)*255);
  char *ends=malloc(sizeof(char)*255);
  char *datanascs=malloc(sizeof(char)*9);
  char *fone=malloc(sizeof(char)*20);
  char *rends=malloc(sizeof(char)*20);
   
  printf("Qual seu RG?:");
  fflush(stdin);
  fgets(rg,12,stdin);
  printf("Qual seu CPF?:");
  fflush(stdin);
  fgets(cpf,12,stdin);
  printf("Qual seu Nome?:");
  fflush(stdin);
  fgets(nome,255,stdin);
  printf("Qual seu Endereco?:");
  fflush(stdin);
  fgets(ends,255,stdin);
  printf("Qual sua data de nascimento?:");
  fgets(datanascs,9,stdin);
  printf("Qual seu telefone?:");
  fflush(stdin);
  fgets(fone,20,stdin);
  printf("Qual seu rendimento?:");
  fflush(stdin);
  fgets(rends,20,stdin);
    //fgets é pra pegar as strings com espaço, o fflush serve pra tirar todo o lixo da string
  datanascs[strcspn(datanascs,"\n")]=0;
  rends[strcspn(rends,"\n")]=0;
  ends[strcspn(ends,"\n")]=0;
  rg[strcspn(rg,"\n")]=0;
  cpf[strcspn(cpf,"\n")]=0;
  nome[strcspn(nome,"\n")]=0;
  fone[strcspn(fone,"\n")]=0; 
    //Esses comandos são para o comando fgets ignorar o \n, pois ele normalmente adiciona um \n na string, mas a gente quer que elas não tenham tanto espaço

  insert_clients(rg,cpf,nome,ends,datanascs,fone,rends); 

  J=0;
}



