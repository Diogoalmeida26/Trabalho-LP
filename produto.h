#ifndef PRODUTO_H
#define PRODUTO_H

// Definição das estruturas
typedef struct {
    int id_maquina;
    int tempo_execucao;
} Processo;

typedef struct {
    int id;
    char nome[50];
    char categoria[20];
    Processo *processos; // Lista dinâmica de processos
    int num_processos;
} Produto;

// Funções CRUD
void criar_produto();
void listar_produtos();
void atualizar_produto();
void excluir_produto();

// Relatórios
void total_produtos();
void produtos_por_categoria();
void produtos_mais_menos_procurados();

#endif // PRODUTO_H
