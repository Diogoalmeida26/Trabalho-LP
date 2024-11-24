#ifndef CLIENTE_H
#define CLIENTE_H

// Estrutura para armazenar informações de clientes
typedef struct {
    int id;               // ID único do cliente
    char nome[50];        // Nome do cliente
    char contato[50];     // Contato (e-mail ou telefone)
    char nif[15];         // Número de identificação fiscal
    char data_registro[11]; // Data de registro no formato "dd/mm/aaaa"
} Cliente;

// Prototipação das funções do módulo Cliente
void criar_cliente();
void listar_clientes();
void atualizar_cliente();
void excluir_cliente();
void total_clientes();
void clientes_mais_ativos();

#endif // CLIENTE_H
