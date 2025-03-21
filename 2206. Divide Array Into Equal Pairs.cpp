class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_map<int, int> counter;
    
            for (int i: nums) {
                counter[i]++;
            }
    
            for (auto &[key, value]: counter) {
                if (value % 2 != 0) return false;
            }
    
            return true;
        }
    };