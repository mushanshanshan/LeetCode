class Tree {
public:
    Tree* child[26];
    bool end;
    Tree() {
        end = false;
        for (int i=0; i<26; i++) {
            child[i] = nullptr;
        }
    }
};

class Trie {
public:
    Tree* root;
    
    Trie() {
        root = new Tree();
    }
    
    void insert(string word) {
        Tree* cur = root;
        for (char c: word) {
            if (!cur->child[c - 'a']) {
                cur->child[c - 'a'] = new Tree();
            }
            cur = cur->child[c - 'a'];
        }
        cur->end = true;
        
    }
    
    bool search(string word) {
        Tree* cur = root;
        for (char c: word) {
            if (!cur->child[c - 'a']) {
                return false;
            }
            cur = cur->child[c - 'a'];
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        Tree* cur = root;
        for (char c: prefix) {
            if (!cur->child[c - 'a']) {
                return false;
            }
            cur = cur->child[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */