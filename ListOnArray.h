#ifndef DATASTRUCT_LISTONARRAY_H
#define DATASTRUCT_LISTONARRAY_H

#endif //DATASTRUCT_LISTONARRAY_H
class ListOnArr {
private:
    T *mainArr_ = new T[0];
    int size_ = 0;
public:
    ListOnArr() = default;

    ListOnArr(ListOnArr &old) {
        size_ = old.size_;
        delete[] mainArr_;
        mainArr_ = new T[size_];
        for (int i = 0; i < size_; ++i) {
            mainArr_[i] = old.mainArr_[i];
        }
    }

    T *back() {
        return &mainArr_[size_ - 1];
    }

    bool empty() {
        return !(bool) size_;
    }

    T *front() {
        return &mainArr_[0];
    }

    int size() {
        return size_;
    }

    void clear() {
        delete[] mainArr_;
        mainArr_ = new T[0];
    }

    void insert(int where, T &element) {
        if (where > size_) {
            throw std::range_error("You can not insert element on this position");
        }
        T arr1[where];
        T arr2[size_ - where + 1];
        for (int i = 0; i < where; ++i) {
            arr1[i] = mainArr_[i];
        }
        arr1[where - 1] = element;
        int k = 0;
        for (int i = where - 1; i < size_; ++i) {
            arr2[k] = mainArr_[i];
            ++k;
        }

        delete[] mainArr_;
        mainArr_ = new T[++size_];

        for (int i = 0; i < where; ++i) {
            mainArr_[i] = arr1[i];
        }

        int j = 0;
        for (int i = where; i < size_; ++i) {
            mainArr_[i] = arr2[j];
            ++j;
        }

    }

    void remove(int where){
        if (where > size_) {
            throw std::range_error("You can not delete element on this position");
        } else if(where == size_){
            pop_back();
        }
        T arr1[where - 1];
        T arr2[size_ - where];
        for (int i = 0; i < where - 1; ++i) {
            arr1[i] = mainArr_[i];
        }
        int k = 0;
        for (int i = where; i < size_; ++i) {
            arr2[k] = mainArr_[i];
            ++k;
        }

        delete[] mainArr_;
        mainArr_ = new T[--size_];

        for (int i = 0; i < where - 1; ++i) {
            mainArr_[i] = arr1[i];
        }

        int j = 0;
        for (int i = where - 1; i < size_; ++i) {
            mainArr_[i] = arr2[j];
            ++j;
        }
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

    void resize(int new_size) {
        T tempArr[new_size];
        for (int i = 0; i < new_size; ++i) {
            tempArr[i] = mainArr_[i];
        }
        delete[] mainArr_;
        mainArr_ = new T[new_size];
        for (int i = 0; i < new_size; ++i) {
            mainArr_[i] = tempArr[i];
        }
        size_ = new_size;
    }

    T *operator[](int num) {
        return &mainArr_[num];
    }
    ~ListOnArr(){
        delete[] mainArr_;
    }
};