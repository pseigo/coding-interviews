#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int data;
  Node *next;
};

Node* reverse(Node *head)
{
  Node *prev = nullptr;
  Node *curr = head;

  while (curr != nullptr) {
    Node *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}

int main()
{
  Node<int> *head = create_linked_list(vector<int>{1, 2, 3, 4, 5});
  head = reverse(head);
}
