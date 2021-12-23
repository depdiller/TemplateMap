#include "Map.h"
#include <string>
#include <iostream>
#include <limits>
template<typename T>
int getNum(T &a);

int main() {
    int choice;
    TemplateMap::Map<std::string, int> testMap;
    while (true) {
        std::cout << "\n\n";
        std::cout << "Choose options: " << std::endl
                  << "0. Exit" << std::endl
                  << "1. Insert pair to map" << std::endl
                  << "2. Search value by key" << std::endl
                  << "3. Print elements of map" << std::endl
                  << "4. Check if map is empty" << std::endl
                  << "5. Print size of map" << std::endl;
//      if (getNum(choice) == 1)
        std::cin >> choice;
        if (choice == 0)
            break;
        switch (choice) {
            case 1: {
                std::string key;
                int value;
                std::cout << "Enter your pair: " << std::endl
                          << "Enter string(key): ";
                std::cin >> key;
                std::cout << "Enter int(value): ";
                std::cin >> value;
                testMap.insert(key, value);
            }
                break;
            case 2: {
                std::string searchKey;
                std::cout << "Enter key for search: ";
                std::cin >> searchKey;
                TemplateMap::MapIteretor<std::string, int> it1 = testMap.search(searchKey);
                if (it1 == nullptr)
                    std::cout << "No such key." << std::endl;
                else
                    std::cout << it1->getValue();
            }
                break;
            case 3: {
                TemplateMap::MapIteretor<std::string, int> it2 = testMap.begin();
                for (; it2 != testMap.end(); ++it2) {
                    std::cout << it2->getKey() << '-' << it2->getValue() << std::endl;
                }
            }
                break;
            case 4: {
                std::cout << testMap.isEmpty() << std::endl;
            }
                break;
            case 5: {
                std::cout << testMap.size() << std::endl;
            }
                break;
            default : {
                std::cout << "Invalid type option. Try again.";
            }
        }
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