/* Created by Language version: 7.7.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__cdp5_CR_CAM
#define _nrn_initial _nrn_initial__cdp5_CR_CAM
#define nrn_cur _nrn_cur__cdp5_CR_CAM
#define _nrn_current _nrn_current__cdp5_CR_CAM
#define nrn_jacob _nrn_jacob__cdp5_CR_CAM
#define nrn_state _nrn_state__cdp5_CR_CAM
#define _net_receive _net_receive__cdp5_CR_CAM 
#define factors factors__cdp5_CR_CAM 
#define state state__cdp5_CR_CAM 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define Nannuli _p[0]
#define cainull _p[1]
#define Buffnull2 _p[2]
#define rf3 _p[3]
#define rf4 _p[4]
#define CRnull _p[5]
#define TotalPump _p[6]
#define ica_pmp _p[7]
#define vrat _p[8]
#define ca _p[9]
#define mg _p[10]
#define Buff1 _p[11]
#define Buff1_ca _p[12]
#define Buff2 _p[13]
#define Buff2_ca _p[14]
#define BTC _p[15]
#define BTC_ca _p[16]
#define DMNPE _p[17]
#define DMNPE_ca _p[18]
#define CR _p[19]
#define CR_1C_0N _p[20]
#define CR_2C_0N _p[21]
#define CR_2C_1N _p[22]
#define CR_1C_1N _p[23]
#define CR_0C_1N _p[24]
#define CR_0C_2N _p[25]
#define CR_1C_2N _p[26]
#define CR_2C_2N _p[27]
#define CR_1V _p[28]
#define CAM0 _p[29]
#define CAM1C _p[30]
#define CAM2C _p[31]
#define CAM1N2C _p[32]
#define CAM1N _p[33]
#define CAM2N _p[34]
#define CAM2N1C _p[35]
#define CAM1C1N _p[36]
#define CAM4 _p[37]
#define pump _p[38]
#define pumpca _p[39]
#define ica _p[40]
#define parea _p[41]
#define parea2 _p[42]
#define cai _p[43]
#define mgi _p[44]
#define nr2ai _p[45]
#define nr2ci _p[46]
#define con_2ci _p[47]
#define Dca _p[48]
#define Dmg _p[49]
#define DBuff1 _p[50]
#define DBuff1_ca _p[51]
#define DBuff2 _p[52]
#define DBuff2_ca _p[53]
#define DBTC _p[54]
#define DBTC_ca _p[55]
#define DDMNPE _p[56]
#define DDMNPE_ca _p[57]
#define DCR _p[58]
#define DCR_1C_0N _p[59]
#define DCR_2C_0N _p[60]
#define DCR_2C_1N _p[61]
#define DCR_1C_1N _p[62]
#define DCR_0C_1N _p[63]
#define DCR_0C_2N _p[64]
#define DCR_1C_2N _p[65]
#define DCR_2C_2N _p[66]
#define DCR_1V _p[67]
#define DCAM0 _p[68]
#define DCAM1C _p[69]
#define DCAM2C _p[70]
#define DCAM1N2C _p[71]
#define DCAM1N _p[72]
#define DCAM2N _p[73]
#define DCAM2N1C _p[74]
#define DCAM1C1N _p[75]
#define DCAM4 _p[76]
#define Dpump _p[77]
#define Dpumpca _p[78]
#define v _p[79]
#define _g _p[80]
#define _ion_cao	*_ppvar[0]._pval
#define _ion_cai	*_ppvar[1]._pval
#define _ion_ica	*_ppvar[2]._pval
#define _style_ca	*((int*)_ppvar[3]._pvoid)
#define _ion_nr2ai	*_ppvar[4]._pval
#define _style_nr2a	*((int*)_ppvar[5]._pvoid)
#define _ion_nr2ci	*_ppvar[6]._pval
#define _style_nr2c	*((int*)_ppvar[7]._pvoid)
#define _ion_con_2ci	*_ppvar[8]._pval
#define _style_con_2c	*((int*)_ppvar[9]._pvoid)
#define diam	*_ppvar[10]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_factors(void);
 static void _hoc_ssDMNPEca(void);
 static void _hoc_ssDMNPE(void);
 static void _hoc_ssBTCca(void);
 static void _hoc_ssBTC(void);
 static void _hoc_ssBuff2ca(void);
 static void _hoc_ssBuff2(void);
 static void _hoc_ssBuff1ca(void);
 static void _hoc_ssBuff1(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_cdp5_CR_CAM", _hoc_setdata,
 "factors_cdp5_CR_CAM", _hoc_factors,
 "ssDMNPEca_cdp5_CR_CAM", _hoc_ssDMNPEca,
 "ssDMNPE_cdp5_CR_CAM", _hoc_ssDMNPE,
 "ssBTCca_cdp5_CR_CAM", _hoc_ssBTCca,
 "ssBTC_cdp5_CR_CAM", _hoc_ssBTC,
 "ssBuff2ca_cdp5_CR_CAM", _hoc_ssBuff2ca,
 "ssBuff2_cdp5_CR_CAM", _hoc_ssBuff2,
 "ssBuff1ca_cdp5_CR_CAM", _hoc_ssBuff1ca,
 "ssBuff1_cdp5_CR_CAM", _hoc_ssBuff1,
 0, 0
};
#define ssDMNPEca ssDMNPEca_cdp5_CR_CAM
#define ssDMNPE ssDMNPE_cdp5_CR_CAM
#define ssBTCca ssBTCca_cdp5_CR_CAM
#define ssBTC ssBTC_cdp5_CR_CAM
#define ssBuff2ca ssBuff2ca_cdp5_CR_CAM
#define ssBuff2 ssBuff2_cdp5_CR_CAM
#define ssBuff1ca ssBuff1ca_cdp5_CR_CAM
#define ssBuff1 ssBuff1_cdp5_CR_CAM
 extern double ssDMNPEca( _threadargsproto_ );
 extern double ssDMNPE( _threadargsproto_ );
 extern double ssBTCca( _threadargsproto_ );
 extern double ssBTC( _threadargsproto_ );
 extern double ssBuff2ca( _threadargsproto_ );
 extern double ssBuff2( _threadargsproto_ );
 extern double ssBuff1ca( _threadargsproto_ );
 extern double ssBuff1( _threadargsproto_ );
 #define _zfactors_done _thread[2]._pval[0]
 #define _zdsq _thread[2]._pval[1]
 #define _zdsqvol _thread[2]._pval[2]
 /* declare global and static user variables */
#define BTCnull BTCnull_cdp5_CR_CAM
 double BTCnull = 0;
#define Buffnull1 Buffnull1_cdp5_CR_CAM
 double Buffnull1 = 0;
#define CAM_start CAM_start_cdp5_CR_CAM
 double CAM_start = 0.03;
#define DMNPEnull DMNPEnull_cdp5_CR_CAM
 double DMNPEnull = 0;
#define K2Non K2Non_cdp5_CR_CAM
 double K2Non = 175;
#define K2Noff K2Noff_cdp5_CR_CAM
 double K2Noff = 0.75;
#define Kd2N Kd2N_cdp5_CR_CAM
 double Kd2N = 0.00615;
#define K1Non K1Non_cdp5_CR_CAM
 double K1Non = 142.5;
#define K1Noff K1Noff_cdp5_CR_CAM
 double K1Noff = 2.5;
#define Kd1N Kd1N_cdp5_CR_CAM
 double Kd1N = 0.0275;
#define K2Con K2Con_cdp5_CR_CAM
 double K2Con = 15;
#define K2Coff K2Coff_cdp5_CR_CAM
 double K2Coff = 0.00925;
#define Kd2C Kd2C_cdp5_CR_CAM
 double Kd2C = 0.00105;
#define K1Con K1Con_cdp5_CR_CAM
 double K1Con = 5.4;
#define K1Coff K1Coff_cdp5_CR_CAM
 double K1Coff = 0.04;
#define Kd1C Kd1C_cdp5_CR_CAM
 double Kd1C = 0.00965;
#define b2 b2_cdp5_CR_CAM
 double b2 = 0.08;
#define b1 b1_cdp5_CR_CAM
 double b1 = 5.33;
#define c2 c2_cdp5_CR_CAM
 double c2 = 0.000107;
#define c1 c1_cdp5_CR_CAM
 double c1 = 5.63;
#define kpmp3 kpmp3_cdp5_CR_CAM
 double kpmp3 = 7.255e-05;
#define kpmp2 kpmp2_cdp5_CR_CAM
 double kpmp2 = 1.75e-05;
#define kpmp1 kpmp1_cdp5_CR_CAM
 double kpmp1 = 0.003;
#define mginull mginull_cdp5_CR_CAM
 double mginull = 0.59;
#define nV2 nV2_cdp5_CR_CAM
 double nV2 = 0.24;
#define nV1 nV1_cdp5_CR_CAM
 double nV1 = 7.3;
#define nR2 nR2_cdp5_CR_CAM
 double nR2 = 0.02;
#define nR1 nR1_cdp5_CR_CAM
 double nR1 = 310;
#define nT2 nT2_cdp5_CR_CAM
 double nT2 = 0.053;
#define nT1 nT1_cdp5_CR_CAM
 double nT1 = 1.8;
#define rf2 rf2_cdp5_CR_CAM
 double rf2 = 0.0397469;
#define rf1 rf1_cdp5_CR_CAM
 double rf1 = 0.0134329;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "mginull_cdp5_CR_CAM", "mM",
 "Buffnull1_cdp5_CR_CAM", "mM",
 "rf1_cdp5_CR_CAM", "/ms",
 "rf2_cdp5_CR_CAM", "/ms",
 "BTCnull_cdp5_CR_CAM", "mM",
 "b1_cdp5_CR_CAM", "/ms",
 "b2_cdp5_CR_CAM", "/ms",
 "DMNPEnull_cdp5_CR_CAM", "mM",
 "c1_cdp5_CR_CAM", "/ms",
 "c2_cdp5_CR_CAM", "/ms",
 "nT1_cdp5_CR_CAM", "/ms",
 "nT2_cdp5_CR_CAM", "/ms",
 "nR1_cdp5_CR_CAM", "/ms",
 "nR2_cdp5_CR_CAM", "/ms",
 "nV1_cdp5_CR_CAM", "/ms",
 "nV2_cdp5_CR_CAM", "/ms",
 "CAM_start_cdp5_CR_CAM", "mM",
 "Kd1C_cdp5_CR_CAM", "mM",
 "K1Coff_cdp5_CR_CAM", "/ms",
 "K1Con_cdp5_CR_CAM", "/mM",
 "Kd2C_cdp5_CR_CAM", "mM",
 "K2Coff_cdp5_CR_CAM", "/ms",
 "K2Con_cdp5_CR_CAM", "/mM",
 "Kd1N_cdp5_CR_CAM", "uM",
 "K1Noff_cdp5_CR_CAM", "/ms",
 "K1Non_cdp5_CR_CAM", "/mM",
 "Kd2N_cdp5_CR_CAM", "mM",
 "K2Noff_cdp5_CR_CAM", "/ms",
 "K2Non_cdp5_CR_CAM", "/mM",
 "kpmp1_cdp5_CR_CAM", "/mM-ms",
 "kpmp2_cdp5_CR_CAM", "/ms",
 "kpmp3_cdp5_CR_CAM", "/ms",
 "Nannuli_cdp5_CR_CAM", "1",
 "cainull_cdp5_CR_CAM", "mM",
 "Buffnull2_cdp5_CR_CAM", "mM",
 "rf3_cdp5_CR_CAM", "/ms",
 "rf4_cdp5_CR_CAM", "/ms",
 "CRnull_cdp5_CR_CAM", "mM",
 "TotalPump_cdp5_CR_CAM", "mol/cm2",
 "ca_cdp5_CR_CAM", "mM",
 "mg_cdp5_CR_CAM", "mM",
 "Buff1_cdp5_CR_CAM", "mM",
 "Buff1_ca_cdp5_CR_CAM", "mM",
 "Buff2_cdp5_CR_CAM", "mM",
 "Buff2_ca_cdp5_CR_CAM", "mM",
 "BTC_cdp5_CR_CAM", "mM",
 "BTC_ca_cdp5_CR_CAM", "mM",
 "DMNPE_cdp5_CR_CAM", "mM",
 "DMNPE_ca_cdp5_CR_CAM", "mM",
 "CR_cdp5_CR_CAM", "mM",
 "CR_1C_0N_cdp5_CR_CAM", "mM",
 "CR_2C_0N_cdp5_CR_CAM", "mM",
 "CR_2C_1N_cdp5_CR_CAM", "mM",
 "CR_1C_1N_cdp5_CR_CAM", "mM",
 "CR_0C_1N_cdp5_CR_CAM", "mM",
 "CR_0C_2N_cdp5_CR_CAM", "mM",
 "CR_1C_2N_cdp5_CR_CAM", "mM",
 "CR_2C_2N_cdp5_CR_CAM", "mM",
 "CR_1V_cdp5_CR_CAM", "mM",
 "CAM0_cdp5_CR_CAM", "mM",
 "CAM1C_cdp5_CR_CAM", "mM",
 "CAM2C_cdp5_CR_CAM", "mM",
 "CAM1N2C_cdp5_CR_CAM", "mM",
 "CAM1N_cdp5_CR_CAM", "mM",
 "CAM2N_cdp5_CR_CAM", "mM",
 "CAM2N1C_cdp5_CR_CAM", "mM",
 "CAM1C1N_cdp5_CR_CAM", "mM",
 "CAM4_cdp5_CR_CAM", "mM",
 "pump_cdp5_CR_CAM", "mol/cm2",
 "pumpca_cdp5_CR_CAM", "mol/cm2",
 "ica_pmp_cdp5_CR_CAM", "mA/cm2",
 "vrat_cdp5_CR_CAM", "1",
 0,0
};
 static double BTC_ca0 = 0;
 static double BTC0 = 0;
 static double Buff2_ca0 = 0;
 static double Buff20 = 0;
 static double Buff1_ca0 = 0;
 static double Buff10 = 0;
 static double CAM40 = 0;
 static double CAM1C1N0 = 0;
 static double CAM2N1C0 = 0;
 static double CAM2N0 = 0;
 static double CAM1N0 = 0;
 static double CAM1N2C0 = 0;
 static double CAM2C0 = 0;
 static double CAM1C0 = 0;
 static double CAM00 = 0;
 static double CR_1V0 = 0;
 static double CR_2C_2N0 = 0;
 static double CR_1C_2N0 = 0;
 static double CR_0C_2N0 = 0;
 static double CR_0C_1N0 = 0;
 static double CR_1C_1N0 = 0;
 static double CR_2C_1N0 = 0;
 static double CR_2C_0N0 = 0;
 static double CR_1C_0N0 = 0;
 static double CR0 = 0;
 static double DMNPE_ca0 = 0;
 static double DMNPE0 = 0;
 static double ca0 = 0;
 static double delta_t = 0.01;
 static double mg0 = 0;
 static double pumpca0 = 0;
 static double pump0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "mginull_cdp5_CR_CAM", &mginull_cdp5_CR_CAM,
 "Buffnull1_cdp5_CR_CAM", &Buffnull1_cdp5_CR_CAM,
 "rf1_cdp5_CR_CAM", &rf1_cdp5_CR_CAM,
 "rf2_cdp5_CR_CAM", &rf2_cdp5_CR_CAM,
 "BTCnull_cdp5_CR_CAM", &BTCnull_cdp5_CR_CAM,
 "b1_cdp5_CR_CAM", &b1_cdp5_CR_CAM,
 "b2_cdp5_CR_CAM", &b2_cdp5_CR_CAM,
 "DMNPEnull_cdp5_CR_CAM", &DMNPEnull_cdp5_CR_CAM,
 "c1_cdp5_CR_CAM", &c1_cdp5_CR_CAM,
 "c2_cdp5_CR_CAM", &c2_cdp5_CR_CAM,
 "nT1_cdp5_CR_CAM", &nT1_cdp5_CR_CAM,
 "nT2_cdp5_CR_CAM", &nT2_cdp5_CR_CAM,
 "nR1_cdp5_CR_CAM", &nR1_cdp5_CR_CAM,
 "nR2_cdp5_CR_CAM", &nR2_cdp5_CR_CAM,
 "nV1_cdp5_CR_CAM", &nV1_cdp5_CR_CAM,
 "nV2_cdp5_CR_CAM", &nV2_cdp5_CR_CAM,
 "CAM_start_cdp5_CR_CAM", &CAM_start_cdp5_CR_CAM,
 "Kd1C_cdp5_CR_CAM", &Kd1C_cdp5_CR_CAM,
 "K1Coff_cdp5_CR_CAM", &K1Coff_cdp5_CR_CAM,
 "K1Con_cdp5_CR_CAM", &K1Con_cdp5_CR_CAM,
 "Kd2C_cdp5_CR_CAM", &Kd2C_cdp5_CR_CAM,
 "K2Coff_cdp5_CR_CAM", &K2Coff_cdp5_CR_CAM,
 "K2Con_cdp5_CR_CAM", &K2Con_cdp5_CR_CAM,
 "Kd1N_cdp5_CR_CAM", &Kd1N_cdp5_CR_CAM,
 "K1Noff_cdp5_CR_CAM", &K1Noff_cdp5_CR_CAM,
 "K1Non_cdp5_CR_CAM", &K1Non_cdp5_CR_CAM,
 "Kd2N_cdp5_CR_CAM", &Kd2N_cdp5_CR_CAM,
 "K2Noff_cdp5_CR_CAM", &K2Noff_cdp5_CR_CAM,
 "K2Non_cdp5_CR_CAM", &K2Non_cdp5_CR_CAM,
 "kpmp1_cdp5_CR_CAM", &kpmp1_cdp5_CR_CAM,
 "kpmp2_cdp5_CR_CAM", &kpmp2_cdp5_CR_CAM,
 "kpmp3_cdp5_CR_CAM", &kpmp3_cdp5_CR_CAM,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[11]._i
 static void _ode_synonym(int, double**, Datum**);
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"cdp5_CR_CAM",
 "Nannuli_cdp5_CR_CAM",
 "cainull_cdp5_CR_CAM",
 "Buffnull2_cdp5_CR_CAM",
 "rf3_cdp5_CR_CAM",
 "rf4_cdp5_CR_CAM",
 "CRnull_cdp5_CR_CAM",
 "TotalPump_cdp5_CR_CAM",
 0,
 "ica_pmp_cdp5_CR_CAM",
 "vrat_cdp5_CR_CAM",
 0,
 "ca_cdp5_CR_CAM",
 "mg_cdp5_CR_CAM",
 "Buff1_cdp5_CR_CAM",
 "Buff1_ca_cdp5_CR_CAM",
 "Buff2_cdp5_CR_CAM",
 "Buff2_ca_cdp5_CR_CAM",
 "BTC_cdp5_CR_CAM",
 "BTC_ca_cdp5_CR_CAM",
 "DMNPE_cdp5_CR_CAM",
 "DMNPE_ca_cdp5_CR_CAM",
 "CR_cdp5_CR_CAM",
 "CR_1C_0N_cdp5_CR_CAM",
 "CR_2C_0N_cdp5_CR_CAM",
 "CR_2C_1N_cdp5_CR_CAM",
 "CR_1C_1N_cdp5_CR_CAM",
 "CR_0C_1N_cdp5_CR_CAM",
 "CR_0C_2N_cdp5_CR_CAM",
 "CR_1C_2N_cdp5_CR_CAM",
 "CR_2C_2N_cdp5_CR_CAM",
 "CR_1V_cdp5_CR_CAM",
 "CAM0_cdp5_CR_CAM",
 "CAM1C_cdp5_CR_CAM",
 "CAM2C_cdp5_CR_CAM",
 "CAM1N2C_cdp5_CR_CAM",
 "CAM1N_cdp5_CR_CAM",
 "CAM2N_cdp5_CR_CAM",
 "CAM2N1C_cdp5_CR_CAM",
 "CAM1C1N_cdp5_CR_CAM",
 "CAM4_cdp5_CR_CAM",
 "pump_cdp5_CR_CAM",
 "pumpca_cdp5_CR_CAM",
 0,
 0};
 static Symbol* _morphology_sym;
 static Symbol* _ca_sym;
 static Symbol* _nr2a_sym;
 static Symbol* _nr2c_sym;
 static Symbol* _con_2c_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 81, _prop);
 	/*initialize range parameters*/
 	Nannuli = 10.9495;
 	cainull = 4.5e-05;
 	Buffnull2 = 60.9091;
 	rf3 = 0.1435;
 	rf4 = 0.0014;
 	CRnull = 0.9;
 	TotalPump = 1e-09;
 	_prop->param = _p;
 	_prop->param_size = 81;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 12, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_morphology_sym);
 	_ppvar[10]._pval = &prop_ion->param[0]; /* diam */
 prop_ion = need_memb(_ca_sym);
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[0]._pval = &prop_ion->param[2]; /* cao */
 	_ppvar[1]._pval = &prop_ion->param[1]; /* cai */
 	_ppvar[2]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[3]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for ca */
 prop_ion = need_memb(_nr2a_sym);
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[4]._pval = &prop_ion->param[1]; /* nr2ai */
 	_ppvar[5]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for nr2a */
 prop_ion = need_memb(_nr2c_sym);
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[6]._pval = &prop_ion->param[1]; /* nr2ci */
 	_ppvar[7]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for nr2c */
 prop_ion = need_memb(_con_2c_sym);
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[8]._pval = &prop_ion->param[1]; /* con_2ci */
 	_ppvar[9]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for con_2c */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 "ca_cdp5_CR_CAM", 0.001,
 "mg_cdp5_CR_CAM", 1e-06,
 "pump_cdp5_CR_CAM", 1e-15,
 "pumpca_cdp5_CR_CAM", 1e-15,
 0,0
};
 static void _thread_mem_init(Datum*);
 static void _thread_cleanup(Datum*);
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _cdp5_CR_CAM_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("ca", -10000.);
 	ion_reg("nr2a", 1.0);
 	ion_reg("nr2c", 1.0);
 	ion_reg("con_2c", 1.0);
 	_morphology_sym = hoc_lookup("morphology");
 	_ca_sym = hoc_lookup("ca_ion");
 	_nr2a_sym = hoc_lookup("nr2a_ion");
 	_nr2c_sym = hoc_lookup("nr2c_ion");
 	_con_2c_sym = hoc_lookup("con_2c_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 4);
  _extcall_thread = (Datum*)ecalloc(3, sizeof(Datum));
  _thread_mem_init(_extcall_thread);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 1, _thread_mem_init);
     _nrn_thread_reg(_mechtype, 0, _thread_cleanup);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 81, 12);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "#ca_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "nr2a_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "#nr2a_ion");
  hoc_register_dparam_semantics(_mechtype, 6, "nr2c_ion");
  hoc_register_dparam_semantics(_mechtype, 7, "#nr2c_ion");
  hoc_register_dparam_semantics(_mechtype, 8, "con_2c_ion");
  hoc_register_dparam_semantics(_mechtype, 9, "#con_2c_ion");
  hoc_register_dparam_semantics(_mechtype, 11, "cvodeieq");
  hoc_register_dparam_semantics(_mechtype, 10, "diam");
 	nrn_writes_conc(_mechtype, 0);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_synonym(_mechtype, _ode_synonym);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 cdp5_CR_CAM /Users/tylerrivera/Honors Project 2022/Honors-Project-2022/Cerebellum Model/Morphology /Morphology Protocols/Mod Files/cdp5_CR_CAM.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 
#define FARADAY _nrnunit_FARADAY[_nrnunit_use_legacy_]
static double _nrnunit_FARADAY[2] = {0x1.34c0c8b92a9b7p+3, 9.64853}; /* 9.64853321233100125 */
 
#define PI _nrnunit_PI[_nrnunit_use_legacy_]
static double _nrnunit_PI[2] = {0x1.921fb54442d18p+1, 3.14159}; /* 3.14159265358979312 */
 static double cao = 2;
 /*Top LOCAL _zfactors_done */
 /*Top LOCAL _zdsq , _zdsqvol */
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int factors(_threadargsproto_);
 extern double *_nrn_thread_getelm();
 
#define _MATELM1(_row,_col) *(_nrn_thread_getelm(_so, _row + 1, _col + 1))
 
#define _RHS1(_arg) _rhs[_arg+1]
  
#define _linmat1  0
 static int _spth1 = 1;
 static int _cvspth1 = 0;
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[30], _dlist1[30]; static double *_temp1;
 static int state();
 
static int  factors ( _threadargsproto_ ) {
   double _lr , _ldr2 ;
 _lr = 1.0 / 2.0 ;
   _ldr2 = _lr / ( Nannuli - 1.0 ) / 2.0 ;
   vrat = PI * ( _lr - _ldr2 / 2.0 ) * 2.0 * _ldr2 ;
   _lr = _lr - _ldr2 ;
    return 0; }
 
static void _hoc_factors(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 factors ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
static int state (void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt)
 {int _reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=1;_i<30;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
}  
_RHS1(1) *= ( diam * diam * vrat) ;
_MATELM1(1, 1) *= ( diam * diam * vrat); 
_RHS1(2) *= ( diam * diam * vrat) ;
_MATELM1(2, 2) *= ( diam * diam * vrat); 
_RHS1(3) *= ( diam * diam * vrat) ;
_MATELM1(3, 3) *= ( diam * diam * vrat); 
_RHS1(4) *= ( diam * diam * vrat) ;
_MATELM1(4, 4) *= ( diam * diam * vrat); 
_RHS1(5) *= ( diam * diam * vrat) ;
_MATELM1(5, 5) *= ( diam * diam * vrat); 
_RHS1(6) *= ( diam * diam * vrat) ;
_MATELM1(6, 6) *= ( diam * diam * vrat); 
_RHS1(7) *= ( diam * diam * vrat) ;
_MATELM1(7, 7) *= ( diam * diam * vrat); 
_RHS1(8) *= ( diam * diam * vrat) ;
_MATELM1(8, 8) *= ( diam * diam * vrat); 
_RHS1(9) *= ( diam * diam * vrat) ;
_MATELM1(9, 9) *= ( diam * diam * vrat); 
_RHS1(10) *= ( diam * diam * vrat) ;
_MATELM1(10, 10) *= ( diam * diam * vrat); 
_RHS1(11) *= ( diam * diam * vrat) ;
_MATELM1(11, 11) *= ( diam * diam * vrat); 
_RHS1(12) *= ( diam * diam * vrat) ;
_MATELM1(12, 12) *= ( diam * diam * vrat); 
_RHS1(23) *= ( diam * diam * vrat) ;
_MATELM1(23, 23) *= ( diam * diam * vrat); 
_RHS1(24) *= ( diam * diam * vrat) ;
_MATELM1(24, 24) *= ( diam * diam * vrat); 
_RHS1(25) *= ( diam * diam * vrat) ;
_MATELM1(25, 25) *= ( diam * diam * vrat); 
_RHS1(26) *= ( diam * diam * vrat) ;
_MATELM1(26, 26) *= ( diam * diam * vrat); 
_RHS1(27) *= ( diam * diam * vrat) ;
_MATELM1(27, 27) *= ( diam * diam * vrat); 
_RHS1(28) *= ( diam * diam * vrat) ;
_MATELM1(28, 28) *= ( diam * diam * vrat); 
_RHS1(29) *= ( ( 1e10 ) * parea) ;
_MATELM1(29, 29) *= ( ( 1e10 ) * parea);  }
 /* COMPARTMENT diam * diam * vrat {
     ca mg Buff1 Buff1_ca Buff2 Buff2_ca BTC BTC_ca DMNPE DMNPE_ca CR CR_1C_0N CR_2C_0N CR_2C_1N CR_0C_1N CR_0C_2N CR_1C_2N CR_1C_1N CR_2C_1N CR_1C_2N CR_2C_2N }
   */
 /* COMPARTMENT ( 1e10 ) * parea {
     pump pumpca }
   */
 /* ~ ca + pump <-> pumpca ( kpmp1 * parea * ( 1e10 ) , kpmp2 * parea * ( 1e10 ) )*/
 f_flux =  kpmp1 * parea * ( 1e10 ) * pump * ca ;
 b_flux =  kpmp2 * parea * ( 1e10 ) * pumpca ;
 _RHS1( 29) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 
 _term =  kpmp1 * parea * ( 1e10 ) * ca ;
 _MATELM1( 29 ,29)  += _term;
 _MATELM1( 28 ,29)  += _term;
 _term =  kpmp1 * parea * ( 1e10 ) * pump ;
 _MATELM1( 29 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _term =  kpmp2 * parea * ( 1e10 ) ;
 _MATELM1( 29 ,0)  -= _term;
 _MATELM1( 28 ,0)  -= _term;
 /*REACTION*/
  /* ~ pumpca <-> pump ( kpmp3 * parea * ( 1e10 ) , 0.0 )*/
 f_flux =  kpmp3 * parea * ( 1e10 ) * pumpca ;
 b_flux =  0.0 * pump ;
 _RHS1( 29) += (f_flux - b_flux);
 
 _term =  kpmp3 * parea * ( 1e10 ) ;
 _MATELM1( 29 ,0)  -= _term;
 _term =  0.0 ;
 _MATELM1( 29 ,29)  += _term;
 /*REACTION*/
   /* pump + pumpca = TotalPump * parea * ( 1e10 ) */
 _RHS1(0) =  TotalPump * parea * ( 1e10 );
 _MATELM1(0, 0) = 1 * ( ( 1e10 ) * parea);
 _RHS1(0) -= pumpca * ( ( 1e10 ) * parea) ;
 _MATELM1(0, 29) = 1 * ( ( 1e10 ) * parea);
 _RHS1(0) -= pump * ( ( 1e10 ) * parea) ;
 /*CONSERVATION*/
 ica_pmp = 2.0 * FARADAY * ( f_flux - b_flux ) / parea ;
   /* ~ ca < < ( - ica * PI * diam / ( 2.0 * FARADAY ) )*/
 f_flux = b_flux = 0.;
 _RHS1( 28) += (b_flux =   ( - ica * PI * diam / ( 2.0 * FARADAY ) ) );
 /*FLUX*/
  _zdsq = diam * diam ;
   _zdsqvol = _zdsq * vrat ;
   /* ~ ca + Buff1 <-> Buff1_ca ( rf1 * _zdsqvol , rf2 * _zdsqvol )*/
 f_flux =  rf1 * _zdsqvol * Buff1 * ca ;
 b_flux =  rf2 * _zdsqvol * Buff1_ca ;
 _RHS1( 6) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 5) += (f_flux - b_flux);
 
 _term =  rf1 * _zdsqvol * ca ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 28 ,6)  += _term;
 _MATELM1( 5 ,6)  -= _term;
 _term =  rf1 * _zdsqvol * Buff1 ;
 _MATELM1( 6 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 5 ,28)  -= _term;
 _term =  rf2 * _zdsqvol ;
 _MATELM1( 6 ,5)  -= _term;
 _MATELM1( 28 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ ca + Buff2 <-> Buff2_ca ( rf3 * _zdsqvol , rf4 * _zdsqvol )*/
 f_flux =  rf3 * _zdsqvol * Buff2 * ca ;
 b_flux =  rf4 * _zdsqvol * Buff2_ca ;
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 3) += (f_flux - b_flux);
 
 _term =  rf3 * _zdsqvol * ca ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 28 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  rf3 * _zdsqvol * Buff2 ;
 _MATELM1( 4 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 3 ,28)  -= _term;
 _term =  rf4 * _zdsqvol ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 28 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ ca + BTC <-> BTC_ca ( b1 * _zdsqvol , b2 * _zdsqvol )*/
 f_flux =  b1 * _zdsqvol * BTC * ca ;
 b_flux =  b2 * _zdsqvol * BTC_ca ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  b1 * _zdsqvol * ca ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 28 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  b1 * _zdsqvol * BTC ;
 _MATELM1( 2 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 1 ,28)  -= _term;
 _term =  b2 * _zdsqvol ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 28 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ ca + DMNPE <-> DMNPE_ca ( c1 * _zdsqvol , c2 * _zdsqvol )*/
 f_flux =  c1 * _zdsqvol * DMNPE * ca ;
 b_flux =  c2 * _zdsqvol * DMNPE_ca ;
 _RHS1( 27) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 26) += (f_flux - b_flux);
 
 _term =  c1 * _zdsqvol * ca ;
 _MATELM1( 27 ,27)  += _term;
 _MATELM1( 28 ,27)  += _term;
 _MATELM1( 26 ,27)  -= _term;
 _term =  c1 * _zdsqvol * DMNPE ;
 _MATELM1( 27 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 26 ,28)  -= _term;
 _term =  c2 * _zdsqvol ;
 _MATELM1( 27 ,26)  -= _term;
 _MATELM1( 28 ,26)  -= _term;
 _MATELM1( 26 ,26)  += _term;
 /*REACTION*/
  /* ~ ca + CR <-> CR_1C_0N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR * ca ;
 b_flux =  nT2 * _zdsqvol * CR_1C_0N ;
 _RHS1( 25) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 24) += (f_flux - b_flux);
 
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 25 ,25)  += _term;
 _MATELM1( 28 ,25)  += _term;
 _MATELM1( 24 ,25)  -= _term;
 _term =  nT1 * _zdsqvol * CR ;
 _MATELM1( 25 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 24 ,28)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 25 ,24)  -= _term;
 _MATELM1( 28 ,24)  -= _term;
 _MATELM1( 24 ,24)  += _term;
 /*REACTION*/
  /* ~ ca + CR_1C_0N <-> CR_2C_0N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_1C_0N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_2C_0N ;
 _RHS1( 24) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 12) += (f_flux - b_flux);
 
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 24 ,24)  += _term;
 _MATELM1( 28 ,24)  += _term;
 _MATELM1( 12 ,24)  -= _term;
 _term =  nR1 * _zdsqvol * CR_1C_0N ;
 _MATELM1( 24 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 12 ,28)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 24 ,12)  -= _term;
 _MATELM1( 28 ,12)  -= _term;
 _MATELM1( 12 ,12)  += _term;
 /*REACTION*/
  /* ~ ca + CR_2C_0N <-> CR_2C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR_2C_0N * ca ;
 b_flux =  nT2 * _zdsqvol * CR_2C_1N ;
 _RHS1( 12) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 11) += (f_flux - b_flux);
 
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 28 ,12)  += _term;
 _MATELM1( 11 ,12)  -= _term;
 _term =  nT1 * _zdsqvol * CR_2C_0N ;
 _MATELM1( 12 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 11 ,28)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 12 ,11)  -= _term;
 _MATELM1( 28 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ ca + CR <-> CR_0C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR * ca ;
 b_flux =  nT2 * _zdsqvol * CR_0C_1N ;
 _RHS1( 25) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 9) += (f_flux - b_flux);
 
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 25 ,25)  += _term;
 _MATELM1( 28 ,25)  += _term;
 _MATELM1( 9 ,25)  -= _term;
 _term =  nT1 * _zdsqvol * CR ;
 _MATELM1( 25 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 9 ,28)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 25 ,9)  -= _term;
 _MATELM1( 28 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ ca + CR_0C_1N <-> CR_0C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_0C_1N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_0C_2N ;
 _RHS1( 9) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 8) += (f_flux - b_flux);
 
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 28 ,9)  += _term;
 _MATELM1( 8 ,9)  -= _term;
 _term =  nR1 * _zdsqvol * CR_0C_1N ;
 _MATELM1( 9 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 8 ,28)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 9 ,8)  -= _term;
 _MATELM1( 28 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ ca + CR_0C_2N <-> CR_1C_2N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR_0C_2N * ca ;
 b_flux =  nT2 * _zdsqvol * CR_1C_2N ;
 _RHS1( 8) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 7) += (f_flux - b_flux);
 
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 28 ,8)  += _term;
 _MATELM1( 7 ,8)  -= _term;
 _term =  nT1 * _zdsqvol * CR_0C_2N ;
 _MATELM1( 8 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 7 ,28)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 8 ,7)  -= _term;
 _MATELM1( 28 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ ca + CR_2C_1N <-> CR_2C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_2C_1N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_2C_2N ;
 _RHS1( 11) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 23) += (f_flux - b_flux);
 
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 11 ,11)  += _term;
 _MATELM1( 28 ,11)  += _term;
 _MATELM1( 23 ,11)  -= _term;
 _term =  nR1 * _zdsqvol * CR_2C_1N ;
 _MATELM1( 11 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 23 ,28)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 11 ,23)  -= _term;
 _MATELM1( 28 ,23)  -= _term;
 _MATELM1( 23 ,23)  += _term;
 /*REACTION*/
  /* ~ ca + CR_1C_2N <-> CR_2C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_1C_2N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_2C_2N ;
 _RHS1( 7) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 23) += (f_flux - b_flux);
 
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 28 ,7)  += _term;
 _MATELM1( 23 ,7)  -= _term;
 _term =  nR1 * _zdsqvol * CR_1C_2N ;
 _MATELM1( 7 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 23 ,28)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 7 ,23)  -= _term;
 _MATELM1( 28 ,23)  -= _term;
 _MATELM1( 23 ,23)  += _term;
 /*REACTION*/
  /* ~ ca + CR_1C_0N <-> CR_1C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR_1C_0N * ca ;
 b_flux =  nT2 * _zdsqvol * CR_1C_1N ;
 _RHS1( 24) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 10) += (f_flux - b_flux);
 
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 24 ,24)  += _term;
 _MATELM1( 28 ,24)  += _term;
 _MATELM1( 10 ,24)  -= _term;
 _term =  nT1 * _zdsqvol * CR_1C_0N ;
 _MATELM1( 24 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 10 ,28)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 24 ,10)  -= _term;
 _MATELM1( 28 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ ca + CR_0C_1N <-> CR_1C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR_0C_1N * ca ;
 b_flux =  nT2 * _zdsqvol * CR_1C_1N ;
 _RHS1( 9) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 10) += (f_flux - b_flux);
 
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 28 ,9)  += _term;
 _MATELM1( 10 ,9)  -= _term;
 _term =  nT1 * _zdsqvol * CR_0C_1N ;
 _MATELM1( 9 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 10 ,28)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 9 ,10)  -= _term;
 _MATELM1( 28 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ ca + CR_1C_1N <-> CR_2C_1N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_1C_1N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_2C_1N ;
 _RHS1( 10) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 11) += (f_flux - b_flux);
 
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 28 ,10)  += _term;
 _MATELM1( 11 ,10)  -= _term;
 _term =  nR1 * _zdsqvol * CR_1C_1N ;
 _MATELM1( 10 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 11 ,28)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 10 ,11)  -= _term;
 _MATELM1( 28 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ ca + CR_1C_1N <-> CR_1C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_1C_1N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_1C_2N ;
 _RHS1( 10) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 7) += (f_flux - b_flux);
 
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 28 ,10)  += _term;
 _MATELM1( 7 ,10)  -= _term;
 _term =  nR1 * _zdsqvol * CR_1C_1N ;
 _MATELM1( 10 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 7 ,28)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 10 ,7)  -= _term;
 _MATELM1( 28 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ ca + CR <-> CR_1V ( nV1 * _zdsqvol , nV2 * _zdsqvol )*/
 f_flux =  nV1 * _zdsqvol * CR * ca ;
 b_flux =  nV2 * _zdsqvol * CR_1V ;
 _RHS1( 25) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 22) += (f_flux - b_flux);
 
 _term =  nV1 * _zdsqvol * ca ;
 _MATELM1( 25 ,25)  += _term;
 _MATELM1( 28 ,25)  += _term;
 _MATELM1( 22 ,25)  -= _term;
 _term =  nV1 * _zdsqvol * CR ;
 _MATELM1( 25 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 22 ,28)  -= _term;
 _term =  nV2 * _zdsqvol ;
 _MATELM1( 25 ,22)  -= _term;
 _MATELM1( 28 ,22)  -= _term;
 _MATELM1( 22 ,22)  += _term;
 /*REACTION*/
  /* ~ ca + CAM0 <-> CAM1C ( K1Con * _zdsqvol , K1Coff * _zdsqvol )*/
 f_flux =  K1Con * _zdsqvol * CAM0 * ca ;
 b_flux =  K1Coff * _zdsqvol * CAM1C ;
 _RHS1( 21) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 20) += (f_flux - b_flux);
 
 _term =  K1Con * _zdsqvol * ca ;
 _MATELM1( 21 ,21)  += _term;
 _MATELM1( 28 ,21)  += _term;
 _MATELM1( 20 ,21)  -= _term;
 _term =  K1Con * _zdsqvol * CAM0 ;
 _MATELM1( 21 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 20 ,28)  -= _term;
 _term =  K1Coff * _zdsqvol ;
 _MATELM1( 21 ,20)  -= _term;
 _MATELM1( 28 ,20)  -= _term;
 _MATELM1( 20 ,20)  += _term;
 /*REACTION*/
  /* ~ ca + CAM1C <-> CAM2C ( K2Con * _zdsqvol , K2Coff * _zdsqvol )*/
 f_flux =  K2Con * _zdsqvol * CAM1C * ca ;
 b_flux =  K2Coff * _zdsqvol * CAM2C ;
 _RHS1( 20) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 19) += (f_flux - b_flux);
 
 _term =  K2Con * _zdsqvol * ca ;
 _MATELM1( 20 ,20)  += _term;
 _MATELM1( 28 ,20)  += _term;
 _MATELM1( 19 ,20)  -= _term;
 _term =  K2Con * _zdsqvol * CAM1C ;
 _MATELM1( 20 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 19 ,28)  -= _term;
 _term =  K2Coff * _zdsqvol ;
 _MATELM1( 20 ,19)  -= _term;
 _MATELM1( 28 ,19)  -= _term;
 _MATELM1( 19 ,19)  += _term;
 /*REACTION*/
  /* ~ ca + CAM2C <-> CAM1N2C ( K1Non * _zdsqvol , K1Noff * _zdsqvol )*/
 f_flux =  K1Non * _zdsqvol * CAM2C * ca ;
 b_flux =  K1Noff * _zdsqvol * CAM1N2C ;
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 18) += (f_flux - b_flux);
 
 _term =  K1Non * _zdsqvol * ca ;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 28 ,19)  += _term;
 _MATELM1( 18 ,19)  -= _term;
 _term =  K1Non * _zdsqvol * CAM2C ;
 _MATELM1( 19 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 18 ,28)  -= _term;
 _term =  K1Noff * _zdsqvol ;
 _MATELM1( 19 ,18)  -= _term;
 _MATELM1( 28 ,18)  -= _term;
 _MATELM1( 18 ,18)  += _term;
 /*REACTION*/
  /* ~ ca + CAM1N2C <-> CAM4 ( K2Non * _zdsqvol , K2Noff * _zdsqvol )*/
 f_flux =  K2Non * _zdsqvol * CAM1N2C * ca ;
 b_flux =  K2Noff * _zdsqvol * CAM4 ;
 _RHS1( 18) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 13) += (f_flux - b_flux);
 
 _term =  K2Non * _zdsqvol * ca ;
 _MATELM1( 18 ,18)  += _term;
 _MATELM1( 28 ,18)  += _term;
 _MATELM1( 13 ,18)  -= _term;
 _term =  K2Non * _zdsqvol * CAM1N2C ;
 _MATELM1( 18 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 13 ,28)  -= _term;
 _term =  K2Noff * _zdsqvol ;
 _MATELM1( 18 ,13)  -= _term;
 _MATELM1( 28 ,13)  -= _term;
 _MATELM1( 13 ,13)  += _term;
 /*REACTION*/
  /* ~ ca + CAM0 <-> CAM1N ( K1Non * _zdsqvol , K1Noff * _zdsqvol )*/
 f_flux =  K1Non * _zdsqvol * CAM0 * ca ;
 b_flux =  K1Noff * _zdsqvol * CAM1N ;
 _RHS1( 21) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 17) += (f_flux - b_flux);
 
 _term =  K1Non * _zdsqvol * ca ;
 _MATELM1( 21 ,21)  += _term;
 _MATELM1( 28 ,21)  += _term;
 _MATELM1( 17 ,21)  -= _term;
 _term =  K1Non * _zdsqvol * CAM0 ;
 _MATELM1( 21 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 17 ,28)  -= _term;
 _term =  K1Noff * _zdsqvol ;
 _MATELM1( 21 ,17)  -= _term;
 _MATELM1( 28 ,17)  -= _term;
 _MATELM1( 17 ,17)  += _term;
 /*REACTION*/
  /* ~ ca + CAM1N <-> CAM2N ( K2Non * _zdsqvol , K2Noff * _zdsqvol )*/
 f_flux =  K2Non * _zdsqvol * CAM1N * ca ;
 b_flux =  K2Noff * _zdsqvol * CAM2N ;
 _RHS1( 17) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 16) += (f_flux - b_flux);
 
 _term =  K2Non * _zdsqvol * ca ;
 _MATELM1( 17 ,17)  += _term;
 _MATELM1( 28 ,17)  += _term;
 _MATELM1( 16 ,17)  -= _term;
 _term =  K2Non * _zdsqvol * CAM1N ;
 _MATELM1( 17 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 16 ,28)  -= _term;
 _term =  K2Noff * _zdsqvol ;
 _MATELM1( 17 ,16)  -= _term;
 _MATELM1( 28 ,16)  -= _term;
 _MATELM1( 16 ,16)  += _term;
 /*REACTION*/
  /* ~ ca + CAM2N <-> CAM2N1C ( K1Con * _zdsqvol , K1Coff * _zdsqvol )*/
 f_flux =  K1Con * _zdsqvol * CAM2N * ca ;
 b_flux =  K1Coff * _zdsqvol * CAM2N1C ;
 _RHS1( 16) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 15) += (f_flux - b_flux);
 
 _term =  K1Con * _zdsqvol * ca ;
 _MATELM1( 16 ,16)  += _term;
 _MATELM1( 28 ,16)  += _term;
 _MATELM1( 15 ,16)  -= _term;
 _term =  K1Con * _zdsqvol * CAM2N ;
 _MATELM1( 16 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 15 ,28)  -= _term;
 _term =  K1Coff * _zdsqvol ;
 _MATELM1( 16 ,15)  -= _term;
 _MATELM1( 28 ,15)  -= _term;
 _MATELM1( 15 ,15)  += _term;
 /*REACTION*/
  /* ~ ca + CAM2N1C <-> CAM4 ( K2Con * _zdsqvol , K2Coff * _zdsqvol )*/
 f_flux =  K2Con * _zdsqvol * CAM2N1C * ca ;
 b_flux =  K2Coff * _zdsqvol * CAM4 ;
 _RHS1( 15) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 13) += (f_flux - b_flux);
 
 _term =  K2Con * _zdsqvol * ca ;
 _MATELM1( 15 ,15)  += _term;
 _MATELM1( 28 ,15)  += _term;
 _MATELM1( 13 ,15)  -= _term;
 _term =  K2Con * _zdsqvol * CAM2N1C ;
 _MATELM1( 15 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 13 ,28)  -= _term;
 _term =  K2Coff * _zdsqvol ;
 _MATELM1( 15 ,13)  -= _term;
 _MATELM1( 28 ,13)  -= _term;
 _MATELM1( 13 ,13)  += _term;
 /*REACTION*/
  /* ~ ca + CAM1C <-> CAM1C1N ( K1Non * _zdsqvol , K1Noff * _zdsqvol )*/
 f_flux =  K1Non * _zdsqvol * CAM1C * ca ;
 b_flux =  K1Noff * _zdsqvol * CAM1C1N ;
 _RHS1( 20) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 14) += (f_flux - b_flux);
 
 _term =  K1Non * _zdsqvol * ca ;
 _MATELM1( 20 ,20)  += _term;
 _MATELM1( 28 ,20)  += _term;
 _MATELM1( 14 ,20)  -= _term;
 _term =  K1Non * _zdsqvol * CAM1C ;
 _MATELM1( 20 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 14 ,28)  -= _term;
 _term =  K1Noff * _zdsqvol ;
 _MATELM1( 20 ,14)  -= _term;
 _MATELM1( 28 ,14)  -= _term;
 _MATELM1( 14 ,14)  += _term;
 /*REACTION*/
  /* ~ ca + CAM1N <-> CAM1C1N ( K1Con * _zdsqvol , K1Coff * _zdsqvol )*/
 f_flux =  K1Con * _zdsqvol * CAM1N * ca ;
 b_flux =  K1Coff * _zdsqvol * CAM1C1N ;
 _RHS1( 17) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 14) += (f_flux - b_flux);
 
 _term =  K1Con * _zdsqvol * ca ;
 _MATELM1( 17 ,17)  += _term;
 _MATELM1( 28 ,17)  += _term;
 _MATELM1( 14 ,17)  -= _term;
 _term =  K1Con * _zdsqvol * CAM1N ;
 _MATELM1( 17 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 14 ,28)  -= _term;
 _term =  K1Coff * _zdsqvol ;
 _MATELM1( 17 ,14)  -= _term;
 _MATELM1( 28 ,14)  -= _term;
 _MATELM1( 14 ,14)  += _term;
 /*REACTION*/
  /* ~ ca + CAM1C1N <-> CAM1N2C ( K2Con * _zdsqvol , K2Coff * _zdsqvol )*/
 f_flux =  K2Con * _zdsqvol * CAM1C1N * ca ;
 b_flux =  K2Coff * _zdsqvol * CAM1N2C ;
 _RHS1( 14) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 18) += (f_flux - b_flux);
 
 _term =  K2Con * _zdsqvol * ca ;
 _MATELM1( 14 ,14)  += _term;
 _MATELM1( 28 ,14)  += _term;
 _MATELM1( 18 ,14)  -= _term;
 _term =  K2Con * _zdsqvol * CAM1C1N ;
 _MATELM1( 14 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 18 ,28)  -= _term;
 _term =  K2Coff * _zdsqvol ;
 _MATELM1( 14 ,18)  -= _term;
 _MATELM1( 28 ,18)  -= _term;
 _MATELM1( 18 ,18)  += _term;
 /*REACTION*/
  /* ~ ca + CAM1C1N <-> CAM2N1C ( K2Non * _zdsqvol , K2Noff * _zdsqvol )*/
 f_flux =  K2Non * _zdsqvol * CAM1C1N * ca ;
 b_flux =  K2Noff * _zdsqvol * CAM2N1C ;
 _RHS1( 14) -= (f_flux - b_flux);
 _RHS1( 28) -= (f_flux - b_flux);
 _RHS1( 15) += (f_flux - b_flux);
 
 _term =  K2Non * _zdsqvol * ca ;
 _MATELM1( 14 ,14)  += _term;
 _MATELM1( 28 ,14)  += _term;
 _MATELM1( 15 ,14)  -= _term;
 _term =  K2Non * _zdsqvol * CAM1C1N ;
 _MATELM1( 14 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 15 ,28)  -= _term;
 _term =  K2Noff * _zdsqvol ;
 _MATELM1( 14 ,15)  -= _term;
 _MATELM1( 28 ,15)  -= _term;
 _MATELM1( 15 ,15)  += _term;
 /*REACTION*/
  cai = ca ;
   mgi = mg ;
   nr2ai = CAM4 / 2.0 ;
   nr2ci = CAM4 / 2.0 ;
   con_2ci = CAM2C ;
     } return _reset;
 }
 
double ssBuff1 ( _threadargsproto_ ) {
   double _lssBuff1;
 _lssBuff1 = Buffnull1 / ( 1.0 + ( ( rf1 / rf2 ) * cainull ) ) ;
   
return _lssBuff1;
 }
 
static void _hoc_ssBuff1(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  ssBuff1 ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
double ssBuff1ca ( _threadargsproto_ ) {
   double _lssBuff1ca;
 _lssBuff1ca = Buffnull1 / ( 1.0 + ( rf2 / ( rf1 * cainull ) ) ) ;
   
return _lssBuff1ca;
 }
 
static void _hoc_ssBuff1ca(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  ssBuff1ca ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
double ssBuff2 ( _threadargsproto_ ) {
   double _lssBuff2;
 _lssBuff2 = Buffnull2 / ( 1.0 + ( ( rf3 / rf4 ) * cainull ) ) ;
   
return _lssBuff2;
 }
 
static void _hoc_ssBuff2(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  ssBuff2 ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
double ssBuff2ca ( _threadargsproto_ ) {
   double _lssBuff2ca;
 _lssBuff2ca = Buffnull2 / ( 1.0 + ( rf4 / ( rf3 * cainull ) ) ) ;
   
return _lssBuff2ca;
 }
 
static void _hoc_ssBuff2ca(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  ssBuff2ca ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
double ssBTC ( _threadargsproto_ ) {
   double _lssBTC;
 _lssBTC = BTCnull / ( 1.0 + ( ( b1 / b2 ) * cainull ) ) ;
   
return _lssBTC;
 }
 
static void _hoc_ssBTC(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  ssBTC ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
double ssBTCca ( _threadargsproto_ ) {
   double _lssBTCca;
 _lssBTCca = BTCnull / ( 1.0 + ( b2 / ( b1 * cainull ) ) ) ;
   
return _lssBTCca;
 }
 
static void _hoc_ssBTCca(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  ssBTCca ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
double ssDMNPE ( _threadargsproto_ ) {
   double _lssDMNPE;
 _lssDMNPE = DMNPEnull / ( 1.0 + ( ( c1 / c2 ) * cainull ) ) ;
   
return _lssDMNPE;
 }
 
static void _hoc_ssDMNPE(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  ssDMNPE ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
double ssDMNPEca ( _threadargsproto_ ) {
   double _lssDMNPEca;
 _lssDMNPEca = DMNPEnull / ( 1.0 + ( c2 / ( c1 * cainull ) ) ) ;
   
return _lssDMNPEca;
 }
 
static void _hoc_ssDMNPEca(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  ssDMNPEca ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
/*CVODE ode begin*/
 static int _ode_spec1(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<30;_i++) _p[_dlist1[_i]] = 0.0;}
 /* COMPARTMENT diam * diam * vrat {
   ca mg Buff1 Buff1_ca Buff2 Buff2_ca BTC BTC_ca DMNPE DMNPE_ca CR CR_1C_0N CR_2C_0N CR_2C_1N CR_0C_1N CR_0C_2N CR_1C_2N CR_1C_1N CR_2C_1N CR_1C_2N CR_2C_2N }
 */
 /* COMPARTMENT ( 1e10 ) * parea {
   pump pumpca }
 */
 /* ~ ca + pump <-> pumpca ( kpmp1 * parea * ( 1e10 ) , kpmp2 * parea * ( 1e10 ) )*/
 f_flux =  kpmp1 * parea * ( 1e10 ) * pump * ca ;
 b_flux =  kpmp2 * parea * ( 1e10 ) * pumpca ;
 Dpump -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 Dpumpca += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ pumpca <-> pump ( kpmp3 * parea * ( 1e10 ) , 0.0 )*/
 f_flux =  kpmp3 * parea * ( 1e10 ) * pumpca ;
 b_flux =  0.0 * pump ;
 Dpumpca -= (f_flux - b_flux);
 Dpump += (f_flux - b_flux);
 
 /*REACTION*/
   /* pump + pumpca = TotalPump * parea * ( 1e10 ) */
 /*CONSERVATION*/
 ica_pmp = 2.0 * FARADAY * ( f_flux - b_flux ) / parea ;
 /* ~ ca < < ( - ica * PI * diam / ( 2.0 * FARADAY ) )*/
 f_flux = b_flux = 0.;
 Dca += (b_flux =   ( - ica * PI * diam / ( 2.0 * FARADAY ) ) );
 /*FLUX*/
  _zdsq = diam * diam ;
 _zdsqvol = _zdsq * vrat ;
 /* ~ ca + Buff1 <-> Buff1_ca ( rf1 * _zdsqvol , rf2 * _zdsqvol )*/
 f_flux =  rf1 * _zdsqvol * Buff1 * ca ;
 b_flux =  rf2 * _zdsqvol * Buff1_ca ;
 DBuff1 -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DBuff1_ca += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + Buff2 <-> Buff2_ca ( rf3 * _zdsqvol , rf4 * _zdsqvol )*/
 f_flux =  rf3 * _zdsqvol * Buff2 * ca ;
 b_flux =  rf4 * _zdsqvol * Buff2_ca ;
 DBuff2 -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DBuff2_ca += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + BTC <-> BTC_ca ( b1 * _zdsqvol , b2 * _zdsqvol )*/
 f_flux =  b1 * _zdsqvol * BTC * ca ;
 b_flux =  b2 * _zdsqvol * BTC_ca ;
 DBTC -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DBTC_ca += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + DMNPE <-> DMNPE_ca ( c1 * _zdsqvol , c2 * _zdsqvol )*/
 f_flux =  c1 * _zdsqvol * DMNPE * ca ;
 b_flux =  c2 * _zdsqvol * DMNPE_ca ;
 DDMNPE -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DDMNPE_ca += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR <-> CR_1C_0N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR * ca ;
 b_flux =  nT2 * _zdsqvol * CR_1C_0N ;
 DCR -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_1C_0N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR_1C_0N <-> CR_2C_0N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_1C_0N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_2C_0N ;
 DCR_1C_0N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_2C_0N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR_2C_0N <-> CR_2C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR_2C_0N * ca ;
 b_flux =  nT2 * _zdsqvol * CR_2C_1N ;
 DCR_2C_0N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_2C_1N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR <-> CR_0C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR * ca ;
 b_flux =  nT2 * _zdsqvol * CR_0C_1N ;
 DCR -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_0C_1N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR_0C_1N <-> CR_0C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_0C_1N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_0C_2N ;
 DCR_0C_1N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_0C_2N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR_0C_2N <-> CR_1C_2N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR_0C_2N * ca ;
 b_flux =  nT2 * _zdsqvol * CR_1C_2N ;
 DCR_0C_2N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_1C_2N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR_2C_1N <-> CR_2C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_2C_1N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_2C_2N ;
 DCR_2C_1N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_2C_2N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR_1C_2N <-> CR_2C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_1C_2N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_2C_2N ;
 DCR_1C_2N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_2C_2N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR_1C_0N <-> CR_1C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR_1C_0N * ca ;
 b_flux =  nT2 * _zdsqvol * CR_1C_1N ;
 DCR_1C_0N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_1C_1N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR_0C_1N <-> CR_1C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR_0C_1N * ca ;
 b_flux =  nT2 * _zdsqvol * CR_1C_1N ;
 DCR_0C_1N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_1C_1N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR_1C_1N <-> CR_2C_1N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_1C_1N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_2C_1N ;
 DCR_1C_1N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_2C_1N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR_1C_1N <-> CR_1C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_1C_1N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_1C_2N ;
 DCR_1C_1N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_1C_2N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR <-> CR_1V ( nV1 * _zdsqvol , nV2 * _zdsqvol )*/
 f_flux =  nV1 * _zdsqvol * CR * ca ;
 b_flux =  nV2 * _zdsqvol * CR_1V ;
 DCR -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_1V += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CAM0 <-> CAM1C ( K1Con * _zdsqvol , K1Coff * _zdsqvol )*/
 f_flux =  K1Con * _zdsqvol * CAM0 * ca ;
 b_flux =  K1Coff * _zdsqvol * CAM1C ;
 DCAM0 -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCAM1C += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CAM1C <-> CAM2C ( K2Con * _zdsqvol , K2Coff * _zdsqvol )*/
 f_flux =  K2Con * _zdsqvol * CAM1C * ca ;
 b_flux =  K2Coff * _zdsqvol * CAM2C ;
 DCAM1C -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCAM2C += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CAM2C <-> CAM1N2C ( K1Non * _zdsqvol , K1Noff * _zdsqvol )*/
 f_flux =  K1Non * _zdsqvol * CAM2C * ca ;
 b_flux =  K1Noff * _zdsqvol * CAM1N2C ;
 DCAM2C -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCAM1N2C += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CAM1N2C <-> CAM4 ( K2Non * _zdsqvol , K2Noff * _zdsqvol )*/
 f_flux =  K2Non * _zdsqvol * CAM1N2C * ca ;
 b_flux =  K2Noff * _zdsqvol * CAM4 ;
 DCAM1N2C -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCAM4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CAM0 <-> CAM1N ( K1Non * _zdsqvol , K1Noff * _zdsqvol )*/
 f_flux =  K1Non * _zdsqvol * CAM0 * ca ;
 b_flux =  K1Noff * _zdsqvol * CAM1N ;
 DCAM0 -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCAM1N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CAM1N <-> CAM2N ( K2Non * _zdsqvol , K2Noff * _zdsqvol )*/
 f_flux =  K2Non * _zdsqvol * CAM1N * ca ;
 b_flux =  K2Noff * _zdsqvol * CAM2N ;
 DCAM1N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCAM2N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CAM2N <-> CAM2N1C ( K1Con * _zdsqvol , K1Coff * _zdsqvol )*/
 f_flux =  K1Con * _zdsqvol * CAM2N * ca ;
 b_flux =  K1Coff * _zdsqvol * CAM2N1C ;
 DCAM2N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCAM2N1C += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CAM2N1C <-> CAM4 ( K2Con * _zdsqvol , K2Coff * _zdsqvol )*/
 f_flux =  K2Con * _zdsqvol * CAM2N1C * ca ;
 b_flux =  K2Coff * _zdsqvol * CAM4 ;
 DCAM2N1C -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCAM4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CAM1C <-> CAM1C1N ( K1Non * _zdsqvol , K1Noff * _zdsqvol )*/
 f_flux =  K1Non * _zdsqvol * CAM1C * ca ;
 b_flux =  K1Noff * _zdsqvol * CAM1C1N ;
 DCAM1C -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCAM1C1N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CAM1N <-> CAM1C1N ( K1Con * _zdsqvol , K1Coff * _zdsqvol )*/
 f_flux =  K1Con * _zdsqvol * CAM1N * ca ;
 b_flux =  K1Coff * _zdsqvol * CAM1C1N ;
 DCAM1N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCAM1C1N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CAM1C1N <-> CAM1N2C ( K2Con * _zdsqvol , K2Coff * _zdsqvol )*/
 f_flux =  K2Con * _zdsqvol * CAM1C1N * ca ;
 b_flux =  K2Coff * _zdsqvol * CAM1N2C ;
 DCAM1C1N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCAM1N2C += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CAM1C1N <-> CAM2N1C ( K2Non * _zdsqvol , K2Noff * _zdsqvol )*/
 f_flux =  K2Non * _zdsqvol * CAM1C1N * ca ;
 b_flux =  K2Noff * _zdsqvol * CAM2N1C ;
 DCAM1C1N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCAM2N1C += (f_flux - b_flux);
 
 /*REACTION*/
  cai = ca ;
 mgi = mg ;
 nr2ai = CAM4 / 2.0 ;
 nr2ci = CAM4 / 2.0 ;
 con_2ci = CAM2C ;
 _p[_dlist1[0]] /= ( ( 1e10 ) * parea);
 _p[_dlist1[1]] /= ( diam * diam * vrat);
 _p[_dlist1[2]] /= ( diam * diam * vrat);
 _p[_dlist1[3]] /= ( diam * diam * vrat);
 _p[_dlist1[4]] /= ( diam * diam * vrat);
 _p[_dlist1[5]] /= ( diam * diam * vrat);
 _p[_dlist1[6]] /= ( diam * diam * vrat);
 _p[_dlist1[7]] /= ( diam * diam * vrat);
 _p[_dlist1[8]] /= ( diam * diam * vrat);
 _p[_dlist1[9]] /= ( diam * diam * vrat);
 _p[_dlist1[10]] /= ( diam * diam * vrat);
 _p[_dlist1[11]] /= ( diam * diam * vrat);
 _p[_dlist1[12]] /= ( diam * diam * vrat);
 _p[_dlist1[23]] /= ( diam * diam * vrat);
 _p[_dlist1[24]] /= ( diam * diam * vrat);
 _p[_dlist1[25]] /= ( diam * diam * vrat);
 _p[_dlist1[26]] /= ( diam * diam * vrat);
 _p[_dlist1[27]] /= ( diam * diam * vrat);
 _p[_dlist1[28]] /= ( diam * diam * vrat);
 _p[_dlist1[29]] /= ( ( 1e10 ) * parea);
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1(void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<30;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
}  
_RHS1(0) *= ( ( 1e10 ) * parea) ;
_MATELM1(0, 0) *= ( ( 1e10 ) * parea); 
_RHS1(1) *= ( diam * diam * vrat) ;
_MATELM1(1, 1) *= ( diam * diam * vrat); 
_RHS1(2) *= ( diam * diam * vrat) ;
_MATELM1(2, 2) *= ( diam * diam * vrat); 
_RHS1(3) *= ( diam * diam * vrat) ;
_MATELM1(3, 3) *= ( diam * diam * vrat); 
_RHS1(4) *= ( diam * diam * vrat) ;
_MATELM1(4, 4) *= ( diam * diam * vrat); 
_RHS1(5) *= ( diam * diam * vrat) ;
_MATELM1(5, 5) *= ( diam * diam * vrat); 
_RHS1(6) *= ( diam * diam * vrat) ;
_MATELM1(6, 6) *= ( diam * diam * vrat); 
_RHS1(7) *= ( diam * diam * vrat) ;
_MATELM1(7, 7) *= ( diam * diam * vrat); 
_RHS1(8) *= ( diam * diam * vrat) ;
_MATELM1(8, 8) *= ( diam * diam * vrat); 
_RHS1(9) *= ( diam * diam * vrat) ;
_MATELM1(9, 9) *= ( diam * diam * vrat); 
_RHS1(10) *= ( diam * diam * vrat) ;
_MATELM1(10, 10) *= ( diam * diam * vrat); 
_RHS1(11) *= ( diam * diam * vrat) ;
_MATELM1(11, 11) *= ( diam * diam * vrat); 
_RHS1(12) *= ( diam * diam * vrat) ;
_MATELM1(12, 12) *= ( diam * diam * vrat); 
_RHS1(23) *= ( diam * diam * vrat) ;
_MATELM1(23, 23) *= ( diam * diam * vrat); 
_RHS1(24) *= ( diam * diam * vrat) ;
_MATELM1(24, 24) *= ( diam * diam * vrat); 
_RHS1(25) *= ( diam * diam * vrat) ;
_MATELM1(25, 25) *= ( diam * diam * vrat); 
_RHS1(26) *= ( diam * diam * vrat) ;
_MATELM1(26, 26) *= ( diam * diam * vrat); 
_RHS1(27) *= ( diam * diam * vrat) ;
_MATELM1(27, 27) *= ( diam * diam * vrat); 
_RHS1(28) *= ( diam * diam * vrat) ;
_MATELM1(28, 28) *= ( diam * diam * vrat); 
_RHS1(29) *= ( ( 1e10 ) * parea) ;
_MATELM1(29, 29) *= ( ( 1e10 ) * parea);  }
 /* COMPARTMENT diam * diam * vrat {
 ca mg Buff1 Buff1_ca Buff2 Buff2_ca BTC BTC_ca DMNPE DMNPE_ca CR CR_1C_0N CR_2C_0N CR_2C_1N CR_0C_1N CR_0C_2N CR_1C_2N CR_1C_1N CR_2C_1N CR_1C_2N CR_2C_2N }
 */
 /* COMPARTMENT ( 1e10 ) * parea {
 pump pumpca }
 */
 /* ~ ca + pump <-> pumpca ( kpmp1 * parea * ( 1e10 ) , kpmp2 * parea * ( 1e10 ) )*/
 _term =  kpmp1 * parea * ( 1e10 ) * ca ;
 _MATELM1( 29 ,29)  += _term;
 _MATELM1( 28 ,29)  += _term;
 _MATELM1( 0 ,29)  -= _term;
 _term =  kpmp1 * parea * ( 1e10 ) * pump ;
 _MATELM1( 29 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 0 ,28)  -= _term;
 _term =  kpmp2 * parea * ( 1e10 ) ;
 _MATELM1( 29 ,0)  -= _term;
 _MATELM1( 28 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ pumpca <-> pump ( kpmp3 * parea * ( 1e10 ) , 0.0 )*/
 _term =  kpmp3 * parea * ( 1e10 ) ;
 _MATELM1( 0 ,0)  += _term;
 _MATELM1( 29 ,0)  -= _term;
 _term =  0.0 ;
 _MATELM1( 0 ,29)  -= _term;
 _MATELM1( 29 ,29)  += _term;
 /* ~ ca < < ( - ica * PI * diam / ( 2.0 * FARADAY ) )*/
 /*FLUX*/
  _zdsq = diam * diam ;
 _zdsqvol = _zdsq * vrat ;
 /* ~ ca + Buff1 <-> Buff1_ca ( rf1 * _zdsqvol , rf2 * _zdsqvol )*/
 _term =  rf1 * _zdsqvol * ca ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 28 ,6)  += _term;
 _MATELM1( 5 ,6)  -= _term;
 _term =  rf1 * _zdsqvol * Buff1 ;
 _MATELM1( 6 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 5 ,28)  -= _term;
 _term =  rf2 * _zdsqvol ;
 _MATELM1( 6 ,5)  -= _term;
 _MATELM1( 28 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ ca + Buff2 <-> Buff2_ca ( rf3 * _zdsqvol , rf4 * _zdsqvol )*/
 _term =  rf3 * _zdsqvol * ca ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 28 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  rf3 * _zdsqvol * Buff2 ;
 _MATELM1( 4 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 3 ,28)  -= _term;
 _term =  rf4 * _zdsqvol ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 28 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ ca + BTC <-> BTC_ca ( b1 * _zdsqvol , b2 * _zdsqvol )*/
 _term =  b1 * _zdsqvol * ca ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 28 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  b1 * _zdsqvol * BTC ;
 _MATELM1( 2 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 1 ,28)  -= _term;
 _term =  b2 * _zdsqvol ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 28 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ ca + DMNPE <-> DMNPE_ca ( c1 * _zdsqvol , c2 * _zdsqvol )*/
 _term =  c1 * _zdsqvol * ca ;
 _MATELM1( 27 ,27)  += _term;
 _MATELM1( 28 ,27)  += _term;
 _MATELM1( 26 ,27)  -= _term;
 _term =  c1 * _zdsqvol * DMNPE ;
 _MATELM1( 27 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 26 ,28)  -= _term;
 _term =  c2 * _zdsqvol ;
 _MATELM1( 27 ,26)  -= _term;
 _MATELM1( 28 ,26)  -= _term;
 _MATELM1( 26 ,26)  += _term;
 /*REACTION*/
  /* ~ ca + CR <-> CR_1C_0N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 25 ,25)  += _term;
 _MATELM1( 28 ,25)  += _term;
 _MATELM1( 24 ,25)  -= _term;
 _term =  nT1 * _zdsqvol * CR ;
 _MATELM1( 25 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 24 ,28)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 25 ,24)  -= _term;
 _MATELM1( 28 ,24)  -= _term;
 _MATELM1( 24 ,24)  += _term;
 /*REACTION*/
  /* ~ ca + CR_1C_0N <-> CR_2C_0N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 24 ,24)  += _term;
 _MATELM1( 28 ,24)  += _term;
 _MATELM1( 12 ,24)  -= _term;
 _term =  nR1 * _zdsqvol * CR_1C_0N ;
 _MATELM1( 24 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 12 ,28)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 24 ,12)  -= _term;
 _MATELM1( 28 ,12)  -= _term;
 _MATELM1( 12 ,12)  += _term;
 /*REACTION*/
  /* ~ ca + CR_2C_0N <-> CR_2C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 28 ,12)  += _term;
 _MATELM1( 11 ,12)  -= _term;
 _term =  nT1 * _zdsqvol * CR_2C_0N ;
 _MATELM1( 12 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 11 ,28)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 12 ,11)  -= _term;
 _MATELM1( 28 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ ca + CR <-> CR_0C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 25 ,25)  += _term;
 _MATELM1( 28 ,25)  += _term;
 _MATELM1( 9 ,25)  -= _term;
 _term =  nT1 * _zdsqvol * CR ;
 _MATELM1( 25 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 9 ,28)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 25 ,9)  -= _term;
 _MATELM1( 28 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ ca + CR_0C_1N <-> CR_0C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 28 ,9)  += _term;
 _MATELM1( 8 ,9)  -= _term;
 _term =  nR1 * _zdsqvol * CR_0C_1N ;
 _MATELM1( 9 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 8 ,28)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 9 ,8)  -= _term;
 _MATELM1( 28 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ ca + CR_0C_2N <-> CR_1C_2N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 28 ,8)  += _term;
 _MATELM1( 7 ,8)  -= _term;
 _term =  nT1 * _zdsqvol * CR_0C_2N ;
 _MATELM1( 8 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 7 ,28)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 8 ,7)  -= _term;
 _MATELM1( 28 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ ca + CR_2C_1N <-> CR_2C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 11 ,11)  += _term;
 _MATELM1( 28 ,11)  += _term;
 _MATELM1( 23 ,11)  -= _term;
 _term =  nR1 * _zdsqvol * CR_2C_1N ;
 _MATELM1( 11 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 23 ,28)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 11 ,23)  -= _term;
 _MATELM1( 28 ,23)  -= _term;
 _MATELM1( 23 ,23)  += _term;
 /*REACTION*/
  /* ~ ca + CR_1C_2N <-> CR_2C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 28 ,7)  += _term;
 _MATELM1( 23 ,7)  -= _term;
 _term =  nR1 * _zdsqvol * CR_1C_2N ;
 _MATELM1( 7 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 23 ,28)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 7 ,23)  -= _term;
 _MATELM1( 28 ,23)  -= _term;
 _MATELM1( 23 ,23)  += _term;
 /*REACTION*/
  /* ~ ca + CR_1C_0N <-> CR_1C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 24 ,24)  += _term;
 _MATELM1( 28 ,24)  += _term;
 _MATELM1( 10 ,24)  -= _term;
 _term =  nT1 * _zdsqvol * CR_1C_0N ;
 _MATELM1( 24 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 10 ,28)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 24 ,10)  -= _term;
 _MATELM1( 28 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ ca + CR_0C_1N <-> CR_1C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 28 ,9)  += _term;
 _MATELM1( 10 ,9)  -= _term;
 _term =  nT1 * _zdsqvol * CR_0C_1N ;
 _MATELM1( 9 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 10 ,28)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 9 ,10)  -= _term;
 _MATELM1( 28 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ ca + CR_1C_1N <-> CR_2C_1N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 28 ,10)  += _term;
 _MATELM1( 11 ,10)  -= _term;
 _term =  nR1 * _zdsqvol * CR_1C_1N ;
 _MATELM1( 10 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 11 ,28)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 10 ,11)  -= _term;
 _MATELM1( 28 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ ca + CR_1C_1N <-> CR_1C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 28 ,10)  += _term;
 _MATELM1( 7 ,10)  -= _term;
 _term =  nR1 * _zdsqvol * CR_1C_1N ;
 _MATELM1( 10 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 7 ,28)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 10 ,7)  -= _term;
 _MATELM1( 28 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ ca + CR <-> CR_1V ( nV1 * _zdsqvol , nV2 * _zdsqvol )*/
 _term =  nV1 * _zdsqvol * ca ;
 _MATELM1( 25 ,25)  += _term;
 _MATELM1( 28 ,25)  += _term;
 _MATELM1( 22 ,25)  -= _term;
 _term =  nV1 * _zdsqvol * CR ;
 _MATELM1( 25 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 22 ,28)  -= _term;
 _term =  nV2 * _zdsqvol ;
 _MATELM1( 25 ,22)  -= _term;
 _MATELM1( 28 ,22)  -= _term;
 _MATELM1( 22 ,22)  += _term;
 /*REACTION*/
  /* ~ ca + CAM0 <-> CAM1C ( K1Con * _zdsqvol , K1Coff * _zdsqvol )*/
 _term =  K1Con * _zdsqvol * ca ;
 _MATELM1( 21 ,21)  += _term;
 _MATELM1( 28 ,21)  += _term;
 _MATELM1( 20 ,21)  -= _term;
 _term =  K1Con * _zdsqvol * CAM0 ;
 _MATELM1( 21 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 20 ,28)  -= _term;
 _term =  K1Coff * _zdsqvol ;
 _MATELM1( 21 ,20)  -= _term;
 _MATELM1( 28 ,20)  -= _term;
 _MATELM1( 20 ,20)  += _term;
 /*REACTION*/
  /* ~ ca + CAM1C <-> CAM2C ( K2Con * _zdsqvol , K2Coff * _zdsqvol )*/
 _term =  K2Con * _zdsqvol * ca ;
 _MATELM1( 20 ,20)  += _term;
 _MATELM1( 28 ,20)  += _term;
 _MATELM1( 19 ,20)  -= _term;
 _term =  K2Con * _zdsqvol * CAM1C ;
 _MATELM1( 20 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 19 ,28)  -= _term;
 _term =  K2Coff * _zdsqvol ;
 _MATELM1( 20 ,19)  -= _term;
 _MATELM1( 28 ,19)  -= _term;
 _MATELM1( 19 ,19)  += _term;
 /*REACTION*/
  /* ~ ca + CAM2C <-> CAM1N2C ( K1Non * _zdsqvol , K1Noff * _zdsqvol )*/
 _term =  K1Non * _zdsqvol * ca ;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 28 ,19)  += _term;
 _MATELM1( 18 ,19)  -= _term;
 _term =  K1Non * _zdsqvol * CAM2C ;
 _MATELM1( 19 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 18 ,28)  -= _term;
 _term =  K1Noff * _zdsqvol ;
 _MATELM1( 19 ,18)  -= _term;
 _MATELM1( 28 ,18)  -= _term;
 _MATELM1( 18 ,18)  += _term;
 /*REACTION*/
  /* ~ ca + CAM1N2C <-> CAM4 ( K2Non * _zdsqvol , K2Noff * _zdsqvol )*/
 _term =  K2Non * _zdsqvol * ca ;
 _MATELM1( 18 ,18)  += _term;
 _MATELM1( 28 ,18)  += _term;
 _MATELM1( 13 ,18)  -= _term;
 _term =  K2Non * _zdsqvol * CAM1N2C ;
 _MATELM1( 18 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 13 ,28)  -= _term;
 _term =  K2Noff * _zdsqvol ;
 _MATELM1( 18 ,13)  -= _term;
 _MATELM1( 28 ,13)  -= _term;
 _MATELM1( 13 ,13)  += _term;
 /*REACTION*/
  /* ~ ca + CAM0 <-> CAM1N ( K1Non * _zdsqvol , K1Noff * _zdsqvol )*/
 _term =  K1Non * _zdsqvol * ca ;
 _MATELM1( 21 ,21)  += _term;
 _MATELM1( 28 ,21)  += _term;
 _MATELM1( 17 ,21)  -= _term;
 _term =  K1Non * _zdsqvol * CAM0 ;
 _MATELM1( 21 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 17 ,28)  -= _term;
 _term =  K1Noff * _zdsqvol ;
 _MATELM1( 21 ,17)  -= _term;
 _MATELM1( 28 ,17)  -= _term;
 _MATELM1( 17 ,17)  += _term;
 /*REACTION*/
  /* ~ ca + CAM1N <-> CAM2N ( K2Non * _zdsqvol , K2Noff * _zdsqvol )*/
 _term =  K2Non * _zdsqvol * ca ;
 _MATELM1( 17 ,17)  += _term;
 _MATELM1( 28 ,17)  += _term;
 _MATELM1( 16 ,17)  -= _term;
 _term =  K2Non * _zdsqvol * CAM1N ;
 _MATELM1( 17 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 16 ,28)  -= _term;
 _term =  K2Noff * _zdsqvol ;
 _MATELM1( 17 ,16)  -= _term;
 _MATELM1( 28 ,16)  -= _term;
 _MATELM1( 16 ,16)  += _term;
 /*REACTION*/
  /* ~ ca + CAM2N <-> CAM2N1C ( K1Con * _zdsqvol , K1Coff * _zdsqvol )*/
 _term =  K1Con * _zdsqvol * ca ;
 _MATELM1( 16 ,16)  += _term;
 _MATELM1( 28 ,16)  += _term;
 _MATELM1( 15 ,16)  -= _term;
 _term =  K1Con * _zdsqvol * CAM2N ;
 _MATELM1( 16 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 15 ,28)  -= _term;
 _term =  K1Coff * _zdsqvol ;
 _MATELM1( 16 ,15)  -= _term;
 _MATELM1( 28 ,15)  -= _term;
 _MATELM1( 15 ,15)  += _term;
 /*REACTION*/
  /* ~ ca + CAM2N1C <-> CAM4 ( K2Con * _zdsqvol , K2Coff * _zdsqvol )*/
 _term =  K2Con * _zdsqvol * ca ;
 _MATELM1( 15 ,15)  += _term;
 _MATELM1( 28 ,15)  += _term;
 _MATELM1( 13 ,15)  -= _term;
 _term =  K2Con * _zdsqvol * CAM2N1C ;
 _MATELM1( 15 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 13 ,28)  -= _term;
 _term =  K2Coff * _zdsqvol ;
 _MATELM1( 15 ,13)  -= _term;
 _MATELM1( 28 ,13)  -= _term;
 _MATELM1( 13 ,13)  += _term;
 /*REACTION*/
  /* ~ ca + CAM1C <-> CAM1C1N ( K1Non * _zdsqvol , K1Noff * _zdsqvol )*/
 _term =  K1Non * _zdsqvol * ca ;
 _MATELM1( 20 ,20)  += _term;
 _MATELM1( 28 ,20)  += _term;
 _MATELM1( 14 ,20)  -= _term;
 _term =  K1Non * _zdsqvol * CAM1C ;
 _MATELM1( 20 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 14 ,28)  -= _term;
 _term =  K1Noff * _zdsqvol ;
 _MATELM1( 20 ,14)  -= _term;
 _MATELM1( 28 ,14)  -= _term;
 _MATELM1( 14 ,14)  += _term;
 /*REACTION*/
  /* ~ ca + CAM1N <-> CAM1C1N ( K1Con * _zdsqvol , K1Coff * _zdsqvol )*/
 _term =  K1Con * _zdsqvol * ca ;
 _MATELM1( 17 ,17)  += _term;
 _MATELM1( 28 ,17)  += _term;
 _MATELM1( 14 ,17)  -= _term;
 _term =  K1Con * _zdsqvol * CAM1N ;
 _MATELM1( 17 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 14 ,28)  -= _term;
 _term =  K1Coff * _zdsqvol ;
 _MATELM1( 17 ,14)  -= _term;
 _MATELM1( 28 ,14)  -= _term;
 _MATELM1( 14 ,14)  += _term;
 /*REACTION*/
  /* ~ ca + CAM1C1N <-> CAM1N2C ( K2Con * _zdsqvol , K2Coff * _zdsqvol )*/
 _term =  K2Con * _zdsqvol * ca ;
 _MATELM1( 14 ,14)  += _term;
 _MATELM1( 28 ,14)  += _term;
 _MATELM1( 18 ,14)  -= _term;
 _term =  K2Con * _zdsqvol * CAM1C1N ;
 _MATELM1( 14 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 18 ,28)  -= _term;
 _term =  K2Coff * _zdsqvol ;
 _MATELM1( 14 ,18)  -= _term;
 _MATELM1( 28 ,18)  -= _term;
 _MATELM1( 18 ,18)  += _term;
 /*REACTION*/
  /* ~ ca + CAM1C1N <-> CAM2N1C ( K2Non * _zdsqvol , K2Noff * _zdsqvol )*/
 _term =  K2Non * _zdsqvol * ca ;
 _MATELM1( 14 ,14)  += _term;
 _MATELM1( 28 ,14)  += _term;
 _MATELM1( 15 ,14)  -= _term;
 _term =  K2Non * _zdsqvol * CAM1C1N ;
 _MATELM1( 14 ,28)  += _term;
 _MATELM1( 28 ,28)  += _term;
 _MATELM1( 15 ,28)  -= _term;
 _term =  K2Noff * _zdsqvol ;
 _MATELM1( 14 ,15)  -= _term;
 _MATELM1( 28 ,15)  -= _term;
 _MATELM1( 15 ,15)  += _term;
 /*REACTION*/
  cai = ca ;
 mgi = mg ;
 nr2ai = CAM4 / 2.0 ;
 nr2ci = CAM4 / 2.0 ;
 con_2ci = CAM2C ;
   } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 30;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  cao = _ion_cao;
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
  nr2ai = _ion_nr2ai;
  nr2ci = _ion_nr2ci;
  con_2ci = _ion_con_2ci;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  _ion_cai = cai;
  _ion_nr2ai = nr2ai;
  _ion_nr2ci = nr2ci;
  _ion_con_2ci = con_2ci;
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 30; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 static void _ode_synonym(int _cnt, double** _pp, Datum** _ppd) { 
	double* _p; Datum* _ppvar;
 	int _i; 
	for (_i=0; _i < _cnt; ++_i) {_p = _pp[_i]; _ppvar = _ppd[_i];
 _ion_cai =  ca ;
 _ion_nr2ai =  CAM4 / 2.0 ;
 _ion_nr2ci =  CAM4 / 2.0 ;
 _ion_con_2ci =  CAM2C ;
 }}
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _cvode_sparse_thread(&_thread[_cvspth1]._pvoid, 30, _dlist1, _p, _ode_matsol1, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  cao = _ion_cao;
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
  nr2ai = _ion_nr2ai;
  nr2ci = _ion_nr2ci;
  con_2ci = _ion_con_2ci;
 _ode_matsol_instance1(_threadargs_);
 }}
 
static void _thread_mem_init(Datum* _thread) {
   _thread[2]._pval = (double*)ecalloc(3, sizeof(double));
 }
 
static void _thread_cleanup(Datum* _thread) {
   _nrn_destroy_sparseobj_thread(_thread[_cvspth1]._pvoid);
   _nrn_destroy_sparseobj_thread(_thread[_spth1]._pvoid);
   free((void*)(_thread[2]._pval));
 }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 2);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 1);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 2, 3);
   nrn_update_ion_pointer(_nr2a_sym, _ppvar, 4, 1);
   nrn_update_ion_pointer(_nr2c_sym, _ppvar, 6, 1);
   nrn_update_ion_pointer(_con_2c_sym, _ppvar, 8, 1);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  BTC_ca = BTC_ca0;
  BTC = BTC0;
  Buff2_ca = Buff2_ca0;
  Buff2 = Buff20;
  Buff1_ca = Buff1_ca0;
  Buff1 = Buff10;
  CR_1C_2N = CR_1C_2N0;
  CR_0C_2N = CR_0C_2N0;
  CR_0C_1N = CR_0C_1N0;
  CR_1C_1N = CR_1C_1N0;
  CR_2C_1N = CR_2C_1N0;
  CR_2C_0N = CR_2C_0N0;
  CAM4 = CAM40;
  CAM1C1N = CAM1C1N0;
  CAM2N1C = CAM2N1C0;
  CAM2N = CAM2N0;
  CAM1N = CAM1N0;
  CAM1N2C = CAM1N2C0;
  CAM2C = CAM2C0;
  CAM1C = CAM1C0;
  CAM0 = CAM00;
  CR_1V = CR_1V0;
  CR_2C_2N = CR_2C_2N0;
  CR_1C_0N = CR_1C_0N0;
  CR = CR0;
  DMNPE_ca = DMNPE_ca0;
  DMNPE = DMNPE0;
  ca = ca0;
  mg = mg0;
  pumpca = pumpca0;
  pump = pump0;
 {
   factors ( _threadargs_ ) ;
   ca = cainull ;
   mg = mginull ;
   Buff1 = ssBuff1 ( _threadargs_ ) ;
   Buff1_ca = ssBuff1ca ( _threadargs_ ) ;
   Buff2 = ssBuff2 ( _threadargs_ ) ;
   Buff2_ca = ssBuff2ca ( _threadargs_ ) ;
   BTC = ssBTC ( _threadargs_ ) ;
   BTC_ca = ssBTCca ( _threadargs_ ) ;
   DMNPE = ssDMNPE ( _threadargs_ ) ;
   DMNPE_ca = ssDMNPEca ( _threadargs_ ) ;
   CR = CRnull ;
   CR_1C_0N = 0.0 ;
   CR_2C_0N = 0.0 ;
   CR_2C_1N = 0.0 ;
   CR_1C_1N = 0.0 ;
   CR_0C_1N = 0.0 ;
   CR_0C_2N = 0.0 ;
   CR_1C_2N = 0.0 ;
   CR_2C_2N = 0.0 ;
   CR_1V = 0.0 ;
   CAM0 = CAM_start ;
   CAM1C = 0.0 ;
   CAM2C = 0.0 ;
   CAM1N2C = 0.0 ;
   CAM1N = 0.0 ;
   CAM2N = 0.0 ;
   CAM2N1C = 0.0 ;
   CAM1C1N = 0.0 ;
   CAM4 = 0.0 ;
   parea = PI * diam ;
   parea2 = PI * ( diam - 0.2 ) ;
   ica = 0.0 ;
   ica_pmp = 0.0 ;
   pump = TotalPump ;
   pumpca = 0.0 ;
   cai = ca ;
   }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  cao = _ion_cao;
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
  nr2ai = _ion_nr2ai;
  nr2ci = _ion_nr2ci;
  con_2ci = _ion_con_2ci;
 initmodel(_p, _ppvar, _thread, _nt);
  _ion_cai = cai;
  nrn_wrote_conc(_ca_sym, (&(_ion_cai)) - 1, _style_ca);
  _ion_nr2ai = nr2ai;
  nrn_wrote_conc(_nr2a_sym, (&(_ion_nr2ai)) - 1, _style_nr2a);
  _ion_nr2ci = nr2ci;
  nrn_wrote_conc(_nr2c_sym, (&(_ion_nr2ci)) - 1, _style_nr2c);
  _ion_con_2ci = con_2ci;
  nrn_wrote_conc(_con_2c_sym, (&(_ion_con_2ci)) - 1, _style_con_2c);
}
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{
} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 
}
 
}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}
 
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
double _dtsav = dt;
if (secondorder) { dt *= 0.5; }
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  cao = _ion_cao;
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
  nr2ai = _ion_nr2ai;
  nr2ci = _ion_nr2ci;
  con_2ci = _ion_con_2ci;
 {  sparse_thread(&_thread[_spth1]._pvoid, 30, _slist1, _dlist1, _p, &t, dt, state, _linmat1, _ppvar, _thread, _nt);
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 30; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 } {
   }
  _ion_cai = cai;
  _ion_nr2ai = nr2ai;
  _ion_nr2ci = nr2ci;
  _ion_con_2ci = con_2ci;
}}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(pumpca) - _p;  _dlist1[0] = &(Dpumpca) - _p;
 _slist1[1] = &(BTC_ca) - _p;  _dlist1[1] = &(DBTC_ca) - _p;
 _slist1[2] = &(BTC) - _p;  _dlist1[2] = &(DBTC) - _p;
 _slist1[3] = &(Buff2_ca) - _p;  _dlist1[3] = &(DBuff2_ca) - _p;
 _slist1[4] = &(Buff2) - _p;  _dlist1[4] = &(DBuff2) - _p;
 _slist1[5] = &(Buff1_ca) - _p;  _dlist1[5] = &(DBuff1_ca) - _p;
 _slist1[6] = &(Buff1) - _p;  _dlist1[6] = &(DBuff1) - _p;
 _slist1[7] = &(CR_1C_2N) - _p;  _dlist1[7] = &(DCR_1C_2N) - _p;
 _slist1[8] = &(CR_0C_2N) - _p;  _dlist1[8] = &(DCR_0C_2N) - _p;
 _slist1[9] = &(CR_0C_1N) - _p;  _dlist1[9] = &(DCR_0C_1N) - _p;
 _slist1[10] = &(CR_1C_1N) - _p;  _dlist1[10] = &(DCR_1C_1N) - _p;
 _slist1[11] = &(CR_2C_1N) - _p;  _dlist1[11] = &(DCR_2C_1N) - _p;
 _slist1[12] = &(CR_2C_0N) - _p;  _dlist1[12] = &(DCR_2C_0N) - _p;
 _slist1[13] = &(CAM4) - _p;  _dlist1[13] = &(DCAM4) - _p;
 _slist1[14] = &(CAM1C1N) - _p;  _dlist1[14] = &(DCAM1C1N) - _p;
 _slist1[15] = &(CAM2N1C) - _p;  _dlist1[15] = &(DCAM2N1C) - _p;
 _slist1[16] = &(CAM2N) - _p;  _dlist1[16] = &(DCAM2N) - _p;
 _slist1[17] = &(CAM1N) - _p;  _dlist1[17] = &(DCAM1N) - _p;
 _slist1[18] = &(CAM1N2C) - _p;  _dlist1[18] = &(DCAM1N2C) - _p;
 _slist1[19] = &(CAM2C) - _p;  _dlist1[19] = &(DCAM2C) - _p;
 _slist1[20] = &(CAM1C) - _p;  _dlist1[20] = &(DCAM1C) - _p;
 _slist1[21] = &(CAM0) - _p;  _dlist1[21] = &(DCAM0) - _p;
 _slist1[22] = &(CR_1V) - _p;  _dlist1[22] = &(DCR_1V) - _p;
 _slist1[23] = &(CR_2C_2N) - _p;  _dlist1[23] = &(DCR_2C_2N) - _p;
 _slist1[24] = &(CR_1C_0N) - _p;  _dlist1[24] = &(DCR_1C_0N) - _p;
 _slist1[25] = &(CR) - _p;  _dlist1[25] = &(DCR) - _p;
 _slist1[26] = &(DMNPE_ca) - _p;  _dlist1[26] = &(DDMNPE_ca) - _p;
 _slist1[27] = &(DMNPE) - _p;  _dlist1[27] = &(DDMNPE) - _p;
 _slist1[28] = &(ca) - _p;  _dlist1[28] = &(Dca) - _p;
 _slist1[29] = &(pump) - _p;  _dlist1[29] = &(Dpump) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/tylerrivera/Honors Project 2022/Honors-Project-2022/Cerebellum Model/Morphology /Morphology Protocols/Mod Files/cdp5_CR_CAM.mod";
static const char* nmodl_file_text = 
  ": Calcium ion accumulation with endogenous buffers, DCM and pump\n"
  "\n"
  "COMMENT\n"
  "\n"
  "The basic code of Example 9.8 and Example 9.9 from NEURON book was adapted as:\n"
  "\n"
  "1) Extended using parameters from Schmidt et al. 2003.\n"
  "2) Pump rate was tuned according to data from Maeda et al. 1999\n"
  "3) DCM was introduced and tuned to approximate the effect of radial diffusion\n"
  "\n"
  "Reference: Anwar H, Hong S, De Schutter E (2010) Controlling Ca2+-activated K+ channels with models of Ca2+ buffering in Purkinje cell. Cerebellum*\n"
  "\n"
  "*Article available as Open Access\n"
  "\n"
  "PubMed link: http://www.ncbi.nlm.nih.gov/pubmed/20981513\n"
  "\n"
  "Written by Haroon Anwar, Computational Neuroscience Unit, Okinawa Institute of Science and Technology, 2010.\n"
  "Contact: Haroon Anwar (anwar@oist.jp)\n"
  "\n"
  "Modified by Stefano Masoli, Department Brain and Behavioral Sciences, University of Pavia, 2015\n"
  "\n"
  "1) Buffer for Granule cell model 2015, without Parvalbumin and Calretinin instead of Calbindin.\n"
  "\n"
  "ENDCOMMENT\n"
  "\n"
  "\n"
  "NEURON {\n"
  "  SUFFIX cdp5_CR_CAM\n"
  "  USEION ca READ cao, cai, ica WRITE cai\n"
  "  USEION nr2a WRITE nr2ai VALENCE 1\n"
  "  USEION nr2c WRITE nr2ci VALENCE 1\n"
  "  USEION con_2c WRITE con_2ci VALENCE 1\n"
  "  RANGE ica_pmp\n"
  "  RANGE Nannuli, Buffnull2, rf3, rf4, vrat, cainull, CR, CR_1C_0N, CR_2C_2N, CR_1V, CRnull\n"
  "  RANGE CAM0, CAM1C, CAM2C, CAM1N2C, CAM1N, CAM2N, CAM2N1C, CAM1C1N, CAM4\n"
  "  RANGE TotalPump\n"
  "\n"
  "}\n"
  "\n"
  "\n"
  "UNITS {\n"
  "	(mol)   = (1)\n"
  "	(molar) = (1/liter)\n"
  "	(mM)    = (millimolar)\n"
  "	(um)    = (micron)\n"
  "	(mA)    = (milliamp)\n"
  "	FARADAY = (faraday)  (10000 coulomb)\n"
  "	PI      = (pi)       (1)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	Nannuli = 10.9495 (1)\n"
  "	celsius (degC)\n"
  "        \n"
  "	cainull = 45e-6 (mM)\n"
  "        mginull =.59    (mM)\n"
  "\n"
  ":	values for a buffer compensating the diffusion\n"
  "\n"
  "	Buffnull1 = 0	(mM)\n"
  "	rf1 = 0.0134329	(/ms mM)\n"
  "	rf2 = 0.0397469	(/ms)\n"
  "\n"
  "	Buffnull2 = 60.9091	(mM)\n"
  "	rf3 = 0.1435	(/ms mM)\n"
  "	rf4 = 0.0014	(/ms)\n"
  "\n"
  ":	values for benzothiazole coumarin (BTC)\n"
  "	BTCnull = 0	(mM)\n"
  "	b1 = 5.33	(/ms mM)\n"
  "	b2 = 0.08	(/ms)\n"
  "\n"
  ":	values for caged compound DMNPE-4\n"
  "	DMNPEnull = 0	(mM)\n"
  "	c1 = 5.63	(/ms mM)\n"
  "	c2 = 0.107e-3	(/ms)\n"
  "\n"
  ":       values for Calretinin (6 sites but only 5 active) (2*2 cooperative sites and 1 single indipendent site)\n"
  "\n"
  "        CRnull =	0.9             (mM):0.7-1.2\n"
  "        nT1   = 1.8            (/ms mM)\n"
  "        nT2   = 0.053        (/ms)\n"
  "        nR1   = 310           (/ms mM)\n"
  "        nR2   = 0.02        (/ms)\n"
  "        \n"
  "	nV1   = 7.3            (/ms mM)\n"
  "        nV2   = 0.24        (/ms)\n"
  "        \n"
  ":	Calmodulin concentration\n"
  "	CAM_start 	= 0.03		(mM) :Pepke 2010\n"
  "\n"
  ": 	Calmodulin Kinetic parameters. The values are the mean between max and min.\n"
  "	:C-lobe\n"
  "	Kd1C = 		0.00965	(mM)						: Kd - Equilibrium binding of 1st Ca2+ to CaM C-terminus \n"
  "	K1Coff = 	0.04	(/ms)						: From 0C to 1C with X ions on N-lobe\n"
  "	K1Con = 	5.4	(/mM ms)					: From 1C to 0C with X ions on N-lobe\n"
  "	Kd2C = 		0.00105	(mM)						: Kd - Equilibrium binding of 2nd Ca2+ to CaM C-terminus\n"
  "	K2Coff = 	0.00925	(/ms)						: From 1C to 2C with X ions on N-lobe\n"
  "	K2Con = 	15	(/mM ms)					: From 2C to 1C with X ions on N-lobe\n"
  "\n"
  "	:N-lobe\n"
  "	Kd1N = 		0.0275	(uM)						: Kd - Equilibrium binding of 1st Ca2+ to CaM N-terminus \n"
  "	K1Noff = 	2.5	(/ms)						: From 0N to 1N with X ions on C-lobe\n"
  "	K1Non = 	142.5	(/mM ms)					: From 1N to 0N with X ions on C-lobe\n"
  "	Kd2N = 		0.00615	(mM)						: Kd - Equilibrium binding of 2nd Ca2+ to CaM N-terminus\n"
  "	K2Noff = 	0.75	(/ms)						: From 1N to 2N with X ions on C-lobe\n"
  "	K2Non = 	175	(/mM ms)					: From 2N to 1N with X ions on C-lobe        \n"
  "        \n"
  "        :pumps\n"
  "\n"
  "  	kpmp1    = 3e-3       (/mM-ms)\n"
  "  	kpmp2    = 1.75e-5   (/ms)\n"
  "  	kpmp3    = 7.255e-5  (/ms)\n"
  "	TotalPump = 1e-9	(mol/cm2)	\n"
  "\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	diam      (um)\n"
  "	ica       (mA/cm2)\n"
  "	ica_pmp   (mA/cm2)\n"
  "	parea     (um)     : pump area per unit length\n"
  "	parea2	  (um)\n"
  "	cai       (mM)\n"
  "	mgi	(mM)\n"
  "	vrat	(1)	\n"
  "	nr2ai  (mM)\n"
  "	nr2ci  (mM)\n"
  "	con_2ci (mM)\n"
  "}\n"
  "\n"
  "CONSTANT { cao = 2	(mM) }\n"
  "\n"
  "STATE {\n"
  "	: ca[0] is equivalent to cai\n"
  "	: ca[] are very small, so specify absolute tolerance\n"
  "	: let it be ~1.5 - 2 orders of magnitude smaller than baseline level\n"
  "\n"
  "	ca		(mM)    <1e-3>\n"
  "	mg		(mM)	<1e-6>\n"
  "	\n"
  "	Buff1		(mM)	\n"
  "	Buff1_ca	(mM)\n"
  "\n"
  "	Buff2		(mM)\n"
  "	Buff2_ca	(mM)\n"
  "\n"
  "	BTC		(mM)\n"
  "	BTC_ca		(mM)\n"
  "\n"
  "	DMNPE		(mM)\n"
  "	DMNPE_ca	(mM)	\n"
  "        \n"
  "        :calretinin\n"
  "        \n"
  "	CR		(mM)\n"
  "	\n"
  "        CR_1C_0N	(mM)\n"
  "	CR_2C_0N	(mM)  \n"
  "	CR_2C_1N	(mM)\n"
  "	\n"
  "	CR_1C_1N	(mM)\n"
  "\n"
  "	CR_0C_1N	(mM)\n"
  "	CR_0C_2N	(mM)\n"
  "	CR_1C_2N	(mM)\n"
  "	\n"
  "	CR_2C_2N	(mM)\n"
  "	\n"
  "	CR_1V 		(mM)\n"
  "	\n"
  ":State for the Calmodulin      \n"
  "\n"
  "	CAM0		(mM)\n"
  "\n"
  "	:C-lobe mainly\n"
  "	CAM1C		(mM)\n"
  "	CAM2C		(mM)\n"
  "	CAM1N2C		(mM)\n"
  "	\n"
  "	:N-Lobe Mainly\n"
  "	CAM1N		(mM)\n"
  "	CAM2N		(mM)\n"
  "	CAM2N1C		(mM)\n"
  "\n"
  "	:One ion on C-lobe and one on N-lobe\n"
  "	CAM1C1N		(mM)\n"
  "\n"
  "	:CaM complete\n"
  "	CAM4		(mM)	\n"
  "	\n"
  "\n"
  "	:pumps\n"
  "	\n"
  "	pump		(mol/cm2) <1e-15>\n"
  "	pumpca		(mol/cm2) <1e-15>\n"
  "\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE state METHOD sparse\n"
  "}\n"
  "\n"
  "LOCAL factors_done\n"
  "\n"
  "INITIAL {\n"
  "		factors()\n"
  "\n"
  "		ca = cainull\n"
  "		mg = mginull\n"
  "		\n"
  "		Buff1 = ssBuff1()\n"
  "		Buff1_ca = ssBuff1ca()\n"
  "\n"
  "		Buff2 = ssBuff2()\n"
  "		Buff2_ca = ssBuff2ca()\n"
  "\n"
  "		BTC = ssBTC()\n"
  "		BTC_ca = ssBTCca()		\n"
  "\n"
  "		DMNPE = ssDMNPE()\n"
  "		DMNPE_ca = ssDMNPEca()\n"
  "		\n"
  "  	:to calculate the steady state of each protein at starting point\n"
  "		\n"
  "		CR 	= CRnull		\n"
  "		\n"
  "		CR_1C_0N = 0\n"
  "		CR_2C_0N = 0	 \n"
  "		CR_2C_1N = 0	\n"
  "		\n"
  "		CR_1C_1N = 0\n"
  "\n"
  "		CR_0C_1N = 0\n"
  "		CR_0C_2N = 0	\n"
  "		CR_1C_2N = 0\n"
  "		\n"
  "		CR_2C_2N = 0	\n"
  "		\n"
  "		CR_1V 	= 0	\n"
  "\n"
  "        :Calmodulin\n"
  "	CAM0	= CAM_start		\n"
  "	CAM1C	= 0\n"
  "	CAM2C	= 0\n"
  "	CAM1N2C = 0\n"
  "	CAM1N   = 0\n"
  "	CAM2N	= 0\n"
  "	CAM2N1C = 0\n"
  "	CAM1C1N = 0\n"
  "	CAM4	= 0\n"
  "		\n"
  "\n"
  "\n"
  "		\n"
  "  	parea = PI*diam\n"
  "	parea2 = PI*(diam-0.2)\n"
  "	ica = 0\n"
  "	ica_pmp = 0\n"
  ":	ica_pmp_last = 0\n"
  "	pump = TotalPump\n"
  "	pumpca = 0\n"
  "	\n"
  "	cai = ca\n"
  "	\n"
  "}\n"
  "\n"
  "PROCEDURE factors() {\n"
  "        LOCAL r, dr2\n"
  "        r = 1/2                : starts at edge (half diam)\n"
  "        dr2 = r/(Nannuli-1)/2  : full thickness of outermost annulus,\n"
  "        vrat = PI*(r-dr2/2)*2*dr2  : interior half\n"
  "        r = r - dr2\n"
  "}\n"
  "\n"
  "\n"
  "LOCAL dsq, dsqvol  : can't define local variable in KINETIC block\n"
  "                   :   or use in COMPARTMENT statement\n"
  "\n"
  "KINETIC state {\n"
  "  COMPARTMENT diam*diam*vrat {ca mg Buff1 Buff1_ca Buff2 Buff2_ca BTC BTC_ca DMNPE DMNPE_ca CR CR_1C_0N CR_2C_0N CR_2C_1N CR_0C_1N CR_0C_2N CR_1C_2N CR_1C_1N CR_2C_1N CR_1C_2N CR_2C_2N}\n"
  "  COMPARTMENT (1e10)*parea {pump pumpca}\n"
  "\n"
  "\n"
  "	:pump\n"
  "	~ ca + pump <-> pumpca  (kpmp1*parea*(1e10), kpmp2*parea*(1e10))\n"
  "	~ pumpca <-> pump   (kpmp3*parea*(1e10), 0)\n"
  "  	CONSERVE pump + pumpca = TotalPump * parea * (1e10)\n"
  "	\n"
  "	ica_pmp = 2*FARADAY*(f_flux - b_flux)/parea	\n"
  "	: all currents except pump\n"
  "	: ica is Ca efflux\n"
  "	~ ca << (-ica*PI*diam/(2*FARADAY))\n"
  "\n"
  "	:RADIAL DIFFUSION OF ca, mg and mobile buffers\n"
  "\n"
  "	dsq = diam*diam\n"
  "		dsqvol = dsq*vrat\n"
  "		~ ca + Buff1 <-> Buff1_ca (rf1*dsqvol, rf2*dsqvol)\n"
  "		~ ca + Buff2 <-> Buff2_ca (rf3*dsqvol, rf4*dsqvol)\n"
  "		~ ca + BTC <-> BTC_ca (b1*dsqvol, b2*dsqvol)\n"
  "		~ ca + DMNPE <-> DMNPE_ca (c1*dsqvol, c2*dsqvol)\n"
  "        	\n"
  "        	:Calretinin\n"
  "        	:Slow state\n"
  "		~ ca + CR <-> CR_1C_0N (nT1*dsqvol, nT2*dsqvol)\n"
  "	       	~ ca + CR_1C_0N <-> CR_2C_0N (nR1*dsqvol, nR2*dsqvol)\n"
  "	       	~ ca + CR_2C_0N <-> CR_2C_1N (nT1*dsqvol, nT2*dsqvol)\n"
  "	       	\n"
  "	       	:fast state\n"
  "		~ ca + CR <-> CR_0C_1N (nT1*dsqvol, nT2*dsqvol)\n"
  "		~ ca + CR_0C_1N <-> CR_0C_2N (nR1*dsqvol, nR2*dsqvol)\n"
  "		~ ca + CR_0C_2N <-> CR_1C_2N (nT1*dsqvol, nT2*dsqvol)\n"
  "		\n"
  "        	:complete\n"
  "        	~ ca + CR_2C_1N <-> CR_2C_2N (nR1*dsqvol, nR2*dsqvol)\n"
  "        	~ ca + CR_1C_2N <-> CR_2C_2N (nR1*dsqvol, nR2*dsqvol)\n"
  "        	\n"
  "        	:mixed\n"
  "        	~ ca + CR_1C_0N <-> CR_1C_1N (nT1*dsqvol, nT2*dsqvol)   \n"
  "		~ ca + CR_0C_1N <-> CR_1C_1N (nT1*dsqvol, nT2*dsqvol) \n"
  "		\n"
  "		~ ca + CR_1C_1N <-> CR_2C_1N (nR1*dsqvol, nR2*dsqvol)   \n"
  "		~ ca + CR_1C_1N <-> CR_1C_2N (nR1*dsqvol, nR2*dsqvol) \n"
  "        	\n"
  "        	:Fith site\n"
  "        	~ ca + CR  <-> CR_1V	     (nV1*dsqvol, nV2*dsqvol)\n"
  "        \n"
  "        :Calmodulin\n"
  "		  :C-lobe\n"
  "		~ ca + CAM0 <-> CAM1C (K1Con*dsqvol, K1Coff*dsqvol)\n"
  "		~ ca + CAM1C <-> CAM2C (K2Con*dsqvol, K2Coff*dsqvol)\n"
  "		~ ca + CAM2C <-> CAM1N2C (K1Non*dsqvol, K1Noff*dsqvol)\n"
  "		~ ca + CAM1N2C <-> CAM4 (K2Non*dsqvol, K2Noff*dsqvol) \n"
  "\n"
  "		  :N-lobe\n"
  "		~ ca + CAM0 <-> CAM1N (K1Non*dsqvol, K1Noff*dsqvol)\n"
  "		~ ca + CAM1N <-> CAM2N (K2Non*dsqvol, K2Noff*dsqvol) \n"
  "		~ ca + CAM2N <-> CAM2N1C (K1Con*dsqvol, K1Coff*dsqvol)\n"
  "		~ ca + CAM2N1C <-> CAM4 (K2Con*dsqvol, K2Coff*dsqvol)\n"
  "\n"
  "		  :Mixed C and N lobes\n"
  "		~ ca + CAM1C <-> CAM1C1N (K1Non*dsqvol, K1Noff*dsqvol) \n"
  "		~ ca + CAM1N <-> CAM1C1N (K1Con*dsqvol, K1Coff*dsqvol)\n"
  "		~ ca + CAM1C1N <-> CAM1N2C (K2Con*dsqvol, K2Coff*dsqvol)\n"
  "		~ ca + CAM1C1N <-> CAM2N1C (K2Non*dsqvol, K2Noff*dsqvol) \n"
  "\n"
  "        	\n"
  "  	cai = ca\n"
  "	mgi = mg\n"
  "	\n"
  "        nr2ai = CAM4/2\n"
  "	nr2ci = CAM4/2\n"
  "	\n"
  "	con_2ci = CAM2C\n"
  "}\n"
  "\n"
  "FUNCTION ssBuff1() (mM) {\n"
  "	ssBuff1 = Buffnull1/(1+((rf1/rf2)*cainull))\n"
  "}\n"
  "FUNCTION ssBuff1ca() (mM) {\n"
  "	ssBuff1ca = Buffnull1/(1+(rf2/(rf1*cainull)))\n"
  "}\n"
  "FUNCTION ssBuff2() (mM) {\n"
  "        ssBuff2 = Buffnull2/(1+((rf3/rf4)*cainull))\n"
  "}\n"
  "FUNCTION ssBuff2ca() (mM) {\n"
  "        ssBuff2ca = Buffnull2/(1+(rf4/(rf3*cainull)))\n"
  "}\n"
  "\n"
  "FUNCTION ssBTC() (mM) {\n"
  "	ssBTC = BTCnull/(1+((b1/b2)*cainull))\n"
  "}\n"
  "\n"
  "FUNCTION ssBTCca() (mM) {\n"
  "	ssBTCca = BTCnull/(1+(b2/(b1*cainull)))\n"
  "}\n"
  "\n"
  "FUNCTION ssDMNPE() (mM) {\n"
  "	ssDMNPE = DMNPEnull/(1+((c1/c2)*cainull))\n"
  "}\n"
  "\n"
  "FUNCTION ssDMNPEca() (mM) {\n"
  "	ssDMNPEca = DMNPEnull/(1+(c2/(c1*cainull)))\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  ;
#endif
