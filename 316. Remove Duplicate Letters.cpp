class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[26] = {0};
        int visited[26] = {0};
        stack<char> sc;
        sc.push('0');

        for (char c:s) count[c - 'a']++;

        for (char c:s) {
            count[c - 'a']--;
            if (visited[c - 'a'] > 0) continue;

            while (c < sc.top() && count[sc.top() - 'a'] > 0) {
                visited[sc.top() - 'a'] = 0;
                sc.pop();
            }            
            sc.push(c);
            visited[c - 'a'] = 1;
        }
        
        string res;
        while (!sc.empty()) {
            res.push_back(sc.top());
            sc.pop();
        }
        reverse(res.begin(), res.end());


        return res.substr(1);
    }
};