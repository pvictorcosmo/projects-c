#define tam 30
#define pets 5
int livres_pet[tam][pets];
int codpet[tam][pets];
char *type_pet[tam][pets];
char *nome_pet[tam][pets];
char *datanascpet[tam][pets];
char aux_pet[255];

void list_pets();

void insert_pets(char nome_pets[],char type_pets[],char datanascpets[]);

void insert_pets_ui();

void delete_pet(int codtest);

void test_type(char type_test[]);

void alt_pets_ui();

void alt_pets(char nome_pets[],char type_pets[],char datanascpets[]);

void order_alf_pets();
