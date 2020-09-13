#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack {
  public:
    Stack() : top(nullptr), stackSize(0) {}
    Stack(Stack&& other) : top(move(other.top)), stackSize(move(other.stackSize)) {}
    ~Stack() {
      while (!isEmpty()) pop();
    }

    template <typename U>
    void push(U&& value) {
      auto n = new Node(forward<U>(value), top);
      top = n;
      ++stackSize;
    }

    T& peek() {
      if (!top) throw StackIsEmptyException();
      return top->value;
    }

    T pop() {
      if (!top) throw StackIsEmptyException();
      auto value(move(top->value));
      auto n = top;
      top = n->next;
      delete n;
      --stackSize;
      return value;
    }

    bool isEmpty() const {
      return !top;
    }

    size_t size() const {
      return stackSize;
    }

    class StackIsEmptyException {};

  private:
    struct Node {
      T value;
      Node* next;

      Node(T&& v, Node* n) : value(move(v)), next(n) {}
      Node(const T& v, Node* n) : value(v), next(n) {}
    };

    Node* top;
    size_t stackSize;
};
