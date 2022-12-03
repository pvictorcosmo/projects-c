#define tam 30
char *cpfs[tam];
int livres[tam];
int  cod[tam];
char  *datanasc[tam];
char *cpftest[tam];
char  *rend[tam];
char nomes[tam][255];
char *end[tam];
char *fones[tam];
char *rgs[tam];
char aux_user[255];
int codtest;


void insert_clients(char rg[],char cpf[],char nome[],char ends[],char datanascs[],char fone[],char rends[]);

void list_clients_ui();

void list_client(int codtest);

void clients_ui();

void list_user(int index);

void order_alf_user();

int delete_user(int codtest);

void alt_user(char rg[],char cpf[],char nome[],char ends[],char datanascs[],char fone[],char rends[]);

void alt_user_ui();

void insert_user_ui();

void search_user(char *cpf);

