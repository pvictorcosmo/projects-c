#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoas.h"



void iniciar() /* Essa função é responsável por tirar todo o "lixo" do vetor e permitir que sua futura ocupação
               ocorra corretamente. */
{
    int i = 0; 
    for(i = 0; i < QUANT_PESSOAS; i++)
    {
        livres[i] = 1;
    }
    return;
} 

/* Agora vamos criar as funções que irão verificar se os dados de uma certa pessoa já existem, isso é essencial para 
que dados que não podem aparecer repetidos, como codigo, RG e CPF, cumpram esse requisito */

char ler_infos(char codigo[], char nome[], char RG[], char CPF[], char end[], char data_nascimento[], char salario[])
{   
    fflush(stdin);
    printf("\nCódigo de 4 dígitos:\n");
    fflush(stdin);
    fgets(codigo, 4, stdin);
    
    printf("\nNome:\n");
    fflush(stdin);
    fgets(nome, 255, stdin);
    
    printf("\nRG (utilize apenas números):\n");
    fflush(stdin);
    fgets(RG, 11, stdin);
    
    printf("\nCPF (utilize apenas números):\n");
    fflush(stdin);
    fgets(CPF, 11, stdin);
    
    printf("\nEndereço:\n");
    fflush(stdin);
    fgets(end, 255, stdin);
    
    printf("\nData de nascimento (dd/mm/aaaa):\n");
    fflush(stdin);
    fgets(data_nascimento, 10, stdin);
    
    printf("\nSalário (R$00000,00):\n");
    fflush(stdin);
    fgets(salario, 20, stdin);
}

int existir_codigo(char codigo[]) //verifica se o código digitado já existe no sistema
{
    int i = 0;
    int index = -1;
    for(i = 0; i < QUANT_PESSOAS; i++)
    {
        if(livres[i] == 0 && !strcmp(codigos[i], codigo))
        {
            index = i;
            break;
        }
    }
    return index;// o index irá indicar o endereço da informação que já existe
}

int existir_CPF(char CPF[]) //verifica se o CPF digitado já existe no sistema
{
    int i = 0;
    int index = -1;
    for(i = 0; i < QUANT_PESSOAS; i++)
    {
        if(livres[i] == 0 && !strcmp(CPFs[i], CPF))
        {
            index = i;
            break;
        }
    }
    return index;// o index irá indicar o endereço da informação que já existe
}

int existir_RG(char RG[]) ////verifica se o RG digitado já existe no sistema
{
    int i = 0;
    int index = -1;
    for(i = 0; i < QUANT_PESSOAS; i++)
    {
        if(livres[i] == 0 && !strcmp(RGs[i], RG))
        {
            index = i;
            break;
        }
    }
    return index;// o index irá indicar o endereço da informação que já existe
}

void inserir(char codigo[], char nome[], char RG[], char CPF[], char end[], char data_nascimento[], char salario[])
// cadastra o usuário passando no argumento as informações requisitadas

