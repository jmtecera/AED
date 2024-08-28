#include <iostream>
#include <list>

template<class T>
void showList(std::list<T>& L){
	std::cout << "R = {";

	for(auto it = L.begin(); it != L.end(); it++){
        if (*it == (L.size() - 1)) {
            std::cout << *it;
        } else {
            std::cout << *it << " ";
        }
	}

    std::cout << "}\n";
}
