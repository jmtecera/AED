// GITVERSION: aed-2021-428-g886be4ed
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

  json q2j(queue<int> q) {
    json rv;
    while (!q.empty()) {
      rv.push_back(q.front());
      q.pop();
    }
    return rv;
  }
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  // END FUNCTIONS FOR THIS EXAM
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
#undef EJERC
#undef EVAL
#define EJERC 1
#define EVAL eval1_t

  typedef void (*priority_stack_t)(list<list<int>> &LL, stack<int> &S);
  class eval1_t : public eval_base_t {
  public:
    priority_stack_t F;
    eval1_t() {
      dumptests=0;
      const char *dt = getenv("DUMPTESTS");
      if (dt && !strcmp(dt,"1")) dumptests=1;
      F=NULL; ejerc=EJERC; testfile="./prios.json";
    }
    void run_case(json &data, json &outuser) {
      check_dni();
      list<list<int>> LL;
      // cout << data << endl;
      json &jLL = data["LL"];
      for (auto &jl : jLL) {
        list<int> L;
        for (auto x : jl) L.push_back(x);
        LL.push_back(L);
      }
      // cout << data << endl;
      stack<int> S;
      F(LL,S);
      json &JS = outuser["S"];
      while (!S.empty()) {
        JS.push_back(S.top());
        S.pop();
      }
      // cout << outuser << endl;
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) {
      return outuser==outref;
    }

    void generate_case(randomg_t &rnd,json &datain) {
      int nl = 5+rnd.rand()%5;
      auto &LL = datain["LL"];
      for (int j=0; j<nl; j++) {
        json jl;
        int m = 3+rnd.rand()%3;
        for (int k=0; k<m; k++) 
          jl.push_back(1+rnd.rand()%20);
        LL.push_back(jl);
      }
    }
  };
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<eval1_t,priority_stack_t>;
}
#undef CSTR

#endif
