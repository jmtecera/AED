#define USECHRONO
#undef HAVE_MPI

#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <map>
#include <list>
using namespace aed;
using namespace std;

//---:---<*>---:---<*>- COMIENZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int DNI = 0;

void neg2pos(list<int>& L, map<int,list<int>>& M){  
        auto it = L.begin();
        
        while (it != L.end()) {
                if (*it < 0) {
                        int n = *it;
                        M[n]; // Empty list for n in case the next element is not positive
                        
                        ++it;
                        while (it != L.end() && *it >= 0) {
                                M[n].push_back(*it);
                                ++it;
                        }
                }
        }
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(neg2pos,vrbs);
  return 0;
}
