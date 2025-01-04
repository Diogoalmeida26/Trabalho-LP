#ifndef ENCOMENDAS_H
#define ENCOMENDAS_H

// Máximo de encomendas e tamanho máximo dos campos
#define MAX_ENCOMENDAS 100
#define TAM_DATA 11

// Funções relacionadas a encomendas
void criar_encomenda();
void listar_encomendas();
void atualizar_encomenda();
void excluir_encomenda();
void relatorio_encomendas_por_estado();
void calcular_tempo_medio_producao();

#endif // ENCOMENDAS_H
