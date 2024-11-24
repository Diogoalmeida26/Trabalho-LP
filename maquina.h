#ifndef MAQUINA_H
#define MAQUINA_H

// Estrutura para representar uma máquina
typedef struct {
    int id;            // ID único da máquina
    char nome[50];     // Nome da máquina
    char tipo[20];     // Tipo da máquina (ex.: Corte, Fresagem, CNC, etc.)
} Maquina;

// Prototipação das funções CRUD e relatórios
void criar_maquina();
void listar_maquinas();
void atualizar_maquina();
void excluir_maquina();
void maquinas_mais_utilizadas();
void tempo_medio_por_maquina();

#endif // MAQUINA_H
