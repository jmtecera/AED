#include <list>
#include "utils.cpp"

std::list<int> concatA(std::list<int> &L1, std::list<int> &L2) {
    std::list<int> L;

    auto it = L.begin();

    L.insert(it, L1.begin(), L1.end());
    L.insert(it, L2.begin(), L2.end());

    return L;
}

std::list<int> concatB(std::list<std::list<int>> &LL) {
    std::list<int> L;

    for (auto it : LL) {
        L.insert(L.end(), it.begin(), it.end());
    }

    return L;
}

std::list<int> concatC(std::list<std::list<int>> &LL) {
    std::list<int> L;

    for (auto it : LL){
        L.splice(L.end(), it);
    }

    return L;
}

int main() {
    std::list<int> L1 = {1, 2, 3, 4};
    std::list<int> L2 = {5, 6, 7, 8};
    std::list<std::list<int>> LL = {{1, 2, 3}, {4, 5}, {6, 7, 8}};

    std::list<int> R1 = concatA(L1, L2);
    std::list<int> R2 = concatB(LL);
    std::list<int> R3 = concatC(LL);

    showList(R1);
    showList(R2);
    showList(R3);

    return 0;
}