{
    int indice = existir_codigo(codigo); //verifica se o código passado no argumento já existe
    if(indice != -1)
    {
        printf("Código já cadastrado no sistema!\n");
        return;
    }
    
    int i = 0;
    for(i = 0; i < QUANT_PESSOAS; i++)
    {
        if(livres[i] == 1)
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
    
    int verificar_RG = existir_RG(RG); //verifica se o RG já existe no sistema, pois não pode haver mais de uma pessoa com o mesmo RG 
    if(verificar_RG != -1)
    {
        printf("RG já cadastrado no sistema!\n");
        return;
    }
    
    int verificar_CPF = existir_CPF(CPF); //verifica se o CPF já existe no sistema, pois não pode haver mais de uma pessoa com o mesmo CPF
    if(verificar_CPF != -1)
    {
        printf("CPF já cadastrado no sistema!\n");
        return;
    }
    
    //agora os vetores irão ser preenchidos com os argumentos passados pelo usuário
    strcpy (codigos[indice], codigo); 
    strcpy (nomes[indice], nome);
    strcpy (RGs[indice], RG);
    strcpy (CPFs[indice], CPF);
    strcpy (ends[indice], end);
    strcpy (datas_nascimento[indice], data_nascimento);
    strcpy (salarios[indice], salario);
    
    livres[indice] = 0;
    printf("ÍNDICE:%d\n", indice);
    
    return;
}

void alterar_cadastro(char codigo[], char novo_codigo[], char novo_nome[], char novo_RG[], char novo_CPF[], char novo_end[], char nova_data_nascimento[], char novo_salario[])
//irá localizar o código da pessoa já existente, para, assim, alterar o seu cadastro com as novas informações
{
    int indice;
    int i = 0; 
    for(i = 0; i < QUANT_PESSOAS; i++)
    {
        if((livres[i] == 0) && !strcmp(codigos[i], codigo) && strcmp(codigo, novo_codigo))
        {
            indice = i;
            break;
        }
    }
    
    int verificar_RG = existir_RG(novo_RG);
    if(verificar_RG != -1)
    {
        printf("RG já cadastrado no sistema!\n");
        return;
    }
    
    int verificar_CPF = existir_CPF(novo_CPF);
    if(verificar_CPF != -1)
    {
        printf("CPF já cadastrado no sistema!\n");
        return;
    }
    
    strcpy (codigos[indice], novo_codigo);
    strcpy (nomes[indice], novo_nome);
    strcpy (RGs[indice], novo_RG);
    strcpy (CPFs[indice], novo_CPF);
    strcpy (ends[indice], novo_end);
    strcpy (datas_nascimento[indice], nova_data_nascimento);
    strcpy (salarios[indice], novo_salario);
    
    return;
}

void excluir_cadastro(char codigo[]) //irá excluir o cadastro de uma pessoa a partir do código dela
{
    int i = 0; 
    for(i = 0; i < QUANT_PESSOAS; i++)
    {
        if(livres[i] == 0 && !strcmp(codigos[i], codigo))
        {
            livres[i] = 1;
            break;
        }
    }
    
    return;
}

void listar_codigo(char codigo[]) //lista as informações da pessoa com base no código dela
{
    int indice = existir_codigo(codigo);
    
    int i = 0; 
    for(i = 0; i < QUANT_PESSOAS; i++)
    {
        if(livres[i] == 0 && !strcmp(codigos[indice], codigo))
        {
            printf("Cadastro da pessoa com o código %s:\n", codigo);
            printf("Nome: %s\n", nomes[indice]);
            printf("RG: %s\n", RGs[indice]);
            printf("CPF: %s\n", CPFs[indice]);
            printf("Endereço: %s\n", ends[indice]);
            printf("Data de nascimento: %s\n", datas_nascimento[indice]);
            printf("Salário: %s\n", salarios[indice]);
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
            printf("\n");
        }
    }
    
    return;
}

void listar_pessoas() //lista o nome de todas as pessoas cadastradas
{
    int i = 0; 
    for(i = 0; i < QUANT_PESSOAS; i++)
    {
        if(livres[i] == 0)
        {
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
            printf("Código: %s\n", codigos[i]);
            printf("Nome: %s\n", nomes[i]);
            printf("RG: %s\n", RGs[i]);
            printf("CPF: %s\n", CPFs[i]);
            printf("Endereço: %s\n", ends[i]);
            printf("Data de Nascimento: %s\n", datas_nascimento[i]);
            printf("Salário: %s\n", salarios[i]);
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        }
    }
}

void ordenar_alfabeticamente() //lista o nome das pessoas cadastradas em ordem alfabética
{
    char nomes[QUANT_PESSOAS][255];
    aux_nomes[255];
    
    int i = 0, j = 0;
    for(i = 1; i < QUANT_PESSOAS; i++) 
    {
        for(j = 1; j < 3; j++) 
        {
            if (strcmp(nomes[j - 1], nomes[j]) > 0) 
            {
            strcpy(aux_nomes, nomes[j - 1]);
            strcpy(nomes[j - 1], nomes[j]);
            strcpy(nomes[j], aux_nomes);
            }   
        }
    }
    
    for (i = 0; i < QUANT_PESSOAS; i++)
    {
    printf("\n%s", nomes[i]);
    }
    
    return;
}
