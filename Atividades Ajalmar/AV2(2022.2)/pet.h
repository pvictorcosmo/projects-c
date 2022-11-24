#define sizeMaxNames 255
int codPet;
typedef struct Pet{
    char namePet[sizeMaxNames];
    char datePet[9];
    int codPet;
    int codUser;
    char typePet[50];
    struct Pet *next;
}Pets;

int nextCodePet();
void insertPetsUI();
void insertPets(char *file_path,char *Name,char *Date,char *Type);
void listPets(char *file_path);
