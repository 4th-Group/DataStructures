#ifndef STACK_NODES__LISTONNODES_H_
#define STACK_NODES__LISTONNODES_H_

template<typename T>
struct Node {
  T value_;
  Node *next_;
  Node *prev_;
};

template<typename T>
class ListOnNodes {
 private:
  Node<T> *head_;
  int size_;

 public:
  ListOnNodes() : size_(0) {
    head_ = nullptr;
  }
  ~ListOnNodes() {
    while (size_ != 0) {
      removeFirst();
    }
  };

  void push(T value) {
    Node<T> *a = new(Node<T>);
    a->next_ = nullptr;
    a->prev_ = nullptr;
    a->value_ = value;
    Node<T> *tmp = head_;
    if (head_ == nullptr) {
      head_ = a;
      size_++;
      return;
    }
    for (int i = 0; i < size_ - 1; i++) {
      tmp = tmp->next_;
    }
    tmp->next_ = a;
    a->prev_ = tmp;
    size_++;
  }

  Node<T> *find(T value) {
    Node<T> *tmp = head_;
    while (tmp && tmp->value_ != value) {
      tmp = tmp->next_;
    }
    return ((tmp && tmp->value_ == value) ? tmp : nullptr);
  }

  void removeFirst() {
    if (head_ == nullptr) {
      return;
    }
    Node<T> *tmp = head_;
    head_ = head_->next_;
    delete tmp;
    head_->prev_ = nullptr;
    size_--;
  }

  T elementByIndex(int index) {
    Node<T> *tmp = head_;
    for (int i = 0; i < index; i++) {
      tmp = tmp->next_;
    }
    return tmp->value_;
  }

  bool isEmpty() {
    return !bool(size_);
  }

  void deleteByIndex(int index) {
    Node<T> *tmp = head_;
    if (index == 0) {
      removeFirst();
    } else if (index == size_ - 1) {
      for (int i = 0; i < index - 1; i++) {
        tmp = tmp->next_;
      }
      delete tmp->next_;
      size_--;
      tmp->next_ = nullptr;
    } else {
      for (int i = 0; i < index - 1; i++) {
        tmp = tmp->next_;
      }
      Node<T> *tmp2 = tmp->next_->next_;
      delete tmp->next_;
      size_--;
      tmp->next_ = tmp2;
      tmp2->prev_ = tmp;
    }
  }

  void insertByIndex(int index, T value) {
    Node<T> *a = new Node<T>;
    a->next_ = nullptr;
    a->prev_ = nullptr;
    a->value_ = value;
    if (index == 0) {
      a->next_ = head_;
      head_->prev_ = a;
      head_ = a;
      size_++;
    } else if (index == size_) {
      push(value);
    } else {
      Node<T> *tmp = head_;
      for (int i = 0; i < index - 1; i++) {
        tmp = tmp->next_;
      }
      Node<T> *tmp2 = tmp;
      tmp2 = tmp2->next_;
      tmp->next_ = a;
      a->prev_ = tmp;
      a->next_ = tmp2;
      tmp2->prev_ = a;
      size_++;
    }
  }
};

#endif //STACK_NODES__LISTONNODES_H_
