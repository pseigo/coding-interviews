#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Node {
  T data;
  Node *next;

  Node(T data = T(), Node *next = nullptr) : data(data), next(next) { }
};

// Not really needed, just wanted to make it. I don't use it anywhere besides
// main() because I'd rather spend time dealing with pointers.
template <typename T>
struct NodePtr {
  Node<T> *ptr;

  NodePtr(Node<T> *ptr = nullptr) : ptr(ptr) { }

  constexpr NodePtr(const NodePtr &other) : ptr(other.ptr) { }
  constexpr NodePtr operator=(const NodePtr &other)
  {
    ptr = other.ptr;
    return *this;
  }

  NodePtr operator ++() // prefix ++
  {
    ptr = ptr->next;
    return *this;
  }

  NodePtr operator ++(int) // postfix ++
  {
    NodePtr original(ptr);
    ptr = ptr->next;
    return original;
  }

  Node<T>* operator ->() const
  {
    return ptr;
  }
};

template <typename T> Node<T>* create_linked_list(vector<T> nodeValues);
template <typename T> void print(Node<T> *head);
template <typename T> Node<T>* reverse(Node<T> *head);

template <typename T> pair<size_t, Node<T>*> size_and_midpoint(Node<T> *head);
template <typename T> void divorce(Node<T> *list, size_t index);
template <typename T> Node<T>* merge(Node<T> *left, Node<T> *right);

// Returns: Head of the sorted linked list.
// Note: Modifies the linked list in place.
template <typename T>
Node<T>* mergesort(Node<T> *head)
{
  if (head == nullptr) {
    return nullptr;
  } else if (head->next == nullptr) {
    return head;
  }

  pair<size_t, Node<T>*> sizeAndMidpoint = size_and_midpoint(head);
  divorce(head, ceil(sizeAndMidpoint.first/2) - 1);

  Node<T>* left = mergesort(head);
  Node<T>* right = mergesort(sizeAndMidpoint.second);

  return merge(left, right);
}

int main()
{
  cout << "=> Reverse a linked list:" << endl;
  NodePtr<int> head = NodePtr<int>(create_linked_list(vector<int>{1, 2, 3, 4, 5}));
  print(head.ptr);

  head = reverse(head.ptr);
  print(head.ptr);

  cout << "\n=> Sort a linked list (using mergesort):" << endl;

  NodePtr<int> unsorted = NodePtr<int>(create_linked_list(vector<int>{8, 4, 5, -1, 5, 234, 1, -3, 564, 123, 19, -23}));
  print(unsorted.ptr);

  unsorted = mergesort(unsorted.ptr);
  print(unsorted.ptr);
}

/*********** MERGESORT HELPERS ***********/
// Midpoint is the node at index ceil(size / 2)
template <typename T>
pair<size_t, Node<T>*> size_and_midpoint(Node<T> *head)
{
  size_t size = 0;
  Node<T> *mid = head;
  while (head != nullptr) {
    head = head->next;
    ++size;

    if (size % 2 == 0) {
      mid = mid->next;
    }
  }
  return make_pair(size, mid);
}

// Side-effects: Sets the `index`th node's `next` pointer to nullptr. If
// `index` >= the size of the list, this function does nothing.
template <typename T>
void divorce(Node<T> *list, size_t index)
{
  for (size_t i = 0; list != nullptr && i < index; i++) {
    list = list->next;
  }
  list->next = nullptr;
}

// Returns: Head of the sorted sub-problem.
template <typename T>
Node<T>* merge(Node<T> *left, Node<T> *right)
{
  // Choose the first node
  Node<T>* curr = nullptr;
  if (left->data < right->data) {
    curr = left;
    left = left->next;
  } else {
    curr = right;
    right = right->next;
  }

  Node<T> *head = curr;

  // Add the rest of the nodes
  while (left != nullptr || right != nullptr) {
    // Add the left list's next node if:
    //   a) Right list is empty, or
    //   b) Both are non-empty and the left list's next node's data is smaller.
    // Otherwise, use the right list's next node.
    if (!right || (left && (left->data < right->data))) {
      curr->next = left;
      left = left->next;
    } else {
      curr->next = right;
      right = right->next;
    }

    curr = curr->next;
  }

  return head;
}
/*********** END OF MERGESORT HELPERS ***********/

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

// Returns: Head of the reversed linked list.
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
