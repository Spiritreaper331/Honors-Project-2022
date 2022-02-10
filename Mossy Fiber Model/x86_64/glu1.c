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
 
#define nrn_init _nrn_init__GrC_Glu1
#define _nrn_initial _nrn_initial__GrC_Glu1
#define nrn_cur _nrn_cur__GrC_Glu1
#define _nrn_current _nrn_current__GrC_Glu1
#define nrn_jacob _nrn_jacob__GrC_Glu1
#define nrn_state _nrn_state__GrC_Glu1
#define _net_receive _net_receive__GrC_Glu1 
 
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
#define taurec _p[0]
#define tauin _p[1]
#define taufacil _p[2]
#define usr _p[3]
#define u0 _p[4]
#define conccap _p[5]
#define glu _p[6]
#define tx1 _p[7]
#define conc01 _p[8]
#define conc02 _p[9]
#define conc03 _p[10]
#define vspr _p[11]
#define glu1 _p[12]
#define glu2 _p[13]
#define glu3 _p[14]
#define v _p[15]
#define _tsav _p[16]
#define _nd_area  *_ppvar[0]._pval
 
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
 _extcall_prop = _prop;
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
 "u0", 0, 1,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "taurec", "ms",
 "tauin", "ms",
 "taufacil", "ms",
 "glu", "mM",
 0,0
};
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void _ba1() ;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void _hoc_destroy_pnt(_vptr) void* _vptr; {
   destroy_point_process(_vptr);
}
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"GrC_Glu1",
 "taurec",
 "tauin",
 "taufacil",
 "usr",
 "u0",
 0,
 "conccap",
 "glu",
 0,
 0,
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
 	taurec = 800;
 	tauin = 3;
 	taufacil = 20;
 	usr = 0.1;
 	u0 = 0;
  }
 	_prop->param = _p;
 	_prop->param_size = 17;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 2, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
 static void _net_receive(Point_process*, double*, double);
 static void _net_init(Point_process*, double*, double);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _glu1_reg() {
	int _vectorized = 1;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,(void*)0, (void*)0, (void*)0, nrn_init,
	 hoc_nrnpointerindex, 1,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 17, 2);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
 pnt_receive[_mechtype] = _net_receive;
 pnt_receive_init[_mechtype] = _net_init;
 pnt_receive_size[_mechtype] = 5;
 	hoc_reg_ba(_mechtype, _ba1, 11);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 GrC_Glu1 /Users/tylerrivera/Honors Project 2022/Honors-Project-2022/Mossy Fiber Model/glu1.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "glutamate concentration and short-term plasticity";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 /* BEFORE BREAKPOINT */
 static void _ba1(Node*_nd, double* _pp, Datum* _ppd, Datum* _thread, _NrnThread* _nt)  {
   double* _p; Datum* _ppvar; _p = _pp; _ppvar = _ppd;
  v = NODEV(_nd);
 if ( t < tx1 ) {
     glu = 0.0 ;
     glu1 = 0.0 ;
     glu2 = 0.0 ;
     glu3 = 0.0 ;
     }
   if ( t >= tx1 ) {
     glu1 = conccap * ( 2.88 + conc01 ) * exp ( ( tx1 - t ) / 0.05 ) ;
     glu2 = conccap * ( 0.2 + conc02 ) * exp ( ( tx1 - t ) / 0.5 ) ;
     glu3 = conccap * ( 0.04 + conc03 ) * exp ( ( tx1 - t ) / 1.7 ) ;
     glu = glu1 + glu2 + glu3 ;
     }
   }
 
static void _net_receive (_pnt, _args, _lflag) Point_process* _pnt; double* _args; double _lflag; 
{  double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _thread = (Datum*)0; _nt = (_NrnThread*)_pnt->_vnt;   _p = _pnt->_prop->param; _ppvar = _pnt->_prop->dparam;
  if (_tsav > t){ extern char* hoc_object_name(); hoc_execerror(hoc_object_name(_pnt->ob), ":Event arrived out of order. Must call ParallelContext.set_maxstep AFTER assigning minimum NetCon.delay");}
 _tsav = t; {
   vspr = ( ( 1.0 - _args[2] - _args[1] ) / taurec + ( _args[2] - 1.0 ) / tauin ) / ( 1.0 / tauin - 1.0 / taurec ) ;
   _args[2] = 1.0 + exp ( ( _args[4] - t ) / taurec ) * vspr + exp ( ( _args[4] - t ) / tauin ) * ( _args[2] - 1.0 - vspr ) ;
   _args[1] = _args[1] * exp ( ( _args[4] - t ) / tauin ) ;
   if ( taufacil > 0.0 ) {
     _args[3] = _args[3] * exp ( ( _args[4] - t ) / taufacil ) ;
     }
   else {
     _args[3] = usr ;
     }
   if ( taufacil > 0.0 ) {
     _args[3] = _args[3] + usr * ( 1.0 - _args[3] ) ;
     }
   _args[1] = _args[1] + _args[2] * _args[3] ;
   conccap = ( _args[3] * _args[2] / usr ) * _args[0] ;
   _args[2] = _args[2] - _args[3] * _args[2] ;
   _args[4] = t ;
   conc01 = glu1 ;
   conc02 = glu2 ;
   conc03 = glu3 ;
   tx1 = t ;
   } }
 
