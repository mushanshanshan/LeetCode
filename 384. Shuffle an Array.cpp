class Solution {
    
    
public:
    vector<int> vec;
    
    Solution(vector<int>& nums) {
        vec = nums;
    }
    
    vector<int> reset() {
        return vec;
    }
    
    vector<int> shuffle() {
        if (vec.empty()) return vec;
        
        vector<int> temp(vec);
        
        for (int i=0; i<vec.size(); i++) {
            int j = std::rand() % vec.size();
            std::swap(temp[i], temp[j]);
        }
        
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */