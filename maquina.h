#ifndef MAQUINAS_H
#define MAQUINAS_H

// Constantes
#define MAX_MAQUINAS 100
#define TAM_NOME 50
#define TAM_TIPO 20

// Estrutura para representar uma máquina
typedef struct {
    int id;
    char nome[TAM_NOME];
    char tipo[TAM_TIPO]; // Exemplo: Corte, Injeção, Solda, etc.
    int tempo_total_producao; // Em minutos
    int processos_associados; // Número de processos em que a máquina foi usada
} Maquina;

// Funções relacionadas às máquinas
void criar_maquina(Maquina maquinas[], int *total_maquinas);
void listar_maquinas(const Maquina maquinas[], int total_maquinas);
void atualizar_maquina(Maquina maquinas[], int total_maquinas);
void excluir_maquina(Maquina maquinas[], int *total_maquinas);
void relatorio_maquinas_mais_utilizadas(const Maquina maquinas[], int total_maquinas);

#endif // MAQUINAS_H
