class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> pre(numCourses, vector<int>());
        stack<int> st;
        int count = 0, cur;
        
        for (auto &a : prerequisites) {
            pre[a[1]].push_back(a[0]);
            inDegree[a[0]]++;
        }
        
        for (int i=0; i<numCourses; i++) {
            if (!inDegree[i]) st.push(i);
        }
        
        while (!st.empty()) {
            cur = st.top();
            st.pop();
            inDegree[cur]--;
            for (int& i: pre[cur]) {
                inDegree[i]--;
                if (!inDegree[i]) st.push(i);
            }
            count++;
        }
        
        if (count == numCourses) return true;
        return false;
        
        
    }
};