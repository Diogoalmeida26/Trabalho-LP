#include "menus.h"
#include "clientes.h"
#include "espacos.h"
#include "reservas.h"
#include "equipamentos.h"
#include "logs.h"
#include "input.h"
#include <stdio.h>

void menu_clientes() {
    int opcao;
    do {
        printf("\n=== Menu de Clientes ===\n");
        printf("1. Inserir Cliente\n");
        printf("2. Listar Clientes\n");
        printf("3. Atualizar Cliente\n");
        printf("4. Remover Cliente\n");
        printf("5. Voltar\n");
        opcao = ler_inteiro("Escolha uma opção: ");

        switch (opcao) {
            case 1: {
                char nome[TAMANHO_MAX_NOME];
                char contato[TAMANHO_MAX_CONTATO];
                char nif[TAMANHO_MAX_NIF];
                ler_string("Nome: ", nome, TAMANHO_MAX_NOME);
                ler_string("Contato: ", contato, TAMANHO_MAX_CONTATO);
                ler_string("NIF: ", nif, TAMANHO_MAX_NIF);
                inserir_cliente(nome, contato, nif);
                break;
            }
            case 2:
                listar_clientes();
                break;
            case 3: {
                int id = ler_inteiro("ID do cliente a atualizar: ");
                atualizar_cliente(id);
                break;
            }
            case 4: {
                int id = ler_inteiro("ID do cliente a remover: ");
                remover_cliente(id);
                break;
            }
            case 5:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 5);
}

void menu_espacos() {
    int opcao;
    do {
        printf("\n=== Menu de Espaços ===\n");
        printf("1. Inserir Espaço\n");
        printf("2. Listar Espaços\n");
        printf("3. Atualizar Espaço\n");
        printf("4. Remover Espaço\n");
        printf("5. Voltar\n");
        opcao = ler_inteiro("Escolha uma opção: ");

        switch (opcao) {
            case 1: {
                char nome[TAMANHO_MAX_NOME];
                int capacidade = ler_inteiro("Capacidade: ");
                char tipo[TAMANHO_MAX_TIPO];
                ler_string("Tipo: ", tipo, TAMANHO_MAX_TIPO);
                inserir_espaco(nome, capacidade, tipo);
                break;
            }
            case 2:
                listar_espacos();
                break;
            case 3: {
                int id = ler_inteiro("ID do espaço a atualizar: ");
                atualizar_espaco(id);
                break;
            }
            case 4: {
                int id = ler_inteiro("ID do espaço a remover: ");
                remover_espaco(id);
                break;
            }
            case 5:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 5);
}

void menu_reservas() {
    int opcao;
    do {
        printf("\n=== Menu de Reservas ===\n");
        printf("1. Inserir Reserva\n");
        printf("2. Listar Reservas\n");
        printf("3. Atualizar Reserva\n");
        printf("4. Remover Reserva\n");
        printf("5. Voltar\n");
        opcao = ler_inteiro("Escolha uma opção: ");

        switch (opcao) {
            case 1: {
                int cliente_id = ler_inteiro("ID do Cliente: ");
                int espaco_id = ler_inteiro("ID do Espaço: ");
                int duracao = ler_inteiro("Duração (em horas): ");
                int participantes = ler_inteiro("Número de Participantes: ");
                char estado[TAMANHO_MAX_ESTADO];
                ler_string("Estado (Pendente, Confirmada, etc.): ", estado, TAMANHO_MAX_ESTADO);
                inserir_reserva(cliente_id, espaco_id, duracao, participantes, estado);
                break;
            }
            case 2:
                listar_reservas();
                break;
            case 3: {
                int id = ler_inteiro("ID da reserva a atualizar: ");
                atualizar_reserva(id);
                break;
            }
            case 4: {
                int id = ler_inteiro("ID da reserva a remover: ");
                remover_reserva(id);
                break;
            }
            case 5:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 5);
}

void menu_equipamentos() {
    int opcao;
    do {
        printf("\n=== Menu de Equipamentos ===\n");
        printf("1. Inserir Equipamento\n");
        printf("2. Listar Equipamentos\n");
        printf("3. Atualizar Equipamento\n");
        printf("4. Remover Equipamento\n");
        printf("5. Voltar\n");
        opcao = ler_inteiro("Escolha uma opção: ");

        switch (opcao) {
            case 1: {
                char nome[TAMANHO_MAX_NOME];
                char tipo[TAMANHO_MAX_TIPO];
                char estado[TAMANHO_MAX_ESTADO];
                ler_string("Nome: ", nome, TAMANHO_MAX_NOME);
                ler_string("Tipo: ", tipo, TAMANHO_MAX_TIPO);
                ler_string("Estado: ", estado, TAMANHO_MAX_ESTADO);
                inserir_equipamento(nome, tipo, estado);
                break;
            }
            case 2:
                listar_equipamentos();
                break;
            case 3: {
                int id = ler_inteiro("ID do equipamento a atualizar: ");
                atualizar_equipamento(id);
                break;
            }
            case 4: {
                int id = ler_inteiro("ID do equipamento a remover: ");
                remover_equipamento(id);
                break;
            }
            case 5:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 5);
}

void menu_principal() {
    int opcao;
    do {
        printf("\n=== Sistema de Gestão ===\n");
        printf("1. Gerir Clientes\n");
        printf("2. Gerir Espaços\n");
        printf("3. Gerir Reservas\n");
        printf("4. Gerir Equipamentos\n");
        printf("5. Sair\n");
        opcao = ler_inteiro("Escolha uma opção: ");

        switch (opcao) {
            case 1:
                menu_clientes();
                break;
            case 2:
                menu_espacos();
                break;
            case 3:
                menu_reservas();
                break;
            case 4:
                menu_equipamentos();
                break;
            case 5:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 5);
}
