class Solution {
public:
    string clearDigits(string s) {
        unordered_set<int> del;
        stack<int> st;
        int N = s.size();
        string res = "";

        for (int i=0; i<N; i++) {
            if (s[i] >= 'a' and s[i] <= 'z') st.push(i);
            else {
                del.insert(i);
                del.insert(st.top());
                st.pop();
            }
        }

        for (int i=0; i<N; i++) {
            if (!del.contains(i)) res += s[i];
        }

        return res;
    }
};