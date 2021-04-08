
/* vendedor.c
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
#include "vendedor.h"

/* funcao que cadastra um vendedor no arquivo */
void cadastrar_vendedor(){

	FILE *f; //Inicializcao do ponteiro para arquivo.
	vendedor v;
	f = fopen(ARQ_VENDEDORES, "ab"); //Aberuta do arquivo.
	if(f == NULL){  //Se o arquivo for null, erro na abertura.
		printf("Erro ao abrir arquivo!\n");
		system("pause");
		exit(1);
	}
	
	fseek(f, 0, SEEK_END);   //Posiciona o ponteiro do arquivo no final.
	v.codigo = ftell(f) / sizeof(vendedor) + 1;  //O codigo sera o tamanho do arquivo dividido pela struct vendedor + 1.
    printf("Nome do Vendedor: ");
    scanf(" %40[^\n]", v.nome);  //Recebe o nome do vendedor.
	fwrite(&v,sizeof(vendedor),1,f); //Escreve os dados do vendedor uma vez no arquivo.
	fclose(f); //Fecha o arquivo.
	printf("Vendedor Cadastrado com sucesso!\n"); //Mensagem para o usuario.
}

/* funcao que lista todos os vendedores */
void listar_vendedores(){
	
	FILE *f; //Inicializcao do ponteiro para arquivo.
	vendedor v;
	f = fopen(ARQ_VENDEDORES, "rb"); //Aberuta do arquivo em mode leitura.
	if(f == NULL){ //Se o arquivo for null, erro na abertura.
		printf("Erro na leitura de arquivo!\n");
		system("pause");
		exit(1);
	}
	
	printf("\n\n\t\tVendedores Cadastrados\n");
	printf("--------------------------------------------\n");
	printf("#Codigo do Vendedor         Nome\n");
	printf("--------------------------------------------\n");
	
	while(fread(&v,sizeof(vendedor),1,f) > 0){ //Enquanto leitura do arquivo for maior que zero, armazenar valor na variavle v.
		printf("%06d                      %-25.25s \n", v.codigo, v.nome);
	}
	printf("--------------------------------------------\n");
	
	fclose(f); //Fechamento de arquivo.
}

/* funcao que altera um vendedor */
void alterar_vendedor(void){
	FILE *f; //Inicializcao do ponteiro para arquivo.
	vendedor v;
	int codigo;
	f = fopen(ARQ_VENDEDORES, "r+b"); //Aberuta do arquivo em mode leitura.
	if(f == NULL){ //Se o arquivo for null, erro na abertura.
		printf("Erro na leitura de arquivo!\n");
		system("pause");
		exit(1);
	}
	
	printf("Digite o codigo do vendedor que seja alterar: "); 
	scanf("%d", &codigo);
	
	fseek(f, (codigo - 1) * sizeof(vendedor),SEEK_SET); //Posicionar o ponteiro de arquivo na posicao do codigo.
	fread(&v, sizeof(vendedor), 1, f); //Ler dados da posicao.
	
	if(feof(f) || codigo <= 0 || codigo != v.codigo) /*Se chegar ao fim do arquivo ou codigo menor ou igual a zero ou codigo diferente do codigo lido, menssagem e retorna */
   {
		fprintf(stderr, "\nErro: Codigo do vendedor invalido!\n");
		return;
   }
   else{
			printf("Codigo do vendedor: %06d\n",v.codigo);  //Exibicao do codigo e do nome do vendedor.
			printf("Nome do vendedor: %s\n", v.nome);
			
			printf("<<<<<Digite o novo registro>>>>>\n");
			printf("Digite o nome: ");  //Apenas o nome do vendedor podera ser alterado.
			scanf(" %40[^\n]", v.nome);
	
		fseek(f, (codigo-1)*sizeof(vendedor), SEEK_SET); //Posicionar o ponteiro do aruivo na posicao codigo.
	    fwrite(&v,sizeof(vendedor),1,f) == sizeof(vendedor); //Sobreescrever o dado.
	   	printf("Registro alterado com Sucesso!\n\n");
        fclose(f); //Encerramento de arquivo.
	}
}
