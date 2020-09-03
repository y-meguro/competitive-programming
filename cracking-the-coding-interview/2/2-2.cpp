#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int d) : data(d), next(nullptr) {}
};

void insert(Node*& head, int data) {
  Node* newNode = new Node(data);
  newNode->next = head;
  head = newNode;
}

void printList(Node* head) {
  while (head) {
    cout << head->data << " --> ";
    head = head->next;
  }
  cout << "nullptr" << endl;
}

Node* kthToLastHelper(Node* curr, int k, int& i) {
  if (curr == nullptr) return nullptr;
  Node* node = kthToLastHelper(curr->next, k, i);
  ++i;
  if (i == k) {
    return curr;
  }
  return node;
}

// kthToLastHelperを使って、再帰で解く
Node* kthToLastRecursive(Node* head, int k) {
  int i = 0;
  return kthToLastHelper(head, k, i);
}

// ループのみで解く
Node* kthToLastIterative(Node* head, int k) {
  if (head == nullptr) return nullptr;

  Node* ptr1 = head;
  Node* ptr2 = head;

  // ptr2をptr1よりk個進める
  int i = 0;
  while (i < k && ptr1) {
    ptr2 = ptr2->next;
    ++i;
  }

  // out of bounds
  if (i < k) return nullptr;

  while (ptr2) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  return ptr1;
}

int main() {
  Node* head = nullptr;
  for (int i = 0; i < 10; i++) {
    insert(head, i);
  }
  printList(head);

  Node* node4 = kthToLastRecursive(head, 4);
  if (node4 != nullptr) {
    cout << node4->data << endl;
  } else {
    cout << "NULL NODE" << endl;
  }

  Node* node6 = kthToLastRecursive(head, 6);
  if (node6 != nullptr) {
    cout << node6->data << endl;
  } else {
    cout << "NULL NODE" << endl;
  }
  return 0;
}