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

void mkabb(btree<int>& T, btree<int>::iterator it, std::list<int>::iterator posS, std::list<int>::iterator posE) {
  if (posS == posE) {return;}
  
  auto mid = posS;
  
  advance(mid, distance(posS, posE) / 2);
  
  it = T.insert(it, *mid);
  
  std::list<int> Lleft(posS, mid);
  std::list<int> Lright(next(mid), posE);

  mkabb(T, it.left(), Lleft.begin(), Lleft.end());
  mkabb(T, it.right(), Lright.begin(), Lright.end());
}

void mkabb(btree<int> &T,list<int> &L) {
  L.sort();

  mkabb(T, T.begin(), L.begin(), L.end());
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0,seed=1234;
  ev.eval<1>(mkabb,vrbs);
  //ev.evalr<1>(mkabb,seed,vrbs);
  return 0;
}
