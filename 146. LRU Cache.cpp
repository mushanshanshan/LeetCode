class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        
        int res = m[key].first;
        auto it = m[key].second;
        l.erase(it);
        l.push_front(key);
        m[key] = {res, l.begin()};
        return res;
    }
    
    void put(int key, int value) {
        if (m.find(key) == m.end()) {
            l.push_front(key);
            m[key] = {value, l.begin()};
            if (cap - 1 < 0) {
                m.erase(l.back());
                l.pop_back();
            } else {
                cap--;
            } 
        } else {
                auto it = m[key].second;
                l.erase(it);
                l.push_front(key);
                m[key] = {value, l.begin()};
            }
    }
    
private:
    list<int> l;
    unordered_map<int, pair<int, list<int>::iterator>> m;
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */