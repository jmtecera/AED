#define USECHRONO
#undef HAVE_MPI

#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <queue>

using namespace aed;
using namespace std;

//---:---<*>---:---<*>- COMIENZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
// COMPLETAR DNI y NOMBRE AQUI:
// Nombre: Juan Manuel Tecera
int DNI=0;

void stack2queue(stack<int> &S, queue<int> &Q, bool (*pred)(int)) {
  
  stack<int> aux;
  
  while (!S.empty()) {
    int val = S.top();
    S.pop();
    
    if (pred(val)) {
      Q.push(val);
    } else {
      aux.push(val);
    }    
  }
  
  while (!aux.empty()) {
    Q.push(aux.top());
    aux.pop();
  }
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(stack2queue, vrbs);
  return 0;
}
