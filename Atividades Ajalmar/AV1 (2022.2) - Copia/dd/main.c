#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoas.h"
#include "pets.h"

int main()
{
    iniciar();
    iniciar_pets();
    
    int cond_pessoas = 1, cond_pets = 1, cond_origem = 1, opcao_origem, opcao_pessoas, opcao_pets, final;
    while (cond_origem == 1)
    {
        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("\nBem-vindo(a) ao programa de cadastro de pessoas e de pets.\n\n");
        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("\nDigite a opção que você deseja executar.\n\n");
        printf("1: Funcionalidades para pessoas.\n");
        printf("2: Funcionalidades para pets.\n");
        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        scanf ("%d", &opcao_origem);
        
        switch (opcao_origem) 
        {
            case 1:
            {
                printf("\nFuncionalidades para pessoas selecionado.\n\n");
                printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                
                while (cond_pessoas == 1)
                {
                    printf("\nDigite a opção que você deseja executar.\n\n");
                    printf("1: Inserir uma nova pessoa.\n");
                    printf("2: Alterar uma pessoa existente.\n");
                    printf("3: Excluir uma pessoa.\n");
                    printf("4: Mostrar/imprimir dados de uma pessoa com base no código.\n");
                    printf("5: Mostrar/imprimir dados de pessoas que tenham um tipo de pet (cão, por exemplo).\n");
                    printf("6: Mostrar/imprimir todas as pessoas.\n");
                    printf("7: Mostrar/imprimir todas as pessoas om ordem alfabética pelo nome.\n");
                    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                    scanf("%d", &opcao_pessoas);
                    
                    int sair_daqui = 0;
                    
                    switch (opcao_pessoas)
                    {
                        case 1:
                        {
                            char codigo[4], nome[255], RG[11], CPF[11], end[255], data_nascimento[10], salario[20];
                                
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            printf("\nDigite as informações necessárias para realizar o cadastro.\n\n");
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            
                            ler_infos(codigo, nome, RG, CPF, end, data_nascimento, salario);
                            inserir(codigo, nome, RG, CPF, end, data_nascimento, salario);
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            printf("\nCadastro realizado com sucesso!\n\n");
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            final = 1;
                        }
                        break;
                        
                        case 2:
                        {
                            char codigo[4], novo_codigo[4], novo_nome[255], novo_RG[11], novo_CPF[11], novo_end[255], nova_data_nascimento[10], novo_salario[20];
                            printf("\nDigite as informações necessárias para alterar o cadastro.\nQuando necessário, utilize '/' para separar as palavras.\n");
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            printf("\nCódigo antigo de 4 dígitos:\n");
                            scanf("%s", &codigo[4]);
                            
                            printf("\nCódigo novo de 4 dígitos:\n");
                            scanf("%s", &novo_codigo[4]);
                                
                            printf("\nNovo nome:\n");
                            scanf("%s", &novo_nome[255]);
                                
                            printf("\nNovo RG (utilize apenas números):\n");
                            scanf("%s", &novo_RG[11]);
                                
                            printf("\nNovo CPF (utilize apenas números):\n");
                            scanf("%s", &novo_CPF[11]);
                                
                            printf("\nNovo endereço:\n");
                            scanf("%s", &novo_end[255]);
                             
                            printf("\nNova data de nascimento (dd/mm/aaaa):\n");
                            scanf("%s", &nova_data_nascimento[10]);
                                
                            printf("\nNovo salário (R$00000,00):\n");
                            scanf("%s", &novo_salario[20]);
                            
                            alterar_cadastro(codigo, novo_codigo, novo_nome, novo_RG, novo_CPF, novo_end, nova_data_nascimento, novo_salario);
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            printf("\nCadastro alterado com sucesso!\n\n");
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            final = 1;
                        }
                        break;
                        
                        case 3:
                        {
                            char codigo[4];
                            
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            printf("\nDigite o código de 4 dígitos da pessoa que você deseja excluir.\n\n");
                            scanf("%s", &codigo[4]);
                            
                            excluir_cadastro(codigo);
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            printf("\nCadastro excluído com sucesso.\n\n");
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            final = 1;
                        }
                        break;
                        
                        case 4:
                        {
                            char codigo[4];
                            
                            printf("\nDigite o código de 4 dígitos para consultar o cadastro da pessoa desejada.\n\n");
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            scanf("%s", codigo);
                            
                            listar_codigo(codigo);
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            printf("\nConsulta do cadastro concluída!\n");
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            final = 1;
                        }
                        break;
                        
                        case 5:
                        {
                            printf("5");
                            final = 1;
                        }
                        break;
                        
                        case 6:
                        {
                            printf("\nPessoas cadastradas no sistema:\n\n");
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            listar_pessoas();
                            
                            final = 1;
                        }
                        break;
                        
                        case 7:
                        {
                            printf("\nPessoas cadastradas no sistema listadas em ordem alfabética:\n\n");
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            ordenar_alfabeticamente();
                            
                            final = 1;
                        }
                        break;
        
                        
                        default:
                        {
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            printf("\nOpção Inválida.\nDeseja digitar novamente? Digite '1' para 'Sim' ou '0' para 'Não': \n"); 
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            scanf("%d", &cond_pessoas);
                            if (cond_pessoas > 1 || cond_pessoas <= 0) 
                            {
                                printf("O programa será encerrado. \n\n");
                                printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                                return 0;
                            }
                            final = 0;
                        }
                        break;
                    }   
                    
                    if(sair_daqui)
                    {
                        break;
                    }
                    
                    if(final == 1) 
                    {
                        printf("Deseja voltar ao menu do programa? Digite '1' para 'Sim' ou '0' para 'Não': \n"); 
                        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                        scanf("%d", &cond_pessoas);
                        if (cond_pessoas == 0)
                        {
                            cond_pets = 0;
                        }
                    }
                }
            }    
                
            case 2:
            {   
                printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                printf("Funcionalidades para pets selecionado.\n\n");
                printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                
                while (cond_pets == 1)
                {
                    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                    printf("\nDigite a opção que você deseja executar.\n\n");
                    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                    printf("1: Inserir um novo pet.\n");
                    printf("2: Alterar um pet existente.\n");
                    printf("3: Excluir um pet.\n");
                    printf("4: Mostrar/imprimir dados de um pet com base no código.\n");
                    printf("5: Mostrar/imprimir todos os pets de uma pessoa com base no código da pessoa.\n");
                    printf("6: Mostrar/imprimir todas os pets em ordem alfabética pelo nome.\n");
                    printf("7: Sair do menu de pets.\n\n");
                    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                    scanf("%d", &opcao_pets);
                 
                    switch (opcao_pets)
                    {
                        case 1:
                        {
                            char nome_pet[255], cod_dono[4], data_pet[10], cod_pet[4], tipo_pet[10];
                            
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            printf("Digite o código de 4 dígitos do animal:\n\n");
                            scanf("%s", &cod_pet[4]);
                            printf("Digite o código do dono do animal:\n");
                            scanf("%s", &cod_dono[4]);
                            printf("Digite o nome do animal:\n");
                            scanf("%s", &nome_pet[255]);
                            printf("Digite a data de nascimento do animal: (dd/mm/aaaa)\n");
                            scanf("%s", &data_pet[10]);
                            printf("Digite a espécie do animal: \n");
                            scanf("%s", &tipo_pet[255]);
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            
                            cadastrar_pets(cod_pet, cod_dono, nome_pet, data_pet, tipo_pet);
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            printf("\nPet cadastrado com sucesso!\n\n");
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            final = 1;
                        }
                        break;
                        
                        case 2:
                        {
                            char cod_pet[4], novo_cod_pet[4], novo_cod_dono[4], novo_nome_pet[255], nova_data_pet[10], novo_tipo_pet[255];
                            
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            printf("\nDigite as informações necessárias para alterar o cadastro do pet.\nQuando necessário, utilize '/' para separar as palavras.\n\n");
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            
                            printf("\nCódigo anterior de 4 dígitos do pet:\n\n");
                            scanf("%s", &cod_pet[4]);
                            
                            printf("\nNovo código de 4 dígitos do pet:\n\n");
                            scanf("%s", &novo_cod_pet[4]);
                            
                            printf("\nNovo código do dono do pet:\n\n");
                            scanf("%s", &novo_cod_dono[4]);
                            
                            printf("\nNovo nome do pet:\n\n");
                            scanf("%s", &novo_nome_pet[255]);
                            
                            printf("\nNova data de nascimento do pet (dd/mm/aaaa):\n\n");
                            scanf("%s", &nova_data_pet[10]);
                            
                            printf("\nNova espécie do pet:\n\n");
                            scanf("%s", &novo_tipo_pet[255]);
                            
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            alterar_pets(cod_pet, novo_cod_pet, novo_cod_dono, novo_nome_pet, nova_data_pet, novo_tipo_pet);
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            printf("\nCadastro atualizado com sucesso!\n\n");
                            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
                            
                            final = 1;
                        }
                        break;
                        
                        case 3:
                        {
                            char cod_pet[4];
                            
                            printf("\nDigite o código de 4 dígitos do pet que você deseja excluir do cadastro:\n\n");
                            scanf("%s", &cod_pet[4]);
                            
                            excluir_pets(cod_pet);
                            printf("\nPet excluído com sucesso!\n\n");
                            
                            final = 1;
                        }
                        break;
                        
                        case 4:
                        {
                            char cod_pet[4];
                            
                            printf("\nDigite o código do pet que você deseja consultar o cadastro:\n\n");
                            scanf("%s", &cod_pet[4]);
                            
                            listar_cod_pets(cod_pet);
                            
                            final = 1;
                        }
                        break;
                        
                        case 5:
                        {
                            printf("5");
                            final = 1;
                        }
                        break;
                        
                        case 6:
                        {
                            printf("\nPets cadastrados listados em ordem alfabética:\n\n");
                            
                            listar_pets_alfabeticamente();
                            final = 1;
                        }
                        break;
                        
                        default:
                        {
                            printf("\nOpção Inválida.\nDeseja digitar novamente? Digite '1' para 'Sim' ou '0' para 'Não': \n"); 
                            scanf("%d", &cond_pets);
                            if (cond_pets > 1 || cond_pets <= 0) 
                            {
                                printf("O programa será encerrado. \n\n");
                                return 0;
                            }
                            final = 0;
                        }
                        break;
                    }
                    
                    if(final == 1) 
                    {
                        printf("Deseja voltar ao menu do programa? Digite '1' para 'Sim' ou '0' para 'Não': \n"); 
                        scanf("%d", &cond_pets);
                        if (cond_pets == 0)
                        {
                            cond_pessoas = 0;
                        }
                    }
                }    
            }
            default:
            {
                printf("\nPrograma encerrado! \n\n");
                cond_origem = 0;
            }
            break;
            
        }
        
        printf("Deseja voltar ao menu do programa? Digite '1' para sim e '0' para não. \n\n");
        scanf("%d", &cond_origem);
    }
    return 0;
}