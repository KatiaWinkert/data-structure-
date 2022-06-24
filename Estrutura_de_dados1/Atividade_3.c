#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
struct corseSchools
{
	int codigo;
	char name[100], instructor[100];
	int tempo; 
};
struct student
{
	struct corseSchools curso;
	int RA;	 
	char name[100], matricula[100];
};
int main()
{
	setlocale(LC_ALL, "Portuguese");
	struct student alunos[100];
	struct corseSchools curso;
	int cont = 0;
  
	printf("\n ~~~~ Cadastro do curso ~~~~ ");
  printf("\n----------------------------------- ");
	printf("\n Codigo do curso: ");
	scanf("%d", &curso.codigo);	
  setbuf(stdin, NULL);
  printf("\n----------------------------------- ");
	printf("\n Nome do curso: ");
	gets(curso.name);	
	setbuf(stdin, NULL);
  printf("\n----------------------------------- ");
	printf("\n Nome do instrutor: ");
	gets(curso.instructor);	
	setbuf(stdin, NULL);
  printf("\n----------------------------------- ");
	
	printf("\nCadastro do Aluno: ");
	printf("\n Qual o RA do aluno?: ");
	scanf("%d", &alunos[cont].RA);
  setbuf(stdin, NULL);
  printf("\n----------------------------------- ");
	printf("\n Nome do Aluno: ");
	gets(alunos[cont].name);	
	setbuf(stdin, NULL);
  printf("\n----------------------------------- ");
	printf("\n Qual a data da Matricula?: ");
	gets(alunos[cont].matricula);	
	setbuf(stdin, NULL);
  printf("\n---------FIM DO CADASTRO------------- ");
	
	alunos[cont].curso = curso;
  
	
 	return 0;
}