static void _net_init(Point_process* _pnt, double* _args, double _lflag) {
       double* _p = _pnt->_prop->param;
    Datum* _ppvar = _pnt->_prop->dparam;
    Datum* _thread = (Datum*)0;
    _NrnThread* _nt = (_NrnThread*)_pnt->_vnt;
 _args[2] = 1.0 ;
   _args[1] = 0.0 ;
   _args[3] = u0 ;
   _args[4] = t ;
   }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
 {
   tx1 = 10000000.0 ;
   conc01 = 0.0 ;
   conc02 = 0.0 ;
   conc03 = 0.0 ;
   conccap = 0.0 ;
   glu = 0.0 ;
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
 _tsav = -1e20;
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
 initmodel(_p, _ppvar, _thread, _nt);
}
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{
} return _current;
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
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
}}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/tylerrivera/Honors Project 2022/Honors-Project-2022/Mossy Fiber Model/glu1.mod";
static const char* nmodl_file_text = 
  "TITLE glutamate concentration and short-term plasticity\n"
  "COMMENT\n"
  "Author: Elena Saftenku, 2001\n"
  "ENDCOMMENT\n"
  "NEURON{\n"
  "POINT_PROCESS GrC_Glu1\n"
  "RANGE conccap,glu\n"
  "RANGE taurec,taufacil,tauin, u0, usr \n"
  "}\n"
  "UNITS{\n"
  "(molar)=(1/liter)\n"
  "(mM)=(millimolar)\n"
  "}\n"
  "PARAMETER {\n"
  "taurec=800 (ms): time constant of recovery from depletion\n"
  "tauin=3 (ms): decay constant of transmitter\n"
  "taufacil=20(ms): time constant of facilitation\n"
  "usr=0.1 : the use of synaptic resources by each spike\n"
  "u0=0 <0,1> : initial value of the facilitated usr\n"
  " }\n"
  "ASSIGNED{\n"
  "tx1(ms): time of spike\n"
  "conccap :release probability\n"
  "conc01(mM): resting concentration at the beginning of the next spike\n"
  "conc02(mM)\n"
  "conc03(mM)\n"
  "vspr :auxiliary variable\n"
  "glu (mM): glutamate concentration\n"
  "glu1 (mM): separate exponential terms of glu\n"
  "glu2 (mM)\n"
  "glu3 (mM)\n"
  "}\n"
  "INITIAL {\n"
  "tx1=10000000\n"
  "conc01=0\n"
  "conc02=0\n"
  "conc03=0\n"
  "\n"
  "conccap=0\n"
  "glu=0\n"
  "}\n"
  "BEFORE BREAKPOINT\n"
  "{ \n"
  "if (t<tx1){\n"
  "glu=0\n"
  "glu1=0\n"
  "glu2=0\n"
  "glu3=0\n"
  "}\n"
  "if(t>=tx1) {\n"
  "glu1= conccap*(2.88(mM)+conc01)*exp((tx1-t)/0.05(ms))\n"
  "glu2=conccap*(0.2(mM)+conc02)*exp((tx1-t)/0.5(ms))\n"
  "glu3=conccap*(0.04(mM)+conc03)*exp((tx1-t)/1.7(ms))\n"
  "glu=glu1+glu2+glu3\n"
  "}\n"
  "}\n"
  "NET_RECEIVE (weight,Eav,R, u,tsyn (ms))\n"
  "{\n"
  "INITIAL\n"
  "{\n"
  "R=1\n"
  "Eav=0\n"
  "u=u0\n"
  "tsyn=t}\n"
  "vspr=((1-R-Eav)/taurec+(R-1)/tauin)/(1/tauin-1/taurec)\n"
  "R=1+exp((tsyn-t)/taurec)*vspr+exp((tsyn-t)/tauin)*(R-1-vspr)\n"
  "Eav=Eav*exp((tsyn-t)/tauin)\n"
  "if (taufacil>0){\n"
  "u=u*exp((tsyn-t)/taufacil)\n"
  "}else {\n"
  "u=usr\n"
  "}\n"
  "if (taufacil>0) {\n"
  "u = u+usr*(1-u)\n"
  "}\n"
  "Eav=Eav+R*u\n"
  "conccap=(u*R/usr)*weight\n"
  "R=R-u*R\n"
  "tsyn=t\n"
  "conc01=glu1\n"
  "conc02=glu2\n"
  "conc03=glu3\n"
  "tx1=t \n"
  "}\n"
  "\n"
  ;
#endif
