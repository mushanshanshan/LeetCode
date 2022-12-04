class Solution {
public:
    static bool cmp(pair<int,int>& a, pair<int,int>& b) {
        return a.second > b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        vector<int> res(k, 0);
        vector<pair<int,int>> counter;
        int cur = nums[0], freq = 1;
        
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] == cur) {
                freq++;
            } else {
                counter.push_back({cur, freq});
                cur = nums[i];
                freq = 1;
            }
        }
        
        counter.push_back({cur, freq});
        
        sort(counter.begin(), counter.end(), cmp);
        
        for (int i=0; i<k; i++) {
            res[i] = counter[i].first;
        }
        
        return res;
        
    }
};