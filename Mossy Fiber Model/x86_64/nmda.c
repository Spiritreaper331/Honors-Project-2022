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
 
#define nrn_init _nrn_init__GrC_NMDA
#define _nrn_initial _nrn_initial__GrC_NMDA
#define nrn_cur _nrn_cur__GrC_NMDA
#define _nrn_current _nrn_current__GrC_NMDA
#define nrn_jacob _nrn_jacob__GrC_NMDA
#define nrn_state _nrn_state__GrC_NMDA
#define _net_receive _net_receive__GrC_NMDA 
#define states states__GrC_NMDA 
 
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
#define gbarnmda _p[1]
#define freqdel _p[2]
#define inmda _p[3]
#define icanmda _p[4]
#define gnmda _p[5]
#define St1nmda _p[6]
#define St2nmda _p[7]
#define St3nmda _p[8]
#define St4nmda _p[9]
#define St5nmda _p[10]
#define DSt1nmda _p[11]
#define DSt2nmda _p[12]
#define DSt3nmda _p[13]
#define DSt4nmda _p[14]
#define DSt5nmda _p[15]
#define _g _p[16]
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
 static double _hoc_vspom();
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
 "vspom", _hoc_vspom,
 0, 0
};
#define vspom vspom_GrC_NMDA
 extern double vspom( double );
 /* declare global and static user variables */
#define alpha_vspom alpha_vspom_GrC_NMDA
 double alpha_vspom = -0.062;
#define cnm_5_2 cnm_5_2_GrC_NMDA
 double cnm_5_2 = 0.008;
#define cnm_3_4 cnm_3_4_GrC_NMDA
 double cnm_3_4 = 0.0067;
#define cnm_2_5 cnm_2_5_GrC_NMDA
 double cnm_2_5 = 0.01;
#define cnm_2_3 cnm_2_3_GrC_NMDA
 double cnm_2_3 = 0.0134;
#define cnm_2_1 cnm_2_1_GrC_NMDA
 double cnm_2_1 = 0.06;
#define cnm_1_2 cnm_1_2_GrC_NMDA
 double cnm_1_2 = 0.2;
#define cnm_3_2 cnm_3_2_GrC_NMDA
 double cnm_3_2 = 5;
#define cnm_4_3 cnm_4_3_GrC_NMDA
 double cnm_4_3 = 10;
