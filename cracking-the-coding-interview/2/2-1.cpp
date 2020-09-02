#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data = 0;
  Node* next = nullptr;
};

void insert(Node*& head, int data) {
  Node* newNode = new Node;
  newNode->data = data;
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

// 一時的なバッファを使える場合。time complexity O(n), space complexity O(n)
void removeDuplicate(Node* head) {
  if (head == nullptr || head->next == nullptr) return; // リストのNodeが1つもない場合と1つしかない場合はreturn
  Node* prev = head;
  Node* curr = head->next;
  unordered_map<int, int> node_map;
  node_map[prev->data] = 1;
  while (curr) {
    while (curr && node_map.find(curr->data) != node_map.end()) { // findが成功した場合(重複があった場合)は飛ばす
      curr = curr->next;
    }
    prev->next = curr;
    node_map[curr->data] = 1;
    prev = curr;
    curr = curr->next;
  }
}

// 一時的なバッファを使えない場合。time complexity O(n^2), space complexity O(1)
void removeDuplicate2(Node* head) {
  if (head == nullptr || head->next == nullptr) return; // リストのNodeが1つもない場合と1つしかない場合はreturn
  Node* curr = head;
  while (curr) {
    Node* runner = curr;
    while (runner->next) {
      if (runner->next->data != curr->data) {
        runner = runner->next;
      } else {
        runner->next = runner->next->next;
      }
    }
    curr = curr->next;
  }
}

int main() {
  Node* head = nullptr;
  for (int i = 0; i < 10; i++) {
    insert(head, i);
  }
  for (int i = 3; i < 5; i++) {
    insert(head, i);
  }
  printList(head);
  removeDuplicate(head);
  printList(head);

  for (int i = 6; i < 9; i++) {
    insert(head, i);
  }
  printList(head);
  removeDuplicate2(head);
  printList(head);
  return 0;
}