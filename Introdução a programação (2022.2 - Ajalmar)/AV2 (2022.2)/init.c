#include "init.h"
#include "user.h"
#include "pet.h"

void interfaceProgram() {
    system("cls");
    int option;
    enum options {
        users = 1, pets
    };

    printf("\n#------------------MENU PRINCIPAL------------------#");
    printf("\n|                                                  |");
    printf("\n| 1 - Para entrar na area de usuarios              |");
    printf("\n|                                                  |");
    printf("\n| 2 - Para entrar na area de pets                  |");
    printf("\n|                                                  |");
    printf("\n#--------------------------------------------------#");
    do {
        printf("\n > ");
        scanf("%d", &option);
        switch (option) {
            case (users):
                interfaceUser();
                break;

            case (pets):
                interfacePets();
                break;
        }
    }while (option != 1);

}

    void interfaceUser() {
        system("cls");
        person listPerson;
        char *TypePet = (char *) malloc(sizeof(char) * 50), *Names;
        int option, codUser, codPet;
        enum options {
            add_users = 1,
            change_users,
            delete_users,
            list_users,
            search_by_code,
            search_by_pet,
            alphabetical_order,
            main_menu
        };
        system("cls");
        printf("\n#------------------MENU DE USUARIOS----------------#");
        printf("\n|                                                  |");
        printf("\n| 1 - Adicionar um usuario                         |");
        printf("\n|                                                  |");
        printf("\n| 2 - Alterar um usuario                           |");
        printf("\n|                                                  |");
        printf("\n| 3 - Excluir um usuario                           |");
        printf("\n|                                                  |");
        printf("\n| 4 - Listar todos os usuarios cadastrados         |");
        printf("\n|                                                  |");
        printf("\n| 5 - Buscar usuario com base no codigo            |");
        printf("\n|                                                  |");
        printf("\n| 6 - Buscar usuarios com tipo de pet especifico   |");
        printf("\n|                                                  |");
        printf("\n| 7 - Listar usuarios em ordem alfabetica          |");
        printf("\n|                                                  |");
        printf("\n| 8 - Voltar ao Menu principal                     |");
        printf("\n|                                                  |");
        printf("\n#--------------------------------------------------#");
        printf("\n > ");
        scanf("%d", &option);
        switch (option) {

            case (add_users):
                insertPersonUI();

                printf("\n#---------------------------------------------------#");
                printf("\n|          USUARIO INSERIDO COM SUCESSO             |");
                printf("\n#---------------------------------------------------#");

                do {
                    printf("\n#---------------------------------------------------#");
                    printf("\n|  1 - Para voltar ao Menu de usuarios              |");
                    printf("\n#---------------------------------------------------#");
                    printf("\n > ");
                    scanf("%d", &option);
                    if (option == 1) {
                        interfaceUser();
                    }
                }while(option!=1);
            break;

            case (change_users):
                changePersonUI();

                printf("\n#---------------------------------------------------#");
                printf("\n|          USUARIO ALTERADO COM SUCESSO             |");
                printf("\n#---------------------------------------------------#");

                do {
                printf("\n#---------------------------------------------------#");
                printf("\n|  1 - Para voltar ao Menu de usuarios              |");
                printf("\n#---------------------------------------------------#");

                printf("\n > ");
                scanf("%d", &option);
                    if (option == 1) {
                        interfaceUser();
                    }
                }while(option!=1);
            break;

            case (delete_users):
                printf("\n#---------------------------------------------------#");
                printf("\n|   DIGITE O CODIGO DO USUARIO QUE DESEJA EXCLUIR   |");
                printf("\n#---------------------------------------------------#");
                printf("\n > ");
                scanf("%d", &codUser);

                deletePerson("persons.bin", codUser);

                printf("\n#---------------------------------------------------#");
                printf("\n|          USUARIO EXCLUIDO COM SUCESSO             |");
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
            break;

            case (list_users):
                listPersons(listPerson, "persons.bin");
                do {
                    printf("\n#-----------------------------------------#");
                    printf("\n|  1 - Para voltar ao Menu de usuarios    |");
                    printf("\n#-----------------------------------------#");
                    printf("\n > ");
                    scanf("%d", &option);
                    if (option == 1)
                        interfaceUser();
                } while (option != 1);

                break;

            case (search_by_code):
                printf("\n#---------------------------------------------------#");
                printf("\n|            DIGITE O CODIGO DO USUARIO             |");
                printf("\n#---------------------------------------------------#");
                printf("\n > ");
                scanf("%d", &codUser);
                searchByCode("persons.bin", codUser);
                do {
                    printf("\n#---------------------------------------------------#");
                    printf("\n|  1 - Para voltar ao Menu de usuarios              |");
                    printf("\n#---------------------------------------------------#");
                    printf("\n > ");
                    scanf("%d", &option);
                    if (option == 1)
                        interfaceUser();
                } while (option != 1);
                break;

            case (search_by_pet):
                system("cls");

                printf("\n#---------------------------------------------------#");
                printf("\n|                DIGITE O TIPO DE PET               |");
                printf("\n#---------------------------------------------------#");
                printf("\n > ");
                fflush(stdin);
                fgets(TypePet,50,stdin);
                searchByTypePet("pets.bin", TypePet);
                do {
                    printf("\n#---------------------------------------------#");
                    printf("\n|  1 - Para voltar ao Menu de usuarios        |");
                    printf("\n#---------------------------------------------#");
                    printf("\n > ");
                    scanf("%d", &option);
                    if (option == 1)
                        interfaceUser();
                } while (option != 1);
                break;

            case (alphabetical_order):
                orderAlfUser("persons.bin");
                do {
                    printf("\n#---------------------------------------------#");
                    printf("\n|  1 - Para voltar ao Menu de pets            |");
                    printf("\n#---------------------------------------------#");
                    printf("\n > ");
                    scanf("%d", &option);
                    if (option == 1)
                        interfaceUser();
                } while (option != 1);
                break;

            case (main_menu):
                interfaceProgram();
                break;

            default:
                printf("\n#---------------------------------------------------#");
                printf("\n|                 OPCAO INEXISTENTE                 |");
                printf("\n#---------------------------------------------------#");
                interfaceUser();
        }

    }

    void interfacePets(){
        system("cls");
        int option, codUser, codPet;
        enum options {
            add_pets = 1,
            change_pets,
            delete_pets,
            list_pets,
            search_by_code,
            search_by_codeUser,
            alphabetical_order,
            main_menu
        };
        system("cls");
        printf("\n#--------------------MENU DE PETS------------------#");
        printf("\n|                                                  |");
        printf("\n| 1 - Adicionar um pet                             |");
        printf("\n|                                                  |");
        printf("\n| 2 - Alterar um pet                               |");
        printf("\n|                                                  |");
        printf("\n| 3 - Excluir um pet                               |");
        printf("\n|                                                  |");
        printf("\n| 4 - Listar todos os pets cadastrados             |");
        printf("\n|                                                  |");
        printf("\n| 5 - Buscar pets com base no codigo               |");
        printf("\n|                                                  |");
        printf("\n| 6 - Listar todos os pets de um usuario           |");
        printf("\n|                                                  |");
        printf("\n| 7 - Listar pets em ordem alfabetica              |");
        printf("\n|                                                  |");
        printf("\n| 8 - Voltar ao Menu principal                     |");
        printf("\n|                                                  |");
        printf("\n#--------------------------------------------------#");
        printf("\n > ");
        scanf("%d", &option);
        switch (option) {

            case (add_pets):
                insertPetsUI();

                do {
                    printf("\n#---------------------------------------------#");
                    printf("\n|  1 - Para voltar ao Menu de pets            |");
                    printf("\n#---------------------------------------------#");
                    printf("\n > ");
                    scanf("%d", &option);
                    if (option == 1)
                        interfacePets();
                } while (option != 1);
                break;

            case (change_pets):
                changePetsUI();
                do {
                    printf("\n#---------------------------------------------#");
                    printf("\n|  1 - Para voltar ao Menu de pets            |");
                    printf("\n#---------------------------------------------#");
                    printf("\n > ");
                    scanf("%d", &option);
                    if (option == 1)
                        interfacePets();
                } while (option != 1);
                break;

            case (delete_pets):
                printf("\n#---------------------------------------------------#");
                printf("\n|     DIGITE O CODIGO DO PET QUE DESEJA EXCLUIR     |");
                printf("\n#---------------------------------------------------#");
                printf("\n > ");
                scanf("%d", &codPet);

                deletePets("pets.bin", codPet);

                printf("\n#---------------------------------------------------#");
                printf("\n|             PET EXCLUIDO COM SUCESSO              |");
                printf("\n#---------------------------------------------------#");

                do {
                    printf("\n#---------------------------------------------#");
                    printf("\n|  1 - Para voltar ao Menu de pets            |");
                    printf("\n#---------------------------------------------#");
                    printf("\n > ");
                    scanf("%d", &option);
                    if (option == 1)
                        interfacePets();
                } while (option != 1);

            break;

            case (list_pets):
                listPets("pets.bin");
                do {
                    printf("\n#---------------------------------------------#");
                    printf("\n|  1 - Para voltar ao Menu de usuarios        |");
                    printf("\n#---------------------------------------------#");
                    printf("\n > ");
                    scanf("%d", &option);
                    if (option == 1)
                        interfacePets();
                } while (option != 1);

                break;

            case (search_by_code):
                printf("\n#---------------------------------------------------#");
                printf("\n|            DIGITE O CODIGO DO PET                 |");
                printf("\n#---------------------------------------------------#");
                printf("\n > ");
                scanf("%d", &codPet);
                searchByPetCode("pets.bin",codPet);

                do {
                    printf("\n#---------------------------------------------#");
                    printf("\n|  1 - Para voltar ao Menu de usuarios        |");
                    printf("\n#---------------------------------------------#");
                    printf("\n > ");
                    scanf("%d", &option);
                    if (option == 1)
                        interfacePets();
                } while (option != 1);
                break;

            case (search_by_codeUser):

                printf("\n#---------------------------------------------------#");
                printf("\n|            DIGITE O CODIGO DO USUARIO             |");
                printf("\n#---------------------------------------------------#");
                printf("\n > ");
                scanf("%d", &codUser);
                searchByUserCode("pets.bin", codUser);

                do {
                    printf("\n#---------------------------------------------#");
                    printf("\n|  1 - Para voltar ao Menu de usuarios        |");
                    printf("\n#---------------------------------------------#");
                    printf("\n > ");
                    scanf("%d", &option);
                    if (option == 1)
                        interfacePets();
                } while (option != 1);
                break;

            case (alphabetical_order):
                orderAlfPet("pets.bin");
                do {
                    printf("\n#---------------------------------------------#");
                    printf("\n|  1 - Para voltar ao Menu de usuarios        |");
                    printf("\n#---------------------------------------------#");
                    printf("\n > ");
                    scanf("%d", &option);
                    if (option == 1)
                        interfacePets();
                } while (option != 1);
                break;

            case (main_menu):
                interfaceProgram();
                break;

            default:
                printf("\n#---------------------------------------------------#");
                printf("\n|                 OPCAO INEXISTENTE                 |");
                printf("\n#---------------------------------------------------#");
                interfaceUser();
        }


    }

    void format(char *text, char *format, char *final) {

        int i = 0;
        while (*text) {
            if (format[i] != '#') {
                final[i] = format[i];
                i++;
            } else {
                final[i] = *text;
                text++;
                i++;
            }
        }
        final[i] = 0;

    }



