// Design Add and Search Words Data Structure
#include <string>
using namespace std;

struct TrieNode {
    TrieNode* children[26] = {nullptr};
    bool isEndOfWord = false;
};

class WordDictionary {
    // trie
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    // 標準 Trie 插入
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children[c - 'a']) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        return searchInNode(word, 0, root);
    }

private:
    // 因為有 '.'，需要用 DFS 遞迴搜尋
    bool searchInNode(const string& word, int index, TrieNode* node) {
        if (!node) return false;
        if (index == word.size()) return node->isEndOfWord;
        
        char c = word[index];
        if (c != '.') {
            // 普通字元：直接往下走
            return searchInNode(word, index + 1, node->children[c - 'a']);
        } else {
            // 萬用字元：26個方向都試試看
            for (int i = 0; i < 26; i++) {
                if (node->children[i]) {
                    if (searchInNode(word, index + 1, node->children[i])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */