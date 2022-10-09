#define tam 30
#define pets 5
int livres_pet[tam][pets];
int codpet[tam][pets];
char type_pet[tam][pets][25];
char nome_pet[tam][pets][255];
char datanascpet[tam][pets][8];
char aux_pet[255];

void list_pets();

void insert_pets();

void insert_pets_ui();

void delete_pet(int codtest);

void test_type(char type_test[]);

void alt_insert_pets();

void order_alf_pets();
