class WordDictionary {
public:
    class Node {
    public:
        vector<Node*> child;
        bool end;

        Node (): end(false), child(26, nullptr) {}
    };

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        _addWord(word, 0, root);
    }
    
    bool search(string word) {
        return _search(word, 0, root);
    }

private:

    Node* root;

    void _addWord(string& word, int idx, Node* cur) {
        if (idx == word.size()) {
            cur->end = true;
            return;
        }
        int c = word[idx] - 'a';
        if (!cur->child[c]) cur->child[c] = new Node();
        _addWord(word, idx+1, cur->child[c]);
    }

    bool _search(string& word, int idx, Node* cur) {
        if (!cur) return false;
        if (idx == word.size()) {
            return cur->end;
        }

        bool res = false;
        if (word[idx] == '.') {
            for (auto c: cur->child) res = res || _search(word, idx+1, c);
        } else {
            res = res || _search(word, idx+1, cur->child[word[idx] - 'a']);
        }
        return res;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */