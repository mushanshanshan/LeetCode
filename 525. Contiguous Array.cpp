class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> dict;
        int res = 0, cnt = 0;
            
        dict[0] = -1;
        for (int i=0; i<nums.size(); i++) {
            cnt += nums[i] == 0? -1 : 1;
            if (dict.find(cnt) != dict.end()) {
                res = max(res, i - dict[cnt]);
            } else {
                dict[cnt] = i;
            }
        }
        
        return res;
        
    }
};