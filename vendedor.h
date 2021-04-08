#ifndef _VENDEDOR_H
#define _VENDEDOR_H
#define ARQ_VENDEDORES "vendedores.dat"

typedef struct {
     int codigo; // c�digo do vendedor
     char nome[41]; // nome do vendedor
} vendedor;

/* fun��o que cadastra um vendedor no arquivo */
void cadastrar_vendedor(void);

/* fun��o que altera um vendedor */
void alterar_vendedor(void);

/* fun��o que lista todos os vendedores */
void listar_vendedores(void);

#endif
