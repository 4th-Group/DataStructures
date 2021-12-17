#ifndef DATASTRUCT_ARRQUEUE_H
#define DATASTRUCT_ARRQUEUE_H

#include "stdexcept"

template<typename T>
class arrQueue {
private:
    T *mainArr_ = new T[0];
    int size_ = 0;

    void resize(bool bigger) {
        int  i;
        if  (bigger && size_ == 1){
            delete[] mainArr_;
            mainArr_ = new T[1];
            return;
        }
        T newArr[size_];
        for (i = bigger; i < size_; ++i) {
            newArr[i] = mainArr_[i - bigger];
        }
        delete[] mainArr_;
        mainArr_ = new T[size_];
        for (i = bigger; i < size_; ++i) {
            mainArr_[i] = newArr[i];
        }
    }

public:
    arrQueue() = default;

    arrQueue(arrQueue &old) {
        size_ = old.size_;
        delete[] mainArr_;
        mainArr_ = new T[size_];
        for (int i = 0; i < size_; ++i) {
            mainArr_[i] = old.mainArr_[i];
        }
    }

    T *back() {
        if (size_ == 0){
            throw std::logic_error("Size is 0");
        }
        return &mainArr_[size_ - 1];
    }

    bool empty() {
        return !(bool) size_;
    }

    T *front() {
        if (size_ == 0){
            throw std::logic_error("Size is 0");
        }
        return &mainArr_[0];
    }

    void pop() {
        if (size_ == 0){
            throw std::logic_error("You cannot pop when size is 0");
        }
        size_--;
        resize(false);
    }

    void push(T &val) {
        size_++;
        resize(true);
        mainArr_[0] = val;
    }

    int size() {
        return size_;
    }

    ~arrQueue(){
        delete[] mainArr_;
    }
};

#endif //DATASTRUCT_ARRQUEUE_H
