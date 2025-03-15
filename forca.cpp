#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

// void obterPalavra(char palavra[])
// {
// 	printf("Jogador 1: Digite uma palarva\n");
// 	scanf("%29s", palavra);
// 	while (getchar() != '\n');
// 	system("clear");
// }

void obterPalavra(char palavras[][30], char palavra[])
{
	srand(time(NULL));
	int aleatorio = rand() % 31;

	strcpy(palavra, palavras[aleatorio]);
}

void iniciarSecreta(char secreta[], char palavra[])
{
	int i;
	int tamanho = strlen(palavra);
	for (i = 0; i < tamanho; i++)
	{
		secreta[i] = '_';
	}

	secreta[tamanho] = '\0';
}

void tentativa(char *letra)
{
	char entrada[10];


	do
    {
        printf("Qual a próxima letra? ");
        fgets(entrada, sizeof(entrada), stdin);
    } while (entrada[0] == '\n');

	*letra = entrada[0];

	if (strlen(entrada) > 1 && entrada[1] != '\n')
	{
		while (getchar() != '\n');
	}
}

void comparar(char secreta[], char palavra[], char letra, int *acertos, int *chances)
{
	int tamanho = strlen(palavra);
	bool acertou = false;
	for (int i = 0; i < tamanho; i++)
	{
		if (palavra[i] == letra)
		{
			if (secreta[i] == '_')
			{
				*acertos = *acertos + 1;
			}

			secreta[i] = palavra[i];
			acertou = true;
		}
	}

	if (!acertou)
	{
		*chances = *chances - 1;
	}
}

int main()
{
	char palavras[20][30] = {
		"abacaxi",
		"travesseiro",
		"cabelereiro",
		"desemprego",
		"lanchonete",
		"encomenda",
		"coquetel",
		"contundente",
		"estudante",
		"mandioca",
		"avassalador",
		"minerio",
		"ultramarino",
		"mastodonte",
		"facultativo",
		"bombeiro",
		"diluvio",
		"visceral",
		"descontraida",
		"farmaceutico"};

	char palavra[30], secreta[30], letra;
	int chances = 3;
	int acertos = 0;

	obterPalavra(palavras, palavra);
	iniciarSecreta(secreta, palavra);

	while (true)
	{
		printf("Palavra: %s | Chances: %d | Acertos: %d \n", secreta, chances, acertos);
		tentativa(&letra);
		comparar(secreta, palavra, letra, &acertos, &chances);
		if (acertos == strlen(palavra))
		{
			system("clear");
			printf("Você acertou! \nA palavra é %s\n", palavra);
			return 0;
		}

		if (chances == 0)
		{
			system("clear");
			printf("Suas chances acabaram :( \nA palavra era: %s\n", palavra);
			return 0;
		}
	}

	return 0;
}
