// GITVERSION: aed-2021-537-g62b5f67c
#ifndef EVAL_HPP
#define EVAL_HPP
#include "evalbase.hpp"
#include "str_convs.hpp"
#include <forward_list>
#include <sstream>
using namespace std;

inline bool even(int x) { return x%2==0; }
inline bool odd(int x) { return x%2; }
inline bool ge7(int x) { return x>=7; }
inline bool le3(int x) { return x<=3; }
inline bool div4(int x) { return x%4==0; }
inline bool isprime(int x) { return is_prime(abs(x)); }
inline bool isnotprime(int x) { return !is_prime(abs(x)); }

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

  typedef set<int> (*setinters_t)(list<set<int>> &LS, set<int> &S,bool (*pred)(int));
  typedef bool (*pred_t )(int);
  class eval1_t : public eval_base_t {
  public:
    setinters_t F;
    json predv;
    int npreds;
    eval1_t() {
      dumptests=0;
      const char *dt = getenv("DUMPTESTS");
      if (dt && !strcmp(dt,"1")) dumptests=1;
      F=NULL; ejerc=EJERC; testfile="./setinters.json";
      json predvv({"odd","even","ge7","even","odd","ge7","le3","div4","isprime","isnotprime"});
      predv = predvv;
      npreds = predv.size();
    }
    void run_case(json &data, json &outuser) {
      check_dni();
      list<set<int>> LS;
      json jLS = data["LS"];
      for (auto &js : jLS) {
        set<int> s = js;
        LS.push_back(s);
      }
      set<int> S = data["S"];
      string spred=data["pred"];
      pred_t pred = NULL;
      if (0) {}
#define CHOOSE(name) else if (spred==#name) pred=&name
      // else if (spred=="odd") pred=&odd;
      CHOOSE(even);
      CHOOSE(odd);
      CHOOSE(ge7);
      CHOOSE(le3);
      CHOOSE(div4);
      CHOOSE(isprime);
      CHOOSE(isnotprime);
      if (pred==NULL) {
        printf("Predicado desconocido %s",spred.c_str());
        assert(0);
      }
      set<int> sout = F(LS,S,pred);
      outuser["Sout"] = sout;
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) {
      return outuser==outref;
    }

    void generate_case(randomg_t &rnd,json &datain) {
      json LS;
      for (int js=0; js<10; js++) {
        set<int> s;
        for (int k=0; k<5; k++) s.insert(rnd.rand()%10);
        LS.push_back(json(s));
      }
      json S = LS.front();
      LS.erase(0);
      datain["LS"]= LS;
      datain["S"]= S;
      int j = rnd.rand()%npreds;
      datain["pred"] = predv[j];
      // cout << datain << endl;
    }
  };
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<eval1_t,setinters_t>;
}
#undef CSTR

#endif
