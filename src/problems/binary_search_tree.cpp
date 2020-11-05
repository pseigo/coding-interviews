#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Node {
    Node *left; 
    Node *right;
    T value;
};

template <typename T>
Node<T>* create_node(const T &value)
{
    Node<T> *node = new Node<T>;
    node->left = nullptr;
    node->right = nullptr;
    node->value= value;
    return node; 
}

// Inserts a node in the BST rooted by `root` and returns it.
template <typename T>
Node<T>* insert(Node<T> *&root, const T &value)
{
    if (root == nullptr) {
        root = create_node(value);
        return root;
    }

    // Duplicate value
    if (root->value == value) {
        if (root->left == nullptr) {
            root->left = create_node(value); 
            return root->left;
        } else if (root->right == nullptr) {
            root->right = create_node(value); 
            return root->right;
        } else {
            return insert(root->left, value);
        }
    }

    if (value < root->value) {
        return insert(root->left, value);
    } else {
        return insert(root->right, value);
    }
}

template <typename T>
void print_preorder(Node<T> *root)
{
    if (root == nullptr) {
        return;
    }
    std::cout << root->value << std::endl;
    print_inorder(root->left);
    print_inorder(root->right);
    return;
}

template <typename T>
void print_inorder(Node<T> *root)
{
    if (root == nullptr) {
        return;
    }
    print_inorder(root->left);
    std::cout << root->value << std::endl;
    print_inorder(root->right);
    return;
}

template <typename T>
void print_postorder(Node<T> *root)
{
    if (root == nullptr) {
        return;
    }
    print_inorder(root->left);
    print_inorder(root->right);
    std::cout << root->value << std::endl;
    return;
}

template <typename T>
void delete_tree(Node<T> *root)
{
    if (root == nullptr) {
        return;
    }
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
    return;
}

// Performs a binary search for a node with the `value` on the BST rooted by `root`.
// Returns nullptr if such a node does not exist. 
template <typename T>
Node<T>* binary_search(Node<T> *root, const T &value)
{
    if (root == nullptr) return nullptr;
    else if (value < root->value) return binary_search(root->left, value);
    else if (value > root->value) return binary_search(root->right, value);
    else return root;
}

// Performs a depth-first search for a node with `value` on the binary tree rooted by
// `root`. Returns nullptr if such a node does not exist.
template <typename T>
Node<T>* dfs(Node<T> *root, const T &value)
{
    if (root == nullptr) {
	return nullptr;
    } else if (root->value == value) {
	return root;
    }

    Node<T> *left = dfs(root->left, value);
    if (left != nullptr) {
	return left;
    }

    return dfs(root->right, value);
}


int main()
{
    Node<int> *root = create_node<int>(10);

    std::vector<int> values = {15, 5, 7, 5, 3, 20, 2, -1};
    for (const int &i : values) {
        insert<int>(root, i);
    }

    std::cout << "===================\n"
              << "Preorder traversal:" << std::endl;
    print_preorder(root);

    std::cout << "==================\n"
              << "Inorder traversal:" << std::endl;
    print_inorder(root);

    std::cout << "====================\n"
              << "Postorder traversal:" << std::endl;
    print_postorder(root);

    for (const int &search_value : values) {
        Node<int> *binary_search_result = dfs(root, search_value);
        if (binary_search_result == nullptr) {
            std::cout << "Did not find the value "
                << search_value << " in the BST." << std::endl;
        } else {
            std::cout << "Found the value " << search_value
                << " in the BST. Sanity check: the node's value is also "
                << binary_search_result->value << "." << std::endl;
        }
    }

    delete_tree(root);
}
