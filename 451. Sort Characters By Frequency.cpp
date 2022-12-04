class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        vector<vector<char>> buck(s.size()+1);

        for (auto c: s) {
            count[c]++;
        }

        for (auto it: count) {
            buck[it.second].push_back(it.first);
        }

        string res;
        for (int i=s.size(); i>=0; i--) {
            for (char c: buck[i]) {
                for (int j=0; j<i; j++) {
                    res += c;
                }
            }
        }

        return res;
    }
};