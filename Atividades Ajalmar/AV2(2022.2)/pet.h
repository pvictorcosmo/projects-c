#define sizeMaxNames 255
int codPet;
typedef struct Pet{
    char namePet[sizeMaxNames];
    char datePet[9];
    int codPet;
    int codUser;
    char typePet[50];
    struct Pet *next;
    int fileExist;
}Pets;

int nextCodePet();

void insertPetsUI();

void insertPets(char *file_path,char *Name,char *Date,char *Type,int codUser);

int compareNamePet (const void *a, const void *b);

void orderAlfPet(char *file_path);

void listPets(char *file_path);

void changePetsUI();

void changePets(char *file_path,char *Name,char *Date,char *Type,int codPet);

void searchByPetCode(char *file_path,int codPet);

void searchByUserCode(char *file_path,int codUser);