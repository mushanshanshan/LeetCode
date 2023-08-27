class Solution {
private:
    vector<int> diff = {-1, 0, 1};

public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> jumps;
        bool first_jump = true;

        for (auto a: stones){
            jumps[a] = unordered_set<int>();
        }

        for (auto a: stones){
            if (first_jump) {
                if (jumps.count(a+1) == 1) jumps[a+1].insert(1);
                first_jump = false;
            } else {
                for (auto j: jumps[a]){
                    for (auto d: diff) {
                        if (j + d > 0 && jumps.count(a+j+d) == 1) jumps[a+j+d].insert(j + d);
                    }
                }
            }
        }


        return jumps[stones[stones.size()-1]].size() > 0;
    }
};