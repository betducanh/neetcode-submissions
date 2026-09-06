struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() : children{}, isEnd(false) {}
};

class PrefixTree {
private:
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            int pos = c - 'a';
            if (curr->children[pos] == nullptr) {
                curr->children[pos] = new TrieNode();
            }
            curr = curr->children[pos];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            int pos = c - 'a';
            if (curr->children[pos] == nullptr) return false;
            curr = curr->children[pos];
        }

        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for (char c : prefix) {
            int pos = c - 'a';
            if (curr->children[pos] == nullptr) return false;
            curr = curr->children[pos];
        }

        return true;
    }
};
