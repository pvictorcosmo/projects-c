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
  livres[index] = 0;
 if(strlen(cpf)==0 || strlen(nome)==0 || strlen(datanascs)==0){
    printf("Informações erradas!");
    livres[index] = 1;
      //Esse bloco testa e diz se as informações estiverem erradas
 }
  //Perguntando as informações do usuário
  

  free(datanascs);
  free(rg);
  free(cpf);
  free(ends);
  free(fone);
  free(rends);
  
}

void list_clients_ui(){ 
  for(i=0;i<tam;i++){  
    if(livres[i] == 0 ){    
        system("cls");  
        printf("\nSeu cadastro foi feito com sucesso!\n");
        printf("Deseja fazer outro cadastro?(s/n):");
        scanf("%s", &resp);
        break;
          //Fazendo cadastro da pessoa e printando as informações na tela
      }
    }
  }
void clients_ui(){
  printf("--------- CADASTROS ---------\n");
  for(i=0;i<tam;i++){
    if(livres[i]==0){
      format(cpfs[i],"###.###.###-##",cpf_format);
      format(rgs[i],"#########-##",rg_format);
      format(datanasc[i],"##/##/####",datanasc_format);

      printf("------- DADOS DO CLIENTE -------");
      printf("\nCodigo: [%i]\nRG: [%s]\nCPF:[%s]\nNome: [%s]\nEndereco: [%s]\nData de nascimento: [%s]\nRendimennto: [R$ %s]\nTelefone: [%s]\n",cod[i], rg_format,cpf_format, nomes[i], end[i],datanasc_format,rend[i],fones[i]);
      
      for(j=0;j<pets;j++){
        if(livres_pet[i][j]==0){
          format(datanascpet[i][j],"##/##/####",datanascpet_format);
          printf("------- DADOS DO SEU PET -------");
          printf("\nCodigo: [%i]\nNome: [%s]\nTipo: [%s]\nData de nascimento:[%s]\n",codpet[i][j],nome_pet[i][j],type_pet[i][j],datanascpet_format);
        }
      }
    }
  }
}
void list_user(int index){

  if(livres[index]==0){
    format(cpfs[index],"###.###.###-##",cpf_format);
    format(rgs[index],"#########-##",rg_format);
    format(datanasc[index],"##/##/####",datanasc_format);
    printf("------- DADOS DO CLIENTE -------");
    printf("\nCodigo: [%i]\nRG: [%s]\nCPF:[%s]\nNome: [%s]\nEndereco: [%s]\nData de nascimento: [%s]\nRendimennto: [R$ %s]\nTelefone: [%s]\n",cod[index], rg_format,cpf_format, nomes[index], end[index],datanasc_format,rend[index],fones[index]);
    for(i=0;i<pets;i++){
    if(livres_pet[index][i]==0){
      format(datanascpet[i][j],"##/##/####",datanascpet_format);
      printf("------- DADOS DO SEU PET -------");
      printf("\nCodigo: [%i]\nNome: [%s]\nTipo: [%s]\nData de nascimento:[%s]\n\n",codpet[index][i],nome_pet[index][i],type_pet[index][i],datanascpet_format);
    }
    }
}
}
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

void order_alf_user(){
    int index = 0;
    int all_index[tam];
    char *nome[tam];
    for(int i = 0; i < tam; ++i) {
        if(nomes[i]) {
            nome[index] = Str(nomes[i]);
            strcpy(nome[index], nomes[i]);
            all_index[index] = i;
            index++;
        }
    }
    int total = index;
    for(int i = 0; i < total; ++i){
      Upper(nome[i]);
    }
    

    char size[255];

    while(index--){
        strcpy(size, "z");
        int size_in = 0;

        for(int i = 0; i < total; ++i) {
            if(strcmp(nome[i], size) < 0) {
                strcpy(size, nome[i]);
                size_in = i;
            }
        }

        strcpy(nome[size_in], "z");
        list_user(all_index[size_in]);
    
    }
    for(int i = 0; i < total; ++i){
        free(nome[i]);
    }
}


void alt_user(char rg[],char cpf[],char nome[],char ends[],char datanascs[],char fone[],char rends[]){

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
    for(j=0;j<pets;j++){
      if(cod[i]==codtest || codpet[i][j]==codtest){
        if(livres[i]==0){
          format(cpfs[i],"###.###.###-##",cpf_format);
          format(rgs[i],"#########-##",rg_format);
          format(datanasc[i],"##/##/####",datanasc_format);
          printf("------- DADOS DO CLIENTE -------");
          printf("\nCodigo: [%i]\nRG: [%s]\nCPF:[%s]\nNome: [%s]\nEndereco: [%s]\nData de nascimento: [%s]\nRendimennto: [R$ %s]\nTelefone: [%s]\n",cod[i], rg_format,cpf_format, nomes[i], end[i],datanasc_format,rend[i],fones[i]);
          for(g=0;g<pets;g++){
            if(livres_pet[i][g]==0){
              format(datanascpet[i][j],"##/##/####",datanascpet_format);
              printf("------- DADOS DO SEU PET -------");
              printf("\nCodigo: [%i]\nNome: [%s]\nTipo: [%s]\nData de nascimento:[%s]\n",codpet[i][j],nome_pet[i][j],type_pet[i][j],datanascpet_format);
            }
          }
        }
      }
    }
  }
}

void insert_user_ui(){
  aux=0;
  char *rg=malloc(sizeof(char)*12);
  char *cpf=malloc(sizeof(char)*12);
  char nome[255];
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




