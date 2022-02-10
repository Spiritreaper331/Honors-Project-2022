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
 
#define nrn_init _nrn_init__Gr_LTP1
#define _nrn_initial _nrn_initial__Gr_LTP1
#define nrn_cur _nrn_cur__Gr_LTP1
#define _nrn_current _nrn_current__Gr_LTP1
#define nrn_jacob _nrn_jacob__Gr_LTP1
#define nrn_state _nrn_state__Gr_LTP1
#define _net_receive _net_receive__Gr_LTP1 
#define states states__Gr_LTP1 
 
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
#define gamma _p[0]
#define eta _p[1]
#define nu1 _p[2]
#define nu2 _p[3]
#define pp _p[4]
#define pd _p[5]
#define gdel1 _p[6]
#define gdel2 _p[7]
#define Mp _p[8]
#define Md _p[9]
#define Ap _p[10]
#define Ad _p[11]
#define Np _p[12]
#define Nd _p[13]
#define messenger _p[14]
#define DNp _p[15]
#define DNd _p[16]
#define Dmessenger _p[17]
#define _g _p[18]
#define _nd_area  *_ppvar[0]._pval
#define picanmda	*_ppvar[2]._pval
#define _p_picanmda	_ppvar[2]._pval
 
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
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gamma", "/ms",
 "eta", "/ms",
 "nu1", "/ms",
 "nu2", "/ms",
 "pp", "/ms",
 "pd", "/ms",
 "gdel1", "/nA-ms",
 "gdel2", "/nA-ms",
 "Mp", "nA/ms",
 "Md", "nA/ms",
 "Ap", "nA2",
 "Ad", "nA2",
 "Np", "nA",
 "Nd", "nA",
 "messenger", "nA",
 "picanmda", "nA",
 0,0
};
 static double Nd0 = 0;
 static double Np0 = 0;
 static double delta_t = 0.01;
 static double messenger0 = 0;
 static double v = 0;
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
 static void _hoc_destroy_pnt(_vptr) void* _vptr; {
   destroy_point_process(_vptr);
}
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[3]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"Gr_LTP1",
 "gamma",
 "eta",
 "nu1",
 "nu2",
 "pp",
 "pd",
 "gdel1",
 "gdel2",
 "Mp",
 "Md",
 "Ap",
 "Ad",
 0,
 0,
 "Np",
 "Nd",
 "messenger",
 0,
 "picanmda",
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
 	_p = nrn_prop_data_alloc(_mechtype, 19, _prop);
 	/*initialize range parameters*/
 	gamma = 0.34;
 	eta = 0.003;
 	nu1 = 0.065;
 	nu2 = 0.065;
 	pp = 9.5e-06;
 	pd = 0.00019;
 	gdel1 = 2.4;
 	gdel2 = 2.4;
 	Mp = 3e-05;
 	Md = 0.0003;
 	Ap = 1.625;
 	Ad = 0.55;
  }
 	_prop->param = _p;
 	_prop->param_size = 19;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 "messenger", 0.0001,
 0,0
};
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _gr_ltp1_reg() {
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
  hoc_register_prop_size(_mechtype, 19, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
  hoc_register_dparam_semantics(_mechtype, 2, "pointer");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 Gr_LTP1 /Users/tylerrivera/Honors Project 2022/Honors-Project-2022/Mossy Fiber Model/gr_ltp1.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Long-term potentiation and depression";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 static int _deriv1_advance = 0;
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist2[3]; static double _dlist2[3];
 static double _savstate1[3], *_temp1 = _savstate1;
 static int _slist1[3], _dlist1[3];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   Dmessenger = - gamma * picanmda - eta * messenger ;
   DNp = nu1 * messenger - ( pp - picanmda * gdel1 ) * Np + ( Mp * Np * Np ) / ( Ap + Np * Np ) ;
   DNd = nu2 * messenger - ( pd - picanmda * gdel2 ) * Nd + ( Md * Nd * Nd ) / ( Ad + Nd * Nd ) ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 Dmessenger = Dmessenger  / (1. - dt*( ( - ( eta )*( 1.0 ) ) )) ;
 DNp = DNp  / (1. - dt*( (( nu1 * messenger - ( pp - picanmda * gdel1 ) * ( Np  + .001) + ( Mp * ( Np  + .001) * ( Np  + .001) ) / ( Ap + ( Np  + .001) * ( Np  + .001) ) ) - ( nu1 * messenger - ( pp - picanmda * gdel1 ) * Np + ( Mp * Np * Np ) / ( Ap + Np * Np )  )) / .001 )) ;
 DNd = DNd  / (1. - dt*( (( nu2 * messenger - ( pd - picanmda * gdel2 ) * ( Nd  + .001) + ( Md * ( Nd  + .001) * ( Nd  + .001) ) / ( Ad + ( Nd  + .001) * ( Nd  + .001) ) ) - ( nu2 * messenger - ( pd - picanmda * gdel2 ) * Nd + ( Md * Nd * Nd ) / ( Ad + Nd * Nd )  )) / .001 )) ;
  return 0;
}
 /*END CVODE*/
 
static int states () {_reset=0;
 { static int _recurse = 0;
 int _counte = -1;
 if (!_recurse) {
 _recurse = 1;
 {int _id; for(_id=0; _id < 3; _id++) { _savstate1[_id] = _p[_slist1[_id]];}}
 error = newton(3,_slist2, _p, states, _dlist2);
 _recurse = 0; if(error) {abort_run(error);}}
 {
   Dmessenger = - gamma * picanmda - eta * messenger ;
   DNp = nu1 * messenger - ( pp - picanmda * gdel1 ) * Np + ( Mp * Np * Np ) / ( Ap + Np * Np ) ;
   DNd = nu2 * messenger - ( pd - picanmda * gdel2 ) * Nd + ( Md * Nd * Nd ) / ( Ad + Nd * Nd ) ;
   {int _id; for(_id=0; _id < 3; _id++) {
if (_deriv1_advance) {
 _dlist2[++_counte] = _p[_dlist1[_id]] - (_p[_slist1[_id]] - _savstate1[_id])/dt;
 }else{
_dlist2[++_counte] = _p[_slist1[_id]] - _savstate1[_id];}}}
 } }
 return _reset;}
 
static int _ode_count(int _type){ return 3;}
 
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
	for (_i=0; _i < 3; ++_i) {
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
  Nd = Nd0;
  Np = Np0;
  messenger = messenger0;
 {
   messenger = 0.0 ;
   Nd = 0.0 ;
   Np = 0.0 ;
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

static double _nrn_current(double _v){double _current=0.;v=_v;{
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
 derivimplicit(_ninits, 3, _slist1, _dlist1, _p, &t, dt, states, &_temp1);
_deriv1_advance = 0;
 if(error){fprintf(stderr,"at line 50 in file gr_ltp1.mod:\nSOLVE states METHOD derivimplicit\n"); nrn_complain(_p); abort_run(error);}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 3; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 } {
   }
}}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(messenger) - _p;  _dlist1[0] = &(Dmessenger) - _p;
 _slist1[1] = &(Np) - _p;  _dlist1[1] = &(DNp) - _p;
 _slist1[2] = &(Nd) - _p;  _dlist1[2] = &(DNd) - _p;
 _slist2[0] = &(Nd) - _p;
 _slist2[1] = &(Np) - _p;
 _slist2[2] = &(messenger) - _p;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/tylerrivera/Honors Project 2022/Honors-Project-2022/Mossy Fiber Model/gr_ltp1.mod";
static const char* nmodl_file_text = 
  "TITLE Long-term potentiation and depression\n"
  "COMMENT\n"
  "Realization of Migliore and Lansky model of long-term potentiation and depression (1999). In contrast to the model of Migliore and Lansky, an activation of autocatalytic processes is controlled not by\n"
  "postsynaptic depolarization, but by [Ca] influx through the NMDA \n"
  "receptor channels. \n"
  "Author: Elena Saftenku, 2001\n"
  "ENDCOMMENT\n"
  "NEURON{\n"
  "POINT_PROCESS  Gr_LTP1\n"
  "POINTER picanmda\n"
  "RANGE gamma,eta,nu1,nu2,pp,pd,gdel1,gdel2,Mp,Md,Ap,Ad\n"
  "}\n"
  "UNITS{\n"
  "(nA)=(nanoamp)\n"
  "(mA)=(milliamp)\n"
  "(mV)=(millivolt)\n"
  "}\n"
  "PARAMETER {\n"
  " gamma=0.34 (/ms) : rate constant of the production of \n"
  ":[Ca]-dependent protein\n"
  " eta=0.003 (/ms) : rate constant of protein degradation \n"
  " nu1=0.065 (/ms) : rate constant of activation of autocatalytic \n"
  ": process Np\n"
  " nu2=0.065 (/ms): the same for Nd\n"
  ":Parameters of autocatalytic processes\n"
  " pp=0.0000095 (/ms)\n"
  " pd=0.00019(/ms)\n"
  " gdel1= 2.4(/nA-ms)\n"
  " gdel2= 2.4(/nA-ms)\n"
  " Mp= 3e-5(nA/ms)\n"
  " Md=3e-4(nA/ms)\n"
  " Ap=1.625(nA2)\n"
  " Ad=0.55(nA2)\n"
  "}\n"
  "ASSIGNED{\n"
  "picanmda (nA): reference to Ca2+ current through NMDA receptors\n"
  " }\n"
  "STATE{\n"
  "Np (nA) \n"
  "Nd (nA)  \n"
  "messenger (nA) <1e-04>\n"
  "}\n"
  "INITIAL {\n"
  "messenger=0\n"
  "  Nd=0\n"
  "  Np=0\n"
  "}\n"
  "BREAKPOINT\n"
  "{\n"
  "SOLVE states METHOD derivimplicit\n"
  "}\n"
  "\n"
  "DERIVATIVE states {\n"
  "messenger' = -gamma*picanmda - eta*messenger\n"
  "  Np' = nu1*messenger  - (pp - picanmda*gdel1)*Np +(Mp*Np*Np)/(Ap+Np*Np)\n"
  "  Nd' = nu2*messenger  -(pd - picanmda*gdel2)*Nd  +(Md*Nd*Nd)/(Ad+Nd*Nd)\n"
  "}\n"
  "\n"
  ;
#endif
