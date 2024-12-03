#define USECHRONO
#undef HAVE_MPI

#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <map>
#include <list>
#include <numeric>

using namespace aed;
//using namespace std;

//---:---<*>---:---<*>- COMIENZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
// COMPLETAR DNI y NOMBRE AQUI:
// Nombre: Juan Manuel Tecera
int DNI=0;

void unify(std::list<std::map<int, int>> &LM, std::map<int, std::list<int>> &U) {
  
  for (auto M : LM) {
    for (auto pair : M) {
      int key = pair.first;
      int val = pair.second;

      U[key].push_back(val);

    }
  }
  
  for (auto &pair : U) { pair.second.sort(); }

}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(unify,vrbs);
  return 0;
}
