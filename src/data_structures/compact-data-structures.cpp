{ // Tree
  struct Node {
    int key;
    std::string data;
    std::vector<Node*> children;
    Node(int key, std::string data) : key(key), data(data) { }
  };
}

{ // Trie
  struct Node {
    char key;
    bool terminates;
    std::vector<Node*> children;
    Node(int key, bool terminates = false) : key(key), terminates(terminates) { }
  };
}

{ // Linked list (or use std::list<T> or std::forward_list<T>)
  struct Node {
      int data;
      Node *prev;
      Node *next;
      Node(int data) : data(data) { }
  };

  Node *head = new Node(1);
  Node *curr = head;
  for (size_t i = 1; i < 5; i++) {
    curr->next = new Node(i);
    curr = curr->next;
  }

  curr = head;
  while (curr != nullptr) {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

{ // Graph: Adjacency matrix (row = from, col = to)
    constexpr size_t numNodes = 10;
    bool graphArr[numNodes][numNodes];
    std::vector<std::vector<bool>> graph(numNodes, std::vector<bool>(numNodes, 0));

    for (int row = 0; row < numNodes; row++) {
        for (int col = 0; col < numNodes; col++) {
            graph[row][col] = true;
            cout << graph[row][col] << ' ';
        }
        cout << endl;
    }
}

{ // Graph: Adjacency list (with a map)
  std::map<int, std::forward_list<int>> graph = {
    {1, {2, 3, 4, 1}},
    {2, {}},
    {3, {1}}
  };

  for (const auto & entry : graph) {
    cout << entry.first << " => ";
    for (const auto & to : entry.second) {
      cout << to << ' ';
    }
    cout << endl;
  }
}

{ // Graph: Adjacency list (with structs)
  struct Node {
    std::string name;
    std::vector<Node*> children;
    Node(std::string name) : name(name) { }
  };
  struct Graph {
    std::vector<Node*> nodes;
  };

  constexpr size_t numNodes = 3;
  Graph g;

  for (size_t i = 0; i < numNodes; ++i) {
      g.nodes.push_back(new Node(std::to_string(i)));
  }

  g.nodes[0]->children.push_back(g.nodes[1]);
  g.nodes[0]->children.push_back(g.nodes[2]);
  g.nodes[2]->children.push_back(g.nodes[0]);

  for (const auto & n : g.nodes) {
      cout << n->name << " => ";
      for (const auto & c : n->children) {
          cout << c->name << " ";
      }
      cout << endl;
  }
}
