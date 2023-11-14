class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        // Map each stop to a list of buses that stop there
        unordered_map<int, vector<int>> stopToBuses;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                stopToBuses[stop].push_back(i);
            }
        }

        queue<int> q;
        q.push(source);
        unordered_set<int> visitedStops;
        visitedStops.insert(source);
        unordered_set<int> visitedBuses;
        int res = 0;

        while (!q.empty()) {
            int size = q.size();
            res++;
            for (int i = 0; i < size; i++) {
                int curStop = q.front();
                q.pop();
                for (int bus : stopToBuses[curStop]) {
                    if (visitedBuses.count(bus)) continue;
                    visitedBuses.insert(bus);
                    for (int stop : routes[bus]) {
                        if (stop == target) return res;
                        if (!visitedStops.count(stop)) {
                            visitedStops.insert(stop);
                            q.push(stop);
                        }
                    }
                }
            }
        }

        return -1;
    }
};
