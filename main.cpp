#include "arrQueue.h"
#include "ForwardListOnArray.h"
#include <iostream>

int main(){
    FListOnArr<int> list;
    int i = 55;
    std::cout << list.empty() << std::endl;
    for (; i < 70; ++i) {
        list.push_back(i);
    }
    std::cout << list.size() << std::endl;
    std::cout << list.empty() << std::endl;

    std::cout << "List: ";
    for (int j = 0; j < list.size(); ++j) {
        std::cout << *list[j] << " ";
    }
    std::cout << std::endl;

    list.pop_back();
    list.pop_back();
    std::cout << list.size() << std::endl;

    std::cout << "List: ";
    for (int j = 0; j < list.size(); ++j) {
        std::cout << *list[j] << " ";
    }
    std::cout << std::endl;

    int h = 30;
    list.insert(5, h);
    std::cout << *list[4] << " " << list.size() << std::endl;

    std::cout << "List: ";
    for (int j = 0; j < list.size(); ++j) {
        std::cout << *list[j] << " ";
    }
    std::cout << std::endl;

    list.remove(5);

    std::cout << "List: ";
    for (int j = 0; j < list.size(); ++j) {
        std::cout << *list[j] << " ";
    }
    std::cout << std::endl;

    std::cout << list.size() << std::endl;

    std::cout << *(list.front()) << " " << *(list.back()) << std::endl;

    list.resize(2);
    std::cout << list.size() << std::endl;
    for (int j = 0; j < list.size(); ++j) {
        std::cout << *list[j] << " ";
    }

    return 0;
}