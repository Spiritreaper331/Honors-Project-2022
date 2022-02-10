/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
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
 
#define nrn_init _nrn_init__GrC_AMPA
#define _nrn_initial _nrn_initial__GrC_AMPA
#define nrn_cur _nrn_cur__GrC_AMPA
#define _nrn_current _nrn_current__GrC_AMPA
#define nrn_jacob _nrn_jacob__GrC_AMPA
#define nrn_state _nrn_state__GrC_AMPA
#define _net_receive _net_receive__GrC_AMPA 
#define states states__GrC_AMPA 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define Erev _p[0]
#define gbarampa _p[1]
#define freqdel _p[2]
#define iampa _p[3]
#define gampa _p[4]
#define St1ampa _p[5]
#define St2ampa _p[6]
#define St3ampa _p[7]
#define St4ampa _p[8]
#define St5ampa _p[9]
#define St6ampa _p[10]
#define St7ampa _p[11]
#define DSt1ampa _p[12]
#define DSt2ampa _p[13]
#define DSt3ampa _p[14]
#define DSt4ampa _p[15]
#define DSt5ampa _p[16]
#define DSt6ampa _p[17]
#define DSt7ampa _p[18]
#define _g _p[19]
#define _nd_area  *_ppvar[0]._pval
#define pNp	*_ppvar[2]._pval
#define _p_pNp	_ppvar[2]._pval
#define pNd	*_ppvar[3]._pval
#define _p_pNd	_ppvar[3]._pval
#define pglu	*_ppvar[4]._pval
#define _p_pglu	_ppvar[4]._pval
 
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
 static int hoc_nrnpointerindex =  2;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
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

 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(_ho) Object* _ho; { void* create_point_process();
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt();
 static double _hoc_loc_pnt(_vptr) void* _vptr; {double loc_point_process();
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(_vptr) void* _vptr; {double has_loc_point();
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(_vptr)void* _vptr; {
 double get_loc_point_process(); return (get_loc_point_process(_vptr));
}
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 0,0
};
 static Member_func _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 0, 0
};
 /* declare global and static user variables */
#define cam_7_3 cam_7_3_GrC_AMPA
 double cam_7_3 = 0.0281;
#define cam_6_7 cam_6_7_GrC_AMPA
 double cam_6_7 = 0.0571;
#define cam_6_5 cam_6_5_GrC_AMPA
 double cam_6_5 = 0.00815;
#define cam_6_2 cam_6_2_GrC_AMPA
 double cam_6_2 = 0.000546;
#define cam_5_6 cam_5_6_GrC_AMPA
 double cam_5_6 = 0.13;
#define cam_5_1 cam_5_1_GrC_AMPA
 double cam_5_1 = 0.0334;
#define cam_3_7 cam_3_7_GrC_AMPA
 double cam_3_7 = 0.513;
#define cam_3_4 cam_3_4_GrC_AMPA
 double cam_3_4 = 6.24;
#define cam_2_6 cam_2_6_GrC_AMPA
 double cam_2_6 = 0.395;
#define cam_2_3 cam_2_3_GrC_AMPA
 double cam_2_3 = 12.5;
#define cam_2_1 cam_2_1_GrC_AMPA
 double cam_2_1 = 4.2;
#define cam_1_2 cam_1_2_GrC_AMPA
 double cam_1_2 = 0.302;
#define cam_1_5 cam_1_5_GrC_AMPA
 double cam_1_5 = 0.109;
#define cam_7_6 cam_7_6_GrC_AMPA
 double cam_7_6 = 2.41;
#define cam_3_2 cam_3_2_GrC_AMPA
 double cam_3_2 = 13.3;
#define cam_4_3 cam_4_3_GrC_AMPA
 double cam_4_3 = 26.6;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "cam_4_3_GrC_AMPA", "/mM-ms",
 "cam_3_2_GrC_AMPA", "/mM-ms",
 "cam_7_6_GrC_AMPA", "/mM-ms",
 "cam_1_5_GrC_AMPA", "/ms",
 "cam_1_2_GrC_AMPA", "/ms",
 "cam_2_1_GrC_AMPA", "/ms",
 "cam_2_3_GrC_AMPA", "/ms",
 "cam_2_6_GrC_AMPA", "/ms",
 "cam_3_4_GrC_AMPA", "/ms",
 "cam_3_7_GrC_AMPA", "/ms",
 "cam_5_1_GrC_AMPA", "/ms",
 "cam_5_6_GrC_AMPA", "/ms",
 "cam_6_2_GrC_AMPA", "/ms",
 "cam_6_5_GrC_AMPA", "/ms",
 "cam_6_7_GrC_AMPA", "/ms",
 "cam_7_3_GrC_AMPA", "/ms",
 "Erev", "mV",
 "gbarampa", "umho",
 "freqdel", "/nA",
 "iampa", "nA",
 "gampa", "umho",
 "pNp", "nA",
 "pNd", "nA",
 "pglu", "mM",
 0,0
};
 static double St7ampa0 = 0;
 static double St6ampa0 = 0;
 static double St5ampa0 = 0;
 static double St4ampa0 = 0;
 static double St3ampa0 = 0;
 static double St2ampa0 = 0;
 static double St1ampa0 = 0;
 static double delta_t = 0.01;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "cam_4_3_GrC_AMPA", &cam_4_3_GrC_AMPA,
 "cam_3_2_GrC_AMPA", &cam_3_2_GrC_AMPA,
 "cam_7_6_GrC_AMPA", &cam_7_6_GrC_AMPA,
 "cam_1_5_GrC_AMPA", &cam_1_5_GrC_AMPA,
 "cam_1_2_GrC_AMPA", &cam_1_2_GrC_AMPA,
 "cam_2_1_GrC_AMPA", &cam_2_1_GrC_AMPA,
 "cam_2_3_GrC_AMPA", &cam_2_3_GrC_AMPA,
 "cam_2_6_GrC_AMPA", &cam_2_6_GrC_AMPA,
 "cam_3_4_GrC_AMPA", &cam_3_4_GrC_AMPA,
 "cam_3_7_GrC_AMPA", &cam_3_7_GrC_AMPA,
 "cam_5_1_GrC_AMPA", &cam_5_1_GrC_AMPA,
 "cam_5_6_GrC_AMPA", &cam_5_6_GrC_AMPA,
 "cam_6_2_GrC_AMPA", &cam_6_2_GrC_AMPA,
 "cam_6_5_GrC_AMPA", &cam_6_5_GrC_AMPA,
 "cam_6_7_GrC_AMPA", &cam_6_7_GrC_AMPA,
 "cam_7_3_GrC_AMPA", &cam_7_3_GrC_AMPA,
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
 static void _hoc_destroy_pnt(_vptr) void* _vptr; {
   destroy_point_process(_vptr);
}
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[5]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"GrC_AMPA",
 "Erev",
 "gbarampa",
 "freqdel",
 0,
 "iampa",
 "gampa",
 0,
 "St1ampa",
 "St2ampa",
 "St3ampa",
 "St4ampa",
 "St5ampa",
 "St6ampa",
 "St7ampa",
 0,
 "pNp",
 "pNd",
 "pglu",
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 20, _prop);
 	/*initialize range parameters*/
 	Erev = 0;
 	gbarampa = 0.001915;
 	freqdel = 0.579;
  }
 	_prop->param = _p;
 	_prop->param_size = 20;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 6, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _ampa_reg() {
	int _vectorized = 0;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 0,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 20, 6);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
  hoc_register_dparam_semantics(_mechtype, 2, "pointer");
  hoc_register_dparam_semantics(_mechtype, 3, "pointer");
  hoc_register_dparam_semantics(_mechtype, 4, "pointer");
  hoc_register_dparam_semantics(_mechtype, 5, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 GrC_AMPA /Users/tylerrivera/Honors Project 2022/Honors-Project-2022/Mossy Fiber Model/ampa.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Jonas et al. (1993) kinetic scheme of AMPA receptors ";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 static int _deriv1_advance = 0;
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist2[7]; static double _dlist2[7];
 static double _savstate1[7], *_temp1 = _savstate1;
 static int _slist1[7], _dlist1[7];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   double _lQ10 ;
 _lQ10 = pow( 2.0 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   DSt1ampa = _lQ10 * ( - ( cam_1_5 + cam_1_2 ) * St1ampa + cam_2_1 * St2ampa + cam_5_1 * St5ampa ) ;
   DSt2ampa = _lQ10 * ( - ( cam_2_1 + cam_2_3 + cam_2_6 ) * St2ampa + cam_1_2 * St1ampa + cam_3_2 * pglu * St3ampa + cam_6_2 * St6ampa ) ;
   DSt3ampa = _lQ10 * ( - ( cam_3_2 * pglu + cam_3_4 + cam_3_7 ) * St3ampa + cam_4_3 * pglu * St4ampa + cam_7_3 * St7ampa + cam_2_3 * St2ampa ) ;
   DSt4ampa = _lQ10 * ( - cam_4_3 * pglu * St4ampa + cam_3_4 * St3ampa ) ;
   DSt5ampa = _lQ10 * ( - ( cam_5_1 + cam_5_6 ) * St5ampa + cam_1_5 * St1ampa + cam_6_5 * St6ampa ) ;
   DSt6ampa = _lQ10 * ( - ( cam_6_2 + cam_6_5 + cam_6_7 ) * St6ampa + cam_7_6 * pglu * St7ampa + cam_5_6 * St5ampa + cam_2_6 * St2ampa ) ;
   DSt7ampa = _lQ10 * ( - ( cam_7_6 * pglu + cam_7_3 ) * St7ampa + cam_3_7 * St3ampa + cam_6_7 * St6ampa ) ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 double _lQ10 ;
 _lQ10 = pow( 2.0 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
 DSt1ampa = DSt1ampa  / (1. - dt*( ( _lQ10 )*( ( ( - ( cam_1_5 + cam_1_2 ) )*( 1.0 ) ) ) )) ;
 DSt2ampa = DSt2ampa  / (1. - dt*( ( _lQ10 )*( ( ( - ( cam_2_1 + cam_2_3 + cam_2_6 ) )*( 1.0 ) ) ) )) ;
 DSt3ampa = DSt3ampa  / (1. - dt*( ( _lQ10 )*( ( ( - ( cam_3_2 * pglu + cam_3_4 + cam_3_7 ) )*( 1.0 ) ) ) )) ;
 DSt4ampa = DSt4ampa  / (1. - dt*( ( _lQ10 )*( ( ( - cam_4_3 * pglu )*( 1.0 ) ) ) )) ;
 DSt5ampa = DSt5ampa  / (1. - dt*( ( _lQ10 )*( ( ( - ( cam_5_1 + cam_5_6 ) )*( 1.0 ) ) ) )) ;
 DSt6ampa = DSt6ampa  / (1. - dt*( ( _lQ10 )*( ( ( - ( cam_6_2 + cam_6_5 + cam_6_7 ) )*( 1.0 ) ) ) )) ;
 DSt7ampa = DSt7ampa  / (1. - dt*( ( _lQ10 )*( ( ( - ( cam_7_6 * pglu + cam_7_3 ) )*( 1.0 ) ) ) )) ;
  return 0;
}
 /*END CVODE*/
 
static int states () {_reset=0;
 { static int _recurse = 0;
 int _counte = -1;
 if (!_recurse) {
 _recurse = 1;
 {int _id; for(_id=0; _id < 7; _id++) { _savstate1[_id] = _p[_slist1[_id]];}}
 error = newton(7,_slist2, _p, states, _dlist2);
 _recurse = 0; if(error) {abort_run(error);}}
 {
   double _lQ10 ;
 _lQ10 = pow( 2.0 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   DSt1ampa = _lQ10 * ( - ( cam_1_5 + cam_1_2 ) * St1ampa + cam_2_1 * St2ampa + cam_5_1 * St5ampa ) ;
   DSt2ampa = _lQ10 * ( - ( cam_2_1 + cam_2_3 + cam_2_6 ) * St2ampa + cam_1_2 * St1ampa + cam_3_2 * pglu * St3ampa + cam_6_2 * St6ampa ) ;
   DSt3ampa = _lQ10 * ( - ( cam_3_2 * pglu + cam_3_4 + cam_3_7 ) * St3ampa + cam_4_3 * pglu * St4ampa + cam_7_3 * St7ampa + cam_2_3 * St2ampa ) ;
   DSt4ampa = _lQ10 * ( - cam_4_3 * pglu * St4ampa + cam_3_4 * St3ampa ) ;
   DSt5ampa = _lQ10 * ( - ( cam_5_1 + cam_5_6 ) * St5ampa + cam_1_5 * St1ampa + cam_6_5 * St6ampa ) ;
   DSt6ampa = _lQ10 * ( - ( cam_6_2 + cam_6_5 + cam_6_7 ) * St6ampa + cam_7_6 * pglu * St7ampa + cam_5_6 * St5ampa + cam_2_6 * St2ampa ) ;
   DSt7ampa = _lQ10 * ( - ( cam_7_6 * pglu + cam_7_3 ) * St7ampa + cam_3_7 * St3ampa + cam_6_7 * St6ampa ) ;
   {int _id; for(_id=0; _id < 7; _id++) {
if (_deriv1_advance) {
 _dlist2[++_counte] = _p[_dlist1[_id]] - (_p[_slist1[_id]] - _savstate1[_id])/dt;
 }else{
_dlist2[++_counte] = _p[_slist1[_id]] - _savstate1[_id];}}}
 } }
 return _reset;}
 
static int _ode_count(int _type){ return 7;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
     _ode_spec1 ();
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 7; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 ();
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
 _ode_matsol_instance1(_threadargs_);
 }}

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  St7ampa = St7ampa0;
  St6ampa = St6ampa0;
  St5ampa = St5ampa0;
  St4ampa = St4ampa0;
  St3ampa = St3ampa0;
  St2ampa = St2ampa0;
  St1ampa = St1ampa0;
 {
   St1ampa = 0.0 ;
   St2ampa = 0.0 ;
   St3ampa = 0.0 ;
   St4ampa = 1.0 ;
   St5ampa = 0.0 ;
   St6ampa = 0.0 ;
   St7ampa = 0.0 ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
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
 initmodel();
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   gampa = gbarampa * St1ampa * ( 1.0 + freqdel * ( pNp - pNd ) ) ;
   iampa = gampa * ( v - Erev ) ;
   }
 _current += iampa;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
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
 _g = _nrn_current(_v + .001);
 	{ _rhs = _nrn_current(_v);
 	}
 _g = (_g - _rhs)/.001;
 _g *=  1.e2/(_nd_area);
 _rhs *= 1.e2/(_nd_area);
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
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
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
double _dtsav = dt;
if (secondorder) { dt *= 0.5; }
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
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
 { error = _deriv1_advance = 1;
 derivimplicit(_ninits, 7, _slist1, _dlist1, _p, &t, dt, states, &_temp1);
_deriv1_advance = 0;
 if(error){fprintf(stderr,"at line 77 in file ampa.mod:\nSOLVE states METHOD derivimplicit\n"); nrn_complain(_p); abort_run(error);}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 7; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 }}}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(St1ampa) - _p;  _dlist1[0] = &(DSt1ampa) - _p;
 _slist1[1] = &(St2ampa) - _p;  _dlist1[1] = &(DSt2ampa) - _p;
 _slist1[2] = &(St3ampa) - _p;  _dlist1[2] = &(DSt3ampa) - _p;
 _slist1[3] = &(St4ampa) - _p;  _dlist1[3] = &(DSt4ampa) - _p;
 _slist1[4] = &(St5ampa) - _p;  _dlist1[4] = &(DSt5ampa) - _p;
 _slist1[5] = &(St6ampa) - _p;  _dlist1[5] = &(DSt6ampa) - _p;
 _slist1[6] = &(St7ampa) - _p;  _dlist1[6] = &(DSt7ampa) - _p;
 _slist2[0] = &(St7ampa) - _p;
 _slist2[1] = &(St6ampa) - _p;
 _slist2[2] = &(St5ampa) - _p;
 _slist2[3] = &(St4ampa) - _p;
 _slist2[4] = &(St3ampa) - _p;
 _slist2[5] = &(St2ampa) - _p;
 _slist2[6] = &(St1ampa) - _p;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/tylerrivera/Honors Project 2022/Honors-Project-2022/Mossy Fiber Model/ampa.mod";
