#include "init.h"
#include "pessoa.h"
#include "pet.h"


void insert_clients(){
  char  datanascs[8];
  char  rends[20];
  char ends[255];
  char rg[12]={0};
  char cpf[12];
  char nome[255];
  char fone[20];
  static int index = -1;
  for (i= 0; i < tam; i++) {
    if(livres[i] == 1){
    index = i;
    break;
    }
  }

  if(index == -1){
    printf("Não há memória para inserir uma pessoa!\n");
      //Não vai funcionar se não houver espaços em branco
}
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
  printf("\nOk! Agora vou fazer perguntas referentes ao seu pet!\n");
    //fgets é pra pegar as strings com espaço, o fflush serve pra tirar todo o lixo da string
  datanascs[strcspn(datanascs,"\n")]=0;
  rends[strcspn(rends,"\n")]=0;
  ends[strcspn(ends,"\n")]=0;
  rg[strcspn(rg,"\n")]=0;
  cpf[strcspn(cpf,"\n")]=0;
  nome[strcspn(nome,"\n")]=0;
  fone[strcspn(fone,"\n")]=0;
    //Esses comandos são para o comando fgets ignorar o \n, pois ele normalmente adiciona um \n na string, mas a gente quer que elas não tenham tanto espaço
  strcpy(nomes[index], nome);
  strcpy(rgs[index], rg);
  strcpy(end[index], ends);
  strcpy(rend[index], rends);
  strcpy(datanasc[index], datanascs);
  strcpy(fones[index], fone);                 
  strcpy(cpfs[index],cpf);
  if(strlen(cpf)!=11 || strlen(nome)==0 || strlen(datanascs)!=8){
    printf("\nAs suas informacoes estavam incorretas, por favor, digite novamente\n");
      //Esse bloco testa e diz se as informações estiverem erradas
        }
  //Perguntando as informações do usuário
  for(j=0;j<tam;j++){
    if(strcmp(cpf,cpftest[j])==0){
      printf("\nVoce ja tem um cadastro aqui, Esses sao os  dados:\n");
      printf("   DADOS DO CLIENTE:\nCodigo: %i\nRG:%s\nCPF:%s\nNome:%s\nEndereco:%s\nSua data de nascimento:%s\nRendimento:%s\nTelefone:%s\n",cod[j], rg,cpf, nome, ends,datanascs,rend,fone);
      list_pets();
        //Este laço testa os valores pra ver se ja tem algum cadastro    
    } 
  }
  livres[index] = 0;
  strcpy(cpftest[index],cpf);

}

void list_clients(){ 
  for(i=0;i<tam;i++){  
    if(livres[i] == 0){
      printf("[0]=%i [1]=%i", livres[0],livres[1]);
      if(strlen(cpfs[i])==11 && strlen(nomes[i])!=0 && strlen(datanasc[i])==8){  
        system("cls");
        printf("\nSeu cadastro foi feito com sucesso!\n");
        printf("Deseja fazer outro cadastro?(s/n):");
        scanf("%s", &resp);
          //Fazendo cadastro da pessoa e printando as informações na tela
          /*Perceber que essa informação só vai ser verdadeira se o numero de caracteres de cpf, nome e data de nascimento forem maior que 0*/
      }
    }
  }
  
}
void clients(){
    for(i=0;i<tam;i++){
      if(livres[i]==0){
        printf("   DADOS DO CLIENTE:\ncodigo: [%i]\nRG:%s\nCPF:%s\nnome:%s\nendereco:%s\nSua data de nascimento:%s\nrendimento:%s\ntelefone:%s\n",cod[i], rgs[i],cpfs[i], nomes[i], end[i],datanasc[i],rend[i],fones[i]);
        space();
      }
      for(j=0;j<pets;j++){
      if(livres_pet[i][j]==0){  
        printf("   DADOS DO SEU PET:\nCodigo: %i\nNome: %s\nTipo: %s\nData de nascimento:%s\n",codpet[i][j],nome_pet[i][j],type_pet[i][j],datanascpet[i][j]);
        space();
      }
      }
      }
    }

void register_users(){
  printf("Voce tem tais cadastros:\n");
  for(i=0;i<tam;i++){
    if(livres[i]==0){
      clients();

    }
  }
}
  

void order_alf_user(){

for (i = 1; i < tam; i++) { /* 3 = qtde de palavras */
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

void funcs_users_pets(){
    char type_pets[25];
    char nome_pets[255];
    char datanascpets[8];
    int i,codtest;
    char type_test[25];
    printf("Funcionalidades do usuario:\n1 - para excluir um usuario\n2 - para alterar um usuario\n3 - para buscar um cadastro pelo codigo\n4 - para mostrar pessoas que tenham um tipo especifico de pet\n5 - para listar os cadastros em ordem alfabetica\n");
    space();
    printf("Funcionalidades do pet:\n6 - para excluir um pet\n7 - para alterar um pet\n8 - para adicionar um novo pet\n9 - para mostrar cadastros com base no codigo do pet\n10 - para mostrar os pets em ordem alfabetica\n");
    scanf("%i",&resp3);

    if(resp3==1){
      printf("Digite o codigo do usuario que deseja excluir:");    
      scanf("%i", &codtest);   
      for(i=0;i<tam;i++){
        if(livres[i]==0){
          if(codtest==cod[i]){
            printf("Usuario excluido com sucesso!");
            livres[i]=1;
            break;  
          }
        }
      }
    }
    if(resp3==2){
      printf("Digite o codigo do usuario que deseja alterar:");    
      scanf("%i", &codtest);
      for(i=0;i<tam;i++){
        if(livres[i]==0){
          if(cod[i]==codtest){
            livres[i]=1;
            insert_clients();
          }
        }          
      }
    }
    if(resp3==3){
      printf("Digite o codigo do usuario acessar:");    
      scanf("%i", &codtest);
      for(i=0;i<tam;i++){
        if(livres[i]==0){
          if(cod[i]==codtest){
            printf("Estes sao dos dados do cliente [%i]:\n ", cod[i]);
            list_clients();
            list_pets();
          }
        }
      }

    }
    if(resp3==4){
      printf("Digite o tipo pet para acessar:");    
      scanf("%s", &type_test);
      for(i=0;i<tam;i++)
        for(j=0;j<pets;j++){
          if(livres[i]==0 || livres_pet[i][j]==0){
            if(strcmp(type_test,type_pet[i][j])==0){
              list_clients();
              list_pets();
            //Testa o tipo do pet pra mostrar eles depois
            }
          }
        }
      }
    if(resp3==5){
      order_alf_user();
    }
    if(resp3==6){
    printf("Digite o codigo do usuario ou do pet que deseja excluir:");    
    scanf("%i", &codtest);
    for(i=0;i<tam;i++){
      for(j=0;j<pets;j++){
        if(livres_pet[i][j]==0){
          if(codtest==codpet[i][j]) {
            printf("pet excluido com sucesso!");
            livres_pet[i][j]=1;
            break;
          }
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

  }
  printf("\nDeseja mostrar todos os cadastros?:");
  scanf("%s", &resp);
    
}



