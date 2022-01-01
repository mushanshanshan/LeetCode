class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> res;
        vector<int> index(10, -1);
        int ma = 0, re = -1;
        
        while(n) {
            res.push_back(n%10);
            n /= 10;
        }
        
        for (int i=0; i<res.size(); i++) {
            if (ma > res[i]) {
                swap(res[i], res[index[ma]]);
                re = 0;
                break;
            }
            ma = max(ma, res[i]);
            if (index[res[i]] < 0) index[res[i]] = i;
        }
        
        if (re == -1) return re;
        
        reverse(res.begin(), res.begin() + index[ma] + 1);
        
        for (int i=res.size()-1; i>=0; i--) {
            re = re * 10 + res[i];
        }
        
        return re;
        
    }
};