#ifndef DATASTRUCT_DEQUEONARRAY_H
#define DATASTRUCT_DEQUEONARRAY_H

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
        return &mainArr_[0];
    }

    bool empty() {
        return !(bool) size_;
    }

    T *front() {
        return &mainArr_[size_ - 1];
    }

    void pop_back() {
        T tempArr[--size_];
        for (int i = 0; i < size_; ++i) {
            tempArr[i] = mainArr_[i];
        }
        delete[] mainArr_;
        mainArr_ = new T[size_];
        for (int i = 0; i < size_; ++i) {
            mainArr_[i] = tempArr[i];
        }
    }

    void push_back(T &value) {
        T tempArr[size_];
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
    }

    void push_front(T &val) {
        size_++;
        T arr[size_];
        for (int i = 1; i < size_; ++i) {
            arr[i] = mainArr_[i];
        }
        arr[0] = val;
        delete[] mainArr_;
        mainArr_ = new T[size_];
        for (int i = 0; i < size_; ++i) {
            mainArr_[i] = arr[i];
        }
    }

    void pop_front() {
        size_--;
        T arr[size_];
        for (int i = 0; i < size_; ++i) {
            arr[i] = mainArr_[i + 1];
        }

        delete[] mainArr_;
        mainArr_ = new T[size_];
        for (int i = 0; i < size_; ++i) {
            mainArr_[i] = arr[i];
        }
    }

    int size() {
        return size_;
    }

    ~DequeOnArr(){
        delete[] mainArr_;
    }
};
#endif //DATASTRUCT_DEQUEONARRAY_H
