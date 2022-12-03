#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<conio.h>
#include<ctype.h>

int i,j,g,h,J,I;
int aux;
int testcode;
int resp3;
char resp2[12];
char resp;
char init;
char cpf_format[25];
char rg_format[25];
char datanasc_format[25];
char datanascpet_format[25];

void start();

void space();

char *Str(char *string_base);

void format(char *text,char format[],char final[]);

void Upper(char *str);

void funcs_clients_ui();