//Biblioteca - Desenvolvimento APS - Algoritimos de Programalção II
//Alunos: Marcelo Henrique Cezario / Gabryel Johnatan Boeira
//E-mails: marcelocezario@gmail.com / gabryel392@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define NUMEROCADASTROS 3


//definindo struct stcContaCorrente e int iNumCadCc como variaveis globais

int iNumCadCc=3;

struct tipo_Endereco
{
	char strRua[51];
	int iNum;
	char strCompl[21];
	char strBairro[31];
	char strCidade[31];
	char strEstado[3];
};
struct tipo_ContaCorrente
{
	int iContaCorrente;
	char strNome[51];
	struct tipo_Endereco stcEndereco;
	char strEmail[51];
};
struct tipo_ContaCorrente stcContaCorrente[NUMEROCADASTROS]={
	100,"Fulano da Silva Santos",{"Rua Teste",111,"Apto 101","Costeira","Sao Jose dos Pinhais","PR"},"fulano@gmail.com",
	101,"Beltrano Correia",{"Rua Novo Teste",222,"","Pinheirinho","Curitiba","PR"},"teste@gmail.com",
	102,"Joãozinho Pereira Pinto",{"Avenida Ultimo Teste",33333,"Apto 1303","Centro","Pinhais","PR"},"novoteste@hotmail.com"
};;


void cabmenuprincipal ()	//exibe o cabeçalho do menu principal
{
	system("cls");
	printf("=====================================================================\n");
	printf("|                     CADASTROS CONTA CORRENTE                      |\n");
	printf("|-------------------------------------------------------------------|\n");
	printf("|                   1 - Cadastrar Conta Corrente                    |\n");
	printf("|                   2 - Listar Conta Corrente                       |\n");
	printf("|                   3 - Excluir Conta Corrente                      |\n");
	printf("|                                                                   |\n");
	printf("|                   4 - Sair                                        |\n");
	printf("=====================================================================\n");
}

void cabcadastrocc ()	//exibe o cabeçalho cadastrar conta
{
	system("cls");
	printf("=====================================================================\n");
	printf("|                                                                   |\n");
	printf("|                      CADASTRAR CONTA CORRENTE                     |\n");
	printf("|                                                                   |\n");
	printf("|-------------------------------------------------------------------|\n");
	printf("|                                                                   |\n");
	printf("|Entre com numero de conta igual a 0 para retornar ao menu principal|\n");
	printf("|                                                                   |\n");
	printf("=====================================================================\n");
}
void cablistarcc()		//exibe o cabeçalho listar contas
{
	system("cls");
	printf("=====================================================================\n");
	printf("|                                                                   |\n");
	printf("|                     LISTAR CONTAS CADASTRADAS                     |\n");
	printf("|                                                                   |\n");
	printf("|-------------------------------------------------------------------|\n");
	printf("|                                                                   |\n");
	printf("|                                                                   |\n");
	printf("|                                                                   |\n");
	printf("=====================================================================\n");
}
void cabexcluircc()		//exibe o cabeçalho excluir conta
{
	system("cls");
	printf("=====================================================================\n");
	printf("|                                                                   |\n");
	printf("|                      EXCLUIR CONTA CADASTRADA                     |\n");
	printf("|                                                                   |\n");
	printf("|-------------------------------------------------------------------|\n");
	printf("|                                                                   |\n");
	printf("|Entre com numero de conta igual a 0 para retornar ao menu principal|\n");
	printf("|                                                                   |\n");
	printf("=====================================================================\n");
}

void cadastrarcontas ()	//cadastra novas contas, utilizado a variavel 'x' apenas para facilitar a leitura == iNumCadCc (numero de contas cadastradas- variavel global)
{
	int i, x=iNumCadCc;
	
	if (iNumCadCc>=NUMEROCADASTROS)
	{
		printf("\nNumero limite de cadastros excedido, exclua algum cadastro antigo para novo lançamento!\n");
	}
	else
	{
		printf("Entre com o numero da conta: ");
		scanf("%d", &stcContaCorrente[x].iContaCorrente);
		while (stcContaCorrente[x].iContaCorrente!=0)
			{
				for (i=0;i<x;i++)
				{
					if(stcContaCorrente[x].iContaCorrente==stcContaCorrente[i].iContaCorrente)
					{
						printf("Numero de conta ja cadastrado!!\n");
						i=-1;
						printf("\nEntre com o numero da conta: ");
						scanf("%d", &stcContaCorrente[x].iContaCorrente);
					}
				}
				if (stcContaCorrente[x].iContaCorrente==0)
				{
				}
				else if (stcContaCorrente[x].iContaCorrente < 100)
				{
					printf("Numero da conta nao deve ser menor que 100!!\n\n");
					printf("\nEntre com o numero da conta: ");
					scanf("%d", &stcContaCorrente[x].iContaCorrente);
				}
				else
				{
					fflush(stdin);
					printf("Nome do correntista...........: ");
					gets(stcContaCorrente[x].strNome);
					fflush(stdin);
					printf("E-mail........................: ");
					gets(stcContaCorrente[x].strEmail);
					fflush(stdin);
					printf("Endereco (sem numero).........: ");
					gets(stcContaCorrente[x].stcEndereco.strRua);
					fflush(stdin);
					printf("Numero........................: ");
					scanf("%d", &stcContaCorrente[x].stcEndereco.iNum);
					fflush(stdin);
					printf("Complemento...................: ");
					gets(stcContaCorrente[x].stcEndereco.strCompl);
					fflush(stdin);
					printf("Bairro........................: ");
					gets(stcContaCorrente[x].stcEndereco.strBairro);
					fflush(stdin);
					printf("Cidade........................: ");
					gets(stcContaCorrente[x].stcEndereco.strCidade);
					fflush(stdin);
					printf("UF............................: ");
					gets(stcContaCorrente[x].stcEndereco.strEstado);
					iNumCadCc++;
					x++;
					if(iNumCadCc>=NUMEROCADASTROS)
					{
						printf("\nCadastro efetuado com sucesso!!");
						printf("\nPara prosseguir com novos lancamentos, exclua algum cadastrado realizado anteriormente!\n");
						stcContaCorrente[x].iContaCorrente=0;
					}
					else
					{
						printf("\nEntre com o numero da conta: ");
						scanf("%d", &stcContaCorrente[x].iContaCorrente);
					}
				}
			}
	}
}

