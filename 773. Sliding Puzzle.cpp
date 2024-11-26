class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> moves = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        int N = 2, M = 3, step = 0;
        string cur = "", target = "123450";
        unordered_set<string> walked;
        queue<string> q;
        

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) cur += ('0' + board[i][j]);
        }
        if (cur == target) return 0;

        q.push(cur);
        while (!q.empty()) {
            int qs = q.size();
            step++;
            for (int cq=0; cq<qs; cq++) {
                cur = q.front();
                q.pop();

                for (int m=0; m<6; m++) {
                    if (cur[m] == '0') {
                        for (int move: moves[m]) {
                            string nstring = cur;
                            swap(nstring[m], nstring[move]);
                            if (nstring == target) return step;
                            if (!walked.contains(nstring)) {
                                walked.insert(nstring);
                                q.push(nstring);
                            }
                        }
                    }
                    
                }
            }
            
            
        }

        return -1;

    }
};