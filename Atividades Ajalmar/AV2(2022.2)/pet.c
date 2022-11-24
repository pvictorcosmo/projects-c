#include "pet.h"
#include "init.h"
#include "user.h"
int nextCodePet() {
    FILE *chv = NULL;
    chv = fopen("keyPet.chv", "rb+");
    if (chv == NULL)
        chv = fopen("keyPet.chv", "wb+");

    fseek(chv, 0, SEEK_SET);
    fread(&cod, sizeof(int), 1, chv);

    cod++;

    fseek(chv, 0, SEEK_SET);
    fwrite(&cod, sizeof(int), 1, chv);
    return cod-1;
}

void insertPetsUI() {
    char *Name=malloc(sizeof(char)*sizeMaxNames);
    char *Date=malloc(sizeof(char)*9);
    char *Type=malloc(sizeof(char)*50);

    printf(" > Nome do pet:");
    fflush(stdin);
    fgets(Name, sizeMaxNames, stdin);

    printf(" > Data de nascimento:");
    fflush(stdin);
    fgets(Date, 9, stdin);

    printf(" > Tipo do pet:");
    fflush(stdin);
    fgets(Type, 50, stdin);

   insertPets("pets.bin",Name,Date,Type);
}

void insertPets(char *file_path,char *Name,char *Date,char *Type){
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
    printf("%d",current->codPet);
    current->codUser=0;
    printf("%s",current->namePet);

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
    FILE *chvPet;
    int codPet=0;
    Pets listPets;

    pets=fopen(file_path,"rb");
    chvPet=fopen("keyPet.chv","rb");
    fseek(chvPet,0,SEEK_SET);
    fread(&codPet,sizeof(int),1,chvPet);
    codPet--;
    for(int j=0;j<codPet;j++)
    {
        fseek(pets, sizeof(Pets) * j, SEEK_SET);
        fread(&listPets, sizeof(Pets), 1, pets);
        printf("\n#-----------------------------------------#");
        printf("\n| > Codigo: %.3d                           |",listPets.codPet);
        printf("\n#-----------------------------------------#");
        printf("\n > Nome do pet: %s", listPets.namePet);
        printf(" > Tipo do pet: %s", listPets.typePet);
        printf(" > Codigo do usuario: %.3d", listPets.codUser);

    }
}