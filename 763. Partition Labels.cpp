class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res{};
        vector<int> dic(26,0);
        
        for (int i=0; i<s.size(); i++) {
            dic[s[i] - 'a'] = i;
        }
        
        int left = 0, m = dic[s[0] - 'a'];
        
        for (int i=0; i<s.size(); i++) {
            m = max(dic[s[i] - 'a'], m);
            if (i == m) {
                res.push_back(i-left+1);
                left = m+1;
            }
        }
        
        return res;
    }
};