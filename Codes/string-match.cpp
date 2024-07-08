#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    TrieNode* failureLink;
    vector<int> output;
    
    TrieNode() : failureLink(nullptr) {}
};

class AhoCorasick {
    TrieNode* root;
    vector<string> keywords;

public:
    AhoCorasick(const vector<string>& keywords) : root(new TrieNode()), keywords(keywords) {
        buildTrie();
        buildFailureLinks();
    }
    
    void buildTrie() {
        for (int i = 0; i < keywords.size(); ++i) {
            TrieNode* node = root;
            for (char ch : keywords[i]) {
                if (node->children.find(ch) == node->children.end()) {
                    node->children[ch] = new TrieNode();
                }
                node = node->children[ch];
            }
            node->output.push_back(i);
        }
    }
    
    void buildFailureLinks() {
        queue<TrieNode*> q;
        for (auto& [ch, node] : root->children) {
            node->failureLink = root;
            q.push(node);
        }
        
        while (!q.empty()) {
            TrieNode* current = q.front();
            q.pop();
            
            for (auto& [ch, nextNode] : current->children) {
                TrieNode* failure = current->failureLink;
                while (failure && failure->children.find(ch) == failure->children.end()) {
                    failure = failure->failureLink;
                }
                if (failure) {
                    nextNode->failureLink = failure->children[ch];
                } else {
                    nextNode->failureLink = root;
                }
                nextNode->output.insert(nextNode->output.end(), nextNode->failureLink->output.begin(), nextNode->failureLink->output.end());
                q.push(nextNode);
            }
        }
    }
    
    vector<pair<int, int>> search(const string& text) {
        vector<pair<int, int>> result;
        TrieNode* node = root;
        
        for (int i = 0; i < text.size(); ++i) {
            while (node && node->children.find(text[i]) == node->children.end()) {
                node = node->failureLink;
            }
            if (node) {
                node = node->children[text[i]];
            } else {
                node = root;
            }
            
            for (int keywordIndex : node->output) {
                result.push_back({i - keywords[keywordIndex].size() + 1, keywordIndex});
            }
        }
        return result;
    }
};

int main() {
    vector<string> keywords = {"badword", "offensive", "inappropriate"};
    AhoCorasick ac(keywords);
    
    string text = "This is an example text with badword and other inappropriate content.";
    vector<pair<int, int>> matches = ac.search(text);
    
    for (auto& match : matches) {
        cout << "Match found for keyword '" << keywords[match.second] << "' at position " << match.first << endl;
    }
    
    return 0;
}