#define v0_block v0_block_GrC_NMDA
 double v0_block = 10;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "alpha_vspom_GrC_NMDA", "/mV",
 "v0_block_GrC_NMDA", "mV",
 "cnm_4_3_GrC_NMDA", "/mM-ms",
 "cnm_3_2_GrC_NMDA", "/mM-ms",
 "cnm_1_2_GrC_NMDA", "/ms",
 "cnm_2_1_GrC_NMDA", "/ms",
 "cnm_2_3_GrC_NMDA", "/ms",
 "cnm_2_5_GrC_NMDA", "/ms",
 "cnm_3_4_GrC_NMDA", "/ms",
 "cnm_5_2_GrC_NMDA", "/ms",
 "Erev", "mV",
 "gbarnmda", "umho",
 "freqdel", "/nA",
 "inmda", "nA",
 "icanmda", "nA",
 "gnmda", "umho",
 "pNp", "nA",
 "pNd", "nA",
 "pglu", "mM",
 0,0
};
 static double St5nmda0 = 0;
 static double St4nmda0 = 0;
 static double St3nmda0 = 0;
 static double St2nmda0 = 0;
 static double St1nmda0 = 0;
 static double delta_t = 0.01;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "alpha_vspom_GrC_NMDA", &alpha_vspom_GrC_NMDA,
 "v0_block_GrC_NMDA", &v0_block_GrC_NMDA,
 "cnm_4_3_GrC_NMDA", &cnm_4_3_GrC_NMDA,
 "cnm_3_2_GrC_NMDA", &cnm_3_2_GrC_NMDA,
 "cnm_1_2_GrC_NMDA", &cnm_1_2_GrC_NMDA,
 "cnm_2_1_GrC_NMDA", &cnm_2_1_GrC_NMDA,
 "cnm_2_3_GrC_NMDA", &cnm_2_3_GrC_NMDA,
 "cnm_2_5_GrC_NMDA", &cnm_2_5_GrC_NMDA,
 "cnm_3_4_GrC_NMDA", &cnm_3_4_GrC_NMDA,
 "cnm_5_2_GrC_NMDA", &cnm_5_2_GrC_NMDA,
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
"GrC_NMDA",
 "Erev",
 "gbarnmda",
 "freqdel",
 0,
 "inmda",
 "icanmda",
 "gnmda",
 0,
 "St1nmda",
 "St2nmda",
 "St3nmda",
 "St4nmda",
 "St5nmda",
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
 	_p = nrn_prop_data_alloc(_mechtype, 17, _prop);
 	/*initialize range parameters*/
 	Erev = 0;
 	gbarnmda = 0.00948;
 	freqdel = 0.579;
  }
 	_prop->param = _p;
 	_prop->param_size = 17;
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

 void _nmda_reg() {
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
  hoc_register_prop_size(_mechtype, 17, 6);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
  hoc_register_dparam_semantics(_mechtype, 2, "pointer");
  hoc_register_dparam_semantics(_mechtype, 3, "pointer");
  hoc_register_dparam_semantics(_mechtype, 4, "pointer");
  hoc_register_dparam_semantics(_mechtype, 5, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 GrC_NMDA /Users/tylerrivera/Honors Project 2022/Honors-Project-2022/Mossy Fiber Model/nmda.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Lester and Jahr (1992) kinetic scheme of NMDA receptors";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 static int _deriv1_advance = 0;
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist2[5]; static double _dlist2[5];
 static double _savstate1[5], *_temp1 = _savstate1;
 static int _slist1[5], _dlist1[5];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   double _lQ10 ;
 _lQ10 = pow( 2.0 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   DSt1nmda = _lQ10 * ( - cnm_1_2 * St1nmda + cnm_2_1 * St2nmda ) ;
   DSt2nmda = _lQ10 * ( - ( cnm_2_1 + cnm_2_3 + cnm_2_5 ) * St2nmda + cnm_1_2 * St1nmda + cnm_3_2 * pglu * St3nmda + cnm_5_2 * St5nmda ) ;
   DSt3nmda = _lQ10 * ( - ( cnm_3_2 * pglu + cnm_3_4 ) * St3nmda + cnm_4_3 * pglu * St4nmda + cnm_2_3 * St2nmda ) ;
   DSt4nmda = _lQ10 * ( - cnm_4_3 * pglu * St4nmda + cnm_3_4 * St3nmda ) ;
   DSt5nmda = _lQ10 * ( - cnm_5_2 * St5nmda + cnm_2_5 * St2nmda ) ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 double _lQ10 ;
 _lQ10 = pow( 2.0 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
 DSt1nmda = DSt1nmda  / (1. - dt*( ( _lQ10 )*( ( ( - cnm_1_2 )*( 1.0 ) ) ) )) ;
 DSt2nmda = DSt2nmda  / (1. - dt*( ( _lQ10 )*( ( ( - ( cnm_2_1 + cnm_2_3 + cnm_2_5 ) )*( 1.0 ) ) ) )) ;
 DSt3nmda = DSt3nmda  / (1. - dt*( ( _lQ10 )*( ( ( - ( cnm_3_2 * pglu + cnm_3_4 ) )*( 1.0 ) ) ) )) ;
 DSt4nmda = DSt4nmda  / (1. - dt*( ( _lQ10 )*( ( ( - cnm_4_3 * pglu )*( 1.0 ) ) ) )) ;
 DSt5nmda = DSt5nmda  / (1. - dt*( ( _lQ10 )*( ( ( - cnm_5_2 )*( 1.0 ) ) ) )) ;
  return 0;
}
 /*END CVODE*/
 
static int states () {_reset=0;
 { static int _recurse = 0;
 int _counte = -1;
 if (!_recurse) {
 _recurse = 1;
 {int _id; for(_id=0; _id < 5; _id++) { _savstate1[_id] = _p[_slist1[_id]];}}
 error = newton(5,_slist2, _p, states, _dlist2);
 _recurse = 0; if(error) {abort_run(error);}}
 {
   double _lQ10 ;
 _lQ10 = pow( 2.0 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   DSt1nmda = _lQ10 * ( - cnm_1_2 * St1nmda + cnm_2_1 * St2nmda ) ;
   DSt2nmda = _lQ10 * ( - ( cnm_2_1 + cnm_2_3 + cnm_2_5 ) * St2nmda + cnm_1_2 * St1nmda + cnm_3_2 * pglu * St3nmda + cnm_5_2 * St5nmda ) ;
   DSt3nmda = _lQ10 * ( - ( cnm_3_2 * pglu + cnm_3_4 ) * St3nmda + cnm_4_3 * pglu * St4nmda + cnm_2_3 * St2nmda ) ;
   DSt4nmda = _lQ10 * ( - cnm_4_3 * pglu * St4nmda + cnm_3_4 * St3nmda ) ;
   DSt5nmda = _lQ10 * ( - cnm_5_2 * St5nmda + cnm_2_5 * St2nmda ) ;
   {int _id; for(_id=0; _id < 5; _id++) {
if (_deriv1_advance) {
 _dlist2[++_counte] = _p[_dlist1[_id]] - (_p[_slist1[_id]] - _savstate1[_id])/dt;
 }else{
_dlist2[++_counte] = _p[_slist1[_id]] - _savstate1[_id];}}}
 } }
 return _reset;}
 
double vspom (  double _lv ) {
   double _lvspom;
 _lvspom = 1. / ( 1. + 0.2801 * 1.2 * exp ( alpha_vspom * ( _lv - v0_block ) ) ) ;
   
return _lvspom;
 }
 
static double _hoc_vspom(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  vspom (  *getarg(1) );
 return(_r);
}
 
static int _ode_count(int _type){ return 5;}
 
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
	for (_i=0; _i < 5; ++_i) {
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
  St5nmda = St5nmda0;
  St4nmda = St4nmda0;
  St3nmda = St3nmda0;
  St2nmda = St2nmda0;
  St1nmda = St1nmda0;
 {
   St1nmda = 0.0 ;
   St2nmda = 0.0 ;
   St3nmda = 0.0 ;
   St4nmda = 1.0 ;
   St5nmda = 0.0 ;
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
   gnmda = gbarnmda * St1nmda * ( 1.0 + freqdel * ( pNp - pNd ) ) ;
   inmda = gnmda * vspom ( _threadargscomma_ v ) * ( v - Erev ) ;
   icanmda = 0.1 * gnmda * ( v - 26.0 ) * vspom ( _threadargscomma_ v ) ;
   }
 _current += inmda;

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
 derivimplicit(_ninits, 5, _slist1, _dlist1, _p, &t, dt, states, &_temp1);
_deriv1_advance = 0;
 if(error){fprintf(stderr,"at line 64 in file nmda.mod:\nSOLVE states METHOD derivimplicit\n"); nrn_complain(_p); abort_run(error);}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 5; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 }}}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(St1nmda) - _p;  _dlist1[0] = &(DSt1nmda) - _p;
 _slist1[1] = &(St2nmda) - _p;  _dlist1[1] = &(DSt2nmda) - _p;
 _slist1[2] = &(St3nmda) - _p;  _dlist1[2] = &(DSt3nmda) - _p;
 _slist1[3] = &(St4nmda) - _p;  _dlist1[3] = &(DSt4nmda) - _p;
 _slist1[4] = &(St5nmda) - _p;  _dlist1[4] = &(DSt5nmda) - _p;
 _slist2[0] = &(St5nmda) - _p;
 _slist2[1] = &(St4nmda) - _p;
 _slist2[2] = &(St3nmda) - _p;
 _slist2[3] = &(St2nmda) - _p;
 _slist2[4] = &(St1nmda) - _p;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/tylerrivera/Honors Project 2022/Honors-Project-2022/Mossy Fiber Model/nmda.mod";
static const char* nmodl_file_text = 
  "TITLE Lester and Jahr (1992) kinetic scheme of NMDA receptors\n"
  "COMMENT\n"
  "Author: Elena Saftenku, 2001\n"
  "ENDCOMMENT\n"
  "NEURON{\n"
  "POINT_PROCESS  GrC_NMDA\n"
  "POINTER pNp, pNd, pglu\n"
  "RANGE   inmda, icanmda\n"
  "RANGE   gnmda, gbarnmda,freqdel \n"
  "RANGE   Erev \n"
  "NONSPECIFIC_CURRENT  inmda \n"
  "}\n"
  "UNITS{\n"
  "(nA)=(nanoamp)\n"
  "(mA)=(milliamp)\n"
  "(mV)=(millivolt)\n"
  "(umho)=(micromho)\n"
  "(molar)=(1/liter)\n"
  "(mM)=(millimolar)\n"
  "}\n"
  "PARAMETER {\n"
  "Erev = 0 (mV)\n"
  "gbarnmda = 9.48e-3 (umho): gpeak=1.1e-3\n"
  "alpha_vspom=-0.062 (/mV): voltage-dependence of Mg2+ block from Maex and\n"
  ": de Shutter (1998)\n"
  "v0_block=10 (mV)\n"
  "cnm_4_3 = 10 (/mM-ms)\n"
  "cnm_3_2 = 5 (/mM-ms)\n"
  "cnm_1_2 = 0.2 (/ms)\n"
  "cnm_2_1 = 0.06 (/ms)\n"
  "cnm_2_3 = 0.0134 (/ms)\n"
  "cnm_2_5 = 0.01 (/ms)\n"
  "cnm_3_4 = 0.0067 (/ms)\n"
  "cnm_5_2= 0.008 (/ms)\n"
  "freqdel=  0.579 (/nA): determines the part of long-term change of NMDAR-mediated synaptic current\n"
  "}\n"
  "ASSIGNED{\n"
  "v (mV)\n"
  "inmda (nA)\n"
  "icanmda (nA): calcium current through NMDA receptors\n"
  "gnmda (umho)\n"
  "pNp (nA) : reference to protein autophosphorylation Np\n"
  "pNd (nA) : reference to protein autophosphorylation Nd\n"
  "pglu (mM) : reference to glutamate concentration\n"
  "celsius(degC)\n"
  "}\n"
  "STATE{\n"
  "St1nmda\n"
  "St2nmda\n"
  "St3nmda\n"
  "St4nmda\n"
  "St5nmda\n"
  "  }\n"
  "INITIAL {\n"
  "St1nmda=0\n"
  "St2nmda=0\n"
  "St3nmda=0\n"
  "St4nmda=1\n"
  "St5nmda=0\n"
  "}\n"
  "\n"
  "BREAKPOINT\n"
  "{\n"
  "SOLVE states METHOD derivimplicit\n"
  "gnmda = gbarnmda*St1nmda *(1+freqdel*(pNp-pNd))\n"
  "inmda =gnmda*vspom(v)*(v-Erev)\n"
  "icanmda=0.1*gnmda*(v-26)*vspom(v)\n"
  "}\n"
  "\n"
  "DERIVATIVE states {\n"
  "LOCAL Q10\n"
  "Q10 = 2^((celsius-20(degC))/10(degC))\n"
  "St1nmda' = Q10*( - cnm_1_2*St1nmda + cnm_2_1*St2nmda)\n"
  "St2nmda' = Q10*(-(cnm_2_1 + cnm_2_3  + cnm_2_5) * St2nmda + \n"
  "cnm_1_2*St1nmda + cnm_3_2*pglu*St3nmda + cnm_5_2*St5nmda)\n"
  "St3nmda' = Q10*(-(cnm_3_2*pglu+cnm_3_4) * St3nmda +\n"
  "cnm_4_3 *pglu* St4nmda + cnm_2_3* St2nmda)\n"
  "St4nmda' = Q10*(-cnm_4_3*pglu*St4nmda+cnm_3_4*St3nmda)\n"
  "St5nmda' = Q10*(-cnm_5_2*St5nmda+ cnm_2_5*St2nmda)\n"
  "}\n"
  "\n"
  "FUNCTION vspom (v(mV))( ){\n"
  "vspom=1./(1.+0.2801*1.2*exp(alpha_vspom*(v-v0_block)))\n"
  "}\n"
  "\n"
  ;
#endif
