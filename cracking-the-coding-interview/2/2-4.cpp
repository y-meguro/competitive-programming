#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int d) : data(d), next(nullptr) {}
};

// 最後尾に挿入する
void insert(Node*& head, int data) {
  Node* newNode = new Node(data);
  if (head == nullptr) {
    head = newNode;
  } else {
    Node* curr = head;
    while (curr->next) {
      curr = curr->next;
    }
    curr->next = newNode;
  }
}

void printList(Node* head) {
  while (head) {
    cout << head->data << " --> ";
    head = head->next;
  }
  cout << "nullptr" << endl;
}

// 前半のリストと後半のリストを作って最後につなげる
Node* partition(Node* head, int x) {
  Node* curr = head;
  // 前半のリスト
  Node* firstCurr = nullptr;
  Node* firstInitial = nullptr;
  // 後半のリスト
  Node* secondCurr = nullptr;
  Node* secondInitial = nullptr;

  while (curr != nullptr) {
    if (curr->data < x) {
      if (firstCurr == nullptr) firstInitial = curr;
      else firstCurr->next = curr;
      firstCurr = curr;
    } else {
      if (secondCurr == nullptr) secondInitial = curr;
      else secondCurr->next = curr;
      secondCurr = curr;
    }
    curr = curr->next;
  }

  firstCurr->next = secondInitial;
  secondCurr->next = nullptr;
  return firstInitial;
}

int main() {
  Node* head = nullptr;
  for (int i = 0; i < 10; ++i) {
    insert(head, rand() % 10);
  }
  printList(head);
  printList(partition(head, 5));
  return 0;
}