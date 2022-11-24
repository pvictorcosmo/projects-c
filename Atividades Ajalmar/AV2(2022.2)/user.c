#include "user.h"
#include "init.h"
#include "pet.h"

int nextCode() {
    FILE *chv = NULL;
    chv = fopen("keyUser.chv", "rb+");
    if (chv == NULL)
        chv = fopen("keyUser.chv", "wb+");

    fseek(chv, 0, SEEK_SET);
    fread(&cod, sizeof(int), 1, chv);

    cod++;

    fseek(chv, 0, SEEK_SET);
    fwrite(&cod, sizeof(int), 1, chv);
    return cod;
}

void insertPersonUI() {

    char *Rg = malloc(sizeof(char) * 12);
    char *Cpf = malloc(sizeof(int) * 12);
    char *Name = malloc(sizeof(int) * sizeMaxNames);
    char *Address = malloc(sizeof(char) * sizeMaxNames);
    char *Date = malloc(sizeof(char) * 9);
    char *Phone = malloc(sizeof(char) * 20);
    char *Income = malloc(sizeof(char) * 20);

    printf("\n#-----------------------------------------#");
    printf("\n|                CADASTRO                 |");
    printf("\n#-----------------------------------------#");

    printf("\n > Nome:");
    fflush(stdin);
    fgets(Name, sizeMaxNames, stdin);

    printf(" > Cpf:");
    fflush(stdin);
    fgets(Cpf, 12, stdin);

    printf(" > Rg:");
    fflush(stdin);
    fgets(Rg, 12, stdin);

    printf(" > Endereco:");
    fflush(stdin);
    fgets(Address, sizeMaxNames, stdin);

    printf(" > Data de nascimento:");
    fflush(stdin);
    fgets(Date, 9, stdin);

    printf(" > Telefone:");
    fflush(stdin);
    fgets(Phone, 20, stdin);

    printf(" > Rendimento Mensal:");
    fflush(stdin);
    fgets(Income, 20, stdin);

    //fgets é pra pegar as strings com espaço, o fflush serve pra tirar todo o lixo da string

    insertPerson("persons.bin",Rg,Cpf,Name,Address,Date,Phone,Income);

}

void insertPerson(char *file_path,char *Rg,char *Cpf,char *Name,char *Address,char *Date,char *Phone,char *Income ){
    person p,*current;
    current=(person*)malloc(sizeof(person));
    FILE *archive=NULL;
    archive=fopen(file_path,"rb+");
    if(archive==NULL)
        archive=fopen(file_path,"wb+");

    int cod=0;
    current=malloc(sizeof(person));
   // FillStrings(p,Rg,Cpf,Name,Address,Date,Phone,Income);
    strcpy(current->rgUser,Rg);
    strcpy(current->cpfUser,Cpf);
    strcpy(current->nameUser,Name);
    strcpy(current->addressUser,Address);
    strcpy(current->dateUser,Date);
    strcpy(current->phoneUser,Phone);
    strcpy(current->incomeUser,Income);
    current->fileExist=1;
    current->codUser=nextCode();
  // printf("%d",current->codUser);


     free(Rg);
     free(Cpf);
     free(Name);
     free(Address);
     free(Date);
     free(Phone);
     free(Income);



     FILE *chv=NULL;
     chv=fopen("keyUser.chv","rb+");
     if(chv==NULL)
         chv=fopen("keyUser.chv","wb+");
     fseek(chv,sizeof(int),SEEK_SET);
     fread(&cod,sizeof(int),1,chv);

     fseek(archive,0,SEEK_END);
     fwrite(current,sizeof(person),1,archive);
     fclose(archive);
     free(current);

 }

 void listPersons(person listPerson,char *file_path){
     FILE *archive;
     FILE *chvUser;
     int codUser=0;

     printf("\n#-----------------------------------------#");
     printf("\n|           LISTA DE CADASTROS            |");
     printf("\n#-----------------------------------------#");

     archive=fopen(file_path,"rb");
     chvUser=fopen("keyUser.chv","rb");

     fseek(chvUser,0,SEEK_SET);
     fread(&codUser,sizeof(int),1,chvUser);
     for(int i=0;i<codUser;i++)
     {

         fseek(archive, sizeof(person) * i, SEEK_SET);
         fread(&listPerson, sizeof(person), 1, archive);
         printf("%d",listPerson.fileExist);
         if(listPerson.fileExist) {
             printf("\n#-----------------------------------------#");
             printf("\n| > Codigo: %.3d                          |", listPerson.codUser);
             printf("\n#-----------------------------------------#");
             printf("\n > Nome: %s", listPerson.nameUser);
             printf(" > Cpf: %s", listPerson.cpfUser);
             printf(" > Endereco: %s", listPerson.addressUser);
             printf(" > Data de nascimento: %s", listPerson.dateUser);
             printf(" > Telefone: %s", listPerson.phoneUser);
             printf(" > Rendimento mensal: %s", listPerson.incomeUser);
             printf("\n#-----------------------------------------#");
         }

     }

     fclose(archive);
 }

 void changePersonUI(){
     int codUser;
     char *Rg = malloc(sizeof(char) * 12);
     char *Cpf = malloc(sizeof(int) * 12);
     char *Name = malloc(sizeof(int) * sizeMaxNames);
     char *Address = malloc(sizeof(char) * sizeMaxNames);
     char *Date = malloc(sizeof(char) * 9);
     char *Phone = malloc(sizeof(char) * 20);
     char *Income = malloc(sizeof(char) * 20);

     printf("\n#---------------------------------------------------#");
     printf("\n|   DIGITE O CODIGO DO USUARIO QUE DESEJA ALTERAR   |");
     printf("\n#---------------------------------------------------#");
     printf("\n > ");
     scanf("%d",&codUser);
     codUser--;
     printf("%d",codUser);

     printf("\n > Nome:");
     fflush(stdin);
     fgets(Name, sizeMaxNames, stdin);

     printf(" > Cpf:");
     fflush(stdin);
     fgets(Cpf, 12, stdin);

     printf(" > Rg:");
     fflush(stdin);
     fgets(Rg, 12, stdin);

     printf(" > Endereco:");
     fflush(stdin);
     fgets(Address, sizeMaxNames, stdin);

     printf(" > Data de nascimento:");
     fflush(stdin);
     fgets(Date, 9, stdin);

     printf(" > Telefone:");
     fflush(stdin);
     fgets(Phone, 20, stdin);

     printf(" > Rendimento Mensal:");
     fflush(stdin);
     fgets(Income, 20, stdin);

     //fgets é pra pegar as strings com espaço, o fflush serve pra tirar todo o lixo da string

     changePerson("persons.bin",Rg,Cpf,Name,Address,Date,Phone,Income,codUser);

}

