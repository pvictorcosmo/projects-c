#define tam 30
#define pets 5
char *cpfs[tam];
int livres[tam][pets];
int  cod[tam];
char  *datanasc[tam][pets];
char *cpftest[tam][pets];
char  *rend[tam][pets];
char *nomes[tam][pets];
char *end[tam][pets];
char *fones[tam][pets];
char *rgs[tam][pets];
char aux_user[255];
int codtest;

void insert_clients(char rg[],char cpf[],char nome[],char ends[],char datanascs[],char fone[],char rends[]);

void list_clients_ui();

void clients_ui();

void order_alf_user();

int delete_user(int codtest);

void alt_user(char rg[],char cpf[],char nome[],char ends[],char datanascs[],char fone[],char rends[]);

void alt_user_ui();

void funcs_clients_ui();

void insert_user_ui();