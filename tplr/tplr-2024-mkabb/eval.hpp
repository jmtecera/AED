// GITVERSION: aed-2021-526-gf252594e
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

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  // END FUNCTIONS FOR THIS EXAM
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
#undef EJERC
#undef EVAL
#define EJERC 1
#define EVAL eval1_t

  typedef void (*mkabb_t)(btree<int> &T,list<int> &L);
  class eval1_t : public eval_base_t {
  public:
    mkabb_t F;
    eval1_t() {
      dumptests=0;
      const char *dt = getenv("DUMPTESTS");
      if (dt && !strcmp(dt,"1")) dumptests=1;
      F=NULL; ejerc=EJERC; testfile="./mkabb.json";
    }
    void run_case(json &data, json &outuser) {
      check_dni();
      btree<int> T;
      list<int> L = data["L"];
      F(T,L);
      outuser["T"] = btree2lisp(T);
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) {
      btree<int> Tuser,Tref;
      lisp2btree(string(outuser["T"]),Tuser);
      lisp2btree(string(outref["T"]),Tref);
      return Tuser==Tref;
    }

    void generate_case(randomg_t &rnd,json &datain) {
      json L;
      int N = 5+rnd.rand()%5;
      for (int k=0; k<N; k++) 
        L.push_back(rnd.rand()%10);
      datain["L"].swap(L);
    }
  };
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<eval1_t,mkabb_t>;
}
#undef CSTR

#endif
