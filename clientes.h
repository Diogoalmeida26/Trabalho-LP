#ifndef CLIENTE_H
#define CLIENTE_H

// Máximo de clientes e tamanho máximo dos campos
#define MAX_CLIENTES 100
#define TAM_NOME 50
#define TAM_CONTATO 50
#define TAM_NIF 15
#define TAM_DATA 11

// Protótipos das funções relacionadas a clientes
void criar_cliente();
void listar_clientes();
void atualizar_cliente();
void excluir_cliente();
void total_clientes();
void clientes_mais_ativos();

#endif // CLIENTE_H
