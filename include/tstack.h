// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

#include <stdexcept>

template<typename T, int SIZE>
class TStack {
 public:
  TStack() : idx_(-1) {}

  void add(const T& elem) {
    if (isFull()) {
      throw std::overflow_error("Stack overflow");
    }
    data_[++idx_] = elem;
  }

  void remove() {
    if (isEmpty()) {
      throw std::underflow_error("Stack underflow");
    }
    --idx_;
  }

  T peek() const {
    if (isEmpty()) {
      throw std::underflow_error("Empty stack");
    }
    return data_[idx_];
  }

  bool isEmpty() const {
    return idx_ == -1;
  }

  bool isFull() const {
    return idx_ + 1 >= limit;
  }

 private:
  static constexpr int limit = SIZE;
  T data_[limit];
  int idx_;
};

#endif  // INCLUDE_TSTACK_H_
