#include <bits/stdc++.h>
#include "stack.hpp"
using namespace std;

template <typename T>
class StackMin {
  public:
    template <typename U>
    void push(U&& value) {
      if (minStack.isEmpty() || value <= minStack.peek()) minStack.push(value);
      stack.push(forward<U>(value));
    }

    T& peek() {
      return stack.peek();
    }

    T& min() {
      return minStack.peek();
    }

    T pop() {
      auto value = stack.pop();
      if (value == min()) minStack.pop();
      return value;
    }

    bool isEmpty() {
      return stack.isEmpty();
    }

  private:
    Stack<T> stack; // 最小値以外を管理
    Stack<T> minStack; // 最小値を管理
};

int main() {
  StackMin<int> stack;
  for (auto v: {5, 10, 4, 9, 3, 3, 8, 2, 7, 6}) {
    stack.push(v);
    cout << "Pushed value: " << v << ", min value: " << stack.min() << endl;
  }
  cout << "=================" << endl;

  while (!stack.isEmpty()) {
    auto v = stack.pop();
    cout << "Popped value: " << v;
    if (stack.isEmpty()) cout << ", stack is empty" << endl;
    else cout << ", min value: " << stack.min() << endl;
  }

  return 0;
}
