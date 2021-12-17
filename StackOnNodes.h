#ifndef STACK_NODES__STACKONNODES_H_
#define STACK_NODES__STACKONNODES_H_

template<typename T>
struct Node {
  T value_;
  Node *next_;
};

template<typename T>
class StackOnNodes {
 private:
  Node<T> *head_;
  int size_;
 public:
  StackOnNodes() : size_(0) {
    head_ = nullptr;
  }
  ~StackOnNodes() = default;

  void push(T value) {
    Node<T> *a = new(Node<T>);
    a->next_ = head_;
    a->value_ = value;
    size_++;
    head_ = a;
  }

  T pop() {
    if(size_!= 0) {
      Node<T> *tmp = head_;
      head_ = tmp->next_;
      T answer = tmp->value_;
      size_--;
      delete tmp;
      return answer;
    }
    throw std::runtime_error("Stack is empty");
  }

  T top() {
    return head_->value_;
  }
};

#endif //STACK_NODES__STACKONNODES_H_
