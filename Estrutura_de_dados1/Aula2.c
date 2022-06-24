#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct lista {
int conteudo; 
struct lista  *prox; 
} no;  

void inserir(int x , no *p){
no *novo; 
  novo = malloc(sizeof(no));
  novo->conteudo = x;
  novo->prox = p->prox; 
  p->prox = novo; 
}

void excluir (no *p){
  no *lixo; 
  lixo = p->prox; //null 
  p->prox = lixo->prox;
  free(lixo); //função free libera o espaço de memoria  
}

void imprimir(no *le){
  no *p; 
  for(p = le; p!= NULL; p = p-> prox ){
    printf("%d\n", p->conteudo);
  }
}

int main(void) {
  int valor = 6; 
  no *le; 
  le = malloc(sizeof(no));
  le-> prox = NULL;

  for (int i = 1; i <= 20; i++){
    inserir (valor * i , le); 
}
  imprimir(le); 
  excluir(le);
  printf("\n");

  return  0; 
  }