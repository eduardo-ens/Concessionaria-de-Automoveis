#ifndef _AUTOMOVEL_H
#define _AUTOMOVEL_H

#include <stdbool.h>

#define ARQ_AUTOMOVEIS "automoveis.dat"
#define ARQ_A_VENDA "avenda.txt"

typedef struct {
     int codigo; // c�digo do autom�vel
     char marca[21]; // marca do autom�vel, por exemplo, Fiat, Chevrolet, VW
     char modelo[21]; // modelo do autom�vel, por exemplo, Palio, Onix, Up
     int ano; // ano do modelo do autom�vel
     float preco; // pre�o de venda do autom�vel
     bool vendido; // indica se o autom�vel foi vendido ou n�o
} automovel;

/* fun��o que cadastra um autom�vel no arquivo */
void cadastrar_automovel(void);

/* fun��o que altera os dados de um autom�vel cadastrado */
void alterar_automovel(void);

/* fun��o que lista todos os autom�veis cadastrados */
void listar_todos_automoveis(void);

/* fun��o que lista os autom�veis a venda */
void listar_automoveis_a_venda(void);
#endif
