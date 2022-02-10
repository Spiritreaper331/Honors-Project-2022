#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _ampa_reg(void);
extern void _glu1_reg(void);
extern void _gr_ltp1_reg(void);
extern void _grc_ca_reg(void);
extern void _grc_calc_reg(void);
extern void _grc_ka_reg(void);
extern void _grc_kca_reg(void);
extern void _grc_kir_reg(void);
extern void _grc_lkg1_reg(void);
extern void _grc_lkg2_reg(void);
extern void _grc_pna_reg(void);
extern void _grg_km_reg(void);
extern void _grg_kv_reg(void);
extern void _grg_na_reg(void);
extern void _grg_nar_reg(void);
extern void _nmda_reg(void);
extern void _spgen2_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," \"ampa.mod\"");
    fprintf(stderr," \"glu1.mod\"");
    fprintf(stderr," \"gr_ltp1.mod\"");
    fprintf(stderr," \"grc_ca.mod\"");
    fprintf(stderr," \"grc_calc.mod\"");
    fprintf(stderr," \"grc_ka.mod\"");
    fprintf(stderr," \"grc_kca.mod\"");
    fprintf(stderr," \"grc_kir.mod\"");
    fprintf(stderr," \"grc_lkg1.mod\"");
    fprintf(stderr," \"grc_lkg2.mod\"");
    fprintf(stderr," \"grc_pna.mod\"");
    fprintf(stderr," \"grg_km.mod\"");
    fprintf(stderr," \"grg_kv.mod\"");
    fprintf(stderr," \"grg_na.mod\"");
    fprintf(stderr," \"grg_nar.mod\"");
    fprintf(stderr," \"nmda.mod\"");
    fprintf(stderr," \"spgen2.mod\"");
    fprintf(stderr, "\n");
  }
  _ampa_reg();
  _glu1_reg();
  _gr_ltp1_reg();
  _grc_ca_reg();
  _grc_calc_reg();
  _grc_ka_reg();
  _grc_kca_reg();
  _grc_kir_reg();
  _grc_lkg1_reg();
  _grc_lkg2_reg();
  _grc_pna_reg();
  _grg_km_reg();
  _grg_kv_reg();
  _grg_na_reg();
  _grg_nar_reg();
  _nmda_reg();
  _spgen2_reg();
}
