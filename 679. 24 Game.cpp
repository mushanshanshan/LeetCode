class Solution {
private:
    double eps;
    
public:
    
    bool backtracking(vector<double>& nums) {
        if (nums.size() == 1) {
            if (abs(nums[0] - 24.0) < eps) return true;
            return false;
        }
        
        bool res = false;
        
        for (int i=0; i<nums.size(); i++) {
            for (int j=i+1; j<nums.size(); j++) {
                vector<double> t;
                for (int k = 0; k<nums.size(); k++) {
                    if (k != j && k != i) t.push_back(nums[k]);
                }
                
                t.push_back(nums[i] + nums[j]);
                res = res || backtracking(t);
                t.pop_back();
                
                t.push_back(nums[i] * nums[j]);
                res = res || backtracking(t);
                t.pop_back();
                
                t.push_back(nums[i] - nums[j]);
                res = res || backtracking(t);
                t.pop_back();
                
                t.push_back(nums[j] - nums[i]);
                res = res || backtracking(t);
                t.pop_back();
                
                t.push_back(nums[i] / nums[j]);
                res = res || backtracking(t);
                t.pop_back();
                
                t.push_back(nums[j] / nums[i]);
                res = res || backtracking(t);
                t.pop_back();
            }
        }
        
        return res;
    }
    
    bool judgePoint24(vector<int>& cards) {
        bool res;
        vector<double> nums(cards.begin(), cards.end());
        eps = 0.0001;
        res = backtracking(nums);
        return res;
    }
};