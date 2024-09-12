#include <stdio.h>    //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h>   //biblioteca respons�vel por alocar espa�o na mem�ria 
#include <locale.h>   //biblioteca aloca��o de texto por regi�o 
#include <string.h>   //biblioteca respos�vel por cuidar das strings
#include <ctype.h>   // biblioteca para ultilizar isdigit
#include <conio.h>   //para ultilizar o getch 

int registro() // Fun��o responsavel por cadastrar os usu�rios no sistema 
{
	//inicio cria��o de vari�veis/string
	char arquivo  [40];
	char cpf      [40];
	char nome     [40];
	char sobrenome[40];
	char cargo    [40];
	
	//fim da cria��o de vari�veis/string
	
	printf("Digite o cpf a ser cadastrado: ");//coletando o cpf do usu�rio
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //respos�vel por copiar os valores sas strings 
	
	FILE *file;// cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo, "w" significa escrever ou criar arquivo
	fprintf(file, cpf);// salvo o valor da vari�vel
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a");//abrindo o arquivo, "a" significa atualizar informa��es no arquivo
	fprintf(file, ",");//colocando uma "," ap�s o cpf para separar as informa��es 
	fclose(file);//fechando o arquivo
	
	printf("Digite o nome a ser cadastrado:");//coletando o nome do usu�rio
	scanf("%s", nome);//salvando a string
	
	file = fopen(arquivo, "a");//abrindo o arquivo e atualizando
	fprintf(file, nome);//adicionando o nome do usu�rio no arquivo 
	fclose(file);//fechando o arquivo 
	
	file = fopen(arquivo, "a");//abrindo o arquivo e adicionando informa��es 
	fprintf(file, ",");//adicionando a "," ap�s o nome para separar as informa��es 
	fclose(file);//fechando o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:");//coletando o sobrenome do usu�rio
	scanf("%s", sobrenome);//salvando a string 
	
	file = fopen(arquivo, "a");//abrindo o arquivo e o atualizando
	fprintf(file, sobrenome);//adicionando o sobrenome do usu�rio ao arquivo
	fclose(file);//fechadno arquivo
	
	file = fopen(arquivo, "a");//abrindo o arquivo para atualiza-lo
	fprintf(file, ",");//adicionando "," ap�s o sobrenome para separar as informa��es 
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informa��o sobre o cargo do usu�rio 
	scanf("%s", cargo);//salvando a string
	
	file = fopen(arquivo, "a");//abrindo o arquivo para atualiza-lo 
	fprintf(file,cargo);//adicionando a informa��o "cargo" do usu�rio no arquivo
	fclose(file);//fechadno o arquivo
	
	file = fopen(arquivo, "a");//abrindo o arquivo para atualiza-lo
	fprintf(file,".");//adicionando o "." para fim das informa��es do usu�rio
	fclose(file);//fechando o arquivo 
	
	
	system("pause");//manter as informa��es visiv�is enquanto registra o usu�rio
	
	
	
}  

int consulta()//fun��o respons�vel por consultar os usu�rio
{
	setlocale(LC_ALL, "Portuguese");//definindo limguagens
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");//coletando o cpf a ser consultando
	scanf("%s", cpf);//salvando a string 
	
	
	FILE * file;//abrindo o arquivo file
	file =  fopen(cpf, "r");//acessando o arquivo e lendo, "r" significa ler o arquivo 
	
	printf("aqui est�o as informa��es do usu�rio:", cpf);

	
	if(file == NULL)//Se o arquivo for nulo, ou seja n�o tem o usu�rio cadastrando no sistema
	{ 
	printf("\nN�o foi possiv�l localizar o arquivo!.\n\n ");//informando que o cpf digitado n�o consta no arquivo
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
		
	}
	
	system("Pause");
}

int deletar()//fun��o respons�vel por deletar os usu�rios
{
	char cpf[40];
	
	printf("Digite o cpf do usu�rio a ser deletado:");//coletando o cpf a ser deletado 
	scanf("%s", cpf);//salvando a string
	 
	
	remove(cpf);//apagando o arquivo do banco de dados
	
	FILE * file;//acessando o file
	file = fopen(cpf, "r");//abrindo o arquivo e o lendo
	
	if (file == NULL)// se o arquivo(cpf) for null
	{
		printf("o usu�rio n�o se encontra no sistema\n\n");//informando que o usu�rio n�o consta no sistema 
		system("pause");//mantendo as informa��es visiveis 
		
	}
		

	
	
}

int main()//fun��o principal 
{
	 int opcao=0;
	 int x=1;
	 
	 for(x=1;x=1;)
	{
	 system("cls");
	 
     setlocale(LC_ALL, "Portuguese");// definindo linguagens 
     
     
     printf("\t -_Cart�rio da Ebac_- \n\n");//incio do menu          
     printf("Escolha a op��o desejada do menu:\n\n"); 
     printf("\t1- Registrar nomes\n");
     printf("\t2- Consultar nomes\n");
     printf("\t3- Deletar nomes\n");
     printf("\t4- Sair do sistema\n\n");
     	
	 printf("op��o: ");//fim do menu
     
     scanf("%d", &opcao);//armazenando a escolha do usu�rio
     
     system("cls");
     
      switch(opcao)
	 {
	 	 case 1://caso a op��o for 1 
	 	 registro();//chmando da fun��o registro
	 	 break;
	 	 
	 	 case 2://caso a op��o for 2
	 	 consulta();//chamada da fun��o consulta
	 	 break;
	 	 
	 	 case 3://caso a op��o for 3 
	 	 deletar();//chamada da fun��o deletar
	 	 break;
	 	 
	 	 case 4:
	 	 printf("Obrigado por ultilizar o sistema!");
	 	 return 0 ;
	 	 break ;
	 	 
	 	 default://caso n�o for nenhuma das op��es 
	 	 printf("Essa op��o n�o est� dispon�vel\n\n");//informando que a op��o n�o existe 
	 	 system("pause");//pusando as informa��es para ficarem visiveis 
		 break;	
	 
	 }
     
    
}
}
