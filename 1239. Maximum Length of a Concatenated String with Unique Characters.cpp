class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> words{bitset<26>()};
        int res = 0;

        for (auto &s: arr) {
            bitset<26> temp;
            for (auto c: s) temp.set(c - 'a');
            if (temp.count() < s.size()) continue;
            for (int i=0; i<words.size(); i++) {
                bitset<26> bs = words[i];
                if ((bs & temp).any()) continue;
                words.push_back(bs | temp);
                res = max(res, (int)words[words.size()-1].count());
            }
        }

        return res;
    }
};