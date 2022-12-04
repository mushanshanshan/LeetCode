class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        int n = res.size();
        
        stack<int> numbers, index;
        
        
        for (int i=0; i< 2*n; i++) {
            if (numbers.empty() || numbers.top() >= nums[i%n]) {
                numbers.push(nums[i%n]);
                index.push(i%n);
            } else {
                while (!numbers.empty() && numbers.top() < nums[i%n]) {
                    res[index.top()%n] = nums[i%n];
                    numbers.pop();
                    index.pop();
                }
                numbers.push(nums[i%n]);
                index.push(i%n);
            }
            
        }
        return res;
    }
};