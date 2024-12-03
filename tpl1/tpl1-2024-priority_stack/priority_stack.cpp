#define USECHRONO
#undef HAVE_MPI

#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <list>
#include <algorithm>

using namespace aed;

//---:---<*>---:---<*>- COMIENZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
// COMPLETAR DNI y NOMBRE AQUI:
// Nombre: Juan Manuel Tecera
int DNI=0;

void priority_stack(std::list<std::list<int>> &LL, std::stack<int> &S) {
  std::list<int> aux;
  
  for (auto it : LL) {
    aux.splice(aux.end(), it);
  }
  
  aux.sort();
  aux.reverse();
  
  for (auto it : aux) {
    S.push(it);
  }

}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(priority_stack,vrbs);
  return 0;
}
