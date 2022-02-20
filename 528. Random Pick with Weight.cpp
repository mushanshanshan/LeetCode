class Solution {
private:
    vector<int> weight;
    
public:
    Solution(vector<int>& w) {
        weight.resize(w.size());
        weight[0] = w[0];
        for (int i=1; i<w.size(); i++) {
            weight[i] = weight[i-1] + w[i];
        }
    }
    
    int pickIndex() {
        int random = rand() % weight[weight.size()-1] + 1;
        
        int l=0, r = weight.size() - 1;
        
        while (l < r) {
            int mid = (l + r) / 2;
            if (weight[mid] > random) {
                r = mid;
            } else if (weight[mid] < random) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */