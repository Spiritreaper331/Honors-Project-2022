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
 
#define nrn_init _nrn_init__GrG_Nar
#define _nrn_initial _nrn_initial__GrG_Nar
#define nrn_cur _nrn_cur__GrG_Nar
#define _nrn_current _nrn_current__GrG_Nar
#define nrn_jacob _nrn_jacob__GrG_Nar
#define nrn_state _nrn_state__GrG_Nar
#define _net_receive _net_receive__GrG_Nar 
#define rate rate__GrG_Nar 
#define states states__GrG_Nar 
 
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
#define Aalpha_s _p[0]
#define V0alpha_s _p[1]
#define Kalpha_s _p[2]
#define Shiftalpha_s _p[3]
#define Abeta_s _p[4]
#define V0beta_s _p[5]
#define Kbeta_s _p[6]
#define Shiftbeta_s _p[7]
#define Aalpha_f _p[8]
#define V0alpha_f _p[9]
#define Kalpha_f _p[10]
#define Abeta_f _p[11]
#define V0beta_f _p[12]
#define Kbeta_f _p[13]
#define gnabar _p[14]
#define ina _p[15]
#define g _p[16]
#define s_inf _p[17]
#define tau_s _p[18]
#define f_inf _p[19]
#define tau_f _p[20]
#define s _p[21]
#define f _p[22]
#define Ds _p[23]
#define Df _p[24]
#define alpha_s _p[25]
#define beta_s _p[26]
#define alpha_f _p[27]
#define beta_f _p[28]
#define ena _p[29]
#define v _p[30]
#define _g _p[31]
#define _ion_ena	*_ppvar[0]._pval
#define _ion_ina	*_ppvar[1]._pval
#define _ion_dinadv	*_ppvar[2]._pval
 
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
 static void _hoc_alp_f(void);
 static void _hoc_alp_s(void);
 static void _hoc_bet_f(void);
 static void _hoc_bet_s(void);
 static void _hoc_rate(void);
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
 "setdata_GrG_Nar", _hoc_setdata,
 "alp_f_GrG_Nar", _hoc_alp_f,
 "alp_s_GrG_Nar", _hoc_alp_s,
 "bet_f_GrG_Nar", _hoc_bet_f,
 "bet_s_GrG_Nar", _hoc_bet_s,
 "rate_GrG_Nar", _hoc_rate,
 0, 0
};
#define alp_f alp_f_GrG_Nar
#define alp_s alp_s_GrG_Nar
#define bet_f bet_f_GrG_Nar
#define bet_s bet_s_GrG_Nar
 extern double alp_f( _threadargsprotocomma_ double );
 extern double alp_s( _threadargsprotocomma_ double );
 extern double bet_f( _threadargsprotocomma_ double );
 extern double bet_s( _threadargsprotocomma_ double );
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "Aalpha_s_GrG_Nar", "/ms",
 "V0alpha_s_GrG_Nar", "mV",
 "Kalpha_s_GrG_Nar", "mV",
 "Shiftalpha_s_GrG_Nar", "/ms",
 "Abeta_s_GrG_Nar", "/ms",
 "V0beta_s_GrG_Nar", "mV",
 "Kbeta_s_GrG_Nar", "mV",
 "Shiftbeta_s_GrG_Nar", "/ms",
 "Aalpha_f_GrG_Nar", "/ms",
 "V0alpha_f_GrG_Nar", "mV",
 "Kalpha_f_GrG_Nar", "mV",
 "Abeta_f_GrG_Nar", "/ms",
 "V0beta_f_GrG_Nar", "mV",
 "Kbeta_f_GrG_Nar", "mV",
 "gnabar_GrG_Nar", "mho/cm2",
 "ina_GrG_Nar", "mA/cm2",
 "g_GrG_Nar", "mho/cm2",
 "tau_s_GrG_Nar", "ms",
 "tau_f_GrG_Nar", "ms",
 0,0
};
 static double delta_t = 0.01;
 static double f0 = 0;
 static double s0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
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
 
