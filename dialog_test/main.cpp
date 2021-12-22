#include "Map.h"
#include <string>
#include <iostream>
#include <limits>
template<typename T>
int getNum(T &a);

int main() {
    int choice;
    TemplateMap::Map<std::string, int> testMap;
    std::cout << "Choose options: " << std::endl
        << "0. Exit" << std::endl
        << "1. Insert pair to map" << std::endl
        << "2. Search value by key" << std::endl
        << "3. Print size of map" << std::endl
        << "4. Check if map is empty" << std::endl;
//    if (getNum(choice) == 1)
    std::cin >> choice;
    switch(choice) {
        case 1:
            std::string key;
            int value;
            std::cout << "Enter your pair: " << std::endl
                << "Enter string(key): ";
            std::cin >> key;
            std::cout << "Enter int(value) :";
            std::cin >> value;
            testMap.insert(key, value);
        case 2:
            std::string searchKey;
            std::cout << "Enter key for search: ";
            std::cin >> searchKey;
            TemplateMap::MapIteretor<std::string, int> it = testMap.search(searchKey);
            if (it == nullptr)
                std::cout << "No such key";
            else
                std::cout << it->getValue();
        case 3:

    }
}

template<class T>
int getNum(T &a) {
    int indic;
    do {
        std::cin >> a;
        indic = 1;
        if (std::cin.eof())
            indic = -1;
        if (!std::cin.good()) {
            std::cout << "Incorrect input. Try again" << std::endl;
            indic = 0;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
    } while (indic == 0);
    return indic < 0 ? -1 : 1;
}