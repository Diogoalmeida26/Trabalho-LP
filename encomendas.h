#ifndef ENCOMENDA_H
#define ENCOMENDA_H

#include "produto.h" // Para associar produtos à encomenda
#include "cliente.h" // Para associar clientes à encomenda

// Estrutura para itens de uma encomenda
typedef struct {
    int id_produto;   // ID do produto
    int quantidade;   // Quantidade do produto na encomenda
} ItemEncomenda;

// Estrutura para encomendas
typedef struct {
    int id;                     // ID único da encomenda
    int id_cliente;             // ID do cliente associado
    char data_criacao[11];      // Data de criação da encomenda
    char prioridade[10];        // Prioridade: Baixa, Média ou Alta
    char estado[15];            // Estado: Aberta, Produção ou Finalizada
    float taxa_cumprimento;     // Progresso: 0% a 100%
    ItemEncomenda *itens;       // Lista dinâmica de itens na encomenda
    int num_itens;              // Número de itens na encomenda
} Encomenda;

// Prototipação das funções
void criar_encomenda();
void listar_encomendas();
void atualizar_encomenda();
void excluir_encomenda();
void listar_encomendas_por_estado();
void listar_encomendas_por_prioridade();

#endif // ENCOMENDA_H
