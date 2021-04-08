

/* venda.c
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
#include "venda.h"
#include "automovel.h"
#include "vendedor.h"

void cadastrar_venda()
{
	FILE *f, *vend, *arq; 
	automovel a;
	vendedor v;
	venda sell;
	
	//Solicita que usuario digite o codigo do veiculo vendido
	printf("Digite o codigo do veiculo vendido: ");
	scanf("%d", &sell.cod_automovel);

	//Retorna mensagem caso codigo_automovel seja menor ou igual a zero
    if(sell.cod_automovel <= 0){
    	printf("Erro: Codigo do automovel invalido!\n");
    	return;
	}

	//Abertura do arquvivo avenda.txt e caso a tentativa de abertura retorne NULL, exibe mensagem de erro
	f = fopen(ARQ_A_VENDA, "rb");
	if(f == NULL) {
		printf("ERRO AO ABRIR ARQ_A_VENDA");
		return;
	}

	//Abertura do arquivo vendedores.dat e caso a tentativa de abertura retorne NULL, exibe mensagem de erro
	vend = fopen(ARQ_VENDEDORES, "rb");
	if(vend == NULL) {
		printf("ERRO AO ABRIR ARQ_VENDEDORES");
		return;
	}

	//Le dados do arquivo avenda.txt e confere se codigo do automovel passado pelo usuario esta cadastrado
	while(fread(&a, sizeof(automovel), 1, f) > 0) {
		//Se codigo estiver cadastrado, exibe informações do automovel
		if(sell.cod_automovel == a.codigo) {  
			printf("Marca: %s\n", a.marca);
			printf("Modelo: %s\n", a.modelo);
			printf("Ano: %d\n", a.ano);
			printf("Preco: %f\n\n", a.preco);

			//Se veiculo estiver disponivel para venda, solicita codigo do vendedor
			if(a.vendido == 0) {
			printf("Digite o codigo do vendedor: ");
			scanf("%d", &sell.cod_vendedor);
			}
			//Se veiculo ja tiver sido vendido, exibe mensagem 	
			else if (a.vendido == 1) {
			printf("Veiculo ja foi vendido");
			return;
			}
		}
	}

	//Le dados do arquivo vendedores.dat e busca o codigo do vendedor
	while(fread(&v, sizeof(vendedor), 1, vend) > 0){
		if(v.codigo == sell.cod_vendedor) {
			//Se encontrar o codigo do vendedor, exibe o nome
			printf("Vendedor: %s\n", v.nome);
			break;
		}
	}

	//Solicita que o usuario digite a data de venda
	printf("Digite o dia da venda(dd): ");
	scanf("%d", &sell.dt.dia);

	printf("Digite o mes da venda(mm): ");
	scanf("%d", &sell.dt.mes);

	printf("Digite o ano da venda(dd): ");
	scanf("%d", &sell.dt.ano);	
	
	//Abre arquivo vendas.dat e caso a tentativa de abertura retorne NULL, exibe mensagem de erro
	arq = fopen(ARQ_VENDAS, "ab");
	if(arq == NULL){
		printf("ERRO AO ABRIR ARQ_VENDAS");
		return;
	}

	//Posiciona cursor no fim do arquivo (por segurança)
    fseek(arq, 1, SEEK_END);
	
	//Escreve informações da struct sell dentro do arquivo vendas.dat
	fwrite(&sell, sizeof(venda), 1, arq);
	
	//Exibe mensagem de sucesso de operacao
    printf("Venda registrada com sucesso!\n");

	//Fecha arquivos
	fclose(f);
	fclose(vend);
	fclose(arq);
}


void listar_vendas_mes()
{
	FILE *f, *arq, *vend;
	automovel a;
	venda v;
	vendedor p;
	int mes, ano;

	//Abre arquivo automoveis.dat e caso retorne NULL, exibe mensagem de erro
	f = fopen(ARQ_AUTOMOVEIS, "rb");
	if(f == NULL) {
		printf("Erro na leitura do arquivo ARQ_AUTOMOVEIS!\n");
		return;
	}

	//Abre arquivo vendas.txt e caso retorne NULL, exibe mensagem de erro
	arq = fopen(ARQ_VENDAS, "rb");
	if(arq == NULL) {
		printf("Erro na leitura do arquivo ARQ_VENDAS!\n");
		return;
	}

	//Abre arquivo vendedores.dat e caso retorne NULL, exibe mensagem de erro
	vend = fopen(ARQ_VENDEDORES, "rb");
	if(vend == NULL) {
		printf("Erro na leitura do arquivo ARQ_VENDEDORES!\n");
		return;
	}

	//Solicita que usuario digite mes e ano que deseja listar vendas
	printf("Digite o mes da busca(mm): ");
	scanf("%d", &mes);
	printf("Digite o ano da busca(aaaa): ");
	scanf("%d", &ano);

	printf("\n\n\t\tCarros Vendidos no mes\n");
    printf("----------------------------------------------------------------------------------------\n");
    printf("Data da Venda     Marca               Modelo                Ano     Preco       Vendedor\n");
	printf("----------------------------------------------------------------------------------------\n");

	//Le dados do arquivo vendas.dat e busca vendas com mes e ano informados pelo usuario
	while(fread(&v,sizeof(venda),1,arq) > 0) {
		if(v.dt.mes == mes && v.dt.ano == ano) {
			printf("%02d/%02d/%d        ", v.dt.dia, v.dt.mes, v.dt.ano);				
		}
		//Se não encontrar o mes , exibe mensagem
		else if(feof(arq) && v.dt.mes != mes){
			printf("Mes informado nao esta nos registros!\n");
			system("pause");
			return;
		}
		//Se não encontrar o ano, exibe mensagem
		else if(feof(arq) && v.dt.ano != ano){
			printf("Ano informado nao esta nos registros!\n");
			return;
		}

		//Apos encontrar venda no mes e ano informados,
		//Le o arquivo automoveis.dat para buscar informacoes dos automoveis e exibi-las
		while(fread(&a, sizeof(automovel), 1, f) > 0) {
		if(v.cod_automovel == a.codigo) {
			printf("%-20s %-20s %-7d %.2f", a.marca, a.modelo, a.ano, a.preco);
		}
	}
	
	//Le arquivo vendedores.dat e busca codigo_vendedor
	while(fread(&p, sizeof(vendedor), 1, vend) > 0) {
		if(v.cod_vendedor == p.codigo) {
			//Ao encontrar, exibe nome do vendedor
			printf("    %s\n", p.nome);
		}
	}
	//Retorna para inicio dos arquivos
	rewind(f);
	rewind(vend);
	}		
	printf("----------------------------------------------------------------------------------------\n");
	
	//Fecha os arquivos	
	fclose(f);	
	fclose(arq);
	fclose(vend);
}
	
void listar_vendas_vendedor()
{
	FILE *vend, *f, *carro;
	vendedor v;
	venda sell;
	automovel a;
	int codigo_vendedor;

	//Abre arquivo vendedores.dat e caso retorne NULL, exibe mensagem de erro
	vend = fopen(ARQ_VENDEDORES, "rb");
	if(vend == NULL) {
		printf("Erro na leitura do arquivo ARQ_VENDEDORES!\n");
		return;
	}

	//Abre arquivo vendas.dat e caso retorne NULL, exibe mensagem de erro
	f = fopen(ARQ_VENDAS, "rb");
	if(f == NULL) {
		printf("Erro na leitura do arquivo ARQ_VENDAS!\n");
		return;
	}

	//Abre arquivo automoveis.dat e caso retorne NULL, exibe mensagem de erro
	carro = fopen(ARQ_AUTOMOVEIS, "rb");
	if(carro == NULL) {
		printf("Erro na leitura do arquivo ARQ_AUTOMOVEIS!\n");
		return;
	}

	//Solicita ao usuario o codigo do vendedor cujo deseja mostrar todas as vendas
	printf("Digite o codigo do vendedor: ");
	scanf("%d", &codigo_vendedor);

	//Le do arquivo vendedores.dat e busca codigo_vendedor
	while(fread(&v, sizeof(vendedor), 1, vend)) {
		if(v.codigo == codigo_vendedor) {
			//Ao encontrar, exibe nome do vendedor
			printf("Vendedor: %s\n\n", v.nome);
		}
	}
	
    printf("--------------------------------------------------------------------------------\n");
    printf("Data da Venda     Marca               Modelo                Ano     Preco\n");
	printf("--------------------------------------------------------------------------------\n");

	//Le do arquivo vendas.dat e busca codigo_vendedor dentro do arquivo
	while(fread(&sell, sizeof(venda), 1, f) > 0) {
		if(sell.cod_vendedor == codigo_vendedor) {
			//Ao encontrar, exibe data da venda
			printf("%02d/%02d/%d        ", sell.dt.dia, sell.dt.mes, sell.dt.ano);

			//Le do arquivo automoveis.dat e busca informacoes do automovel vendido
			while(fread(&a, sizeof(automovel), 1, carro) > 0) {
				if(a.codigo == sell.cod_automovel) {
					//Ao encontrar, exibe as informacoes do automovel
					printf("%-20s %-20s %-7d %.2f\n", a.marca, a.modelo, a.ano, a.preco);	
				}
			}
		}
		//Retorna ao inicio do arquivo automoveis.dat
		rewind(carro);
	}
	printf("--------------------------------------------------------------------------------\n");
	
	//Fecha os arquivos
	fclose(f);
	fclose(vend);
	fclose(carro);
}