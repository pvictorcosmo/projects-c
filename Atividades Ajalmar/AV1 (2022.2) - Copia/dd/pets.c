#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pets.h"

void iniciar_pets() /* Essa função é responsável por tirar todo o "lixo" do vetor e permitir que sua futura ocupação
               ocorra corretamente. */
{
    int i = 0; 
    for(i = 0; i < QUANT_PETS; i++)
    {
        livres_pets[i] = 1;
    }
    return;
}

int existir_codigo_pet(char cod_pets[]) // nao tá contando pq temos q achar onde colocar a variavel de cod_pets = 1000 pra contar++//
{
    int i = 0;
    int index = -1;
    for(i = 0; i < QUANT_PETS; i++)
    {
        if(livres_pets[i] == 0 && !strcmp(codigos_pets[i], cod_pets))
        {
            index = i;
            break;
        }
    }
    return index;// o index irá indicar o endereço da informação que já existe
}

void cadastrar_pets(char cod_pet[], char cod_dono[], char nome_pet[], char data_pet[], char tipo_pet[])
{
    int indice = existir_codigo_pet(cod_pet); //verifica se o código passado no argumento já existe
    if(indice != -1)
    {
        printf("Código já cadastrado no sistema!\n");
        return;
    }
    
    int i = 0;
    for(i = 0; i < QUANT_PETS; i++)
    {
        if(livres_pets[i] == 1)
        {
            indice = i;
            break;
        }
    }
    
    if(indice == -1) //se o índice ainda for -1 depois das linhas de código executadas anteriormente, significa que não há mais espaço para cadastrar outra pessoa
    {
        printf("Não há mais espaço no banco de dados! Por favor, libere espaço para realizar o cadastro!.\n");
        return;
    }
    
    //agora os vetores irão ser preenchidos com os argumentos passados pelo usuário
    strcpy (codigos_pets[indice], cod_pet); 
    strcpy (codigos_donos[indice], cod_dono);
    strcpy (nomes_pets[indice], nome_pet);
    strcpy (datas_pets[indice], data_pet);
    strcpy (especies[indice], tipo_pet);
    
    return;
}

void alterar_pets(char cod_pet[], char novo_cod_pet[], char novo_cod_dono[], char novo_nome_pet[], char nova_data_pet[], char novo_tipo_pet[])
{
    int indice;
    int i = 0; 
    for(i = 0; i < 10; i++)
    {
        if((livres_pets[i] == 0) && !strcmp(codigos_pets[i], cod_pet) && strcmp(cod_pet, novo_cod_pet))
        {
            indice = i;
            break;
        }
    }
    
    strcpy (codigos_pets[indice], novo_cod_pet);
    strcpy (codigos_donos[indice], novo_cod_dono);
    strcpy (nomes_pets[indice], novo_nome_pet);
    strcpy (datas_pets[indice], nova_data_pet);
    strcpy (especies[indice], novo_tipo_pet);
    
    return;
}

void excluir_pets(char cod_pet[]) //irá excluir o cadastro de uma pessoa a partir do código dela
{
    int i = 0; 
    for(i = 0; i < 10; i++)
    {
        if(livres_pets[i] == 0 && !strcmp(codigos_pets[i], cod_pet))
        {
            livres_pets[i] = 1;
            break;
        }
    }
    
    return;
}

void listar_cod_pets(char cod_pet[])
{
    int indice = existir_codigo_pet(cod_pet);
    
    int i = 0; 
    for(i = 0; i < 10; i++)
    {
        if(livres_pets[i] == 0)
        {
            printf("Cadastro da pessoa com o código %s:\n", codigos_pets[indice]);
            printf("Nome: %s\n", nomes_pets[indice]);
            printf("Data de nascimento: %s\n", datas_pets[indice]);
            printf("Espécie: %s\n", especies[indice]);
            printf("///////////////////////////////////////////////////.\n");
            printf("\n");
        }
    }
    
    return;
}

void listar_pets_alfabeticamente()
{
    char nomes_pets[QUANT_PETS][255];
    aux_nomes_pets[255];
    
    int i = 0, j = 0;
    for(i = 1; i < QUANT_PETS; i++) 
    {
        for(j = 1; j < 3; j++) 
        {
            if (strcmp(nomes_pets[j - 1], nomes_pets[j]) > 0) 
            {
            strcpy(aux_nomes_pets, nomes_pets[j - 1]);
            strcpy(nomes_pets[j - 1], nomes_pets[j]);
            strcpy(nomes_pets[j], aux_nomes_pets);
            }   
        }
    }
    
    for (i = 0; i < QUANT_PETS; i++)
    {
    printf("\n%s", nomes_pets[i]);
    }
    
    return;
}