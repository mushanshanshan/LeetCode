class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        int res=0, count, left, right;
        
        for (int& i: nums) hash.insert(i);
        
        while (!hash.empty()) {
            count = 1;
            left = *(hash.begin());
            right = left;

            hash.erase(right);
            
            while (hash.count(--left)) {

                count++;
                hash.erase(left);
            }
            
            while (hash.count(++right)) {
 
                count++;
                hash.erase(right);
            }
            
            res = max(res, count);
            
        }
        
        return res;
    }
};