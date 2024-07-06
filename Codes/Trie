#include <iostream>
#include <unordered_map>

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    bool search(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }
};

int main() {
    Trie trie;
    trie.insert("newsletter");
    trie.insert("news");

    std::string searchWord = "news";
    if (trie.search(searchWord)) {
        std::cout << searchWord << " found in Trie\n";
    } else {
        std::cout << searchWord << " not found in Trie\n";
    }
    return 0;
}

