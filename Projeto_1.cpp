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
	
	system("cls");
	
	//inicio da escolha para voltar ao menu, ou registrar outro usu�rio.
	char opcao;
	
	printf("\tDeseja registrar mais usu�rio?\n");
	printf("\t1 - sim\n");
	printf("\t2 - n�o\n");
	printf("\tOp��o:");
	
	
	
	scanf("%d", &opcao);
	system("cls");
	
	switch(opcao)
	{
		case 1:
		registro();
		break;
		
		case 2:
		return 0;
		break;
		
		default:
		printf("Essa op��o n�o est� dispon�vel\n\n");
		break; 
		
		return 0 ;
	}

    // fim da escolha.
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
	
	
	if(file == NULL)//Se o arquivo for nulo, ou seja n�o tem o usu�rio cadastrando no sistema
	{ 
	printf("\nUsu�rio n�o se encontra no sistema!.\n\n ");//informando que o cpf digitado n�o consta no arquivo
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
		
	}

    system("pause");
    
    system("cls");


    //inicio da escolha para voltar ao menu, ou consultar outro usu�rio.
	char opcao;
	
	
	printf("\tDeseja consultar outro usu�rio?\n");
	printf("\t1 - Sim\n");
	printf("\t2 - N�o\n");
	printf("\tOp��o:");
	
	scanf("%d", &opcao);
	
	system("cls");
	
	switch(opcao)
	{
		case 1:
		consulta();
		break;
		
		case 2:
		return 0;
		break;
		
		default:
		printf("Essa op��o n�o est� dispon�vel\n\n");
		system("pause");
		break;
		
		
	
	}
	
    // fim da escolha 

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
    system("cls");
    
    //inicio da escolha para voltar ao menu, ou deletar outro usu�rio.
	char opcao;

	printf("\tDeseja deletar outro usu�rio?\n");
	printf("\t1 - Sim\n");
	printf("\t2 - N�o\n");
	printf("\tOp��o:");
	
	scanf("%d", &opcao); 
	
	system("cls");
	
	
	switch(opcao)
	{
		case 1:
		deletar();
		break;
		
		case 2:
		return 0 ;
		break;
		
		default:
		printf("Essa op��o n�o est� dispon�vel");
		break;
			
	
		
	}
	// fim da escolha.
	
	
	
}
 typedef struct//estrutura para logan no sistema 
	 {
	 	char usuario[20];
	 	char senha[20];
	 }pessoa; pessoa p[1];

int main()//fun��o principal 
{
	setlocale(LC_ALL, "Portuguese");//definindo linguagem
	printf("\t -_Cart�rio da Ebac_- \n\n");
	printf("\t\tlogin\n\n");
	
	char usuario[20];
	char senha  [20];
	
	strcpy (p[0] .usuario, "David");//criando um usu�rio 
	strcpy (p[0] .senha,   "Admin");// criando a senha 

	printf("Usu�rio:");// perguntando o usu�rio a logar
	scanf("%s", usuario);// salvando a resposta na string 
	
	printf("Senha:");// perguntando a senha 
	scanf("%s", senha);// salvando a resposta na string 
	
	if ((strcmp (usuario,p [0].usuario)==0 ) && (strcmp (senha,p[0].senha) == 0 ))// comparando se o usu�rio e/ou a senha digitado s�o corretos 
	{
		printf("Usu�rio logado\n");// confirma��o de login 
	}else
	{
		printf("Usu�rio e/ou senha incorretos\n");// dados digitados incorretos 
		return 0;
		
	}
	system("pause");
	system("cls");
	
	
	 
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
	 	
	 	 
	 	 default://caso n�o for nenhuma das op��es 
	 	 printf("Essa op��o n�o est� dispon�vel\n\n");//informando que a op��o n�o existe 
	 	 system("pause");//pusando as informa��es para ficarem visiveis 
		 break;	
	 
	  }
     
    
    }
  
}
