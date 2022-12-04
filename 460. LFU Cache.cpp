class LFUCache {
private:
    int cap, minFreq, maxCap;
    unordered_map <int, pair<int, int>> m;
    unordered_map <int, list<int>> freq;
    unordered_map <int, list<int>::iterator> iter;

public:
    LFUCache(int capacity) {
        cap = capacity;
        maxCap = capacity;
        
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        
        freq[m[key].second].erase(iter[key]);
        m[key].second++;
        freq[m[key].second].push_back(key);
        iter[key] = --freq[m[key].second].end();
        if (freq[minFreq].size() == 0) minFreq++;
        return m[key].first;
    }
    
    void put(int key, int value) {
        if (maxCap == 0) return;
        if (get(key) != -1) {
            m[key].first = value;
        } else {
            if (cap == 0) {
                m.erase(freq[minFreq].front());
                iter.erase(freq[minFreq].front());
                freq[minFreq].pop_front();
            } else {
                cap--;
            }
            
            m[key] = {value, 1};
            freq[1].push_back(key);
            iter[key] = --freq[1].end();
            minFreq = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */