class Solution {
    typedef pair<int, int> task;
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size(), j = 0;
        long time = 0;
        vector<int> res;
        for (int i=0; i<n; i++) tasks[i].push_back(i); // [enqueueTime, processingTime, index]
        sort(tasks.begin(), tasks.end());

        priority_queue<task, vector<task>, greater<>> pq; 

        while (j<n || !pq.empty()) {
            if (pq.empty()) time = max(time, (long)tasks[j][0]);

            while (j < n && tasks[j][0] <= time) { 
                pq.emplace(tasks[j][1], tasks[j][2]); // [processingTime, index]
                j++;
            }

            time += (long)pq.top().first;
            res.push_back(pq.top().second);
            pq.pop();
                   
        }

        return res;
    }
};