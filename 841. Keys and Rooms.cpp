class Solution {
public:
    
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        queue<int> q;
        int count = 0, cur;
        q.push(0);
        visited[0] = true;
        
        while (!q.empty()) {
            cur = q.front();
            count++;
            q.pop();
            for (int& i: rooms[cur]) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }     
            }
        }
        
        if (count == rooms.size()) return true;
        return false;
        
    }
};