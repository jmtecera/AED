#include <list>
#include "utils.cpp"

void junta(std::list<int> &L, int c) {
    auto it = L.begin();
    while (it != L.end()) {
        auto it2 = it++;
        for(int i = 1; (it != L.end() && i < c); i++) {
			*it2 += *it;
			it++;
		}
		it = L.erase(++it2,it);
    }
}

int main() {
    std::list<int> L = {1, 3, 2, 4, 5, 2, 2, 3, 5, 7, 4, 3, 2, 2};
    junta(L, 3);

    showList(L);
}

