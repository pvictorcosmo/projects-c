#include "user.h"
#include "init.h"
#include "pet.h"

int nextCode() {
    int cod=0;
    FILE *chv = NULL;
    chv = fopen("keyUser.chv", "rb+");
    if (chv == NULL)
        chv = fopen("keyUser.chv", "wb+");

    fseek(chv, 0, SEEK_SET);
    fread(&cod, sizeof(int), 1, chv);

    cod++;

    fseek(chv, 0, SEEK_SET);
    fwrite(&cod, sizeof(int), 1, chv);

    fseek(chv, 0, SEEK_SET);
    fread(&cod, sizeof(int), 1, chv);

    return cod;
}

int checkCpf(char *file_path,char *string){
    int codUser=0;
    person listPersons;

    FILE *Person=NULL;
    FILE *chv=NULL;

    chv=fopen("keyUser.chv","rb");

    Person=fopen(file_path,"rb+");

    if(Person==NULL)
        Person=fopen(file_path,"wb+");

    fseek(chv,0,SEEK_SET);
    fread(&codUser,sizeof(short int),1,chv);

    for(int i=0;i<codUser;i++){
        fseek(chv,sizeof(person)*i,SEEK_SET);
        fread(&listPersons,sizeof(person),1,Person);

        if(!strcmp(listPersons.cpfUser,string)){
            return 0;
        }
    }
    return 1;
}
int insertPersonUI() {
    system("cls");
    int option;

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

    if(strlen(Name)>0 && strlen(Cpf)==11 && strlen(Date)==8) {

        if(checkCpf("persons.bin",Cpf)) {
            insertPerson("persons.bin", Rg, Cpf, Name, Address, Date, Phone, Income);
        }
        else{
            printf("\n#---------------------------------------------------#");
            printf("\n|              USUARIO JA CADASTRADO                |");
            printf("\n#---------------------------------------------------#");

            printf("\n#---------------------------------------------------#");
            printf("\n|  1 - Para voltar ao Menu de usuarios              |");
            printf("\n#---------------------------------------------------#");
            printf("\n > ");

            scanf("%d", &option);
            if(option==1)
                interfaceUser();
        }
    }
    else{
        printf("\n#-------------------------------------------------#");
        printf("\n|   INFORMACOES ERRADAS FAVOR INSERIR NOVAMENTE   |");
        printf("\n#-------------------------------------------------#");
        insertPersonUI();
    }
    return 1;
}

