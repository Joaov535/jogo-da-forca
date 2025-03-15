#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

void obterPalavra(char palavras[][30], char palavra[])
{
	int aleatorio = rand() % 20;

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
		while (getchar() != '\n')
			;
	}
}

bool comparar(char secreta[], char palavra[], char letra, int *acertos, int *chances)
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
		*chances = *chances + 1;
	}

	return acertou;
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

	string partes[7] = {"", " O\n", "/", "|", "\\\n", "/ ", "\\"};
	string boneco = "";
	char palavra[30], secreta[30], letra;
	int chances = 0;
	int acertos = 0;

	obterPalavra(palavras, palavra);
	iniciarSecreta(secreta, palavra);

	while (true)
	{
		system(CLEAR);
		cout << boneco << endl;
		printf("\nPalavra: %s \n", secreta);
		tentativa(&letra);

		if (!comparar(secreta, palavra, letra, &acertos, &chances))
		{	
			boneco += partes[chances];
		}

		if (acertos == strlen(palavra))
		{
			system(CLEAR);
			printf("Você acertou! \nA palavra é %s\n", palavra);
			return 0;
		}

		if (chances == 7)
		{
			system(CLEAR);
			printf("Suas chances acabaram :( \nA palavra era: %s\n", palavra);
			return 0;
		}
	}

	return 0;
}