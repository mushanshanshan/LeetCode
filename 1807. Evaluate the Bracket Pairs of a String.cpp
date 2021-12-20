class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> dict;
        for (auto& k: knowledge) {
            dict[k[0]] = k[1];
        }
        
        stack<char> st;
        string temp = "", res = "";
        int cur = 0, n = s.size();
        
        while (cur < n) {
            if (s[cur] != '(') {
                res += s[cur];
                cur++;
            } else {
                cur++;
                temp = "";
                while (s[cur] != ')') {
                    temp += s[cur];
                    cur++;
                }
                cur++;

                if (dict.count(temp)) {
                    temp = dict[temp];
                } else {
                    temp = "?";
                }
                
                res += temp;
            }
        }
        
        
        return res;
        
    }
};