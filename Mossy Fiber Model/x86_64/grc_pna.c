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
 
#define nrn_init _nrn_init__GrC_pNa
#define _nrn_initial _nrn_initial__GrC_pNa
#define nrn_cur _nrn_cur__GrC_pNa
#define _nrn_current _nrn_current__GrC_pNa
#define nrn_jacob _nrn_jacob__GrC_pNa
#define nrn_state _nrn_state__GrC_pNa
#define _net_receive _net_receive__GrC_pNa 
#define _f_rate _f_rate__GrC_pNa 
#define rate rate__GrC_pNa 
#define states states__GrC_pNa 
 
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
#define Aalpha_m _p[0]
#define Kalpha_m _p[1]
#define V0alpha_m _p[2]
#define Abeta_m _p[3]
#define Kbeta_m _p[4]
#define V0beta_m _p[5]
#define V0_minf _p[6]
#define B_minf _p[7]
#define gnabar _p[8]
#define ina _p[9]
#define m_inf _p[10]
#define tau_m _p[11]
#define g _p[12]
#define alpha_m _p[13]
#define beta_m _p[14]
#define m _p[15]
#define Dm _p[16]
#define ena _p[17]
#define v _p[18]
#define _g _p[19]
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
 static void _hoc_alp_m(void);
 static void _hoc_bet_m(void);
 static void _hoc_linoid(void);
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
 "setdata_GrC_pNa", _hoc_setdata,
 "alp_m_GrC_pNa", _hoc_alp_m,
 "bet_m_GrC_pNa", _hoc_bet_m,
 "linoid_GrC_pNa", _hoc_linoid,
 "rate_GrC_pNa", _hoc_rate,
 0, 0
};
#define alp_m alp_m_GrC_pNa
#define bet_m bet_m_GrC_pNa
#define linoid linoid_GrC_pNa
 extern double alp_m( _threadargsprotocomma_ double );
 extern double bet_m( _threadargsprotocomma_ double );
 extern double linoid( _threadargsprotocomma_ double , double );
 
static void _check_rate(double*, Datum*, Datum*, _NrnThread*); 
static void _check_table_thread(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, int _type) {
   _check_rate(_p, _ppvar, _thread, _nt);
 }
 /* declare global and static user variables */
#define usetable usetable_GrC_pNa
 double usetable = 1;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "usetable_GrC_pNa", 0, 1,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "Aalpha_m_GrC_pNa", "/mV-ms",
 "Kalpha_m_GrC_pNa", "mV",
 "V0alpha_m_GrC_pNa", "mV",
 "Abeta_m_GrC_pNa", "/mV-ms",
 "Kbeta_m_GrC_pNa", "mV",
 "V0beta_m_GrC_pNa", "mV",
 "V0_minf_GrC_pNa", "mV",
 "B_minf_GrC_pNa", "mV",
 "gnabar_GrC_pNa", "mho/cm2",
 "ina_GrC_pNa", "mA/cm2",
 "tau_m_GrC_pNa", "ms",
 "g_GrC_pNa", "mho/cm2",
 "alpha_m_GrC_pNa", "/ms",
 "beta_m_GrC_pNa", "/ms",
 0,0
};
 static double delta_t = 0.01;
 static double m0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "usetable_GrC_pNa", &usetable_GrC_pNa,
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
"GrC_pNa",
 "Aalpha_m_GrC_pNa",
 "Kalpha_m_GrC_pNa",
 "V0alpha_m_GrC_pNa",
 "Abeta_m_GrC_pNa",
 "Kbeta_m_GrC_pNa",
 "V0beta_m_GrC_pNa",
 "V0_minf_GrC_pNa",
 "B_minf_GrC_pNa",
 "gnabar_GrC_pNa",
 0,
 "ina_GrC_pNa",
 "m_inf_GrC_pNa",
 "tau_m_GrC_pNa",
 "g_GrC_pNa",
 "alpha_m_GrC_pNa",
 "beta_m_GrC_pNa",
 0,
 "m_GrC_pNa",
 0,
 0};
 static Symbol* _na_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 20, _prop);
 	/*initialize range parameters*/
 	Aalpha_m = -0.091;
 	Kalpha_m = -5;
 	V0alpha_m = -42;
 	Abeta_m = 0.062;
 	Kbeta_m = 5;
 	V0beta_m = -42;
 	V0_minf = -42;
 	B_minf = 5;
 	gnabar = 2e-05;
 	_prop->param = _p;
 	_prop->param_size = 20;
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

 void _grc_pna_reg() {
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
     _nrn_thread_table_reg(_mechtype, _check_table_thread);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 20, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 GrC_pNa /Users/tylerrivera/Honors Project 2022/Honors-Project-2022/Mossy Fiber Model/grc_pna.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double *_t_m_inf;
 static double *_t_tau_m;
static int _reset;
static char *modelname = "Cerebellum Granule Cell Model, pNa channel";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int _f_rate(_threadargsprotocomma_ double);
static int rate(_threadargsprotocomma_ double);
 
#define _deriv1_advance _thread[0]._i
#define _dith1 1
#define _recurse _thread[2]._i
#define _newtonspace1 _thread[3]._pvoid
extern void* nrn_cons_newtonspace(int);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static void _n_rate(_threadargsprotocomma_ double _lv);
 static int _slist2[1];
  static int _slist1[1], _dlist1[1];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   rate ( _threadargscomma_ v ) ;
   Dm = ( m_inf - m ) / tau_m ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rate ( _threadargscomma_ v ) ;
 Dm = Dm  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_m )) ;
  return 0;
}
 /*END CVODE*/
 