void changePerson(char *file_path,char *Rg,char *Cpf,char *Name,char *Address,char *Date,char *Phone,char *Income,int codUser){
    FILE *archive=NULL;
    archive=fopen(file_path,"rb+");
    if(archive==NULL)
        archive=fopen(file_path,"wb+");
    person *current;
    current=(person*)malloc(sizeof(person));


   // fclose(archive);

    strcpy(current->rgUser,Rg);
    strcpy(current->cpfUser,Cpf);
    strcpy(current->nameUser,Name);
    strcpy(current->addressUser,Address);
    strcpy(current->dateUser,Date);
    strcpy(current->phoneUser,Phone);
    strcpy(current->incomeUser,Income);
    current->codUser=codUser+1;

    free(Rg);
    free(Cpf);
    free(Name);
    free(Address);
    free(Date);
    free(Phone);
    free(Income);

    fseek(archive,sizeof(person)*codUser,SEEK_SET);
    fwrite(current,sizeof(person),1,archive);
    fclose(archive);
    free(current);
}

void deletePerson(char *file_path,int codUser){
    codUser--;
    FILE *archive=NULL;
    archive=fopen(file_path,"rb+");
    if(archive==NULL)
        archive=fopen(file_path,"wb+");
    person *current;
    current=(person *)malloc(sizeof(person));
    current->fileExist=0;

    fseek(archive,sizeof (person)*codUser,SEEK_SET);
    fwrite(current,sizeof(person),1,archive);
}

void searchByCode(char *file_path,int codUser){

    codUser--;
    FILE *archive=NULL;
    person listPerson;
    archive=fopen(file_path,"rb");

    fseek(archive, sizeof(person) * codUser, SEEK_SET);
    fread(&listPerson, sizeof(person), 1, archive);

    printf("\n#-----------------------------------------#");
    printf("\n| > Codigo: %.3d                          |", listPerson.codUser);
    printf("\n#-----------------------------------------#");
    printf("\n > Nome: %s", listPerson.nameUser);
    printf(" > Cpf: %s", listPerson.cpfUser);
    printf(" > Endereco: %s", listPerson.addressUser);
    printf(" > Data de nascimento: %s", listPerson.dateUser);
    printf(" > Telefone: %s", listPerson.phoneUser);
    printf(" > Rendimento mensal: %s", listPerson.incomeUser);
    printf("\n#-----------------------------------------#");

}

void searchByCodePet(char *file_path, int codPet){

}
