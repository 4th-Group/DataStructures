#ifndef DATASTRUCT_STACKQUEUE_H
#define DATASTRUCT_STACKQUEUE_H

template <typename T>
class stackQueue{
private:
    T *start_;
    T *end_;
    T *mainArr_ = new T[0];
    int size_ = 0;
public:
    stackQueue() = default;
    stackQueue(stackQueue &old){
        start_ = old.start_;
        end_ = old.end_;
        size_ = old.size_;
        delete[] mainArr_;
        mainArr_ = new T[size_];
        for (int i = 0; i < size; ++i) {
            mainArr_[i] = old.mainArr_[i];
        }
    }

};
#endif //DATASTRUCT_STACKQUEUE_H
