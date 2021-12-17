#ifndef DATASTRUCT_TESTSDEQUEONARRAY_H
#define DATASTRUCT_TESTSDEQUEONARRAY_H

#include "DequeOnArray.h"

#include <iostream>

 void tests(){
    DequeOnArr<int> deque;
    int i = 5;
     for (; i < 10; ++i) {
         deque.push_back(i);
     }
     deque.pop_back();
        std::cout << *(deque.front()) << " " << deque.size() << " " << *(deque.back()) << std::endl;
    i = 6;
     for (; i < 20; ++i) {
         deque.push_front(i);
     }
     deque.pop_front();
     std::cout << *(deque.front()) << " " << deque.size() << " " << *(deque.back()) << std::endl;



}
#endif //DATASTRUCT_TESTSDEQUEONARRAY_H
