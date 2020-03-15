#include <stdio.h>

int main(void){
	int grafo[3][3];
	//Inicia todas as células do grafo com o valor zero
	for (int linha=0; linha < 3; linha++)
		for (int coluna=0; coluna < 3; coluna++)
			grafo[linha][coluna] = 0;
		
	//Define as células do grafo que representam arestas entre os vértices
	grafo[0][1] = 1;
	grafo[1][0] = 1;
	grafo[1][2] = 1;
	grafo[2][0] = 1;
	grafo[2][1] = 1;
	printf("\n\n\n");
	//Imprime as arestas que existem etre os vértices
	for (int linha=0; linha < 3; linha++)
		for (int coluna=0; coluna < 3; coluna++)
			if (grafo[linha][coluna] == 1)
				printf("\nAresta %1d - %1d\n", linha, coluna);
		
	return(0);
}
