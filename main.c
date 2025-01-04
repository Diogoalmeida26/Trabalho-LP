#include "menus.h"
#include "clientes.h"
#include "espacos.h"
#include "reservas.h"
#include "equipamentos.h"
#include "logs.h"
#include <stdio.h>

int main() {
    // Mensagem de inicialização
    printf("=== Sistema de Gestão de Reservas ===\n");
    printf("Carregando o sistema...\n");

    // Menu principal
    menu_principal();

    // Liberação de memória antes de encerrar o programa
    liberar_clientes();
    liberar_espacos();
    liberar_reservas();
    liberar_equipamentos();

    printf("Sistema encerrado com sucesso.\n");
    return 0;
}