static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0; int error = 0;
 { double* _savstate1 = _thread[_dith1]._pval;
 double* _dlist2 = _thread[_dith1]._pval + 1;
 int _counte = -1;
 if (!_recurse) {
 _recurse = 1;
 {int _id; for(_id=0; _id < 1; _id++) { _savstate1[_id] = _p[_slist1[_id]];}}
 error = nrn_newton_thread(_newtonspace1, 1,_slist2, _p, states, _dlist2, _ppvar, _thread, _nt);
 _recurse = 0; if(error) {abort_run(error);}}
 {
   rate ( _threadargscomma_ v ) ;
   Dm = ( m_inf - m ) / tau_m ;
   {int _id; for(_id=0; _id < 1; _id++) {
if (_deriv1_advance) {
 _dlist2[++_counte] = _p[_dlist1[_id]] - (_p[_slist1[_id]] - _savstate1[_id])/dt;
 }else{
_dlist2[++_counte] = _p[_slist1[_id]] - _savstate1[_id];}}}
 } }
 return _reset;}
 
double alp_m ( _threadargsprotocomma_ double _lv ) {
   double _lalp_m;
 double _lQ10 ;
 _lQ10 = pow( 3.0 , ( ( celsius - 30.0 ) / 10.0 ) ) ;
   _lalp_m = _lQ10 * Aalpha_m * linoid ( _threadargscomma_ _lv - V0alpha_m , Kalpha_m ) ;
   
return _lalp_m;
 }
 
