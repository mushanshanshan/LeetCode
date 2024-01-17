class RandomizedSet {
private:
    unordered_map<int, int> position;
    vector<int> data;

public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (position.find(val) != position.end()) {
            return false;
        } else {
            data.push_back(val);
            position[val] = data.size() - 1;
            return true;
        }
        
    }
    
    bool remove(int val) {
        if (position.find(val) != position.end()) {
            data[position[val]] = data.back();
            position[data.back()] = position[val];
            data.pop_back();
            position.erase(val);
            return true;
        } else {
            return false;
        }
        
    }
    
    int getRandom() {
        int rand_index = rand() % data.size();
        return data[rand_index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */