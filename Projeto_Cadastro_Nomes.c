#include <stdio.h> // biblioteca de comunicação com o usuario
#include <stdlib.h> //bibliotea de alocação de espaço em memoria
#include <locale.h> //bibliotea de alocação de texto por região
#include <string.h> //biblioteca de strings


int registro() //função respónsavel por cadastrar usuarios no sistema
{
	//inicio criação de variaveis/string
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char aparelho[40];
	//final da criação de variaveis/string
	
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuario
	scanf("%s",cpf); //armazenar a escolha do usuario //%s refere-se as strings
	
	strcpy(arquivo,cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo,"w"); //cria o arquivo e o "W" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo o "a" significa gravar
	fprintf(file, "-");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");//coletando informação do usuario
	scanf("%s",nome);//armazenar a escolha do usuario
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,"-");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informação do usuario
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, "-");
	fclose(file);
	
	printf("Digite o aparelho: ");//coletando informação do usuario
	scanf("%s",aparelho);//armazenar a escolha do usuario
	
	file = fopen(arquivo,"a");
	fprintf(file,aparelho);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, "-");
	fclose(file);
	
	system("pause");//pausa o sistema para verificação do usuario
	
}

int consulta()

{
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");//coletando informação do usuario
	scanf("%s",cpf);//armazenar a escolha do usuario
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\n\n CPF não está cadastrado. \n\n");//coletando informação do usuario
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as iformações do Cliente: ");//coletando informação do usuario
		printf("%s", conteudo);//coletando informação do usuario
		printf("\n\n");
    }
	
	system("pause");//pausa o sistema para verificação do usuario
	
}

int deletar()

{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado:");//coletando informação do usuario
	scanf("%s",cpf);//armazenar a escolha do usuario
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file ==  NULL)
	{
		printf("Usuário não cadastrado! \n");//coletando informação do usuario
	}	
	
	system("pause"); //pausa o sistema para verificação do usuario
}




int main ()

{
	int opcao=0; // definindo variaveis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");//limpar a tela
				
		setlocale(LC_ALL, "Portuguese"); // definindo localização
	
	
		printf("###IT Solutions Assistência Técnica### \n\n"); // o comando \n pula linhas // começo do menu
		printf("Escolha a opção desejada: \n\n");
		printf("\t1 - Registrar clientes \n"); // o comando \t da um espaço em linha como se fosse tab
		printf("\t2 - Consultar clientes \n");
		printf("\t3 - Deletar cadastro \n\n\n\n"); // final do menu
		printf("Opção:");
	
		scanf("%d", &opcao); //armazenar a escolha do usuario
	
		system("cls"); //limpar a tela 
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro();//chamada de funções
			break;
			
			case 2:
			consulta();//chamada de funções
			break;
			
			case 3:
			deletar();//chamada de funções
			break;
			
			default:
			printf("Essa opção não está disponível! \n\n"); //final da seleção
			system("pause");
			break;
			
		}
		
	}
	
}
