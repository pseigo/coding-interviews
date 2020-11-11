#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Node {
  T data;
  Node *next;
  Node(T data = T(), Node *next = nullptr) : data(data), next(next) { }
};

template <typename T>
Node<T>* create_linked_list(vector<T> nodeValues)
{
  if (nodeValues.empty()) {
    return nullptr;
  }

  Node<T> *head = new Node<T>(nodeValues.at(0));
  Node<T> *prev = nullptr;
  Node<T> *curr = head;

  for (size_t i = 1; i < nodeValues.size(); i++) {
    prev = curr;
    curr = new Node<T>(nodeValues.at(i));
    prev->next = curr;
  }

  return head;
}

template <typename T>
void print(Node<T> *head)
{
  if (head != nullptr) {
    while (head != nullptr) {
      cout << head->data << " ";
      head = head->next;
    }
    cout << endl;
  }
}

// Returns the head of the reversed linked list
template <typename T>
Node<T>* reverse(Node<T> *head)
{
  Node<T> *prev = nullptr;
  Node<T> *curr = head;

  while (curr != nullptr) {
    Node<T> *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}

int main()
{
  Node<int> *head = create_linked_list(vector<int>{1, 2, 3, 4, 5});
  print(head);

  head = reverse(head);
  print(head);
}
