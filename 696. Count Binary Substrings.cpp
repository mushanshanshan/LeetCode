class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 1, res = 0, pre_count = 0;
        char cur = s[0], pre = 'i';
        
        for (int i=1; i<s.size(); i++) {
            if (s[i] == s[i-1]){
                count++;
            } else {
                if (pre_count != 0) res += min(pre_count, count);
                pre_count = count;
                count = 1;
            }
            
        }
        res += min(pre_count, count);
        return res;
    }
};