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
    int ver=0, are=0, n=0, k=0, p=0, t=0;
    
    //Conta o número de linhas
    arquivo = fopen(nome_arquivo, "r");
    if(arquivo == NULL){
            printf("Erro, nao foi possivel abrir o arquivo\n");
    }
    else{        
        while( (fgets(linha, sizeof(linha), arquivo))!=NULL ){
           numero_linhas++;
           //printf("\n numero de linhas %d",numero_linhas);
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
    
    //Imprime as arestas, informa se é completo (p), informa se é simples (n)
    for (int i=0; i < numero_linhas; i++){
        ver+=1;
		if(k>1){
			p=1;
		}
		k=0;
        for (int j=0; j < numero_linhas; j++){
            if(i==j){
                if(grafo[i][j]==1){
                    n=1;
                }
            }
            if (grafo[i][j] == 1){
                printf("Aresta %1d - %1d\n", i, j);
                are+=1;
                
            }
            if(grafo[i][j]==0){
				k++;
			}
        }
    }
    
	//complementar
	printf("\n=====GRAFO COMPLEMENTAR========\n");
    for (int i=0; i< numero_linhas; i++){
		for (int j=0; j < numero_linhas; j++){
			if (i!=j){
				if (grafo[i][j]==0){
					printf("Aresta %1d - %1d\n",i,j);
					t++;
				}
			}		
		}
	}
	if(t==0){
		printf("\tNão possui complementar");
		printf("\n");
	}	
    
    //Todas as impressões
    printf("\nO número de arestas é: %d \nO número de vertices é: %d",are/2,ver);
    if(n==0){
        printf("\nEsse grafo é simples");
    }
    else{
        printf("\n Esse grafo não é simples");
    } 
	if(p==1){
		printf("\nEsse grafo não é completo");
	}
	
	if(p==0){
		printf("\nEsse grafo é completo");
	}
    
    fclose(arquivo);
    
    return 0;
}
