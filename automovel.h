#ifndef _AUTOMOVEL_H
#define _AUTOMOVEL_H

#include <stdbool.h>

#define ARQ_AUTOMOVEIS "automoveis.dat"
#define ARQ_A_VENDA "avenda.txt"

typedef struct {
     int codigo; // código do automóvel
     char marca[21]; // marca do automóvel, por exemplo, Fiat, Chevrolet, VW
     char modelo[21]; // modelo do automóvel, por exemplo, Palio, Onix, Up
     int ano; // ano do modelo do automóvel
     float preco; // preço de venda do automóvel
     bool vendido; // indica se o automóvel foi vendido ou não
} automovel;

/* função que cadastra um automóvel no arquivo */
void cadastrar_automovel(void);

/* função que altera os dados de um automóvel cadastrado */
void alterar_automovel(void);

/* função que lista todos os automóveis cadastrados */
void listar_todos_automoveis(void);

/* função que lista os automóveis a venda */
void listar_automoveis_a_venda(void);
#endif
