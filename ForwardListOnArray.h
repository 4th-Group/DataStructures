#ifndef DATASTRUCT_FORWARDLISTONARRAY_H
#define DATASTRUCT_FORWARDLISTONARRAY_H

template<typename T>
class FListOnArr{
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
    FListOnArr() = default;

    FListOnArr(FListOnArr &old) {
        size_ = old.size_;
        delete[] mainArr_;
        mainArr_ = new T[size_];
        for (int i = 0; i < size_; ++i) {
            mainArr_[i] = old.mainArr_[i];
        }
    }

    T *back() {
        return &mainArr_[0];
    }

    bool empty() {
        return !(bool) size_;
    }

    T *front() {
        return &mainArr_[size_ - 1];
    }

    int size(){
        return size_;
    }

    void clear(){
        delete[] mainArr_;
        mainArr_ = new T[0];
    }

    void insert(int where, T element){

    }

    void pop_back(T value){

    }

    void push_back(T value){

    }

    void resize(int new_size){

    }

    void reverse(){

    }
};


#endif //DATASTRUCT_FORWARDLISTONARRAY_H
