#include "tipos.h"
#include "validacao.h"
#include "utils.h"
#include "bombeiro.h"
#include "equipamento.h"
#include "ocorrencia.h"
#include "intervencao.h"
#include "relatorios.h"
#include "menu.h"

int main(void) {
    OcorrenciaRepo ocorrs;    init_ocorr_repo(&ocorrs);
    IntervencaoRepo intervs;  init_interv_repo(&intervs);
    BombeiroRepo bombeiros;   init_bombeiro_repo(&bombeiros);
    EquipamentoRepo equips;   init_equip_repo(&equips);

    correr_menu(&ocorrs, &intervs, &bombeiros, &equips);

    free_ocorr_repo(&ocorrs);
    free_interv_repo(&intervs);
    free_bombeiro_repo(&bombeiros);
    free_equip_repo(&equips);
    return 0;
}


