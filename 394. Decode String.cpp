class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string res, temps, counts;
        int count;
        
        for (int i=0; i<s.size(); i++) {
            if (s[i] != ']') st.push(s[i]);
            else {
                temps = "";
                counts = "";
                while (st.top()!='[') {
                    temps = st.top() + temps;
                    st.pop();
                }

                st.pop();
                
                while (!st.empty() && st.top() >= '0' && st.top() <= '9') {
                    counts = st.top() + counts;
                    st.pop();
                }
                
                count = stoi(counts);
                while (count) {
                    for (char & c: temps) {
                        st.push(c);
                    }
                    count--;
                }
                
            }
        }
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        
        return res;
    }
};