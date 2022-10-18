#define QUANT_PESSOAS 30

char livres[QUANT_PESSOAS]; //lógicos, 0 (ocupado) ou 1 (desocupado)
char codigos[QUANT_PESSOAS][4]; //código da pessoa, não pode haver códigos repetidos
char nomes[QUANT_PESSOAS][255]; //nome da pessoa
char RGs[QUANT_PESSOAS][11]; //RG da pessoa, não pode haver RGs repetidos
char CPFs[QUANT_PESSOAS][11]; //CPF da pessoa, não pode haver CPFs repetidos
char ends[QUANT_PESSOAS][255]; //endereço da pessoa
char datas_nascimento[QUANT_PESSOAS][10]; //data de nascimento da pessoa
char salarios[QUANT_PESSOAS][20]; //salário mensal da pessoa
char aux_nomes[255];

void iniciar();
char ler_infos(char codigo[], char nome[], char RG[], char CPF[], char end[], char data_nascimento[], char salario[]);
int existir_codigo(char codigo[]);
int existir_CPF(char CPF[]);
int existir_RG(char RG[]);
void inserir(char codigo[], char nome[], char RG[], char CPF[], char end[], char data_nascimento[], char salario[]);
void alterar_cadastro(char codigo[], char novo_codigo[], char novo_nome[], char novo_RG[], char novo_CPF[], char novo_end[], char nova_data_nascimento[], char novo_salario[]);
void excluir_cadastro(char codigo[]);
void listar_codigo(char codigo[]);
void listar_donos_pets();
void listar_pessoas();
void ordenar_alfabeticamente();