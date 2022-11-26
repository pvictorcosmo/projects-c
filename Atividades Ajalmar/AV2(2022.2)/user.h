#include "init.h"

#define sizeMaxNames 255
int cod;
typedef struct User{
  int codUser;
  char nameUser[sizeMaxNames];
  char cpfUser[12];
  char rgUser[12];
  char dateUser[9];
  char addressUser[sizeMaxNames];
  char phoneUser[20];
  char incomeUser[20];
  int fileExist;
}person;

int nextCode();
void insertPerson(char *file_path,char *Rg,char *Cpf,char *Name,char *Address,char *Date,char *Phone,char *Income );

void insertPersonUI();

void listPersons(person listPerson,char *file_path);

void changePersonUI();

void changePerson(char *file_path,char *Rg,char *Cpf,char *Name,char *Address,char *Date,char *Phone,char *Income,int codUser );

void deletePerson(char *file_path,int codUser);

void searchByCode(char *file_path,int codUser);

void searchByTypePet(char *file_path, char *Type);

int compareName (const void *a, const void *b);

void orderAlfUser(char *file_path);

