#include <bits/stdc++.h>
#include "stack.hpp"
using namespace std;

template <typename T>
class MyQueue {
  public:
    template <typename U>
    void add(U&& value) {
      newValues.push(forward<U>(value));
    }

    T peek() {
      if (reversed.isEmpty()) move(newValues, reversed);
      return reversed.peek();
    }

    T remove() {
      if (reversed.isEmpty()) move(newValues, reversed);
      return reversed.pop();
    }

    bool isEmpty() {
      return newValues.isEmpty() && reversed.isEmpty();
    }

  private:
    Stack<T> newValues; // reversed が空でない間に add された値をためておく
    Stack<T> reversed; // newValues にたまった値を逆順で入れる（古い値が stack の上に来る）

    static void move(Stack<T>& from, Stack<T>& to) {
      while (!from.isEmpty()) to.push(from.pop());
    }
};

int main() {
  MyQueue<int> queue;
  for (int i = 0; i < 10; ++i) {
    queue.add(i);
    cout << "Queue value " << i << endl;
  }

  for (int i = 0; i < 5; ++i) {
    cout << "Removed value " << queue.remove() << endl;
  }

  for (int i = 10; i < 15; ++i) {
    queue.add(i);
    cout << "Queue value " << i << endl;
  }

  while (!queue.isEmpty()) {
    cout << "Removed value " << queue.remove() << endl;
  }

  return 0;
}
