class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, bool> used;
        unordered_map<char, char> dict;
        
        for (int i=0; i<s.size(); i++) {
            if (!dict.count(s[i])) {
                if (used[t[i]]) return false;
                dict[s[i]] = t[i];
                used[t[i]] = true;
            } else if (dict[s[i]] != t[i]) {
                return false;
            }
        }
        
        return true;
    }
};