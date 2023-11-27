class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int res = 0, N = garbage.size();

        unordered_map<char, int> truck_map{{'M', 0}, {'P', 1}, {'G', 2}};
        vector<int> position(3, 0);

        for (int i=0; i<N; i++) {
            for (char g: garbage[i]) {
                res += 1;
                int idx = truck_map[g];
                if (position[idx] != i) {
                    for (int j = position[idx]; j<i; j++) {
                        res += travel[j];
                    }

                    position[idx] = i;
                }
            }

        }

        return res;
    }
};