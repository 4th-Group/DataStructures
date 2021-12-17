#ifndef DEQUE__DEQUE_H_
#define DEQUE__DEQUE_H_

template<typename T>
struct Node {
  T value_;
  Node<T> *next_;
  Node<T> *prev_;
};

template<typename T>
class Deque {
 private:
  Node<T> *head_;
  Node<T> *tail_;
 public:

  Deque() : head_(nullptr), tail_(nullptr) {}

  ~Deque() = default;

  void push_front(T value) {
    Node<T> *tmp = new (Node<T>);
    tmp->next_ = head_;
    tmp->prev_ = nullptr;
    tmp->value_ = value;
    if (head_ == nullptr) {
      head_ = tmp;
      tail_ = head_;
      return;
    }
    head_->prev_ = tmp;
    head_ = tmp;
  }

  void push_back(T value) {
    if (head_ == nullptr) {
      push_front(value);
      return;
    }
    Node<T> *tmp = new (Node<T>);
    tmp->next_ = nullptr;
    tmp->prev_ = tail_;
    tmp->value_ = value;
    tail_->next_ = tmp;
    tail_ = tmp;
  }

  T front() {
    return head_->value_;
  }

  T back() {
    return tail_->value_;
  }

  void delete_first() {
    if (head_) {
      Node<T> *tmp = head_;
      if (head_ != tail_) {
        head_ = tmp->next_;
        tmp->next_->prev_ = nullptr;
      } else {
        head_ = nullptr;
        tail_ = nullptr;
      }
      delete tmp;
    }
  }

  void delete_last() {
    if (tail_) {
      if (tail_ == head_) {
        delete_first();
      } else {
        Node<T> *tmp = tail_;
        tmp->prev_->next_ = nullptr;
        tail_ = tmp->prev_;
        delete tmp;
      }
    }
  }
};

#endif //DEQUE__DEQUE_H_
