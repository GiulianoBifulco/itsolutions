#include <stdio.h> // biblioteca de comunica��o com o usuario
#include <stdlib.h> //bibliotea de aloca��o de espa�o em memoria
#include <locale.h> //bibliotea de aloca��o de texto por regi�o
#include <string.h> //biblioteca de strings


int registro() //fun��o resp�nsavel por cadastrar usuarios no sistema
{
	//inicio cria��o de variaveis/string
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char aparelho[40];
	//final da cria��o de variaveis/string
	
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usuario
	scanf("%s",cpf); //armazenar a escolha do usuario //%s refere-se as strings
	
	strcpy(arquivo,cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo,"w"); //cria o arquivo e o "W" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo o "a" significa gravar
	fprintf(file, "-");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");//coletando informa��o do usuario
	scanf("%s",nome);//armazenar a escolha do usuario
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,"-");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informa��o do usuario
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, "-");
	fclose(file);
	
	printf("Digite o aparelho: ");//coletando informa��o do usuario
	scanf("%s",aparelho);//armazenar a escolha do usuario
	
	file = fopen(arquivo,"a");
	fprintf(file,aparelho);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, "-");
	fclose(file);
	
	system("pause");//pausa o sistema para verifica��o do usuario
	
}

int consulta()

{
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");//coletando informa��o do usuario
	scanf("%s",cpf);//armazenar a escolha do usuario
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\n\n CPF n�o est� cadastrado. \n\n");//coletando informa��o do usuario
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as iforma��es do Cliente: ");//coletando informa��o do usuario
		printf("%s", conteudo);//coletando informa��o do usuario
		printf("\n\n");
    }
	
	system("pause");//pausa o sistema para verifica��o do usuario
	
}

int deletar()

{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado:");//coletando informa��o do usuario
	scanf("%s",cpf);//armazenar a escolha do usuario
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file ==  NULL)
	{
		printf("Usu�rio n�o cadastrado! \n");//coletando informa��o do usuario
	}	
	
	system("pause"); //pausa o sistema para verifica��o do usuario
}




int main ()

{
	int opcao=0; // definindo variaveis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");//limpar a tela
				
		setlocale(LC_ALL, "Portuguese"); // definindo localiza��o
	
	
		printf("###IT Solutions Assist�ncia T�cnica### \n\n"); // o comando \n pula linhas // come�o do menu
		printf("Escolha a op��o desejada: \n\n");
		printf("\t1 - Registrar clientes \n"); // o comando \t da um espa�o em linha como se fosse tab
		printf("\t2 - Consultar clientes \n");
		printf("\t3 - Deletar cadastro \n\n\n\n"); // final do menu
		printf("Op��o:");
	
		scanf("%d", &opcao); //armazenar a escolha do usuario
	
		system("cls"); //limpar a tela 
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro();//chamada de fun��es
			break;
			
			case 2:
			consulta();//chamada de fun��es
			break;
			
			case 3:
			deletar();//chamada de fun��es
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel! \n\n"); //final da sele��o
			system("pause");
			break;
			
		}
		
	}
	
}
