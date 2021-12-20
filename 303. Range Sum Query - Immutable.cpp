class NumArray {
public:
    vector<int> s;
    
    NumArray(vector<int>& nums) {
        int t = 0;
        s.push_back(t);
        for (int& i: nums) {
            t += i;
            s.push_back(t);
        }
    }
    
    int sumRange(int left, int right) {
        return  s[right+1] - s[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */