#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct pessoa {
    char nome[20];
    char end[20];
    char cpf[12];
};

int compararNome (const void *a, const void *b) {
    return strcmp (((struct pessoa *)a)->nome,((struct pessoa *)b)->nome);
}

int main () {
    int i;
    int idades[]={9,7,8,5,2};
    char nomes[][20] =  {"Joao","Pedro","Ana","Maria","Teste"};
    char ends[][20] =  {"fortal","ceara","brasil","portuga","israel"};
    char cpfs[][20] =  {"1234","08820813","cpffoda","cpfbebe","3753354"};

    struct pessoa item[5];

    printf("Pessoas sem ordem:\n");
    for (i = 0; i < 5; i++) {
        strcpy(item[i].nome, nomes[i]);
        strcpy(item[i].end, ends[i]);
        strcpy(item[i].cpf, cpfs[i]);


    }

    qsort(item, 5, sizeof(struct pessoa), compararNome);

    printf("Pessoas ordenadas por nome:\n");
    for (i = 0; i < 5; i++) {
        printf("Nome: %s,cpf: %s, end=%s\n", item[i].nome, item[i].cpf,item[i].end);
    }

    return(0);
}