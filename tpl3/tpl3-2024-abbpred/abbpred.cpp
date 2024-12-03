#define USECHRONO
#undef HAVE_MPI

#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <list>
#include <btree.hpp>

using namespace aed;

//---:---<*>---:---<*>- COMIENZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
// COMPLETAR DNI y NOMBRE AQUI:
// Nombre: Juan Manuel Tecera
int DNI=0;

void list_btree(btree<int> &T, btree<int>::iterator it, std::list<int> &L) {
    if (it == T.end()) { return; }
    
    L.push_back(*it);
    
    list_btree(T, it.left(), L);
    list_btree(T, it.right(), L);
    
}

void insert_btree(btree<int> &T, btree<int>::iterator m, int x, comp_t comp) {
    if (m == T.end()) {
        T.insert(m, x);
    } else {
        if (comp(x, *m)) {
            insert_btree(T, m.left(), x, comp);
        } else {
            insert_btree(T, m.right(), x, comp);
        }
    }
}

void abbpred(btree<int> &T, comp_t comp) {
    std::list<int> L;
    list_btree(T, T.begin(), L);
    
    T.clear();
    
    for (auto x : L) {
        insert_btree(T, T.begin(), x, comp);
    }
    
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0, seed=1234;
  ev.eval<1>(abbpred,vrbs);
  // ev.evalr<1>(abbpred,seed,vrbs);
  return 0;
}
