#define USECHRONO
#undef HAVE_MPI

#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <set>
#include <list>

using namespace aed;

// bool even(int x) { return x%2==0; }
// bool odd(int x) { return x%2; }
// bool ge7(int x) { return x>=7; }
// bool le3(int x) { return x<=3; }
// bool div4(int x) { return x%4==0; }
// bool isprime(int x) { return is_prime(abs(x)); }
// bool isnotprime(int x) { return !is_prime(abs(x)); }

//---:---<*>---:---<*>- COMIENZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
// COMPLETAR DNI y NOMBRE AQUI:
// Nombre: Juan Manuel Tecera
int DNI=0;

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>

int count(std::set<int> &s, bool (*pred)(int)) {
  int c = 0;
  
  for (auto it : s) {
    if (pred(it)) {
      c++;
    }
  }
  
  return c;
}


set<int> setinters(std::list<std::set<int>> &LS, std::set<int> &S, bool (*pred)(int)) {
  int c_max = -1;
  std::set<int> res;
  
  for (auto &LSset : LS) {
    std::set<int> tmp;
    
    for (auto &itLS : LSset) { 
      if (S.find(itLS) != S.end()) {
        tmp.insert(itLS);
      }
    }
    
    int c = count(tmp, pred);
    
    if (c > c_max) {
      c_max = c; 
      res = LSset;
    }
  }

  return res;
}                                                                    

int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(setinters,vrbs);
  return 0;
}
