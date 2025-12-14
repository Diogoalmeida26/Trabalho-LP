#include "menu.h"
#include "utils.h"
#include <stdio.h>

static DataHora ler_datahora(void) {
    DataHora d;
    printf("Ano: "); ler_int(&d.ano);
    printf("Mes: "); ler_int(&d.mes);
    printf("Dia: "); ler_int(&d.dia);
    printf("Hora: "); ler_int(&d.hora);
    printf("Min: "); ler_int(&d.min);
    return d;
}

static void menu_ocorrencias(OcorrenciaRepo *or) {
    int op;
    do {
        printf("\n--- Ocorrencias ---\n");
        printf("1) Adicionar\n2) Listar\n3) Atualizar estado\n0) Voltar\n> ");
        if (!ler_int_intervalo(0, 3, &op)) { printf("Opcao invalida\n"); continue; }
        if (op == 1) {
            char local[MAX_LOCAL];
            printf("Local: "); ler_string(local, sizeof(local));
            printf("Tipo (1-FLORESTAL,2-URBANO,3-INDUSTRIAL): ");
            int tipo; ler_int(&tipo);
            DataHora dh = ler_datahora();
            printf("Prioridade (1-BAIXA,2-NORMAL,3-ALTA): ");
            int pr; ler_int(&pr);
            if (adicionar_ocorrencia(or, local, (TipoOcorrencia)tipo, dh, (Prioridade)pr))
                printf("Criada.\n");
            else printf("Falha ao criar.\n");
        } else if (op == 2) {
            listar_ocorrencias(or);
        } else if (op == 3) {
            printf("ID: "); int id; ler_int(&id);
            printf("Novo estado (1-REPORTADA,2-EM_INTERVENCAO,3-CONCLUIDA): ");
            int st; ler_int(&st);
            if (atualizar_estado_ocorrencia(or, id, (EstadoOcorrencia)st))
                printf("Atualizado.\n");
            else printf("Falha.\n");
        }
    } while (op != 0);
}

static void menu_bombeiros(BombeiroRepo *br) {
    int op;
    do {
        printf("\n--- Bombeiros ---\n");
        printf("1) Adicionar\n2) Listar\n3) Atualizar\n0) Voltar\n> ");
        if (!ler_int_intervalo(0, 3, &op)) { printf("Opcao invalida\n"); continue; }
        if (op == 1) {
            char nome[MAX_NOME];
            printf("Nome: "); ler_string(nome, sizeof(nome));
            printf("Especialidade (1-COMBATE,2-RESGATE,3-SUPORTE): "); int esp; ler_int(&esp);
            printf("Estado (1-DISP,2-INTERV,3-TREINO): "); int st; ler_int(&st);
            if (adicionar_bombeiro(br, nome, (Especialidade)esp, (EstadoBombeiro)st))
                printf("Criado.\n");
            else printf("Falha.\n");
        } else if (op == 2) {
            listar_bombeiros(br);
        } else if (op == 3) {
            printf("ID: "); int id; ler_int(&id);
            char nome[MAX_NOME];
            printf("Novo nome: "); ler_string(nome, sizeof(nome));
            printf("Especialidade (1-3): "); int esp; ler_int(&esp);
            printf("Estado (1-3): "); int st; ler_int(&st);
            if (atualizar_bombeiro(br, id, nome, (Especialidade)esp, (EstadoBombeiro)st))
                printf("Atualizado.\n");
            else printf("Falha.\n");
        }
    } while (op != 0);
}

static void menu_equipamentos(EquipamentoRepo *er) {
    int op;
    do {
        printf("\n--- Equipamentos ---\n");
        printf("1) Adicionar\n2) Listar\n3) Atualizar\n0) Voltar\n> ");
        if (!ler_int_intervalo(0, 3, &op)) { printf("Opcao invalida\n"); continue; }
        if (op == 1) {
            char nome[MAX_NOME], local[MAX_LOCAL];
            printf("Nome: "); ler_string(nome, sizeof(nome));
            printf("Local: "); ler_string(local, sizeof(local));
            printf("Estado (1-DISP,2-EM_USO,3-MANUTENCAO): "); int st; ler_int(&st);
            if (adicionar_equipamento(er, nome, (EstadoEquip)st, local))
                printf("Criado.\n");
            else printf("Falha.\n");
        } else if (op == 2) {
            listar_equipamentos(er);
        } else if (op == 3) {
            printf("ID: "); int id; ler_int(&id);
            char nome[MAX_NOME], local[MAX_LOCAL];
            printf("Novo nome: "); ler_string(nome, sizeof(nome));
            printf("Novo local: "); ler_string(local, sizeof(local));
            printf("Estado (1-3): "); int st; ler_int(&st);
            if (atualizar_equipamento(er, id, nome, (EstadoEquip)st, local))
                printf("Atualizado.\n");
            else printf("Falha.\n");
        }
    } while (op != 0);
}

