class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int N = s.size(), M = spaces.size(), space_index = 0;

        for (int i=0; i<N; i++) {
            if (space_index < M && i == spaces[space_index]) {
                res.push_back(' ');
                space_index++;
            }
            res.push_back(s[i]);
        }

        return res;
    }
};