static const char* nmodl_file_text = 
  "TITLE Jonas et al. (1993) kinetic scheme of AMPA receptors \n"
  "COMMENT\n"
  "Author: Elena Saftenku, 2001\n"
  "ENDCOMMENT\n"
  "NEURON{\n"
  "POINT_PROCESS GrC_AMPA\n"
  "POINTER pNp, pNd, pglu\n"
  "RANGE   iampa\n"
  "RANGE gampa, gbarampa, freqdel\n"
  "RANGE  Erev \n"
  "NONSPECIFIC_CURRENT iampa\n"
  "}\n"
  "\n"
  "UNITS{\n"
  "(nA)=(nanoamp)\n"
  "(mA)=(milliamp)\n"
  "(mV)=(millivolt)\n"
  "(umho)=(micromho)\n"
  "(molar)=(1/liter)\n"
  "(mM)=(millimolar)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "Erev = 0 (mV)\n"
  "gbarampa =  1.915e-3 (umho): gpeak=0.45e-3\n"
  "cam_4_3 = 26.6  (/mM-ms)\n"
  "cam_3_2 = 13.3 (/mM-ms)\n"
  "cam_7_6 =2.41 (/mM-ms)\n"
  "cam_1_5 = 0.109 (/ms)\n"
  "cam_1_2 = 0.302 (/ms)\n"
  "cam_2_1 = 4.2 (/ms)\n"
  "cam_2_3 = 12.5 (/ms)\n"
  "cam_2_6 = 0.395 (/ms)\n"
  "cam_3_4 =  6.24 (/ms)\n"
  "cam_3_7 = 0.513 (/ms)\n"
  "cam_5_1=0.0334 (/ms)\n"
  "cam_5_6 = 0.13 (/ms)\n"
  "cam_6_2 = 0.000546 (/ms)\n"
  "cam_6_5 = 0.00815 (/ms)\n"
  "cam_6_7 =0.0571(/ms)\n"
  "cam_7_3=0.0281(/ms)\n"
  "freqdel=0.579 (/nA): determines the part of long-term change of AMPAR-mediated synaptic current\n"
  "}\n"
  "\n"
  "ASSIGNED{\n"
  "v (mV)\n"
  "iampa (nA)\n"
  "gampa  (umho)\n"
  "pNp (nA) : reference to protein autophosphorylation Np\n"
  "pNd (nA) : reference to protein autophosphorylation Nd\n"
  "pglu (mM): reference to glutamate concentration\n"
  "celsius (degC)\n"
  "}\n"
  "\n"
  "STATE{\n"
  "St1ampa\n"
  "St2ampa\n"
  "St3ampa\n"
  "St4ampa\n"
  "St5ampa\n"
  "St6ampa\n"
  "St7ampa\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "St1ampa=0\n"
  "St2ampa=0\n"
  "St3ampa=0\n"
  "St4ampa=1\n"
  "St5ampa=0\n"
  "St6ampa=0\n"
  "St7ampa=0\n"
  "}\n"
  "\n"
  "BREAKPOINT\n"
  "{\n"
  "SOLVE states METHOD derivimplicit\n"
  "gampa = gbarampa*St1ampa *(1+freqdel*(pNp-pNd))\n"
  "iampa =gampa*(v-Erev)\n"
  "}\n"
  "\n"
  "DERIVATIVE states {\n"
  "LOCAL Q10\n"
  "Q10 = 2^((celsius-20(degC))/10(degC))\n"
  "  \n"
  "St1ampa' = Q10*(-(cam_1_5 + cam_1_2)*St1ampa + cam_2_1*St2ampa + \n"
  "cam_5_1* St5ampa)\n"
  "St2ampa' = Q10*( -(cam_2_1 + cam_2_3  + cam_2_6) * St2ampa + cam_1_2*St1ampa+\n"
  "cam_3_2*pglu*St3ampa + cam_6_2*St6ampa)\n"
  "St3ampa' = Q10*(-(cam_3_2*pglu+cam_3_4+cam_3_7) * St3ampa + \n"
  "cam_4_3 *pglu* St4ampa + cam_7_3*St7ampa + cam_2_3* St2ampa)\n"
  "St4ampa' = Q10*(-cam_4_3*pglu*St4ampa+cam_3_4*St3ampa)\n"
  "St5ampa' = Q10*(-(cam_5_1+cam_5_6)*St5ampa+ cam_1_5*St1ampa+cam_6_5*St6ampa)\n"
  "St6ampa' = Q10*(-(cam_6_2+cam_6_5+cam_6_7)*St6ampa+cam_7_6*pglu*St7ampa\n"
  "+cam_5_6*St5ampa + cam_2_6*St2ampa)\n"
  "St7ampa' = Q10*(-(cam_7_6*pglu+cam_7_3)*St7ampa+cam_3_7*St3ampa+\n"
  "cam_6_7*St6ampa)\n"
  "}\n"
  "\n"
  ;
#endif
