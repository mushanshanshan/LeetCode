class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int min_num = INT_MAX, res = INT_MAX;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] % 2 == 1) nums[i]*=2;
            pq.emplace(nums[i]);
            min_num = min(min_num, nums[i]);
        }

        while (pq.top() % 2 == 0) {
            int temp = pq.top() / 2;
            res = min(res, pq.top() - min_num);
            pq.emplace(temp);
            pq.pop();
            min_num = min(min_num, temp);
        }
        
        return min(res, pq.top() - min_num);
    }
};