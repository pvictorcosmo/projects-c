#define QUANT_PETS 100

char livres_pets[QUANT_PETS]; //lógicos, 0 (ocupado) ou 1 (desocupado)
char codigos_pets[QUANT_PETS][4]; //código do pet, não pode haver mais de um pet com o mesmo código
char codigos_donos[QUANT_PETS][4]; //código do dono do pet
char nomes_pets[QUANT_PETS][255]; //nome do pet, não pode haver nomes iguais de pets do mesmo dono
char especies[QUANT_PETS][255]; //espécie do pet(cachorro, gato, pássaro...)
char datas_pets[QUANT_PETS][10]; //data de nascimento do pet
char aux_nomes_pets[255]; //necessária para ordenar alfabeticamente

void iniciar_pets();
int existir_codigo_pet(char cod_pets[]);
void cadastrar_pets(char cod_pet[], char cod_dono[], char nome_pet[], char data_pet[], char tipo_pet[]);
void alterar_pets(char cod_pet[], char novo_cod_dono[], char novo_cod_pet[], char novo_nome[], char nova_data_pet[], char novo_tipo_pet[]);
void excluir_pets(char codigo[]);
void listar_cod_pets(char cod_pet[]);
void listar_pets_donos();
void listar_pets_alfabeticamente();
