class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int N = s.size();
        if (t.size() != N) return false;
        unordered_map<char, char> map;
        set<char> cs;

        for (int i=0; i<N; i++) {
            if (map.find(s[i]) == map.end()) {
                if (cs.count(t[i]) > 0) return false;
                map[s[i]] = t[i];
                cs.insert(t[i]);
            }
            else {
                if (map[s[i]] != t[i]) return false;
            }
        }

        return true;
    }
};