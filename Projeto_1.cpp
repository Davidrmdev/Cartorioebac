#include <stdio.h>    //biblioteca de comunicação com o usuário 
#include <stdlib.h>   //biblioteca responsável por alocar espaço na memória 
#include <locale.h>   //biblioteca alocação de texto por região 
#include <string.h>   //biblioteca resposável por cuidar das strings
#include <ctype.h>   // biblioteca para ultilizar isdigit
#include <conio.h>   //para ultilizar o getch 

int registro() // Função responsavel por cadastrar os usuários no sistema 
{
	//inicio criação de variáveis/string
	char arquivo  [40];
	char cpf      [40];
	char nome     [40];
	char sobrenome[40];
	char cargo    [40];
	
	//fim da criação de variáveis/string
	
	printf("Digite o cpf a ser cadastrado: ");//coletando o cpf do usuário
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //resposável por copiar os valores sas strings 
	
	FILE *file;// cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo, "w" significa escrever ou criar arquivo
	fprintf(file, cpf);// salvo o valor da variável
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a");//abrindo o arquivo, "a" significa atualizar informações no arquivo
	fprintf(file, ",");//colocando uma "," após o cpf para separar as informações 
	fclose(file);//fechando o arquivo
	
	printf("Digite o nome a ser cadastrado:");//coletando o nome do usuário
	scanf("%s", nome);//salvando a string
	
	file = fopen(arquivo, "a");//abrindo o arquivo e atualizando
	fprintf(file, nome);//adicionando o nome do usuário no arquivo 
	fclose(file);//fechando o arquivo 
	
	file = fopen(arquivo, "a");//abrindo o arquivo e adicionando informações 
	fprintf(file, ",");//adicionando a "," após o nome para separar as informações 
	fclose(file);//fechando o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:");//coletando o sobrenome do usuário
	scanf("%s", sobrenome);//salvando a string 
	
	file = fopen(arquivo, "a");//abrindo o arquivo e o atualizando
	fprintf(file, sobrenome);//adicionando o sobrenome do usuário ao arquivo
	fclose(file);//fechadno arquivo
	
	file = fopen(arquivo, "a");//abrindo o arquivo para atualiza-lo
	fprintf(file, ",");//adicionando "," após o sobrenome para separar as informações 
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informação sobre o cargo do usuário 
	scanf("%s", cargo);//salvando a string
	
	file = fopen(arquivo, "a");//abrindo o arquivo para atualiza-lo 
	fprintf(file,cargo);//adicionando a informação "cargo" do usuário no arquivo
	fclose(file);//fechadno o arquivo
	
	file = fopen(arquivo, "a");//abrindo o arquivo para atualiza-lo
	fprintf(file,".");//adicionando o "." para fim das informações do usuário
	fclose(file);//fechando o arquivo 
	
	
	system("pause");//manter as informações visivéis enquanto registra o usuário
	
	
	
}  

int consulta()//função responsável por consultar os usuário
{
	setlocale(LC_ALL, "Portuguese");//definindo limguagens
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");//coletando o cpf a ser consultando
	scanf("%s", cpf);//salvando a string 
	
	
	FILE * file;//abrindo o arquivo file
	file =  fopen(cpf, "r");//acessando o arquivo e lendo, "r" significa ler o arquivo 
	
	printf("aqui estão as informações do usuário:", cpf);

	
	if(file == NULL)//Se o arquivo for nulo, ou seja não tem o usuário cadastrando no sistema
	{ 
	printf("\nNão foi possivél localizar o arquivo!.\n\n ");//informando que o cpf digitado não consta no arquivo
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
		
	}
	
	system("Pause");
}

int deletar()//função responsável por deletar os usuários
{
	char cpf[40];
	
	printf("Digite o cpf do usuário a ser deletado:");//coletando o cpf a ser deletado 
	scanf("%s", cpf);//salvando a string
	 
	
	remove(cpf);//apagando o arquivo do banco de dados
	
	FILE * file;//acessando o file
	file = fopen(cpf, "r");//abrindo o arquivo e o lendo
	
	if (file == NULL)// se o arquivo(cpf) for null
	{
		printf("o usuário não se encontra no sistema\n\n");//informando que o usuário não consta no sistema 
		system("pause");//mantendo as informações visiveis 
		
	}
		

	
	
}

int main()//função principal 
{
	 int opcao=0;
	 int x=1;
	 
	 for(x=1;x=1;)
	{
	 system("cls");
	 
     setlocale(LC_ALL, "Portuguese");// definindo linguagens 
     
     
     printf("\t -_Cartório da Ebac_- \n\n");//incio do menu          
     printf("Escolha a opção desejada do menu:\n\n"); 
     printf("\t1- Registrar nomes\n");
     printf("\t2- Consultar nomes\n");
     printf("\t3- Deletar nomes\n");
     printf("\t4- Sair do sistema\n\n");
     	
	 printf("opção: ");//fim do menu
     
     scanf("%d", &opcao);//armazenando a escolha do usuário
     
     system("cls");
     
      switch(opcao)
	 {
	 	 case 1://caso a opção for 1 
	 	 registro();//chmando da função registro
	 	 break;
	 	 
	 	 case 2://caso a opção for 2
	 	 consulta();//chamada da função consulta
	 	 break;
	 	 
	 	 case 3://caso a opção for 3 
	 	 deletar();//chamada da função deletar
	 	 break;
	 	 
	 	 case 4:
	 	 printf("Obrigado por ultilizar o sistema!");
	 	 return 0 ;
	 	 break ;
	 	 
	 	 default://caso não for nenhuma das opções 
	 	 printf("Essa opção não está disponível\n\n");//informando que a opção não existe 
	 	 system("pause");//pusando as informações para ficarem visiveis 
		 break;	
	 
	 }
     
    
}
}
