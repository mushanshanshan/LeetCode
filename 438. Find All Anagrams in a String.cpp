class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (m > n) return{};
        vector<int> exist(26, 0);
        vector<int> need(26, 0);
        vector<int> res;
        
        for (int i=0; i<m; i++) {
            cout<<i<<endl;
            need[p[i] - 'a']++;
            exist[s[i] - 'a']++;
        }
        
        if (need == exist) res.push_back(0);
        
        for (int i=m; i<n; i++) {
            cout<<i<<endl;
            exist[s[i-m] - 'a']--;
            exist[s[i] - 'a']++;
            if (need == exist) res.push_back(i-m+1);
        }
        return res;
    }
};