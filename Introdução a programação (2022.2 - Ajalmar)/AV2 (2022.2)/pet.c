#include "pet.h"
#include "init.h"
#include "user.h"
int nextCodePet() {
    FILE *chv = NULL;
    chv = fopen("keyPets.chv", "rb+");
    if (chv == NULL)
        chv = fopen("keyPets.chv", "wb+");

    fseek(chv, 0, SEEK_SET);
    fread(&codPet, sizeof(int), 1, chv);

    codPet++;

    fseek(chv, 0, SEEK_SET);
    fwrite(&codPet, sizeof(int), 1, chv);
    fclose(chv);
    return codPet;
}

int checkCodUser(char *file_path,int TestCodUser){

    int codUser=0;
    FILE *chv=NULL;
    chv=fopen(file_path,"rb");
    fseek(chv,0,SEEK_SET);
    fread(&codUser,sizeof(int),1,chv);
    for (int i=1;i<=codUser;i++){
        if(i==TestCodUser){
            return 0; //Coduser exists
        }
    }

    return 1;
}
int checkCodPet(char *file_path,int TestCodPet){

    int codPet=0;
    FILE *chv=NULL;
    chv=fopen(file_path,"rb");

    fseek(chv,0,SEEK_SET);
    fread(&codPet,sizeof(int),1,chv);

    for(int i=0;i<codPet;i++){

        if(TestCodPet==i+1){
            return 0;
        }
    }
    return 1;
}
void insertPetsUI() {
    int codUser, option;
    char *Name = malloc(sizeof(char) * sizeMaxNames);
    char *Date = malloc(sizeof(char) * 9);
    char *Type = malloc(sizeof(char) * 50);

    printf("\n#-----------------------------------------#");
    printf("\n|                CADASTRO                 |");
    printf("\n#-----------------------------------------#");

    printf("\n > Nome do pet:");
    fflush(stdin);
    fgets(Name, sizeMaxNames, stdin);

    printf(" > Data de nascimento:");
    fflush(stdin);
    fgets(Date, 9, stdin);

    printf(" > Tipo do pet:");
    fflush(stdin);
    fgets(Type, 50, stdin);

    printf("\n#-----------------------------------------#");
    printf("\n| > CODIGO DO DONO DO PET:                |");
    printf("\n#-----------------------------------------#");
    printf("\n > ");
    scanf("%d", &codUser);

    if (!checkCodUser("keyUser.chv", codUser)) {
        if(checkName("pets.bin",Name,codUser)) {
            insertPets("pets.bin", Name, Date, Type, codUser);
        }
        else{
            printf("\n#---------------------------------------------------#");
            printf("\n|             NOME DE PET JA CADASTRADO             |");
            printf("\n#---------------------------------------------------#");
            printf("\n#---------------------------------------------------#");
            printf("\n|  1 - Para voltar ao Menu de pets                  |");
            printf("\n#---------------------------------------------------#");
            printf("\n > ");
            scanf("%d", &option);
            if (option == 1)
                interfacePets();
        }
    }
    else {
        printf("\n#---------------------------------------------------#");
        printf("\n|                USUARIO NAO EXISTE                 |");
        printf("\n#---------------------------------------------------#");

        printf("\n#---------------------------------------------------#");
        printf("\n|  1 - Para voltar ao Menu de pets                  |");
        printf("\n#---------------------------------------------------#");
        printf("\n > ");
        scanf("%d", &option);
        if (option == 1)
            interfacePets();

    }
}

int checkName(char *file_path,char *namePet,int codUser){
    FILE *checkNames;
    Pets Current;
    checkNames=fopen(file_path,"rb");

    while(fread(&Current,sizeof(Pets),1,checkNames) !=0){
        if(Current.fileExist==1) {
            if (Current.codUser == codUser) {
                if (strcmp(namePet, Current.namePet)==0) {
                    return 0; // name exists
                }
            }
        }

    }
    return 1;

}

void insertPets(char *file_path,char *Name,char *Date,char *Type,int codUser){
    Pets *current;
    current=malloc(sizeof(Pets));

    FILE *archive=NULL;

    archive=fopen(file_path,"rb+");
    if(archive==NULL) {
        archive=fopen(file_path,"wb+");
    }

    strcpy(current->namePet,Name);
    strcpy(current->datePet,Date);
    strcpy(current->typePet,Type);
    current->codPet=nextCodePet();
    current->codUser=codUser;
    current->fileExist=1;

    free(Name);
    free(Date);
    free(Type);

    fseek(archive,0,SEEK_END);
    fwrite(current,sizeof(Pets),1,archive);
    fclose(archive);
    free(current);
    printf("\n#---------------------------------------------------#");
    printf("\n|             PET INSERIDO COM SUCESSO              |");
    printf("\n#---------------------------------------------------#");

}

