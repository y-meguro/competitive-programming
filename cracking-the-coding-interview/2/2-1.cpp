#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data = 0;
  Node* next = nullptr;
};

// 先頭に挿入する
void insert(Node*& head, int data) { // ポインタ変数が参照される。参照されるので呼び出し元のheadも書き換わる
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = head; // nextには1つ前に先頭だったnodeのポインタが入る
  head = newNode;
}

void printList(Node* head) {
  while (head) {
    cout << head->data << " --> ";
    head = head->next;
  }
  cout << "nullptr" << endl;
}

int main() {
  Node* head = nullptr;
  for (int i = 0; i < 10; i++) {
    insert(head, i);
  }
  printList(head);
  return 0;
}