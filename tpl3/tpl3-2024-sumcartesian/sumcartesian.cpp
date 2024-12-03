#define USECHRONO
#undef HAVE_MPI

#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>

using namespace aed;

//---:---<*>---:---<*>- COMIENZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
// COMPLETAR DNI y NOMBRE AQUI:
// Nombre: Juan Manuel Tecera
int DNI=0;

int sumpairs(std::set<std::pair<int, int>> &prod) {
  int sum = 0;
  for (auto it : prod) {
    sum += abs(it.first - it.second);
  }
  return sum;
}

std::set<std::pair<int, int>> prodcartesian(std::set<int> &A, std::set<int> &B) {
  std::set<std::pair<int, int>> prod;
  
  for (auto itA : A) {
    for (auto itB : B) {
      prod.insert({itA, itB});
    }
  }
  return prod;
  
}

int sumcartesian(set<int> &A, set<int> &B) {
  
  std::set<std::pair<int, int>> resprod = prodcartesian(A, B);
  
  return sumpairs(resprod);
}

//---:---<*>---:---<*>- FINALIZA CODIGO FUNCION --:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(sumcartesian,vrbs);
  return 0;
}
