class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainderCount;
        int N = arr.size();
        
        for (int num : arr) {
            int rem = ((num % k) + k) % k;
            remainderCount[rem]++;
        }
        
        for (auto& [rem, count] : remainderCount) {
            if (rem == 0) {
                if (count % 2 != 0) return false;
            } else {
                int complement = k - rem;
                if (remainderCount[complement] != count) return false;
            }
        }
        
        return true;
    }
};