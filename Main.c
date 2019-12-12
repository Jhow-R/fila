#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TipoFilaCandidato.h"

int main()
{

	TipoFila ini, fim;
	TipoCandidato candidato;
	int op, i, cont = 0, contInicial = 0, contPercorrida = 0;

	char cursoVaga[50];
	char tempoExpVaga[50];
	char sucesso = 'F';
	char respCand;

	INIT(&ini, &fim);

	do
	{

		// Menu
		printf("Digite 1- Inscricao de candidato, 2- Vaga de emprego, 3 Encerrar: ");
		scanf("%d", &op);

		switch (op)
		{
		case 1:

			// Cadastrar candidato
			printf("Digite o nome: ");
			fflush(stdin);
			gets(candidato.nome);

			printf("Digite o email: ");
            fflush(stdin);
			gets(candidato.email); 
				
			printf("Digite o telefone: ");
            fflush(stdin);
			gets(candidato.telefone);

			printf("Digite o curso: ");
			fflush(stdin);
			gets(candidato.curso);

			printf("Digite o tempo de experiencia: ");
			fflush(stdin);
			gets(candidato.tempoExp);

			printf("\n");

			// Sï¿½ serï¿½o inseridos na fila os candidatos que forem de um dos cursos, caso contrï¿½rio, serï¿½o eliminados
			if ((strcmpi(candidato.curso, "sistemas de informacao") == 0) || (strcmpi(candidato.curso, "engenharia de quimica") == 0) || (strcmpi(candidato.curso, "engenharia de mecatronica")) == 0)
			{
				ENQUEUE(&ini, &fim, candidato);
				// Variï¿½vel de controle para contagem dos candidatos
				contInicial++;
			}

			break;

		case 2:
			// Cadastrar vaga
			printf("Digite a area de formacao: ");
			fflush(stdin);
			gets(cursoVaga);

			printf("Digite o tempo de experiencia: ");
			fflush(stdin);
			gets(tempoExpVaga);

			printf("\n Candidatos a analisar: %d \n", contInicial);

			do
			{
				cont = contInicial;

				if ((isEmpty(ini, fim) == 1))
				{
					printf("Nao ha candidatos na fila \n");
					break;
				}
				else
				{
					printf("\n Analisando... \n \n");

					for (i = 0; i = cont; i++)
					{

						// Tirar candidato da fila para analisï¿½-lo
						DEQUEUE(&ini, &fim, &candidato);

						// Verificando se o candidato corresponde os requisitos da vaga
						if ((strcmpi(candidato.curso, cursoVaga) == 0) && (strcmpi(candidato.tempoExp, tempoExpVaga) == 0))
						{
							printf("Deu match! \n");
							printf("Nome: %s \n", candidato.nome);
							printf("Email: %s \n", candidato.email);
							sucesso = 'T';
							break;
						}
						else
						{
							// Caso nï¿½o se enquadre no requerido, candidato serï¿½ reinserido na fila ficando no final
							ENQUEUE(&ini, &fim, candidato);
							sucesso = 'F';
						}

						cont--;
					}

					// Caso nï¿½o exista candidato para a vaga
					if ((sucesso == 'F') && (cont == 0))
					{
						printf("Nenhum candidato apto para a vaga :c \n");
						break;
					}

					printf("\n");

					if (sucesso == 'T')
					{
						printf("Ola, %s. Deseja aceitar a proposta [S/N]? ", candidato.nome);
						fflush(stdin);
						scanf("%c", &respCand);

						if ((respCand == 'S') || (respCand == 's'))
						{
							printf("Sua contratacao para a vaga foi concluida! \n");
							contInicial--;
							break;
						}
						else
						{
							printf("Tudo bem, voce voltara para a fila! \n");
							ENQUEUE(&ini, &fim, candidato);
							contPercorrida++;

							// Verificar se já foram todos os candidatos possíveis
							if (contPercorrida == contInicial)
							{
								printf("Nenhum candidato apto para a vaga :c \n");
								break;
							}
						}
					}
				}
			} while ((respCand != 'S') || (respCand != 's'));

			printf("\n");
			op = 0;

			break;

		case 3:
			// Verificar se hï¿½ candidatos na fila
			if ((isEmpty(ini, fim) == 1) || contInicial == 0)
			{
				printf("\n Sem candidatos na fila \n");
			}
			else
			{
				printf("\n %d candidato(s) removido(s) da fila \n", contInicial);

				// Remover candidatos que ficaram na fila antes de encerrar o algoritmo
				for (i = 0; i = contInicial; i++)
				{
					FIRST(ini, fim, &candidato);
					printf("======================================== \n");
					printf("Nome: %s \n", candidato.nome);
					printf("Email: %s \n", candidato.email);
					DEQUEUE(&ini, &fim, &candidato);
					contInicial--;
				}
			}

			break;
		default:
			printf("Opcao invalida... tente novamente \n");
			op = 0;
		}
	} while ((op == 1) || (op == 2) || (op == 0) || (op == 9));
}
