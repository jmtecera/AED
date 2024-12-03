// GITVERSION: aed-2021-537-g62b5f67c
#ifndef EVAL_HPP
#define EVAL_HPP
#include "evalbase.hpp"
#include "str_convs.hpp"
#include <forward_list>
#include <sstream>
#include <list>
#include <map>
using namespace std;

namespace aed {

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  //   FUNCTIONS FOR THIS EXAM
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  
  map<int,int> listPair2map(list<pair<int,int>> LP) {
    map<int,int> m;
    
    for(auto i:LP) {
      m[i.first]=i.second;
    }
    
    return m;
  }
  
  list<pair<int,int>> map2listPair(map<int,int> M) {
    list<pair<int,int>> lp;
    
    for(auto i:M) {
      lp.push_back(make_pair(i.first,i.second));
    }
    
    return lp;
  }
  
  list<pair<int,list<int>>> map2listPairList(map<int,list<int>> M) {
    list<pair<int,list<int>>> lp;
    
    for(auto i:M) {
      lp.push_back(make_pair(i.first,i.second));
    }
    
    return lp;
  }

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  // END FUNCTIONS FOR THIS EXAM
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
#undef EJERC
#undef EVAL
#define EJERC 1
#define EVAL eval1_t
  
  typedef void (*unify_t)(list<map<int,int>>& LM, map<int,list<int>>& U);
  class eval1_t : public eval_base_t {
  public:
    unify_t F;
    eval1_t() { dumptests=0; F=NULL; ejerc=EJERC; testfile="./lm.json"; }
    void run_case(json &data,json &outuser) {
      list<list<pair<int,int>>> LMpair = data["LMin"];
      
      list<map<int,int>> LM;
      
      for(auto i:LMpair) {
        LM.push_back(listPair2map(i));
      }
      
      map<int,list<int>> U;
      F(LM, U);
      
      outuser["Uout"] = map2listPairList(U);
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) {
      return outuser==outref;
    }
    
    void generate_case(randomg_t &rnd,json &datain) {
      list<map<int,int>> LM;
      
      int l=10;
      int m=5+rnd.rand()%l;
      
      int cotaVal=20;
      
      for(int i=0; i<m; i++) {
        int n=rnd.rand()%m;
        
        map<int,int> tempM;
        for(int j=0; j<n; j++) {
          int x = 1+rnd.rand()%cotaVal;
          int y = 1+rnd.rand()%cotaVal;
          tempM[x]=y;
        }
        
        LM.push_back(tempM);
      }
      
      list<list<pair<int,int>>> LMpair;
      for(auto i:LM) {
        LMpair.push_back(map2listPair(i));
      }
      
      datain["LMin"] = LMpair;
    }
  };
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<eval1_t,unify_t>;
}
#undef CSTR

#endif
