// GITVERSION: aed-2021-422-g23f79710
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

  typedef void (*compact_queues_t)(list<queue<int>> &LQ, int n);
  class eval1_t : public eval_base_t {
  public:
    compact_queues_t F;
    eval1_t() {
      dumptests=0;
      const char *dt = getenv("DUMPTESTS");
      if (dt && !strcmp(dt,"1")) dumptests=1;
      F=NULL; ejerc=EJERC; testfile="./compq.json";
    }
    void run_case(json &data, json &outuser) {
      check_dni();
      list<queue<int>> LQ;
      auto &jlq = data["LQ"];
      for (auto &jq : jlq) {
        queue<int> q;
        for (auto x : jq) q.push(x);
        LQ.push_back(q);
      }
      int n = data["n"];
      F(LQ,n);
      json &jlqo = outuser["LQ"];
      for (auto &q : LQ) {
        json jq;
        while (!q.empty()) {
          jq.push_back(q.front());
          q.pop();
        }
        jlqo.push_back(jq);
      }
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) {
      return outuser==outref;
    }

    void generate_case(randomg_t &rnd,json &datain) {
#if 0
      int m = 10+rnd.rand()%10;
      json L;
      for (int j=0; j<m; j++) L.push_back(rnd.rand()%4);
      datain["L"].swap(L);
#endif
    }
  };
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<eval1_t,compact_queues_t>;
}
#undef CSTR

#endif
