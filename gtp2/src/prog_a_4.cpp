#include <iostream>
#include <list>
#include "utils.cpp"

void invert(std::list<int> &L) {
    auto it1 = L.begin();
    auto it2 = L.end(); it2--;
    while (it1 != it2) {
        std::cout << "Swap of " << *it1 << " to " << *it2 << '\n';
        std::swap(*it1, *it2);
        it1++;
        if (it1 == it2) break;
        it2--;
    }

}


int main() {
    std::list<int> L = {1, 2, 3, 4, 5};
    invert(L);

    showList(L);

    return 0;
}


