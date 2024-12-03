#define USECHRONO
#undef HAVE_MPI

#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <tree.hpp>
using namespace aed;
using namespace std;

//---:---<*>---:---<*>- COMIENZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int DNI=0;

void mkmono(tree<int> &T,tree<int>::iterator n,int &last) {
        if (n == T.end()) return; // si esta vacio, no hago nada
        
        if (n == T.begin()) {
                last = *n; // arranco last en base a la raiz    
        } else {
                if (*n <= last) { // chequeo si last es mayor q el nodo
                        *n = last + 1;
                }
        }
        
        last = *n; // Actualiza last al valor nodal (independiemente de si lo tuvo que modificar o no)
        
        mkmono(T, n.lchild(), last); // recursivo para los hijos
        mkmono(T, n.right(), last);
}

void mkmono(tree<int> &T) {
        int last;
        mkmono(T, T.begin(), last);
}



//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(mkmono,vrbs);
  return 0;
}
