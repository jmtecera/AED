// GITVERSION: aed-2021-508-g3b514a8c
#ifndef EVAL_HPP
#define EVAL_HPP
#include "evalbase.hpp"
#include "str_convs.hpp"
#include <forward_list>
#include <sstream>
using namespace std;

namespace aed {

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  //   FUNCTIONS FOR THIS EXAM
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>

  typedef bool (*comp_t)(int x,int y);
  
  bool menor(int x,int y) { return x<y; }
  bool mayor(int x,int y) { return x>y; }
  bool menor_abs(int x,int y) { return abs(x)<abs(y); }

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  // END FUNCTIONS FOR THIS EXAM
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
#undef EJERC
#undef EVAL
#define EJERC 1
#define EVAL eval1_t

  typedef void (*abbpred_t)(btree<int> &T,comp_t comp);
  class eval1_t : public eval_base_t {
  public:
    abbpred_t F;
    eval1_t() {
      dumptests=0;
      const char *dt = getenv("DUMPTESTS");
      if (dt && !strcmp(dt,"1")) dumptests=1;
      F=NULL; ejerc=EJERC; testfile="./abp.json";
    }
    void run_case(json &data, json &outuser) {
      check_dni();
      btree<int> T;
      string s = data["T"];
      lisp2btree(s,T);
      comp_t comp=NULL;
      string scomp = data["comp"];
#define DEF(fun) else if ( scomp== #fun) comp=fun
      // if (data["comp"] == "menor") comp=menor;
      if (0) {}
      DEF(menor);
      DEF(mayor);
      DEF(menor_abs);
      assert(comp);
      F(T,comp);
      outuser["T"] = btree2lisp(T);
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) {
      btree<int> Tuser,Tref;
      lisp2btree(string(outuser["T"]),Tuser);
      lisp2btree(string(outref["T"]),Tref);
      return Tuser==Tref;
    }

    class add_t : public scalarfunc_t {
    public:
      int val;
      int map(int x) { return x+val; }
    };

    static int addfun(int x) { return x-5; }
    
    void generate_case(randomg_t &rnd,json &datain) {
      btree<int> T;
      int key = rnd.rand()%3;
      string scomp = (key==0? "menor" : key==1? "mayor" : "menor_abs");
      datain["comp"] = scomp;
      make_random_btree(T,10,0.6,rnd);
      // cout << btree2lisp(T) << endl;
      make_unique(T);
      // cout << btree2lisp(T) << endl;
      if (scomp=="menor_abs") {
        add_t add;
        add.val = -5;
        apply(T,add);
        // apply(T,addfun);
      }
      
      // cout << btree2lisp(T) << endl;
      // cout << "-----------" << endl;
      datain["T"] = btree2lisp(T);
    }
  };
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<eval1_t,abbpred_t>;
}
#undef CSTR

#endif