int listarcontas (int x)	//lista as contas correntes cadastradas, 'x' é numero de contas ja cadastradas
{
	if(x==0)
	{
		return 1;		
	}
	else
	{
		x--;
		listarcontas (x);
		printf("\n");
		printf("\nCadastro numero....: %3d", x+1);
		printf("\nNumero da conta....: %d", stcContaCorrente[x].iContaCorrente);
		printf("\nNome do correntista: %s", stcContaCorrente[x].strNome);
		printf("\nE-mail.............: %s", stcContaCorrente[x].strEmail);
		printf("\nEndereco...........: %s", stcContaCorrente[x].stcEndereco.strRua);
		printf(" %d %s", stcContaCorrente[x].stcEndereco.iNum, stcContaCorrente[x].stcEndereco.strCompl);
		printf("\nBairro.............: %s", stcContaCorrente[x].stcEndereco.strBairro);
		printf("\nCidade.............: %s", stcContaCorrente[x].stcEndereco.strCidade);
		printf("\nUF.................: %s", stcContaCorrente[x].stcEndereco.strEstado);
		printf("\n");
	}
}

void excluircontas ()
{
	int x, i, iContaExcluir, iVetorExcluir, iContaNaoCadastrada;
	char cOpcao;
	
	printf("Digite o numero da conta que deseja excluir: ");
	scanf("%d", &iContaExcluir);
	if (iContaExcluir==0)
	{
		printf("\nRetornando ao menu principal!\n\n");
	}
	else
	{
		while(iContaExcluir!=0)
		{
			iContaNaoCadastrada=0;
			for (x=0;x<iNumCadCc;x++)
			{
				if(iContaExcluir==stcContaCorrente[x].iContaCorrente)
				{
					iContaNaoCadastrada=1;
					iVetorExcluir = x;
					fflush(stdin);
					printf("\nTem certeza que deseja excluir a conta %d em nome de %s (S/N)? ", stcContaCorrente[iVetorExcluir].iContaCorrente, stcContaCorrente[iVetorExcluir].strNome);
					scanf("%c", &cOpcao);
					switch(cOpcao)
					{
						case 's':
						case 'S':
							for(i=iVetorExcluir;i<iNumCadCc;i++)
							{
								stcContaCorrente[i].iContaCorrente = stcContaCorrente[i+1].iContaCorrente;
								strcpy (stcContaCorrente[i].strNome, stcContaCorrente[i+1].strNome);
								strcpy (stcContaCorrente[i].strEmail, stcContaCorrente[i+1].strEmail);
								strcpy (stcContaCorrente[i].stcEndereco.strRua, stcContaCorrente[i+1].stcEndereco.strRua);
								stcContaCorrente[i].stcEndereco.iNum = stcContaCorrente[i+1].stcEndereco.iNum;
								strcpy (stcContaCorrente[i].stcEndereco.strCompl, stcContaCorrente[i+1].stcEndereco.strCompl);
								strcpy (stcContaCorrente[i].stcEndereco.strBairro, stcContaCorrente[i+1].stcEndereco.strBairro);
								strcpy (stcContaCorrente[i].stcEndereco.strCidade, stcContaCorrente[i+1].stcEndereco.strCidade);
								strcpy (stcContaCorrente[i].stcEndereco.strEstado, stcContaCorrente[i+1].stcEndereco.strEstado);
								iNumCadCc--;
							}
							printf("\nConta corrente excluida com sucesso!\n\n");
							system ("pause, cls");
							break;
						case 'n':
						case 'N':
							printf("\nA conta nao foi excluida!\n\n");
							system ("pause, cls");
							break;
						default:
							fflush(stdin);
							printf("\nOpcao invalida, a conta nao foi excluida!\n\n");
							system ("pause, cls");
							break;								
					}
				}
			}
			if(iContaNaoCadastrada==0)
			{
				printf("\nConta nao cadastrada!\n\n");
				system("pause, cls");
			}
			cabexcluircc();
			printf("\nDigite o numero da conta que deseja excluir: ");
			scanf("%d", &iContaExcluir);
		}
	}
}

void encerrarprograma()	//confirma se deseja encerrar e encerra o programa em caso positivo
{
	char cOpcao;
	
	fflush(stdin);
	printf("\nTem certeza que deseja encerrar (S/N)? ");
	scanf("%c", &cOpcao);
	switch (cOpcao)
	{
		case 's':
		case 'S':
			printf("\n\nO programa esta sendo encerrado!");
			getch();
			exit(0);
			break;
		case 'n':
		case 'N':
			printf("\nO programa nao foi encerrado!\n\n");
			break;
		default:
			printf("\nValor invalido, o programa nao foi encerrado!\n\n");
			break;					
	}
}
