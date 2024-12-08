#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define VALOR_INVALIDO "O valor inserido é inválido"
#define MAX_INT 2147483647
#define SIZE_BUFFER 100
#define MENU "+--------------------------+"
#define CODE 3500

typedef enum {
    ATIVO,
    INATIVO,
    ABERTA,
    PRODUCAO,
    FINALIZADA
} Estado;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

// Estrutura para clientes
typedef struct {
    int id;
    char *nome;
    char *telemovel; // 9 dígitos, sem começar com zero
    char *nif;       // 9 dígitos, sem começar com zero
    Data dataRegistro;
    int atividades;  // Número de encomendas associadas ao cliente
} Cliente;

typedef struct {
    Cliente *clientes;
    int totalClientes;
    int numClientes;
} Clientes;

// Estrutura para produtos
typedef struct {
    int id;
    char *nome;
    char *categoria; // Ex: Roupa, Comida, Ginásio, Jardinagem
    int processos;   // Número de processos associados
} Produto;

typedef struct {
    Produto *produtos;
    int totalProdutos;
    int numProdutos;
} Produtos;

// Estrutura para encomendas
typedef struct {
    int id;
    int idCliente;   // Relacionado ao cliente que fez a encomenda
    Data dataCriacao;
    char *prioridade; // Baixa, Média ou Alta
    Estado estado;    // Aberta, Produção ou Finalizada
    float taxaCumprimento;
    int *itens;       // IDs dos produtos incluídos
    int *quantidades; // Quantidade dos produtos incluídos
    int numItens;
} Encomenda;

typedef struct {
    Encomenda *encomendas;
    int totalEncomendas;
    int numEncomendas;
} Encomendas;

// Estrutura para máquinas
typedef struct {
    int id;
    char *nome;
    char *tipo; // Ex: Corte, Injeção, Solda, Fresagem, etc.
    int tempoTotalProducao;
} Maquina;

typedef struct {
    Maquina *maquinas;
    int totalMaquinas;
    int numMaquinas;
} Maquinas;

// Funções auxiliares
void cleanInputBuffer();
int obterInteiro(int minValue, int maxValue, const char *msg);
void lerString(char *str, unsigned int size, const char *msg);
float obterFloat(float minValue, float maxValue, const char *msg);

#endif /* INPUT_H */
