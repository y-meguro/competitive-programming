#include <bits/stdc++.h>
using namespace std;

struct Node {
  char data;
  Node* next;
  Node(char c) : data(c), next(nullptr) {}
};

void printList(Node* head) {
  while (head) {
    cout << head->data << " --> ";
    head = head->next;
  }
  cout << "nullptr" << endl;
}

void deleteNode(Node* node) {
  if (node == nullptr || node->next == nullptr) return;
  Node* nextNode = node->next;
  node->data = nextNode->data;
  node->next = nextNode->next;
  delete nextNode;
  return;
}

int main() {
  Node* head = new Node('a');
  head->next = new Node('b');
  head->next->next = new Node('c');
  head->next->next->next = new Node('d');
  head->next->next->next->next = new Node('e');
  printList(head);

  deleteNode(head->next->next);
  printList(head);
  return 0;
}