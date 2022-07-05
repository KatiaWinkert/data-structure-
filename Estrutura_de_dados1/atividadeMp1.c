#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// definição de variaveis  
int destino;
int origem;
int quantidadeNos = 0;
int *custos = NULL;
int RA[7] = {2, 1, 1, 3, 9, 1, 2};
float precoGasolina = 6.596;

//PrototipaçÃo:
void dijkstra (int vertices, int origem, int destino, int *custo); 
void exibirMenu(void); 
void grafoIniciar(void); 
void grafoProcurar(void); 

//impleemntação do algoritimo de Dijkstra 
void dijkstra(int vertices, int origem, int destino, int *custos) {
  int i,v, cont = 0;
  int *ant, *tmp; 
  int *z; /* vertices para os quais se conhece o caminho minimo */
  double min;
  double dist[vertices]; /* vetor com os custos dos caminhos */


  /* aloca as linhas da matriz */
  ant = calloc (vertices, sizeof(int *));
  tmp = calloc (vertices, sizeof(int *));
  if (ant == NULL) {
    printf ("** Erro: Memoria Insuficiente **");
    exit(-1);
  }

  z = calloc (vertices, sizeof(int *));
  if (z == NULL) {
    printf ("** Erro: Memoria Insuficiente **");
    exit(-1);
  }

  for (i = 0; i < vertices; i++) {
    if (custos[(origem - 1) * vertices + i] !=- 1) {
      ant[i] = origem - 1;
      dist[i] = custos[(origem-1)*vertices+i];
    }
    else {
      ant[i]= -1;
      dist[i] = HUGE_VAL;
    }
    z[i]=0;
  }
  z[origem-1] = 1;
  dist[origem-1] = 0;

  /* Ciclo principal */
  do {
    /* Encontra o vertice que deve entrar em z */
    min = HUGE_VAL;
    for (i=0;i<vertices;i++)
      if (!z[i])
        if (dist[i]>=0 && dist[i]<min) {
          min=dist[i];v=i;
        }

    /* Calcula distancias dos novos vizinhos de z */
    if (min != HUGE_VAL && v != destino - 1) {
      z[v] = 1;
      for (i = 0; i < vertices; i++)
        if (!z[i]) {
          if (custos[v*vertices+i] != -1 && dist[v] + custos[v*vertices+i] < dist[i]) {
            dist[i] = dist[v] + custos[v*vertices+i];
            ant[i] =v;
          }
        }
    }
  } while (v != destino - 1 && min != HUGE_VAL);

  /* Mostra o Resultado da procura */
  printf("\tDe %d para %d: \t", origem, destino);
  if (min == HUGE_VAL) {
    printf("Nao Existe\n");
    printf("\tCusto: \t- \n");
  }
  else {
    i = destino;
    i = ant[i-1];
    while (i != -1) {
      // printf("<-%d",i+1);
      tmp[cont] = i+1;
      cont++;
      i = ant[i];
    }
 
    for (i = cont; i > 0 ; i--) {
      printf("%d -> ", tmp[i-1]);
    }
    printf("%d", destino);
 
    printf("\n\tCusto: %d\n",(int) dist[destino-1]);
  }
}

void exibirMenu(void){
	system("cls");
	printf("________________________________________\n"); 
	printf("Implementacao do Algoritmo de Dijasktra\n");
	printf("________________________________________\n"); 
	printf("Comandos:   \n"); 
	printf("\t 1 - Iniciar o Grafo\n");
	printf("\t 2 - Procurar os menores caminhos no grafo\n\n");
	printf("\t 0 - Sair do programa\n ") ; 
	printf("________________________________________\n"); 
}

void grafoIniciar(void) {
	
	printf("\n Informe o numero de nos: "); 
	scanf("%d", &quantidadeNos);
	printf("\nInicializando o grafo...\n");
	if (custos != NULL) {
		free(custos);
	}
	
	int tamanhoMatriz = quantidadeNos * quantidadeNos;
	custos = (int *) malloc(sizeof(int) * tamanhoMatriz);
	
	//Caso o compilador venha falhar em alocar o espaço da memoria
	if(custos == NULL){
		system ("color fc");
		printf(" -- ERRO: Memoria Insuficiente --"); 
		exit(-1); 
	}
		
	//Preenchendo a matriz com -1
	int i;	
	for(i = 0; i < tamanhoMatriz; i++){
		custos[i] = -1;
	}
	
	printf("\nGrafo inicializado com sucesso.\n");
	
	int contador = 0;
	do{
		printf("Entre com as Arestas:\n");
   	
		printf("Origem da aresta (entre 1 e %d ou '0' para sair): ", quantidadeNos);
		scanf("%d",&origem);
		if(origem == 0) break;
		
		printf("Destino da aresta (entre 1 e %d, menos %d): ", quantidadeNos, origem);
		scanf("%d", &destino);
		
		float custo = RA[contador] * precoGasolina;
		custos[(origem - 1) * quantidadeNos + destino - 1] = custo;
		contador++;
		printf("O custo para esta aresta eh de: %f\n\n", custo);

   } while (origem != 0 || contador == 6);
	
}

void grafoProcurar(void) {
  int i, j;
 
  /* Azul */
  system("cls");
  system("color 03");
  printf("Lista dos Menores Caminhos no Grafo Dado: \n");
 
  for (i = 1; i <= quantidadeNos; i++) {
    for (j = 1; j <= quantidadeNos; j++)
      dijkstra(quantidadeNos, i, j, custos);
    printf("\n");
  }

  printf("<Pressione ENTER para voltar ao menu inicial>\n");
  /* Volta cor normal */
  system("color 07");
  system("pause");
}

void main(int argc, char **argv) {
	int opcao = -1;
	
	do {
		exibirMenu();
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				grafoIniciar();
				break;
			case 2:
				grafoProcurar();
				break;
			default:
				break;
		}
	} while(opcao != 0);
}

