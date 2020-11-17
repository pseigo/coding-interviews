#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    char key;
    bool terminates;
    vector<Node*> children;
    Node(int key, bool terminates = false) : key(key), terminates(terminates) { }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        addWord(word, 0, root);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(const string &word) {
        if (word.empty()) {
            return false;
        }

        for (Node *child : root) {
            if (search(word, 0, child)) {
                return true;
            }
        }
        return false;
    }

private:
    vector<Node*> root;

    void addWord(string word, size_t charIdx, vector<Node*> &nodes) {
        if (charIdx == word.length()) {
            return;
        }

        const char searchChar = word[charIdx];
        auto res = find_if(nodes.begin(), nodes.end(),
            [=](Node *n) {
                return n != nullptr && n->key == searchChar;
            }
        );

        if (res == nodes.end()) {
            Node *n = new Node(searchChar);
            nodes.push_back(n);

            if (charIdx + 1 >= word.length()) {
                n->terminates = true;
                return;
            } else {
                return addWord(word, charIdx + 1, n->children);
            }
        } else if (charIdx + 1 >= word.length()) {
            (*res)->terminates = true;
            return;
        }

        return addWord(word, charIdx + 1, (*res)->children);
    }

    bool search(const string &word, size_t charIdx, Node *curr) {
        const char searchChar = word[charIdx];

        // Check if this character is NOT a match
        if (searchChar != '.' && curr->key != searchChar) {
            return false;
        }

        if (charIdx + 1 >= word.length()) {
            return curr->terminates;
        }

        for (Node *child : curr->children) {
            if (search(word, charIdx + 1, child)) {
                return true;
            }
        }

        return false;
    }
};

void contains(WordDictionary &wd, string word)
{
    bool contains = wd.search(word);
    cout << "dictionary " << (contains ? "contains" : "does not contain")
        << " the word \"" << word << "\"" << endl;
}

int main()
{
    WordDictionary wd;
    wd.addWord("yike");
    for (size_t i = 0; i < 6; i++) {
        contains(wd, string("yikes").substr(0, i));
    }
    for (size_t i = 0; i < 5; i++) {
        contains(wd, string("aaaa").substr(0, i));
    }
    for (size_t i = 0; i < 6; i++) {
        contains(wd, string(".....").substr(0, i));
    }
    contains(wd, "yi.e");
}
