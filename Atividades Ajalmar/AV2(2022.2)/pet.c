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

    fseek(chv, 0, SEEK_SET);
    fread(&codPet, sizeof(int), 1, chv);
    return codPet;
}

void insertPetsUI() {
    int codUser;
    char *Name=malloc(sizeof(char)*sizeMaxNames);
    char *Date=malloc(sizeof(char)*9);
    char *Type=malloc(sizeof(char)*50);

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
    scanf("%d",&codUser);

   insertPets("pets.bin",Name,Date,Type,codUser);
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

}

void listPets(char *file_path){
    FILE *pets;
    FILE *chvPet=NULL;
    int codPet=0;
    Pets listPets;

    pets=fopen(file_path,"rb");
    chvPet=fopen("keyPets.chv","rb");

    fseek(chvPet,0,SEEK_SET);
    fread(&codPet,sizeof(int),1,chvPet);

    printf("%d",codPet);
    for(int j=0;j<codPet;j++)
    {
        fseek(pets, sizeof(Pets) * j, SEEK_SET);
        fread(&listPets, sizeof(Pets), 1, pets);
        if(listPets.fileExist==1) {
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

void changePetsUI(){
    int codPet;
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

    changePets("pets.bin",Name,Date,Type,codPet);

}

void changePets(char *file_path,char *Name,char *Date,char *Type,int codPet){
    codPet--;
    Pets *current;
    current=(Pets *)malloc(sizeof(Pets));

    FILE *archive=NULL;
    archive=fopen(file_path,"rb+");
    if(archive==NULL)
        archive=fopen(file_path,"wb+");


    strcpy(current->namePet,Name);
    strcpy(current->datePet,Date);
    strcpy(current->typePet,Type);
    current->codPet=codPet+1;

    free(Name);
    free(Date);
    free(Type);

    fseek(archive,sizeof(Pets)*codPet,SEEK_END);
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
        printf("\n|          CADASTRO ENCONTRADO            |");
        printf("\n#-----------------------------------------#");

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

void searchByUserCode(char *file_path,int codUser){
    codUser--;
    FILE *pets;
    FILE *chvPet;
    int codPet=0;
    Pets listPets;

    pets=fopen(file_path,"rb");
    chvPet=fopen("keyPets.chv","rb");

    fseek(chvPet,0,SEEK_SET);
    fread(&codPet,sizeof(int),1,chvPet);

    for(int j=0;j<codPet;j++) {
        fseek(pets, sizeof(Pets) * j, SEEK_SET);
        fread(&listPets, sizeof(Pets), 1, pets);
        if (listPets.codUser == codUser) {
            printf("\n#-----------------------------------------#");
            printf("\n| > Codigo: %.3d                           |", listPets.codPet);
            printf("\n#-----------------------------------------#");
            printf("\n > Nome do pet: %s", listPets.namePet);
            printf(" > Data de nascimento do pet: %s", listPets.datePet);
            printf(" > Tipo do pet: %s", listPets.typePet);
            printf(" > Codigo do usuario: %.3d", listPets.codUser);
        } else {
            printf("\n#-----------------------------------------#");
            printf("\n|           PET NAO ENCONTRADO            |");
            printf("\n#-----------------------------------------#");


        }
    }

}

int compareNamePet (const void *a, const void *b) {
    return strcmp (((Pets *)a)->namePet,((Pets *)b)->namePet);
}

void orderAlfPet(char *file_path){

    Pets listPets;
    int codPet=0;

    FILE *Pet;
    FILE *chvPet;

    Pet=fopen(file_path,"rb");
    chvPet=fopen("keyPets.chv","rb");

    fread(&codPet,sizeof(int),1,chvPet);
    printf("%d",codPet);
    int auxCod=codPet;
    Pets allPets[codPet-1];
    for(int i=0;i<codPet;i++) {
        fseek(Pet, sizeof(Pets) * i, SEEK_SET);
        fread(&listPets,sizeof(Pets),1,Pet);

        strcpy(allPets[i].namePet,listPets.namePet);
        strcpy(allPets[i].typePet,listPets.typePet);
        strcpy(allPets[i].datePet,listPets.datePet);
        allPets[i].codUser=listPets.codUser;
        allPets[i].codPet=listPets.codPet;
    }

    qsort(allPets, codPet, sizeof(Pets), compareNamePet);
    printf("%d",allPets[0].namePet);
    for(int i=0;i<auxCod;i++) {
        printf("\n#-----------------------------------------#");
        printf("\n| > Codigo: %.3d                           |", allPets[i].codPet);
        printf("\n#-----------------------------------------#");
        printf("\n > Nome do pet: %s", allPets[i].namePet);
        printf(" > Data de nascimento do pet: %s", allPets[i].datePet);
        printf(" > Tipo do pet: %s", allPets[i].typePet);
        printf(" > Codigo do usuario: %.3d", allPets[i].codUser);
    }




}