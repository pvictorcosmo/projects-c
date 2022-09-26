#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
#define tam 30
int livres[tam];
int livres_pet[tam];
//Vetores correspondentes o cliente:
int  cod[tam];
char  datanasc[tam][8];
char cpftest[tam][12];
char  rend[tam][20];
char nomes[tam][255];
char end[tam][255];
char fones[tam][20];
char rgs[tam][12];
char cpfs[tam][12];
//Vetores correspondentes ao pet:
int codpet[tam];
char type_pet[tam][25];
char nome_pet[tam][255];
char datanascpet[tam][8];
//Vetores de ação ou usados para iniciar
char resp3;
char respxc;
char resp2[12];
char resp;
char init;
char alf[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','x','w','y','z'};
char alfb[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','W','Y','Z'};


    //Criando as strings pra armazenar os dados do usuário
    //alf e alfb sao usadas pra fazer a ordem alfabetica



void iniciar()
{
  int i;  
  for (i= 0; i < tam; i++) {
    livres[i] = 1;
    livres_pet[i]=1;
    /*Nesse laço eu to preenchendo todos os valores de livres com 0, pra quando houver 
    alguma coisa pra preencher o indice, mudar pra 1*/
}
for(i=0;i<tam;i++){
    cod[i]= 100+rand()%900;
    codpet[i]=100+rand()%900;
}
}
void ordem_alfabetica(){
    int i,j;
    for(i=0;i<tam;i++){
    if(livres[i]==0 && livres_pet[i]==0){    
     for(j= 0; j < 26; j++){
        if(nomes[i][0] == alf[j]|| nomes[i][0] == alfb[j]){
            printf("\n[ codigo: %i\nRG:%s\nCPF:%s\nnome:%s\nendereco:%s\nSua data de nascimento:%c\nrendimento:[R$%s]\ntelefone:%s ]",cod[i], rgs[i],cpfs[i], nomes[i], end[i],datanasc[i],rend[i],fones[i]);
            //testa valores daquela string do alfabeto e imprime na ordem(GENIAL APENAS POR FAVOR MIM AGRADEÇA CAROL)
        }        
        }
     }
    }

}

void inserir_contato()
{
int i,j;
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
printf("Valor:%i\nValor:%i",livres[0],livres[1]);
for (i= 0; i < tam; i++) {
  if(livres[i] == 1 && livres_pet[i]==1){
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
printf("index: %i", index);

if(strlen(cpf)!=11 || strlen(nome)==0 || strlen(datanascs)!=8){
       printf("\nAs suas informacoes estavam incorretas, por favor, digite novamente\n");
       printf("Deseja fazer outro cadastro?(s/n):");
       scanf("%s", &resp);
             //Esse bloco testa e diz se as informações estiverem erradas
        }
  //Perguntando as informações do usuário
  for(j=0;j<tam;j++){
    if(strcmp(cpf,cpftest[j])==0){
        printf("\nVoce ja tem um cadastro aqui, Esses sao os  dados:\n");
         printf("   DADOS DO CLIENTE:\ncodigo: %i\nRG:%s\nCPF:%s\nnome:%s\nendereco:%s\nSua data de nascimento:%s\nrendimento:%s\ntelefone:%s\n",cod[j], rg,cpf, nome, ends,datanascs,rend,fone,codpet[j]);
         exit(0);
  //Este laço testa os valores pra ver se ja tem algum cadastro    
    } 
  }

livres[index] = 0;
printf("index: %i", index);
strcpy(cpftest[index],cpf);
}

void listar_contatos(){
  int i;
  for(i=0;i<tam;i++){  
    if(livres[i] == 0 && livres_pet[i]==0){
     if(strlen(cpfs[i])==11 && strlen(nomes[i])!=0 && strlen(datanasc[i])==8){  
      
        printf("\nSeu cadastro foi feito com sucesso!\n");
        printf("   DADOS DO CLIENTE:\ncodigo: %i\nRG:%s\nCPF:%.3s.%.3s.%.3s-%.2s\nnome:%s\nendereco:%s\nSua data de nascimento:%s\nrendimento:%s\ntelefone:%s\n   DADOS DO SEU PET:\nCodigo: %i\nNome: %s\nTipo: %s\nData de nascimento:%s\n",cod[i], rgs[i],cpfs[i], nomes[i], end[i],datanasc[i],rend[i],fones[i],codpet[i],nome_pet[i],type_pet[i],datanascpet[i]);
        printf("Deseja fazer outro cadastro?(s/n):");
        scanf("%s", &resp);
          //Fazendo cadastro da pessoa e printando as informações na tela
          /*Perceber que essa informação só vai ser verdadeira se o numero de caracteres de cpf, nome e data de nascimento forem maior que 0*/
      }
    }
  }
  
}

void cadastros(){
int i;
printf("Voce tem tais cadastros:\n");
for(i=0;i<tam;i++){
    if(livres[i]==0 && livres_pet[i]==0){
    printf("   DADOS DO CLIENTE:\ncodigo: %i\nRG:%s\nCPF:%s\nnome:%s\nendereco:%s\nSua data de nascimento:%s\nrendimento:%s\ntelefone:%s\n   DADOS DO SEU PET:\nCodigo: %i\nNome: %s\nTipo: %s\nData de nascimento:%s\n",cod[i], rgs[i],cpfs[i], nomes[i], end[i],datanasc[i],rend[i],fones[i],codpet[i],nome_pet[i],type_pet[i],datanascpet[i]);
    }
}
}
void inserir_pet(){
int i,j;
char type_pets[25];
char nome_pets[255];
char datanascpets[8];
static int index = -1;
printf("Valor:%i\nValor:%i",livres[0],livres_pet[0]);
for (i= 0; i < tam; i++) {
  if(livres_pet[i]==1){
    index = i;
    break;
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
livres_pet[i]=0;
}
void alterar_usuario(){
    int i,codtest;
    char type_test[25];
    printf("\nVoce tem algumas opções:\nFuncionalidades do usuario:\nDigite 'x' para excluir um usuario\nDigite 'c' para alterar um usuario\nDigite 'i' para buscar um cadastro pelo codigo\nDigite 'r' para mostrar pessoas que tenham um tipo especifico de pet\nDigite 'z' para listar os cadastros em ordem alfabetica\nFuncionalidades do pet?\nDigite 'p' para excluir um pet\nDigite 'l' para alterar um pet\n ");
    scanf("%s",&resp3);
    if(resp3=='x'){
      printf("Digite o codigo do usuario que deseja excluir:");    
      scanf("%i", &codtest);   
      for(i=0;i<tam;i++){
        if(livres[i]==0 && livres_pet[i]==0){
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
        if(livres[i]==0 && livres_pet[i]==0){
        if(cod[i]==codtest){
            livres[i]=1;
            inserir_contato();
                }
            }
            
        }
      }
    if(resp3=='z'){
        ordem_alfabetica();
    }
    if(resp3=='p'){
      printf("Digite o codigo do usuario ou do pet que deseja alterar:");    
      scanf("%i", &codtest);
    for(i=0;i<tam;i++){
      if(livres[i]==0 && livres_pet[i]==0){
        if(codtest==cod[i] || codtest==codpet[i]) {
          printf("pet excluido com sucesso!");
          livres_pet[i]=1;
          break;
            
        }
        }      
    }  
    }
    if(resp3=='l'){
      printf("Digite o codigo do usuario ou do pet que deseja alterar:");    
      scanf("%i", &codtest);
      for(i=0;i<tam;i++){
        if(livres[i]==0 && livres_pet[i]==0){
          if(cod[i]==codtest || codpet[i]==codtest){
            livres_pet[i]=1;
            inserir_pet();
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
            printf("   DADOS DO CLIENTE:\ncodigo: %i\nRG:%s\nCPF:%s\nnome:%s\nendereco:%s\nSua data de nascimento:%s\nrendimento:%s\ntelefone:%s\n",cod[i], rgs[i],cpfs[i], nomes[i], end[i],datanasc[i],rend[i],fones[i],codpet[i]);
          }
        }
      }

    }
    if(resp3=='r'){
      printf("Digite o tipo pet para acessar:");    
      scanf("%s", &type_test);
      for(i=0;i<tam;i++){
        if(livres[i]==0 || livres_pet[i]==0){
          if(strcmp(type_test,type_pet[i])==0){
            printf("   DADOS DO CLIENTE:\ncodigo: %i\nRG:%s\nCPF:%s\nnome:%s\nendereco:%s\nSua data de nascimento:%s\nrendimento:%s\ntelefone:%s\n   DADOS DO SEU PET:\nCodigo: %i\nNome: %s\nTipo: %s\nData de nascimento:%s\n",cod[i], rgs[i],cpfs[i], nomes[i], end[i],datanasc[i],rend[i],fones[i],codpet[i],nome_pet[i],type_pet[i],datanascpet[i]);
          }
        }
      }
    }
 printf("Deseja mostrar todos os cadastros?:");
 scanf("%s", &resp);
}



int main() {
srand(time(NULL));

iniciar();
printf("Seja bem vindo!\nPara acessar cadastro precisamos dos dados\n");
printf("Digite 'n' para adicionar um novo usuario!:");
scanf("%s",&init);
if(init=='n'){
  do{
  inserir_contato();
  inserir_pet();
  listar_contatos();}while(resp=='s');
  do{
    cadastros();
    alterar_usuario();}while(resp=='s');
  
  /*O código vai funcionar enquanto a resposta for s, a nao ser que a pessoa ja tenha um cadastro, se a resposta for n, o código vai mostrar todos listados
  */
}else if(init=='c'){
}
  
return 0;
system("pause");
}