static void menu_intervencoes(IntervencaoRepo *ir, OcorrenciaRepo *or, BombeiroRepo *br, EquipamentoRepo *er) {
    int op;
    do {
        printf("\n--- Intervencoes ---\n");
        printf("1) Adicionar\n2) Listar\n3) Fechar\n4) Alocar bombeiro\n5) Alocar equipamento\n0) Voltar\n> ");
        if (!ler_int_intervalo(0, 5, &op)) { printf("Opcao invalida\n"); continue; }
        if (op == 1) {
            printf("ID ocorrencia: "); int ocId; ler_int(&ocId);
            DataHora dh = ler_datahora();
            printf("Estado (1-PLANEAMENTO,2-EXECUCAO,3-CONCLUIDA): "); int st; ler_int(&st);
            if (!buscar_ocorrencia(or, ocId)) { printf("Ocorrencia inexistente.\n"); continue; }
            if (adicionar_intervencao(ir, ocId, dh, (EstadoIntervencao)st))
                printf("Criada.\n");
            else printf("Falha.\n");
        } else if (op == 2) {
            listar_intervencoes(ir);
        } else if (op == 3) {
            printf("ID intervencao: "); int id; ler_int(&id);
            DataHora fim = ler_datahora();
            if (fechar_intervencao(ir, id, fim)) printf("Fechada.\n"); else printf("Falha.\n");
        } else if (op == 4) {
            printf("ID intervencao: "); int id; ler_int(&id);
            Intervencao *i = buscar_intervencao(ir, id);
            if (!i) { printf("Nao existe.\n"); continue; }
            printf("ID bombeiro: "); int bid; ler_int(&bid);
            if (alocar_bombeiro_intervencao(i, br, bid)) printf("Alocado.\n"); else printf("Falha.\n");
        } else if (op == 5) {
            printf("ID intervencao: "); int id; ler_int(&id);
            Intervencao *i = buscar_intervencao(ir, id);
            if (!i) { printf("Nao existe.\n"); continue; }
            printf("ID equipamento: "); int eid; ler_int(&eid);
            if (alocar_equipamento_intervencao(i, er, eid)) printf("Alocado.\n"); else printf("Falha.\n");
        }
    } while (op != 0);
}

static void menu_relatorios(const OcorrenciaRepo *or, const IntervencaoRepo *ir, const BombeiroRepo *br, const EquipamentoRepo *er) {
    int op;
    do {
        printf("\n--- Relatorios ---\n");
        printf("1) Ocorrencias por estado\n2) Ocorrencias por prioridade\n3) Intervencoes por ocorrencia\n4) Bombeiros disponiveis\n5) Equipamentos disponiveis\n0) Voltar\n> ");
        if (!ler_int_intervalo(0, 5, &op)) { printf("Opcao invalida\n"); continue; }
        if (op == 1) { printf("Estado (1-3): "); int st; ler_int(&st); listar_ocorrencias_por_estado(or, (EstadoOcorrencia)st); }
        else if (op == 2) { printf("Prioridade (1-3): "); int pr; ler_int(&pr); listar_ocorrencias_por_prioridade(or, (Prioridade)pr); }
        else if (op == 3) { printf("Ocorrencia ID: "); int oc; ler_int(&oc); listar_intervencoes_por_ocorrencia(ir, oc); }
        else if (op == 4) listar_bombeiros_disponiveis(br);
        else if (op == 5) listar_equipamentos_disponiveis(er);
    } while (op != 0);
}

void correr_menu(OcorrenciaRepo *or, IntervencaoRepo *ir, BombeiroRepo *br, EquipamentoRepo *er) {
    int op;
    do {
        printf("\n=== Menu Principal ===\n");
        printf("1) Ocorrencias\n2) Intervencoes\n3) Bombeiros\n4) Equipamentos\n5) Relatorios\n0) Sair\n> ");
        if (!ler_int_intervalo(0, 5, &op)) { printf("Opcao invalida\n"); continue; }
        if (op == 1) menu_ocorrencias(or);
        else if (op == 2) menu_intervencoes(ir, or, br, er);
        else if (op == 3) menu_bombeiros(br);
        else if (op == 4) menu_equipamentos(er);
        else if (op == 5) menu_relatorios(or, ir, br, er);
    } while (op != 0);
}