int deletePets(char *file_path,int codPet){
    int option;
    if(!checkCodPet("keyPets.bin",codPet)){
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
                interfacePets();
        } while (option != 1);
    }
    codPet--;
    FILE *archive=NULL;
    archive=fopen(file_path,"rb+");

    if(archive==NULL)
        archive=fopen(file_path,"wb+");
    Pets current;

    current.fileExist=0;

    fseek(archive,sizeof (Pets)*codPet,SEEK_SET);
    fwrite(&current,sizeof(Pets),1,archive);


    fread(&current,sizeof(Pets),1,archive);

    if(current.fileExist==0){
        return 1;
    }

    return 0;
}

void listPets(char *file_path){

    FILE *pets;
    FILE *persons;
    FILE *chvPet=NULL;

    int codPet=0;
    Pets listPets;
    person listPersons;

    pets=fopen(file_path,"rb");
    chvPet=fopen("keyPets.chv","rb");
    persons=fopen("persons.bin","rb");

    fseek(chvPet,0,SEEK_SET);
    fread(&codPet,sizeof(int),1,chvPet);

    if(codPet==0){
        printf("\n#---------------------------------------------------#");
        printf("\n|                 NAO HA CADASTROS                  |");
        printf("\n#---------------------------------------------------#");

    }else {
        printf("\n#---------------------------------------------------#");
        printf("\n|                LISTA DE CADASTROS                 |");
        printf("\n#---------------------------------------------------#");
    }
    while(fread( &listPersons,sizeof(person),1,persons) != 0) {
        if (listPersons.fileExist == 1) {
            printf("pessoa:%d e file:%d", listPersons.codUser, listPersons.fileExist);
            while (fread(&listPets, sizeof(Pets), 1, pets) != 0) {

                if (listPets.fileExist == 1) {
                    printf("\n#-----------------------------------------#");
                    printf("\n| > Codigo: %.3d                           |", listPets.codPet);
                    printf("\n#-----------------------------------------#");
                    printf("\n > Nome do pet: %s", listPets.namePet);
                    printf(" > Data de nascimento do pet: %s", listPets.datePet);
                    printf(" > Tipo do pet: %s", listPets.typePet);
                    printf(" > Codigo do usuario: %.3d", listPets.codUser);
                }


            }
        }
    }
    fclose(pets);
    fclose(persons);
    fclose(chvPet);
}

void changePetsUI(){
    int codPet,codUser;
    char *Name = malloc(sizeof(int) * sizeMaxNames);
    char *Date = malloc(sizeof(char) * 9);
    char *Type = malloc(sizeof(char) * 50);

    printf("\n#---------------------------------------------------#");
    printf("\n|     DIGITE O CODIGO DO PET QUE DESEJA ALTERAR     |");
    printf("\n#---------------------------------------------------#");
    printf("\n > ");
    scanf("%d",&codPet);
    codPet--;

    printf(" > Nome do pet:");
    fflush(stdin);
    fgets(Name, sizeMaxNames, stdin);

    printf(" > Data de nascimento:");
    fflush(stdin);
    fgets(Date, 9, stdin);

    printf(" > Tipo do pet:");
    fflush(stdin);
    fgets(Type, 50, stdin);
    //fgets é pra pegar as strings com espaço, o fflush serve pra tirar todo o lixo da string

    printf("\n#-----------------------------------------#");
    printf("\n| > CODIGO DO DONO DO PET:                |");
    printf("\n#-----------------------------------------#");
    printf("\n > ");
    scanf("%d", &codUser);

    changePets("pets.bin",Name,Date,Type,codUser,codPet);

}

void changePets(char *file_path,char *Name,char *Date,char *Type,int codUser,int codPet){
    Pets *current;
    current=(Pets *)malloc(sizeof(Pets));

    FILE *archive=NULL;
    archive=fopen(file_path,"rb+");
    if(archive==NULL)
        archive=fopen(file_path,"wb+");


    strcpy(current->namePet,Name);
    strcpy(current->datePet,Date);
    strcpy(current->typePet,Type);
    current->codUser=codUser;
    current->codPet=codPet+1;
    current->fileExist=1;

    free(Name);
    free(Date);
    free(Type);
    fseek(archive,sizeof(Pets)*codPet,SEEK_SET);
    fwrite(current,sizeof(Pets),1,archive);
    fclose(archive);
    free(current);
}

