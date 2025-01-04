#ifndef PRODUTO_H
#define PRODUTO_H

// Máximo de produtos e tamanho máximo dos campos
#define MAX_PRODUTOS 100
#define TAM_NOME_PROD 50
#define TAM_CATEGORIA 30

// Protótipos das funções relacionadas a produtos
void criar_produto();
void listar_produtos();
void atualizar_produto();
void excluir_produto();
void total_produtos();
void produtos_por_categoria();
void produtos_mais_menos_procurados();

#endif // PRODUTO_H
