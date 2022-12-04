class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        int i = 0, j = 0, k = 0;
        for (; i<s.size(); i++, j++) {
            if (j == (k + spaces[k])) {
                j++;
                res += " ";
                res += s[i];
                if (k!=spaces.size()-1) k++;
            } else {
                res += s[i]; 
            }
        }
        return res;
    }
};