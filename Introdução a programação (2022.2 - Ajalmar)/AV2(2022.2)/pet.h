#ifndef PET_H
#define PET_H

#define sizeMaxNames 255
int codPet;
typedef struct Pet{
    char namePet[sizeMaxNames];
    char datePet[9];
    int codPet;
    int codUser;
    char typePet[50];
    int fileExist;
}Pets;

int nextCodePet();

void insertPetsUI();

int checkCodUser(char *file_path,int codUser);

int checkCodPet(char *file_path,int codUser);

void insertPets(char *file_path,char *Name,char *Date,char *Type,int codUser);

int deletePets(char *file_path,int codPet);

int compareNamePet (const void *a, const void *b);

void orderAlfPet(char *file_path);

void listPets(char *file_path);

void changePetsUI();

void changePets(char *file_path,char *Name,char *Date,char *Type,int codUser,int codPet);

void searchByPetCode(char *file_path,int codPet);

int searchByUserCode(char *file_path,int codUser);

#endif //PET_H