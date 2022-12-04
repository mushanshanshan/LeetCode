class MyHashMap {
private:
    vector<vector<int>> hash;

public:
    MyHashMap() {
        hash.resize(1001, vector<int>());
    }
    
    void put(int key, int value) {
        int first = key / 1000, second = key % 1000;
        if (hash[first].size() == 0) hash[first].resize(1001, -1);
        hash[first][second] = value;
    }
    
    int get(int key) {
        if (hash[key / 1000].size() == 0) return -1;
        return hash[key / 1000][key % 1000];
    }
    
    void remove(int key) {
        if (hash[key / 1000].size() == 0) return;
        hash[key / 1000][key % 1000] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */