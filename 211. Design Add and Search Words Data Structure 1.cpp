class WordDictionary {
public:
    
    class Node {
        public:
        
            bool word = false;
            vector<Node*> child = vector<Node*>(27, NULL);

            Node* get(char c) {
                if (c == '.') {
                    return child[26];
                } else {
                    return child[int(c - 'a')];
                }
            }

            void add(char c) {
                child[int(c - 'a')] = new Node();
                if (!child[26]) {
                    child[26] = new Node();
                }
            }
    };
    
    
    Node* root;
    
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        _add(word, 0, root);
    }
    
    
    void _add(string word, int pos, Node* cur) {
        if (pos == size(word)) {
            cur->word = true;
            return;
        }
        if (!cur->get(word[pos])) {
            cur->add(word[pos]);
        }
        _add(word, pos+1, cur->get(word[pos]));
        _add(word, pos+1, cur->get('.'));
    }
    
    bool search(string word) {
        Node* cur = root;
        for (char c: word) {
            cur = cur->get(c);
            if (!cur) return false;
        }
        if (cur->word) return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */