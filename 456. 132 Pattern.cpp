class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int nk = INT_MIN;
        stack<int> s;

        for (int i=nums.size()-1; i>=0; i--) {
            if (nums[i] < nk) return true;

            while (!s.empty() && s.top() < nums[i]) {
                nk = max(nk, s.top());
                s.pop();
            }
            s.push(nums[i]);
        }

        return false;
    }
};