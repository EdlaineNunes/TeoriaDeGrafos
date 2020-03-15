#include <stdio.h>
#include <string.h>

int main(void)
{
	char nome_arquivo[] = "exemplo.grafo";
	FILE *arquivo;
	
	char linha[1000];
	char caractere;
	
	int numero_linhas = 0;	
	int linha_atual = 0;
	int coluna_atual = 0;
	
	//Conta o número de linhas
	arquivo = fopen(nome_arquivo, "r");
	if(arquivo == NULL){
			printf("Erro, nao foi possivel abrir o arquivo\n");
	}else{		
		while( (fgets(linha, sizeof(linha), arquivo))!=NULL ){
			numero_linhas++;
		}		
	}
	
	//Declara a matriz do grafo
	int grafo[numero_linhas][numero_linhas];
	
	//Preenche a matriz do grafo
	arquivo = fopen(nome_arquivo, "r");
	if(arquivo == NULL){
	    printf("Erro, nao foi possivel abrir o arquivo\n");
	}else{
	    while( (caractere=fgetc(arquivo))!= EOF ){
			if(caractere == '\n'){
				linha_atual++;
				coluna_atual = 0;
			}else{				
				grafo[linha_atual][coluna_atual] = (caractere == '1');
				coluna_atual++;
			}
		}
	}
	
	//Imprime as arestas que existem etre os vértices
	for (int i=0; i < numero_linhas; i++){
		for (int j=0; j < numero_linhas; j++){
			if (grafo[i][j] == 1){
				printf("Aresta %1d - %1d\n", i, j);
			}
		}
	}
			
	fclose(arquivo);
	
	return 0;
}
