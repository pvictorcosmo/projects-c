
#include "init.h"
#include "pessoa.h"
#include "pet.h"

void start(){
  for (i= 0; i < tam; i++) {
    livres[i] = 1;
    for(j=0;j<pets;j++){
      livres_pet[i][j]=1;
    }
    /*Nesse laço eu to preenchendo todos os valores de livres com 0, pra quando houver 
    alguma coisa pra preencher o indice, mudar pra 1*/
  }
  for(i=0;i<tam;i++){
    cod[i]= 100+rand()%900;
    testcode=cod[i];
    for(j=0;j<tam;j++){
    if(testcode==cod[j]){
    cod[j]= 100+rand()%900;

    }
    }

  }
  for(i=0;i<tam;i++){
    for(j=0;j<pets;j++){
    codpet[i][j]=100+rand()%900;
    testcode=codpet[i][j];
    for(g=0;g<tam;g++){
        for(h=0;h<pets;h++){
            if(testcode==codpet[g][h]){
                codpet[g][h]=100+rand()%900;
            }
        }
    }
    }
  }

  for(i=0;i<tam;i++){
    datanasc[i]=NULL;
    rend[i]=NULL;
    cpftest[j]=NULL;
    end[i]=NULL;
    fones[i]=NULL;
    rgs[i]=NULL;
  }

}

void space(){
  printf("---------------------------------\n");
}

void format(char *text,char format[],char final[]){

  int i = 0;
  while(*text){
    if(format[i] != '#'){
      final[i] = format[i];
      i++;
    }
    else{
      final[i] = *text;
      text++;
      i++;
    }
  }
  final[i] = 0;

}

char *Str(char *string_base)
{
    return (char *) malloc((strlen(string_base) + 1) * sizeof(char));
}


void Upper(char *names)
{
    for(size_t i = 0; i < strlen(names); ++i){
        names[i] = (char) toupper((int) names[i]);
    }
}

void funcs_clients_ui(){
    char type_pets[25];
    char nome_pets[255];
    char datanascpets[8];
    int i;
    char type_test[25];
    printf("--------- FUNCIONALIDADES DO USUARIO ---------");
    printf("\n1 - para excluir um usuario\n2 - para alterar um usuario\n3 - para buscar um cadastro pelo codigo\n4 - Para mostrar cadastros que tenham um tipo especifico de pet\n5 - para listar os cadastros em ordem alfabetica\n\n");
    printf("--------- FUNCIONALIDADES DO PET ---------");
    printf("\n6 - para excluir um pet\n7 - para alterar um pet\n8 - para adicionar um novo pet\n9 - para mostrar cadastros com base no codigo do pet\n10 - para mostrar os pets em ordem alfabetica\n");
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
      
      case 5:
        for(i=0;i<tam;i++){
          if(livres[i]==0){
          order_alf_user();
          }
        }
      break;

      case 6:
        printf("Digite o codigo do usuario ou do pet que deseja excluir:");    
        scanf("%i", &codtest);
        delete_pet(codtest);
      break;

      case 7:
        printf("Digite o codigo do pet que deseja alterar:");    
        scanf("%i", &codtest);
        for(i=0;i<tam;i++){
          for(j=0;j<pets;j++){
            if(codtest==codpet[i][j]){
              I=i;
              J=j;
              alt_pets_ui();
            }
          }
        }
      break;

      case 8:
        printf("Digite o codigo do usuario que deseja adicionar um novo pet:");    
        scanf("%i", &codtest);
        for(i=0;i<tam;i++){
          if(codtest==cod[i]){
            I=i;
            insert_new_pets_ui();
          }
        }
      break;

     /* case 9:
        printf("Digite o codigo do pet que deseja mostrar o cadastro:");    
        scanf("%i", &codtest);
        list_client(codtest);
      break;*/

      case 9:
        for(i=0;i<tam;i++){
          for(j=0;j<tam;j++){
          if(livres[i]==0){
            order_alf_pets();
          }
          }
        }

    }
    printf("\nDeseja mostrar todos os cadastros?:");
    scanf("%s", &resp);
}