int insertPerson(char *file_path,char *Rg,char *Cpf,char *Name,char *Address,char *Date,char *Phone,char *Income){
    person *current;
    current=(person*)malloc(sizeof(person));

    FILE *archive=NULL;
    archive=fopen(file_path,"rb+");
    if(archive==NULL)
        archive=fopen(file_path,"wb+");
    
    strcpy(current->rgUser,Rg);
    strcpy(current->cpfUser,Cpf);
    strcpy(current->nameUser,Name);
    strcpy(current->addressUser,Address);
    strcpy(current->dateUser,Date);
    strcpy(current->phoneUser,Phone);
    strcpy(current->incomeUser,Income);
    current->fileExist=1;
    current->codUser=nextCode();

    free(Rg);
    free(Cpf);
    free(Name);
    free(Address);
    free(Date);
    free(Phone);
    free(Income);

    fseek(archive,0,SEEK_END);
    fwrite(current,sizeof(person),1,archive);

    fclose(archive);
    free(current);
    return 0;

 }

 void listPersons(person listPerson,char *file_path){

     char *cpfFormat=(char *)malloc(sizeof(char)*14);
     char *DateFormat=(char *)malloc(sizeof(char)*12);
     FILE *archive;
     FILE *chvUser;
     int codUser=0;

     archive=fopen(file_path,"rb");
     chvUser=fopen("keyUser.chv","rb");

     fseek(chvUser,0,SEEK_SET);
     fread(&codUser,sizeof(int),1,chvUser);

     if(codUser==0){
         printf("\n#---------------------------------------------------#");
         printf("\n|                 NAO HA CADASTROS                  |");
         printf("\n#---------------------------------------------------#");

     }else {
         printf("\n#---------------------------------------------------#");
         printf("\n|                LISTA DE CADASTROS                 |");
         printf("\n#---------------------------------------------------#");
     }
     for(int i=0;i<codUser;i++){

         fseek(archive, sizeof(person) * i, SEEK_SET);
         fread(&listPerson, sizeof(person), 1, archive);

         format(listPerson.cpfUser,"###.###.###-##",cpfFormat);
         format(listPerson.dateUser,"##/##/####",DateFormat);

         if(listPerson.fileExist==1) {
             printf("\n#-----------------------------------------#");
             printf("\n| > Codigo: %.3d                           |", listPerson.codUser);
             printf("\n#-----------------------------------------#");
             printf("\n > Nome: %s", listPerson.nameUser);
             printf(" > Cpf: %s", cpfFormat);
             printf("\n > Endereco: %s", listPerson.addressUser);
             printf(" > Data de nascimento: %s", DateFormat);
             printf("\n > Telefone: %s", listPerson.phoneUser);
             printf(" > Rendimento mensal: R$: %s", listPerson.incomeUser);
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
     if(strlen(Name)>0 && strlen(Cpf)==11 && strlen(Date)==8) {
         changePerson("persons.bin", Rg, Cpf, Name, Address, Date, Phone, Income,codUser);
     }
     else{
         printf("\n#-------------------------------------------------#");
         printf("\n|   INFORMACOES ERRADAS FAVOR INSERIR NOVAMENTE   |");
         printf("\n#-------------------------------------------------#");
         changePersonUI();
     }


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
    current->fileExist=1;

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

int deletePerson(char *file_path,int codUser){
    int option;
    if(checkCodUser("persons.bin",codUser)){
        printf("\n#---------------------------------------------------#");
        printf("\n|               USUARIO INEXISTENTE                 |");
        printf("\n#---------------------------------------------------#");
        do {
            printf("\n#---------------------------------------------#");
            printf("\n|  1 - Para voltar ao Menu de usuarios        |");
            printf("\n#---------------------------------------------#");
            printf("\n > ");
            scanf("%d", &option);
            if (option == 1)
                interfaceUser();
        } while (option != 1);
    }
    codUser--;
    FILE *archive=NULL;
    archive=fopen(file_path,"rb+");

    if(archive==NULL)
        archive=fopen(file_path,"wb+");
    person current;
    current.fileExist=0;

    fseek(archive,sizeof (person)*codUser,SEEK_SET);
    fwrite(&current,sizeof(person),1,archive);

    fseek(archive,sizeof (person)*codUser,SEEK_SET);
    fread(&current,sizeof(person),1,archive);

    if(current.fileExist==0){
        return 1;
    }

    return 0;
}

void searchByCode(char *file_path,int codUser){

    char *cpfFormat=(char *)malloc(sizeof(char)*14);
    char *DateFormat=(char *)malloc(sizeof(char)*12);
    codUser--;
    FILE *archive=NULL;
    person listPerson;
    archive=fopen(file_path,"rb");

    fseek(archive, sizeof(person) * codUser, SEEK_SET);
    fread(&listPerson, sizeof(person), 1, archive);

    format(listPerson.cpfUser,"###.###.###-##",cpfFormat);
    format(listPerson.dateUser,"##/##/####",DateFormat);
    if(listPerson.fileExist==1) {
        printf("\n#-----------------------------------------#");
        printf("\n| > Codigo: %.3d                          |", listPerson.codUser);
        printf("\n#-----------------------------------------#");
        printf("\n > Nome: %s", listPerson.nameUser);
        printf(" > Cpf: %s", listPerson.cpfUser);
        printf("\n > Endereco: %s", listPerson.addressUser);
        printf(" > Data de nascimento: %s", listPerson.dateUser);
        printf("\n > Telefone: %s", listPerson.phoneUser);
        printf(" > Rendimento mensal: %s", listPerson.incomeUser);
        printf("\n#-----------------------------------------#");
    }
    else{
        printf("\n#---------------------------------------------------#");
        printf("\n|              USUARIO NAO ENCONTRADO               |");
        printf("\n#---------------------------------------------------#");
    }
}

void searchByTypePet(char *file_path, char *Type){
    int codPet=0;
    char *cpfFormat=(char *)malloc(sizeof(char)*14);
    char *DateFormat=(char *)malloc(sizeof(char)*12);
    FILE *FilePets;
    FILE *FileUser;
    FILE *chvPets;
    Pets listPets;
    person listUser;

    FilePets=fopen(file_path,"rb");
    FileUser=fopen("persons.bin","rb+");

    chvPets=fopen("keyPets.chv","rb");

    fseek(chvPets,0,SEEK_SET);
    fread(&codPet,sizeof(int),1,chvPets);

    for(int i=0;i<codPet;i++) {

        fseek(FilePets, sizeof(Pets) * i, SEEK_SET);
        fread(&listPets, sizeof(Pets), 1, FilePets);

        if(!strcmp(listPets.typePet,Type) && strlen(listPets.namePet)!=0){
            fseek(FileUser,sizeof(person)*i,SEEK_SET);
            fread(&listUser,sizeof(person),1,FileUser);

            format(listUser.cpfUser,"###.###.###-##",cpfFormat);
            format(listUser.dateUser,"##/##/####",DateFormat);

            printf("\n#-----------------------------------------#");
            printf("\n| > Codigo: %.3d                           |", listUser.codUser);
            printf("\n#-----------------------------------------#");
            printf("\n > Nome: %s", listUser.nameUser);
            printf(" > Cpf: %s", cpfFormat);
            printf("\n > Endereco: %s", listUser.addressUser);
            printf(" > Data de nascimento: %s", DateFormat);
            printf(" > Telefone: %s", listUser.phoneUser);
            printf(" > Rendimento mensal: %s", listUser.incomeUser);
            printf("\n#--------------------------------------------#");

        }
    }

}


int compareName (const void *a, const void *b) {
    return strcmp (((person *)a)->nameUser,((person *)b)->nameUser);
}

void orderAlfUser(char *file_path){

    person listPersons;
    int codUser=0;

    FILE *User;
    FILE *chvUser;

    User=fopen(file_path,"rb");
    chvUser=fopen("keyUser.chv","rb");

    fread(&codUser,sizeof(int),1,chvUser);
    printf("%d",codUser);
    int auxCod=codUser;
    person allPersons[codUser-1];
    for(int i=0;i<codUser;i++) {
        fseek(User, sizeof(person) * i, SEEK_SET);
        fread(&listPersons,sizeof(person),1,User);

        strcpy(allPersons[i].rgUser,listPersons.rgUser);
        strcpy(allPersons[i].cpfUser,listPersons.cpfUser);
        strcpy(allPersons[i].nameUser,listPersons.nameUser);
        strcpy(allPersons[i].addressUser,listPersons.addressUser);
        strcpy(allPersons[i].dateUser,listPersons.dateUser);
        strcpy(allPersons[i].phoneUser,listPersons.phoneUser);
        strcpy(allPersons[i].incomeUser,listPersons.incomeUser);
        allPersons[i].codUser=listPersons.codUser;
        allPersons[i].fileExist=listPersons.fileExist;
    }

    qsort(allPersons, codUser, sizeof(person), compareName);
    printf("%d",codUser);
    for(int i=0;i<auxCod;i++) {
        if (allPersons[i].fileExist == 1) {
            printf("\n#-----------------------------------------#");
            printf("\n| > Codigo: %.3d                           |", allPersons[i].codUser);
            printf("\n#-----------------------------------------#");
            printf("\n > Nome: %s", allPersons[i].nameUser);
            printf(" > Cpf: %s", allPersons[i].cpfUser);
            printf("\n > Endereco: %s", allPersons[i].addressUser);
            printf(" > Data de nascimento: %s", allPersons[i].dateUser);
            printf("\n > Telefone: %s", allPersons[i].phoneUser);
            printf(" > Rendimento mensal: %s", allPersons[i].incomeUser);
            printf("\n#-----------------------------------------#");
        }
    }




}