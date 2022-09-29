#include "init.h"
#include "pessoa.h"
#include "pet.h"
/*void ordem_alfabetica(){
  for(i=0;i<tam;i++){
    if(livres[i]==0){    
      for(j= 0; j < 26; j++){
        if(nomes[i][0] == alf[j]|| nomes[i][0] == alfb[j]){
          printf("\n[ codigo: %i\nRG:%s\nCPF:%s\nnome:%s\nendereco:%s\nSua data de nascimento:%c\nrendimento:[R$%s]\ntelefone:%s ]",cod[i], rgs[i],cpfs[i], nomes[i], end[i],datanasc[i],rend[i],fones[i]);
            //testa valores daquela string do alfabeto e imprime na ordem(GENIAL APENAS POR FAVOR MIM AGRADEÇA CAROL)
        }        
      }
    }
  }
}
*/
void insert_clients(){
  char  datanascs[8];
  char  rends[20];
  char ends[255];
  char rg[12];
  char cpf[12];
  char nome[255];
  char fone[20];
  char type_pets[25];
  char nome_pets[255];
  char datanascpets[8];
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
  scanf("%s", &rg);
  printf("Qual seu CPF?:");
  scanf("%s", &cpf);
  printf("Qual seu Nome?:");
  scanf("%s", &nome);
  printf("Qual seu Endereco?:");
  scanf("%s", &ends);
  printf("Qual sua data de nascimento?:");
  scanf("%s", &datanascs);
  printf("Qual seu telefone?:");
  scanf("%s", &fone);
  printf("Qual seu rendimento?:");
  scanf("%s", &rends);
  printf("\nOk! Agora vou fazer perguntas referentes ao seu pet!\n");

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
      printf("   DADOS DO CLIENTE:\ncodigo: %i\nRG:%s\nCPF:%s\nnome:%s\nendereco:%s\nSua data de nascimento:%s\nrendimento:%s\ntelefone:%s\n",cod[j], rg,cpf, nome, ends,datanascs,rend,fone);
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
      if(strlen(cpfs[i])==11 && strlen(nomes[i])!=0 && strlen(datanasc[i])==8){  
        printf("\nSeu cadastro foi feito com sucesso!\n");
        printf("   DADOS DO CLIENTE:\ncodigo: %i\nRG:%s\nCPF:%s\nnome:%s\nendereco:%s\nSua data de nascimento:%s\nrendimento:%s\ntelefone:%s\n",cod[i], rgs[i],cpfs[i], nomes[i], end[i],datanasc[i],rend[i],fones[i]);
        list_pets();
        printf("Deseja fazer outro cadastro?(s/n):");
        scanf("%s", &resp);
          //Fazendo cadastro da pessoa e printando as informações na tela
          /*Perceber que essa informação só vai ser verdadeira se o numero de caracteres de cpf, nome e data de nascimento forem maior que 0*/
      }
    }
  }
  
}

void register_users(){
  printf("Voce tem tais cadastros:\n");
  for(i=0;i<tam;i++){
    if(livres[i]==0){
      printf("   DADOS DO CLIENTE:\ncodigo: %i\nRG:%s\nCPF:%s\nnome:%s\nendereco:%s\nSua data de nascimento:%s\nrendimento:%s\ntelefone:%s\n",cod[i], rgs[i],cpfs[i], nomes[i], end[i],datanasc[i],rend[i],fones[i]);
    }
  }
}

void funcs_users(){
    int i,codtest;
    char type_test[25];
    printf("\nVoce tem algumas opcoes:\nFuncionalidades do usuario:\nDigite 'x' para excluir um usuario\nDigite 'c' para alterar um usuario\nDigite 'i' para buscar um cadastro pelo codigo\nDigite 'r' para mostrar pessoas que tenham um tipo especifico de pet\nDigite 'z' para listar os cadastros em ordem alfabetica\nFuncionalidades do pet:\nDigite 'p' para excluir um pet\nDigite 'l' para alterar um pet\nDigite 'n' para adcionar um novo pet");
    scanf("%s",&resp3);

    if(resp3=='x'){
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
    if(resp3=='c'){
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
    if(resp3=='i'){
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
    if(resp3=='r'){
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
    if(resp3=='z'){
    }
    if(resp3=='p'){
    printf("Digite o codigo do usuario ou do pet que deseja alterar:");    
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
  if(resp3=='l'){
    printf("Digite o codigo do pet que deseja alterar:");    
    scanf("%i", &codtest);
    for(i=0;i<tam;i++){
      for(j=0;j<pets;j++){
        if(livres_pet[i][j]==0){
          if(codpet[i][j]==codtest){
            livres_pet[i][j]=1;
            insert_pets();
          }
        }
      }   
    }
  }
  if(resp3=='n'){
    printf("Digite o codigo do usuario que deseja adicionar um novo pet:");    
    scanf("%i", &codtest);
    for(i=0;i<tam;i++){
      if(cod[i]==codtest){
        insert_pets();     
      }    
    }
  }
  printf("Deseja mostrar todos os cadastros?:");
  scanf("%s", &resp);
    
}