void searchByPetCode(char *file_path,int codPet) {
    codPet--;
    FILE *archive = NULL;
    Pets listPets;
    archive = fopen(file_path, "rb");

    fseek(archive, sizeof(Pets) * codPet, SEEK_SET);
    fread(&listPets, sizeof(Pets), 1, archive);
    if (listPets.fileExist==1) {
        printf("\n#-----------------------------------------#");
        printf("\n| > Codigo: %.3d                           |", listPets.codPet);
        printf("\n#-----------------------------------------#");
        printf("\n > Nome do pet: %s", listPets.namePet);
        printf(" > Data de nascimento do pet: %s", listPets.datePet);
        printf(" > Tipo do pet: %s", listPets.typePet);
        printf(" > Codigo do usuario: %.3d", listPets.codUser);
    }
    else{
        printf("\n#-----------------------------------------#");
        printf("\n|       CADASTRO  NAO ENCONTRADO          |");
        printf("\n#-----------------------------------------#");


    }
}

int searchByUserCode(char *file_path,int codUser){

    FILE *pets;
    FILE *chvPet;
    int codPet=0,countPets=0;
    Pets listPets;
    pets=fopen(file_path,"rb");
    chvPet=fopen("keyPets.chv","rb");

    fseek(chvPet,0,SEEK_SET);
    fread(&codPet,sizeof(int),1,chvPet);

    for(int j=0;j<codPet;j++) {
        fseek(pets, sizeof(Pets) * j, SEEK_SET);
        fread(&listPets, sizeof(Pets), 1, pets);
        if (listPets.codUser == codUser && listPets.fileExist==1) {
            printf("\n#-----------------------------------------#");
            printf("\n| > Codigo: %.3d                           |", listPets.codPet);
            printf("\n#-----------------------------------------#");
            printf("\n > Nome do pet: %s", listPets.namePet);
            printf(" > Data de nascimento do pet: %s", listPets.datePet);
            printf(" > Tipo do pet: %s", listPets.typePet);
            printf(" > Codigo do usuario: %.3d", listPets.codUser);
            countPets++;
        }
    }
    if(countPets==0) {
        printf("\n#-----------------------------------------#");
        printf("\n|           NENHUM PET ENCONTRADO         |");
        printf("\n#-----------------------------------------#");
        return 0;
    }


}

int compareNamePet (const void *a, const void *b) {
    return strcmp (((Pets *)a)->namePet,((Pets *)b)->namePet);
}

void orderAlfPet(char *file_path) {

    Pets listPets;
    int codPet = 0;

    FILE *Pet;
    FILE *chvPet;

    Pet = fopen(file_path, "rb");
    chvPet = fopen("keyPets.chv", "rb");

    fread(&codPet, sizeof(int), 1, chvPet);
    printf("%d", codPet);
    int auxCod=codPet;
    Pets allPets[codPet - 1];
    for (int i = 0; i < codPet; i++) {
        fseek(Pet, sizeof(Pets) * i, SEEK_SET);
        fread(&listPets, sizeof(Pets), 1, Pet);
        strcpy(allPets[i].namePet, listPets.namePet);
        strcpy(allPets[i].typePet, listPets.typePet);
        strcpy(allPets[i].datePet, listPets.datePet);
        allPets[i].codUser = listPets.codUser;
        allPets[i].codPet = listPets.codPet;
        allPets[i].fileExist = listPets.fileExist;


    }

    qsort(allPets, codPet, sizeof(Pets), compareNamePet);
    for (int i = 0; i < auxCod; i++) {
        if (allPets[i].fileExist == 1) {
            printf("\n#-----------------------------------------#");
            printf("\n| > Codigo: %.3d                           |", allPets[i].codPet);
            printf("\n#-----------------------------------------#");
            printf("\n > Nome do pet: %s", allPets[i].namePet);
            printf(" > Data de nascimento do pet: %s", allPets[i].datePet);
            printf(" > Tipo do pet: %s", allPets[i].typePet);
            printf(" > Codigo do usuario: %.3d", allPets[i].codUser);
        }
    }
}