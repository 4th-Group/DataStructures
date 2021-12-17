#ifndef STACK_NODES__QUEUEONNODES_H_
#define STACK_NODES__QUEUEONNODES_H_

template<typename T>
struct Node {
  T value_;
  Node *next_;
};

template<typename T>
class QueueOnNodes {
 private:
  Node<T> *head_;
  Node<T> *tail_;
  int size_;
 public:
  QueueOnNodes() : size_(0) {
    head_ = nullptr;
    tail_ = nullptr;
  }
  ~QueueOnNodes() {
    while (size_ != 0) {
      pop();
    }
  };

  void push(T value) {
    Node<T> *a = new(Node<T>);
    a->next_ = nullptr;
    a->value_ = value;
    if (size_ != 0) {
      tail_->next_ = a;
    }
    tail_ = a;
    if (size_ == 0) {
      head_ = tail_;
    }
    size_++;
  }

  T pop() {
    if (size_ != 0) {
      Node<T> *tmp = head_;
      head_ = tmp->next_;
      T answer = tmp->value_;
      size_--;
      delete tmp;
      return answer;
    }
    throw std::runtime_error("Queue is empty");
  }

  T front() {
    return head_->value_;
  }

  T back() {
    return tail_->value_;
  }

  bool isEmpty() {
    return !bool(size_);
  }
};

#endif //STACK_NODES__QUEUEONNODES_H_
