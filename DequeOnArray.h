#ifndef DATASTRUCT_DEQUEONARRAY_H
#define DATASTRUCT_DEQUEONARRAY_H

#include "stdexcept"
#include "cassert"

template <typename T>
class DequeOnArr{
private:
    T *mainArr_ = new T[0];
    int size_ = 0;

public:
    DequeOnArr() = default;

    DequeOnArr(DequeOnArr &old) {
        size_ = old.size_;
        delete[] mainArr_;
        mainArr_ = new T[size_];
        for (int i = 0; i < size_; ++i) {
            mainArr_[i] = old.mainArr_[i];
        }
    }

    T *back() {
        if (size_ == 0){
            throw std::logic_error("size of the deque is 0");
        }
        return &mainArr_[size_ - 1];
    }

    bool empty() {
        if (size_ == 0){
            throw std::logic_error("size of the deque is 0");
        }
        return !(bool) size_;
    }

    T *front() {
        return &mainArr_[0];
    }

    void pop_back() {

        if (size_ == 0){
            throw std::logic_error("size of the deque is 0");
        }
        T* tempArr = new T[--size_];
        for (int i = 0; i < size_; ++i) {
            tempArr[i] = mainArr_[i];
        }
        delete[] mainArr_;
        mainArr_ = new T[size_];
        for (int i = 0; i < size_; ++i) {
            mainArr_[i] = tempArr[i];
        }
        delete[] tempArr;
    }

    void push_back(T &value) {
        T* tempArr = new T[size_];
        for (int i = 0; i < size_; ++i) {
            tempArr[i] = mainArr_[i];
        }
        delete[] mainArr_;
        mainArr_ = new T[size_ + 1];
        for (int i = 0; i < size_; ++i) {
            mainArr_[i] = tempArr[i];
        }
        mainArr_[size_] = value;
        ++size_;
        delete[] tempArr;
    }

    void push_front(T &val) {
        size_++;
        T* arr = new T[size_];
        for (int i = 1; i < size_; ++i) {
            arr[i] = mainArr_[i - 1];
        }
        arr[0] = val;
        delete[] mainArr_;
        mainArr_ = new T[size_];
        for (int i = 0; i < size_; ++i) {
            mainArr_[i] = arr[i];
        }
        delete[] arr;
    }

    void pop_front() {
        if (size_ == 0){
            throw std::logic_error("size of the deque is 0");
        }
        size_--;
        T* arr = new T[size_];
        for (int i = 0; i < size_; ++i) {
            arr[i] = mainArr_[i + 1];
        }

        delete[] mainArr_;
        mainArr_ = new T[size_];
        for (int i = 0; i < size_; ++i) {
            mainArr_[i] = arr[i];
        }
        delete[] arr;
    }

    int size() {
        return size_;
    }

    ~DequeOnArr(){
        delete[] mainArr_;
    }
};
#endif //DATASTRUCT_DEQUEONARRAY_H
