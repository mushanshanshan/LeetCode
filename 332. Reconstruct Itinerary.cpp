class Solution {
public:
    unordered_map<string, map<string, int>> ticket;
    vector<string> path;
    
    bool backtracking(int len) {
        
        if (path.size() == len+1) {
            return true;
        }
        
        for (auto& flight: ticket[path.back()]) {
            if (flight.second > 0) {
                flight.second--;
                path.push_back(flight.first);
                if (backtracking(len)) {
                    return true;
                }
                flight.second++;
                path.pop_back();
            }
        }
        
        return false;
        
        
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        ticket.clear();
        for (auto p: tickets) {
            ticket[p[0]][p[1]]++;
        }
        path.push_back("JFK");
        backtracking(tickets.size());
        return path;
    }
};