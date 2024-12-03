#ifndef SHOW_LIST_HPP
#define SHOW_LIST_HPP

#include <iostream>
#include <list>

template<class T>
void showList(std::list<T>& L) {
    std::cout << "R = {";

    for (auto it = L.begin(); it != L.end(); it++) {
        if (std::next(it) == L.end()) {
            std::cout << *it;
        } else {
            std::cout << *it << " ";
        }
    }

    std::cout << "}\n";
}

#endif