#define _cvode_ieq _ppvar[3]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"GrG_Nar",
 "Aalpha_s_GrG_Nar",
 "V0alpha_s_GrG_Nar",
 "Kalpha_s_GrG_Nar",
 "Shiftalpha_s_GrG_Nar",
 "Abeta_s_GrG_Nar",
 "V0beta_s_GrG_Nar",
 "Kbeta_s_GrG_Nar",
 "Shiftbeta_s_GrG_Nar",
 "Aalpha_f_GrG_Nar",
 "V0alpha_f_GrG_Nar",
 "Kalpha_f_GrG_Nar",
 "Abeta_f_GrG_Nar",
 "V0beta_f_GrG_Nar",
 "Kbeta_f_GrG_Nar",
 "gnabar_GrG_Nar",
 0,
 "ina_GrG_Nar",
 "g_GrG_Nar",
 "s_inf_GrG_Nar",
 "tau_s_GrG_Nar",
 "f_inf_GrG_Nar",
 "tau_f_GrG_Nar",
 0,
 "s_GrG_Nar",
 "f_GrG_Nar",
 0,
 0};
 static Symbol* _na_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 32, _prop);
 	/*initialize range parameters*/
 	Aalpha_s = -0.00493;
 	V0alpha_s = -4.48754;
 	Kalpha_s = -6.81881;
 	Shiftalpha_s = 8e-05;
 	Abeta_s = 0.01558;
 	V0beta_s = 43.9749;
 	Kbeta_s = 0.10818;
 	Shiftbeta_s = 0.04752;
 	Aalpha_f = 0.31836;
 	V0alpha_f = -80;
 	Kalpha_f = -62.5262;
 	Abeta_f = 0.01014;
 	V0beta_f = -83.3332;
 	Kbeta_f = 16.0538;
 	gnabar = 0.0005;
 	_prop->param = _p;
 	_prop->param_size = 32;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ena */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
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

 void _grg_nar_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("na", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 5);
  _extcall_thread = (Datum*)ecalloc(4, sizeof(Datum));
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
  hoc_register_prop_size(_mechtype, 32, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 GrG_Nar /Users/tylerrivera/Honors Project 2022/Honors-Project-2022/Mossy Fiber Model/grg_nar.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Cerebellum Granule Cell Model, Na resurgent channel";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rate(_threadargsprotocomma_ double);
 
#define _deriv1_advance _thread[0]._i
#define _dith1 1
#define _recurse _thread[2]._i
#define _newtonspace1 _thread[3]._pvoid
extern void* nrn_cons_newtonspace(int);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist2[2];
  static int _slist1[2], _dlist1[2];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   rate ( _threadargscomma_ v ) ;
   Ds = ( s_inf - s ) / tau_s ;
   Df = ( f_inf - f ) / tau_f ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rate ( _threadargscomma_ v ) ;
 Ds = Ds  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_s )) ;
 Df = Df  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_f )) ;
  return 0;
}
 /*END CVODE*/
 
static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0; int error = 0;
 { double* _savstate1 = _thread[_dith1]._pval;
 double* _dlist2 = _thread[_dith1]._pval + 2;
 int _counte = -1;
 if (!_recurse) {
 _recurse = 1;
 {int _id; for(_id=0; _id < 2; _id++) { _savstate1[_id] = _p[_slist1[_id]];}}
 error = nrn_newton_thread(_newtonspace1, 2,_slist2, _p, states, _dlist2, _ppvar, _thread, _nt);
 _recurse = 0; if(error) {abort_run(error);}}
 {
   rate ( _threadargscomma_ v ) ;
   Ds = ( s_inf - s ) / tau_s ;
   Df = ( f_inf - f ) / tau_f ;
   {int _id; for(_id=0; _id < 2; _id++) {
if (_deriv1_advance) {
 _dlist2[++_counte] = _p[_dlist1[_id]] - (_p[_slist1[_id]] - _savstate1[_id])/dt;
 }else{
_dlist2[++_counte] = _p[_slist1[_id]] - _savstate1[_id];}}}
 } }
 return _reset;}
 
