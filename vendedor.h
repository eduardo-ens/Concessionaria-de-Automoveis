#ifndef _VENDEDOR_H
#define _VENDEDOR_H
#define ARQ_VENDEDORES "vendedores.dat"

typedef struct {
     int codigo; // código do vendedor
     char nome[41]; // nome do vendedor
} vendedor;

/* função que cadastra um vendedor no arquivo */
void cadastrar_vendedor(void);

/* função que altera um vendedor */
void alterar_vendedor(void);

/* função que lista todos os vendedores */
void listar_vendedores(void);

#endif
