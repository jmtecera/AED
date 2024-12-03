#define USECHRONO
#undef HAVE_MPI

#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <queue>
#include <list>

using namespace aed;

//---:---<*>---:---<*>- COMIENZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
// COMPLETAR DNI y NOMBRE AQUI:
// Nombre: Juan Manuel Tecera
int DNI=0;

void compact_queues(std::list<std::queue<int>> &LQ, int n) {
    
  for(auto &it : LQ) {
    if (it.size() > n) {
      std::queue<int> aux;
      int sum = 0;
      
      for (int i = 0; i < n; i++) {
        aux.push(it.front());
        it.pop();
      }

      while(!it.empty()) {
        sum += it.front();
        it.pop();
      }
      
      while(!aux.empty()) {
        it.push(aux.front());
        aux.pop();
      }
      
      it.push(sum);

    }
  }
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(compact_queues,vrbs);
  return 0;
}