static int  rate ( _threadargsprotocomma_ double _lv ) {
   double _la_s , _lb_s , _la_f , _lb_f ;
 _la_s = alp_s ( _threadargscomma_ _lv ) ;
   _lb_s = bet_s ( _threadargscomma_ _lv ) ;
   s_inf = _la_s / ( _la_s + _lb_s ) ;
   tau_s = 1.0 / ( _la_s + _lb_s ) ;
   _la_f = alp_f ( _threadargscomma_ _lv ) ;
   _lb_f = bet_f ( _threadargscomma_ _lv ) ;
   f_inf = _la_f / ( _la_f + _lb_f ) ;
   tau_f = 1.0 / ( _la_f + _lb_f ) ;
    return 0; }
 
static void _hoc_rate(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 rate ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double alp_s ( _threadargsprotocomma_ double _lv ) {
   double _lalp_s;
 double _lQ10 ;
 _lQ10 = pow( 3.0 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   if ( ( _lv + V0alpha_s ) / Kalpha_s > 200.0 ) {
     _lalp_s = _lQ10 * ( Shiftalpha_s + Aalpha_s * ( ( _lv + V0alpha_s ) / 1.0 ) / ( exp ( 200.0 ) - 1.0 ) ) ;
     }
   else {
     _lalp_s = _lQ10 * ( Shiftalpha_s + Aalpha_s * ( ( _lv + V0alpha_s ) / 1.0 ) / ( exp ( ( _lv + V0alpha_s ) / Kalpha_s ) - 1.0 ) ) ;
     }
   
return _lalp_s;
 }
 
static void _hoc_alp_s(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alp_s ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double bet_s ( _threadargsprotocomma_ double _lv ) {
   double _lbet_s;
 double _lQ10 ;
 _lQ10 = pow( 3.0 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   if ( ( ( _lv + V0beta_s ) / Kbeta_s ) > 200.0 ) {
     _lbet_s = _lQ10 * ( Shiftbeta_s + Abeta_s * ( ( _lv + V0beta_s ) / 1.0 ) / ( exp ( 200.0 ) - 1.0 ) ) ;
     }
   else {
     _lbet_s = _lQ10 * ( Shiftbeta_s + Abeta_s * ( ( _lv + V0beta_s ) / 1.0 ) / ( exp ( ( _lv + V0beta_s ) / Kbeta_s ) - 1.0 ) ) ;
     }
   
return _lbet_s;
 }
 
static void _hoc_bet_s(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  bet_s ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double alp_f ( _threadargsprotocomma_ double _lv ) {
   double _lalp_f;
 double _lQ10 ;
 _lQ10 = pow( 3.0 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   if ( ( _lv - V0alpha_f ) / Kalpha_f > 200.0 ) {
     _lalp_f = _lQ10 * Aalpha_f * exp ( 200.0 ) ;
     }
   else {
     _lalp_f = _lQ10 * Aalpha_f * exp ( ( _lv - V0alpha_f ) / Kalpha_f ) ;
     }
   
return _lalp_f;
 }
 
static void _hoc_alp_f(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alp_f ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double bet_f ( _threadargsprotocomma_ double _lv ) {
   double _lbet_f;
 double _lQ10 ;
 _lQ10 = pow( 3.0 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   if ( ( _lv - V0beta_f ) / Kbeta_f > 200.0 ) {
     _lbet_f = _lQ10 * Abeta_f * exp ( 200.0 ) ;
     }
   else {
     _lbet_f = _lQ10 * Abeta_f * exp ( ( _lv - V0beta_f ) / Kbeta_f ) ;
     }
   
return _lbet_f;
 }
 
static void _hoc_bet_f(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  bet_f ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 2;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ena = _ion_ena;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 2; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
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
  ena = _ion_ena;
 _ode_matsol_instance1(_threadargs_);
 }}
 
static void _thread_mem_init(Datum* _thread) {
   _thread[_dith1]._pval = (double*)ecalloc(4, sizeof(double));
   _newtonspace1 = nrn_cons_newtonspace(2);
 }
 
static void _thread_cleanup(Datum* _thread) {
   free((void*)(_thread[_dith1]._pval));
   nrn_destroy_newtonspace(_newtonspace1);
 }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_na_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_na_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 2, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  f = f0;
  s = s0;
 {
   rate ( _threadargscomma_ v ) ;
   s = s_inf ;
   f = f_inf ;
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
  ena = _ion_ena;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   g = gnabar * s * f ;
   ina = g * ( v - ena ) ;
   alpha_s = alp_s ( _threadargscomma_ v ) ;
   beta_s = bet_s ( _threadargscomma_ v ) ;
   alpha_f = alp_f ( _threadargscomma_ v ) ;
   beta_f = bet_f ( _threadargscomma_ v ) ;
   }
 _current += ina;

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
  ena = _ion_ena;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dina;
  _dina = ina;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dinadv += (_dina - ina)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
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
  ena = _ion_ena;
 {  _deriv1_advance = 1;
 derivimplicit_thread(2, _slist1, _dlist1, _p, states, _ppvar, _thread, _nt);
_deriv1_advance = 0;
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 2; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 } }}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(s) - _p;  _dlist1[0] = &(Ds) - _p;
 _slist1[1] = &(f) - _p;  _dlist1[1] = &(Df) - _p;
 _slist2[0] = &(f) - _p;
 _slist2[1] = &(s) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/tylerrivera/Honors Project 2022/Honors-Project-2022/Mossy Fiber Model/grg_nar.mod";
static const char* nmodl_file_text = 
  "TITLE Cerebellum Granule Cell Model, Na resurgent channel\n"
  "\n"
  "COMMENT	  \n"
  "Reference: E.D'Angelo, T.Nieus, A. Maffei, S. Armano, P. Rossi,\n"
  "V. Taglietti, A. Fontana, G. Naldi \"Theta-frequency bursting and \n"
  "resonance in cerebellar granule cells: experimental evidence and \n"
  "modeling of a slow K+-dependent mechanism\", J. neurosci., 2001,\n"
  "21,P. 759-770.\n"
  "ENDCOMMENT\n"
  " \n"
  "NEURON { \n"
  "	SUFFIX GrG_Nar\n"
  "	USEION na READ ena WRITE ina \n"
  "	RANGE gnabar, ina, g\n"
  "	RANGE Aalpha_s,Abeta_s,V0alpha_s,V0beta_s,Kalpha_s,Kbeta_s \n"
  "      RANGE Shiftalpha_s,Shiftbeta_s,tau_s,s_inf\n"
  "	RANGE Aalpha_f,Abeta_f,V0alpha_f,V0beta_f,Kalpha_f, Kbeta_f\n"
  "	RANGE tau_f,f_inf\n"
  "} \n"
  " \n"
  "UNITS {    \n"
  "	(mA) = (milliamp) \n"
  "	(mV) = (millivolt) \n"
  "} \n"
  " \n"
  "PARAMETER { \n"
  "	\n"
  "	: s-ALFA\n"
  "	Aalpha_s = -0.00493 (/ms)\n"
  "	V0alpha_s = -4.48754 (mV)\n"
  "	Kalpha_s = -6.81881 (mV)\n"
  "	Shiftalpha_s = 0.00008 (/ms)\n"
  "\n"
  "	: s-BETA\n"
  "	Abeta_s = 0.01558 (/ms)\n"
  "	V0beta_s = 43.97494 (mV)\n"
  "	Kbeta_s =  0.10818 (mV)\n"
  "	Shiftbeta_s = 0.04752 (/ms)\n"
  "\n"
  "	: f-ALFA\n"
  "	Aalpha_f = 0.31836 (/ms)\n"
  "	V0alpha_f = -80 (mV)\n"
  "	Kalpha_f = -62.52621 (mV)\n"
  "\n"
  "	: f-BETA\n"
  "	Abeta_f = 0.01014 (/ms)\n"
  "	V0beta_f = -83.3332 (mV)\n"
  "	Kbeta_f = 16.05379 (mV)\n"
  "\n"
  "	gnabar= 0.0005 (mho/cm2)\n"
  "	\n"
  "} \n"
  "\n"
  "STATE { \n"
  "	s \n"
  "	f\n"
  "} \n"
  "\n"
  "ASSIGNED { \n"
  "	ina (mA/cm2) \n"
  "	g (mho/cm2) \n"
  "      alpha_s (/ms)\n"
  "	beta_s (/ms)\n"
  "	s_inf\n"
  "	tau_s (ms)\n"
  "	alpha_f (/ms)\n"
  "	beta_f (/ms)\n"
  "	f_inf\n"
  "	tau_f (ms) \n"
  "      ena(mV)\n"
  "      celsius (degC) \n"
  "      v (mV) \n"
  "} \n"
  " \n"
  "INITIAL { \n"
  "	rate(v) \n"
  "      s = s_inf\n"
  "	f = f_inf\n"
  "} \n"
  " \n"
  "BREAKPOINT { \n"
  "	SOLVE states METHOD derivimplicit \n"
  "	g = gnabar*s*f\n"
  "	ina = g*(v - ena)\n"
  "\n"
  "	alpha_s = alp_s(v)\n"
  "	beta_s = bet_s(v) \n"
  "\n"
  "	alpha_f = alp_f(v)\n"
  "	beta_f = bet_f(v) \n"
  "} \n"
  " \n"
  "DERIVATIVE states { \n"
  "	rate(v) \n"
  "	s' = ( s_inf - s ) / tau_s \n"
  "	f' = ( f_inf - f ) / tau_f \n"
  "} \n"
  " \n"
  "PROCEDURE rate(v (mV)) { LOCAL a_s,b_s,a_f,b_f\n"
  "\n"
  "	a_s = alp_s(v)  \n"
  "	b_s = bet_s(v) \n"
  "	s_inf = a_s / ( a_s + b_s ) \n"
  "	tau_s = 1 / ( a_s + b_s ) \n"
  "\n"
  "	a_f = alp_f(v)  \n"
  "	b_f = bet_f(v) \n"
  "	f_inf = a_f / ( a_f + b_f ) \n"
  "	tau_f = 1 / ( a_f + b_f ) \n"
  "} \n"
  "\n"
  "\n"
  "\n"
  "FUNCTION alp_s(v (mV)) (/ms){ LOCAL Q10\n"
  "	Q10 = 3^( ( celsius - 20 (degC) ) / 10 (degC) )\n"
  "if((v+V0alpha_s)/Kalpha_s >200){\n"
  "alp_s = Q10*(Shiftalpha_s+Aalpha_s*((v+V0alpha_s)/ 1 (mV) )/\n"
  "(exp(200)-1))\n"
  "}else{\n"
  "	alp_s = Q10*(Shiftalpha_s+Aalpha_s*((v+V0alpha_s)/ 1 (mV) )/(exp((v+V0alpha_s)/Kalpha_s)-1))\n"
  "}\n"
  "}\n"
  "FUNCTION bet_s(v (mV)) (/ms){ LOCAL Q10\n"
  "	Q10 = 3^((celsius-20(degC))/10(degC))\n"
  "if(((v+V0beta_s)/Kbeta_s)>200){\n"
  "bet_s =	Q10*(Shiftbeta_s+Abeta_s*((v+V0beta_s)/1 (mV) )/\n"
  "(exp(200)-1))\n"
  "}else{	\n"
  "	bet_s =	Q10*(Shiftbeta_s+Abeta_s*((v+V0beta_s)/1 (mV) )/(exp((v+V0beta_s)/Kbeta_s)-1))\n"
  "}\n"
  "}\n"
  "\n"
  "FUNCTION alp_f(v (mV)) (/ms){ LOCAL Q10\n"
  "	Q10 = 3^( ( celsius - 20 (degC) ) / 10 (degC) )\n"
  "if(( v - V0alpha_f )/Kalpha_f >200){\n"
  "alp_f =	Q10 * Aalpha_f * exp(200)\n"
  "}else{\n"
  "	alp_f =	Q10 * Aalpha_f * exp(( v - V0alpha_f )/Kalpha_f)\n"
  "}\n"
  "}\n"
  "FUNCTION bet_f(v (mV)) (/ms){ LOCAL Q10\n"
  "	Q10 = 3^( ( celsius - 20 (degC) ) / 10 (degC) )\n"
  "if(( v - V0beta_f )/Kbeta_f >200){\n"
  "bet_f =	Q10 * Abeta_f * exp(200)	\n"
  "}else{\n"
  "	bet_f =	Q10 * Abeta_f * exp(( v - V0beta_f )/Kbeta_f )	\n"
  "}\n"
  "}\n"
  "\n"
  ;
#endif
