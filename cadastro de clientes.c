#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char nome[50];
	char email[50];
	char cpf[12];
} obj_cliente;

int main(void)
{
	obj_cliente cliente[100];
	int numero_do_cliente = 0, opcao, finalizar = 1;
	
	
	do
	{
		system("cls");
		printf("Digite o numero desejado\n0 - Finalizar\t1 - Adicionar cliente\t2 - Ver clientes\t3 - Editar clientes\t4 - Excluir\n\nResposta: ");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			
			case 0:
				return 0;
			break;
				
			case 1: 
			system("cls");
			printf("Digite o nome do cliente: ");
			scanf("%c");
			fgets(cliente[numero_do_cliente].nome,50,stdin);
			
			printf("\nDigite o email desse cliente: ");
			fgets(cliente[numero_do_cliente].email,50,stdin);
			
			printf("\n(O CPF deve ser sem pontos e tracos)");
			printf("\nDigite o CPF do cliente:");
			fgets(cliente[numero_do_cliente].cpf,12,stdin);
			
			system("cls");
			printf("cliente adicionado com sucesso\n\n");
			system("pause");
			numero_do_cliente++;		
			break;
			
			case 2:
			{
			
				int i;
				system("cls");
				printf("Clientes listados ate o momento\n-----------------------------------------------------------\n");
				for(i = 0; i < numero_do_cliente; i++)
				{
					printf("Cliente[%d]: %s",i, cliente[i].nome);
					printf("email: %s", cliente[i].email);
					printf("CPF: %s", cliente[i].cpf);
					printf("\n");
				}
				system("pause");
				system("cls");
			}
			break;
			
			case 3:	
			{
				char nome[50];
				int i;
				system("cls");
				printf("Digite o nome do cliente que quer alterar: ");
				scanf("%c");
				fgets(nome,50,stdin);
				printf("\n");				
				
				for(i = 0; i < numero_do_cliente; i++)
				{
					if(strcmp( cliente[i].nome, nome) == 0)
					{
						printf("CLIENTE ENCONTRADO\n");
						printf("\nDigite o novo nome: ");
						fgets(cliente[i].nome,50,stdin);
						
						printf("\n\nDigite o novo email: ");
						fgets(cliente[i].email, 50, stdin);
						
						printf("\n\nDigite o novo CPF:");
						fgets(cliente[i].cpf, 12,stdin);
						printf("Cliente alterado com sucesso\n\n");
						
					}
					break;
				}
				system("pause");
				system("cls");
			}
			break;
			
			case 4:
			{
				int i, sub, confirmacao;
				char nome[50];
				printf("Digite o nome do cliente que quer deletar: ");
				scanf("%c");
				fgets(nome,50,stdin);
				
				for(i = 0; i < numero_do_cliente; i++)
				{
					if(strcmp(cliente[i].nome, nome) == 0)
					{
						for(sub = i; sub < numero_do_cliente; sub++)
						{
							cliente[sub] = cliente[sub+1];
						}
						break;
					}
				}
					
				numero_do_cliente--;
				
				system("cls");
				printf("Cliente deletado com sucesso!\n\n");
				system("pause");
				system("cls");
			}
			break;

		}
			
	}while(finalizar != 0);
}
