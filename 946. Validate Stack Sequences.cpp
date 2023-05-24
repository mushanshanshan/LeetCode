class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> sa;
        int i=0, j=0, N = pushed.size(), M = popped.size();

        while (j < M) {
            while (sa.empty() || sa.top() != popped[j]) {
                if (i >= N) return false;
                sa.push(pushed[i++]);
            }
            sa.pop();
            j++;
        }

        return true;
    }
};