static void _hoc_alp_m(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alp_m ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double bet_m ( _threadargsprotocomma_ double _lv ) {
   double _lbet_m;
 double _lQ10 ;
 _lQ10 = pow( 3.0 , ( ( celsius - 30.0 ) / 10.0 ) ) ;
   _lbet_m = _lQ10 * Abeta_m * linoid ( _threadargscomma_ _lv - V0beta_m , Kbeta_m ) ;
   
return _lbet_m;
 }
 
static void _hoc_bet_m(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  bet_m ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 static double _mfac_rate, _tmin_rate;
  static void _check_rate(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  static int _maktable=1; int _i, _j, _ix = 0;
  double _xi, _tmax;
  static double _sav_Aalpha_m;
  static double _sav_Kalpha_m;
  static double _sav_V0alpha_m;
  static double _sav_Abeta_m;
  static double _sav_Kbeta_m;
  static double _sav_V0beta_m;
  static double _sav_celsius;
  if (!usetable) {return;}
  if (_sav_Aalpha_m != Aalpha_m) { _maktable = 1;}
  if (_sav_Kalpha_m != Kalpha_m) { _maktable = 1;}
  if (_sav_V0alpha_m != V0alpha_m) { _maktable = 1;}
  if (_sav_Abeta_m != Abeta_m) { _maktable = 1;}
  if (_sav_Kbeta_m != Kbeta_m) { _maktable = 1;}
  if (_sav_V0beta_m != V0beta_m) { _maktable = 1;}
  if (_sav_celsius != celsius) { _maktable = 1;}
  if (_maktable) { double _x, _dx; _maktable=0;
   _tmin_rate =  - 100.0 ;
   _tmax =  100.0 ;
   _dx = (_tmax - _tmin_rate)/200.; _mfac_rate = 1./_dx;
   for (_i=0, _x=_tmin_rate; _i < 201; _x += _dx, _i++) {
    _f_rate(_p, _ppvar, _thread, _nt, _x);
    _t_m_inf[_i] = m_inf;
    _t_tau_m[_i] = tau_m;
   }
   _sav_Aalpha_m = Aalpha_m;
   _sav_Kalpha_m = Kalpha_m;
   _sav_V0alpha_m = V0alpha_m;
   _sav_Abeta_m = Abeta_m;
   _sav_Kbeta_m = Kbeta_m;
   _sav_V0beta_m = V0beta_m;
   _sav_celsius = celsius;
  }
 }

 static int rate(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _lv) { 
#if 0
_check_rate(_p, _ppvar, _thread, _nt);
#endif
 _n_rate(_p, _ppvar, _thread, _nt, _lv);
 return 0;
 }

 static void _n_rate(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _lv){ int _i, _j;
 double _xi, _theta;
 if (!usetable) {
 _f_rate(_p, _ppvar, _thread, _nt, _lv); return; 
}
 _xi = _mfac_rate * (_lv - _tmin_rate);
 if (isnan(_xi)) {
  m_inf = _xi;
  tau_m = _xi;
  return;
 }
 if (_xi <= 0.) {
 m_inf = _t_m_inf[0];
 tau_m = _t_tau_m[0];
 return; }
 if (_xi >= 200.) {
 m_inf = _t_m_inf[200];
 tau_m = _t_tau_m[200];
 return; }
 _i = (int) _xi;
 _theta = _xi - (double)_i;
 m_inf = _t_m_inf[_i] + _theta*(_t_m_inf[_i+1] - _t_m_inf[_i]);
 tau_m = _t_tau_m[_i] + _theta*(_t_tau_m[_i+1] - _t_tau_m[_i]);
 }

 
static int  _f_rate ( _threadargsprotocomma_ double _lv ) {
   double _la_m , _lb_m ;
 _la_m = alp_m ( _threadargscomma_ _lv ) ;
   _lb_m = bet_m ( _threadargscomma_ _lv ) ;
   if ( ( - ( _lv - V0_minf ) / B_minf ) > 200.0 ) {
     m_inf = 1.0 / ( 1.0 + exp ( 200.0 ) ) ;
     }
   else {
     m_inf = 1.0 / ( 1.0 + exp ( - ( _lv - V0_minf ) / B_minf ) ) ;
     }
   tau_m = 5.0 / ( _la_m + _lb_m ) ;
    return 0; }
 
static void _hoc_rate(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 
#if 1
 _check_rate(_p, _ppvar, _thread, _nt);
#endif
 _r = 1.;
 rate ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double linoid ( _threadargsprotocomma_ double _lx , double _ly ) {
   double _llinoid;
 if ( fabs ( _lx / _ly ) < 1e-6 ) {
     _llinoid = _ly * ( 1.0 - _lx / _ly / 2.0 ) ;
     }
   else {
     if ( _lx / _ly > 200.0 ) {
       _llinoid = _lx / ( exp ( 200.0 ) - 1.0 ) ;
       }
     else {
       _llinoid = _lx / ( exp ( _lx / _ly ) - 1.0 ) ;
       }
     }
   
return _llinoid;
 }
 
static void _hoc_linoid(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  linoid ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 1;}
 
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
	for (_i=0; _i < 1; ++_i) {
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
   _thread[_dith1]._pval = (double*)ecalloc(2, sizeof(double));
   _newtonspace1 = nrn_cons_newtonspace(1);
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
  m = m0;
 {
   rate ( _threadargscomma_ v ) ;
   m = m_inf ;
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

#if 0
 _check_rate(_p, _ppvar, _thread, _nt);
#endif
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
   g = gnabar * m ;
   ina = g * ( v - ena ) ;
   alpha_m = alp_m ( _threadargscomma_ v ) ;
   beta_m = bet_m ( _threadargscomma_ v ) ;
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
 derivimplicit_thread(1, _slist1, _dlist1, _p, states, _ppvar, _thread, _nt);
_deriv1_advance = 0;
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 1; ++_i) {
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
 _slist1[0] = &(m) - _p;  _dlist1[0] = &(Dm) - _p;
 _slist2[0] = &(m) - _p;
   _t_m_inf = makevector(201*sizeof(double));
   _t_tau_m = makevector(201*sizeof(double));
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/tylerrivera/Honors Project 2022/Honors-Project-2022/Mossy Fiber Model/grc_pna.mod";
static const char* nmodl_file_text = 
  "TITLE Cerebellum Granule Cell Model, pNa channel\n"
  "\n"
  "COMMENT\n"
  "Reference: E.D'Angelo, T.Nieus, A. Maffei, S. Armano, P. Rossi,\n"
  "V. Taglietti, A. Fontana, G. Naldi \"Theta-frequency bursting and \n"
  "resonance in cerebellar granule cells: experimental evidence and \n"
  "modeling of a slow K+-dependent mechanism\", J. neurosci., 2001,\n"
  "21,P. 759-770.\n"
  "ENDCOMMENT\n"
  " \n"
  "NEURON { \n"
  "	SUFFIX GrC_pNa \n"
  "	USEION na READ ena WRITE ina \n"
  "	RANGE gnabar, ina, g, alpha_m, beta_m\n"
  "	RANGE Aalpha_m, Kalpha_m, V0alpha_m\n"
  "	RANGE Abeta_m, Kbeta_m, V0beta_m\n"
  "	RANGE V0_minf, B_minf\n"
  "	RANGE m_inf, tau_m\n"
  "} \n"
  " \n"
  "UNITS { \n"
  "	(mA) = (milliamp) \n"
  "	(mV) = (millivolt) \n"
  "} \n"
  " \n"
  "PARAMETER { \n"
  "	Aalpha_m = -0.091 (/mV-ms) \n"
  "	Kalpha_m = -5 (mV)\n"
  "	V0alpha_m = -42 (mV)\n"
  "	Abeta_m = 0.062 (/mV-ms)  \n"
  "	Kbeta_m = 5 (mV)\n"
  "	V0beta_m = -42 (mV)\n"
  "	V0_minf = -42 (mV)\n"
  "	B_minf = 5 (mV)\n"
  "	gnabar= 2e-5 (mho/cm2)  \n"
  "} \n"
  "\n"
  "STATE { \n"
  "	m \n"
  "} \n"
  "\n"
  "ASSIGNED { \n"
  "	ina (mA/cm2) \n"
  "	m_inf \n"
  "	tau_m (ms) \n"
  "	g (mho/cm2) \n"
  "	alpha_m (/ms)\n"
  "	beta_m (/ms)\n"
  "      ena (mV)\n"
  "      celsius (degC) \n"
  "      v (mV) \n"
  "} \n"
  " \n"
  "INITIAL { \n"
  "	rate(v) \n"
  "	m = m_inf \n"
  "} \n"
  " \n"
  "BREAKPOINT { \n"
  "	SOLVE states METHOD derivimplicit \n"
  "	g = gnabar*m \n"
  "	ina = g*(v - ena) \n"
  "	alpha_m = alp_m(v)\n"
  "	beta_m = bet_m(v)\n"
  "} \n"
  " \n"
  "DERIVATIVE states { \n"
  "	rate(v) \n"
  "	m' =(m_inf - m)/tau_m \n"
  "} \n"
  "\n"
  "FUNCTION alp_m(v(mV))(/ms) { LOCAL Q10\n"
  "	Q10 = 3^((celsius-30(degC))/10(degC))\n"
  "	alp_m = Q10 * Aalpha_m*linoid(v-V0alpha_m, Kalpha_m) \n"
  "} \n"
  " \n"
  "FUNCTION bet_m(v(mV))(/ms) { LOCAL Q10\n"
  "	Q10 = 3^((celsius-30(degC))/10(degC))\n"
  "	bet_m = Q10 * Abeta_m*linoid(v-V0beta_m, Kbeta_m) \n"
  "} \n"
  " \n"
  "PROCEDURE rate(v (mV)) {LOCAL a_m, b_m \n"
  "	TABLE m_inf, tau_m \n"
  "	DEPEND Aalpha_m, Kalpha_m, V0alpha_m, \n"
  "	       Abeta_m, Kbeta_m, V0beta_m, celsius FROM -100 TO 100 WITH 200 \n"
  "	a_m = alp_m(v)  \n"
  "	b_m = bet_m(v)  \n"
  "if((-(v-V0_minf)/B_minf)>200){\n"
  "m_inf = 1/(1+exp(200))\n"
  "}else{\n"
  "	m_inf = 1/(1+exp(-(v-V0_minf)/B_minf))\n"
  "}\n"
  "	tau_m = 5/(a_m + b_m) \n"
  "} \n"
  "\n"
  "FUNCTION linoid(x (mV),y (mV)) (mV) {\n"
  "        if (fabs(x/y) < 1e-6) {\n"
  "        linoid = y*(1 - x/y/2)\n"
  "        }else{\n"
  "if(x/y>200){\n"
  "linoid = x/(exp(200) - 1)\n"
  "}else{\n"
  "        linoid = x/(exp(x/y) - 1)\n"
  "        }\n"
  "}\n"
  "}\n"
  "\n"
  "\n"
  ;
#endif
