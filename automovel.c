
/* automovel.c
 * 
 * Implementação das operações realizadas sobre o tipo venda.
 * 
 * Componentes do grupo: Bruno Brocanelli
 * 						 Eduardo Nascimento da Silva
 * 
 * Data: 02/12/2020
 */
#include <stdio.h>
#include <stdlib.h>
#include "automovel.h"

/* funcao que cadastra um automovel no arquivo */
void cadastrar_automovel(void){
	
	FILE *arq, *f; //Inicializacao de ponteiros 
	automovel a;
	arq = fopen(ARQ_AUTOMOVEIS, "ab"); //Abertura do arquivo binario.
	if(arq == NULL){ //Se o arquivo for null, erro, exibe mensagem e sai.
		printf("Erro na abertura de arquivo!\n");
		system("pause");
		exit(1);
	}
	
	fseek(arq, 0, SEEK_END); //Posiciona o ponteiro do arquivo.
	a.codigo = ftell(arq) / sizeof(automovel) + 1; //O codigo sera o tamanho do arquivo dividido pela struct vendedor + 1.
	printf("Digite a Marca: ");
	scanf(" %20[^\n]",a.marca);
	printf("Digite o Modelo: ");
	scanf(" %20[^\n]", a.modelo);
	printf("Digite o Ano: ");
	scanf("%d", &a.ano);
	printf("Digite o Preco: ");
	scanf("%f", &a.preco);
	printf("Automovel Vendido? [1-S | 0-N]: ");
	scanf("%d", &a.vendido);
	
		if(a.vendido == 0){ //Se o carro nao tiver sido vendido.
		f = fopen(ARQ_A_VENDA, "a+"); //Abrir arquivo Arq_a_Venda.
		if(f == NULL){ //Se o arquivo for NULL, erro na abertura, exibe a menssagem e sai.
			printf("Erro na abertura de arquivo!\n");
			system("pause");
			exit(1);
		}
		
		fwrite(&a,sizeof(automovel),1,f); //Escreve os dados do carro uma vez no arquivo de ponteiro f.
		fclose(f); //Encerra o arquivo.
	}


	fwrite(&a,sizeof(automovel), 1,arq); //Escreve os dados do carro uma vez no arquivo de ponteiro arq.
	fclose(arq);//Encerra o arquivo
	
	printf("Veiculo cadastrado com Sucesso!\n");
}

/* funcao que lista todos os automoveis cadastrados */
void listar_todos_automoveis(void){
	FILE *f; //Inicializacao do ponteiro para arquivo.
	automovel a;
	f = fopen(ARQ_AUTOMOVEIS, "rb");//Inicializacao do arquivo em modo de leitura.
	if(f == NULL){ //Se arquivo for null, erro, exibe menssagem e retorna.
		printf("Erro na leitura de arquivo!\n");
		system("pause");
		exit(1);
	}
	
	printf("\n\n\t\tCarros Cadastrados\n");
	printf("----------------------------------------------------------------------------------\n");
	printf("#Codigo     Marca                Modelo               Ano      Preco     Situacao\n");
	printf("----------------------------------------------------------------------------------\n");
	
	while(fread(&a,sizeof(automovel),1,f) > 0){ //Ler dados do arquivo enquanto nao for zero.
		printf("%06d      %-20s %-20s %-8d %-10.2f %d\n", a.codigo, a.marca,a.modelo,a.ano,a.preco,a.vendido); //Exibe os dados lidos.
	}
	printf("----------------------------------------------------------------------------------\n");
	
	fclose(f); //Encerra o arquivo.
}

/* funcao que lista os automoveis a venda */
void listar_automoveis_a_venda(void){
	FILE *f; //Inicializacao do ponteiro para arquivo.
	automovel a;
	f = fopen(ARQ_A_VENDA, "r");//Inicializacao do arquivo em modo de leitura.
	if(f == NULL){//Se arquivo for null, erro, exibe menssagem e retorna.
		printf("Erro na leitura de arquivo!\n");
		system("pause");
		exit(1);
	}
	
	printf("\n\n\t\tCarros Nao Vendidos Cadastrados\n");
	printf("----------------------------------------------------------------------------------\n");
	printf("#Codigo     Marca                Modelo               Ano      Preco     Situacao\n");
	printf("----------------------------------------------------------------------------------\n");
	
	while(fread(&a,sizeof(automovel),1,f) > 0){ //Ler dados do arquivo enquanto nao for zero.
		printf("%06d      %-20s %-20s %-8d %-10.2f %d\n", a.codigo, a.marca,a.modelo,a.ano,a.preco,a.vendido); //Exibe os dados lidos.
	}
	printf("----------------------------------------------------------------------------------\n");
	
	fclose(f); //Encerra o arquivo.
}

/* funcao que altera os dados de um automovel cadastrado */
void alterar_automovel(void){

    FILE *f; //Inicializacao do ponteiro 
	automovel a;
	int codigo;
	f = fopen(ARQ_AUTOMOVEIS, "r+b"); //Abertura do arquivo em mode de leitura e escrita.
	if(f == NULL){
		printf("Erro na leitura de arquivo!\n");
		system("pause");
		exit(1);
	}
	
	printf("Digite o codigo do carro que seja alterar: ");
	scanf("%d", &codigo);
	
	fseek(f, (codigo - 1) * sizeof(automovel),SEEK_SET);//Posicionar o ponteiro de arquivo na posicao do codigo.
	fread(&a, sizeof(automovel), 1, f);//Ler dados da posicao.
	
	if(feof(f) || codigo <= 0 || codigo != a.codigo) /*Se chegar ao fim do arquivo ou codigo menor ou igual a zero ou codigo diferente do codigo lido, menssagem e retorna */
     {
		fprintf(stderr, "\nErro: Codigo do carro invalido!\n");
		return;
	  }
	  else{
			printf("Codigo do Carro: %06d\n",a.codigo);
			printf("Marca do Carro: %s\n", a.marca);
			printf("Modelo do Carro: %s\n", a.modelo);
			printf("Ano do Carro: %d\n", a.ano);
			printf("Preco do Carro: %f\n", a.preco);
			printf("Situacao do Carro: %d\n", a.vendido);
			
			printf("\n\n");
			printf("<<<<<Digite o novo registro>>>>>\n");
	        printf("Marca do Carro: ");
	        scanf(" %20[^\n]", a.marca);
			printf("Modelo do Carro: ");
			scanf(" %20[^\n]", a.modelo);
			printf("Ano do Carro: ");
			scanf("%d", &a.ano);
			printf("Preco do Carro: ");
			scanf("%f", &a.preco);
			printf("Situacao do Carro: ");
			scanf("%d", &a.vendido);
			
			fseek(f, (codigo-1)*sizeof(automovel), SEEK_SET); ////Posicionar o ponteiro do aruivo na posicao codigo.
	        fwrite(&a,sizeof(automovel),1,f) == sizeof(automovel);//Sobreescrever o dado.
	        fclose(f);//Encerra o arquivo.
	        printf("Cadastro alterado com sucesso!\n");
	  }
}