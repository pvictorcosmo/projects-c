#include "init.h"
#include "user.h"
#include "pet.h"

void interfaceProgram(){
    int option;
    enum options{users=1,pets};
    printf("\n#------------------MENU PRINCIPAL------------------#");
    printf("\n|                                                  |");
    printf("\n| 1- Para entrar na area de usuarios               |");
    printf("\n|                                                  |");
    printf("\n| 2- Para entrar na area de pets                   |");
    printf("\n|                                                  |");
    printf("\n|               By:Paulo Victor Cosmo              |");
    printf("\n#--------------------------------------------------#");
    printf("\n > ");
    scanf("%d",&option);
    switch(option){
        case(users):
            interfaceUser();
        break;

        case(pets):
            interfacePets();
        break;

    }

}

void interfaceUser(){
    person listPerson;
    int option,codUser,codPet;
    enum options{add_users=1,change_users,delete_users,list_users,search_by_code,search_by_pet,alphabetical_order,main_menu};
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
    printf("\n|               By:Paulo Victor Cosmo              |");
    printf("\n#--------------------------------------------------#");
    printf("\n > ");
    scanf("%d",&option);
    switch(option){

        case(add_users):
            insertPersonUI();
        break;

        case(change_users):
            changePersonUI();
        break;

        case(delete_users):
            printf("\n#---------------------------------------------------#");
            printf("\n|   DIGITE O CODIGO DO USUARIO QUE DESEJA EXCLUIR   |");
            printf("\n#---------------------------------------------------#");
            printf("\n > ");
            scanf("%d",&codUser);
            deletePerson("persons.bin",codUser);
            if(deletePerson) {
                printf("\n#---------------------------------------------------#");
                printf("\n|          USUARIO EXCLUIDO COM SUCESSO             |");
                printf("\n#---------------------------------------------------#");
            }

            printf("\n#---------------------------------------------#");
            printf("\n|  8 - Para voltar ao Menu de usuarios        |");
            printf("\n#---------------------------------------------#");
            printf("\n > ");
            scanf("%d",&option);
            if(option==8)
                interfaceUser();
        break;

        case(list_users):
            listPersons(listPerson,"persons.bin");

            printf("\n#---------------------------------------------#");
            printf("\n|  8 - Para voltar ao Menu de usuarios        |");
            printf("\n#---------------------------------------------#");
            printf("\n > ");
            scanf("%d",&option);
            if(option==8)
                interfaceUser();
        break;

        case(search_by_code):
            printf("\n#---------------------------------------------------#");
            printf("\n|            DIGITE O CODIGO DO USUARIO             |");
            printf("\n#---------------------------------------------------#");
            printf("\n > ");
            scanf("%d",&codUser);
            searchByCode("persons.bin",codUser);

            printf("\n#---------------------------------------------#");
            printf("\n|  8 - Para voltar ao Menu de usuarios        |");
            printf("\n#---------------------------------------------#");
            printf("\n > ");
            scanf("%d",&option);
            if(option==8)
                interfaceUser();

        break;

        case(search_by_pet):
            system("cls");
            printf("\n#---------------------------------------------------#");
            printf("\n|            DIGITE O CODIGO DO USUARIO             |");
            printf("\n#---------------------------------------------------#");
            printf("\n > ");
            scanf("%d",&codPet);
            searchByCode("persons.bin",codPet);

            printf("\n#---------------------------------------------#");
            printf("\n|  8 - Para voltar ao Menu de usuarios        |");
            printf("\n#---------------------------------------------#");
            printf(" > ");
            scanf("%d",&option);
            if(option==8)
                interfaceUser();

        break;

        case(alphabetical_order):
        break;

        case (main_menu):
            interfaceProgram();
        break;
    }

}

void interfacePets(){
    int option;
    enum options{add_pets=1,change_pets,delete_pets,list_pets,search_by_code,search_by_codeUser,alphabetical_order,main_menu};
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
    printf("\n| 7 - Listar usuarios em ordem alfabetica          |");
    printf("\n|                                                  |");
    printf("\n| 8 - Voltar ao Menu principal                     |");
    printf("\n|                                                  |");
    printf("\n|               By:Paulo Victor Cosmo              |");
    printf("\n#--------------------------------------------------#");
    printf("\n > ");
    scanf("%d",&option);
    switch(option){
        case (add_pets):
            insertPetsUI();
        break;

        case(change_pets):
            changePetsUI();
        break;

        case(delete_pets):
        break;

        case (list_pets):
            listPets("pets.bin");
        break;

        case(search_by_code):
            printf("\n#---------------------------------------------------#");
            printf("\n|            DIGITE O CODIGO DO USUARIO             |");
            printf("\n#---------------------------------------------------#");
            printf("\n > ");
            scanf("%d",&codPet);
            searchByPetCode("pets.bin",codPet);

            printf("\n#---------------------------------------------#");
            printf("\n|  8 - Para voltar ao Menu de usuarios        |");
            printf("\n#---------------------------------------------#");
            printf("\n > ");
            scanf("%d",&option);
            if(option==8)
                interfaceUser();
        break;

        case(search_by_codeUser):
        break;

        case(alphabetical_order):
        break;

        case(main_menu):
            interfaceProgram();
        break;
    }


}