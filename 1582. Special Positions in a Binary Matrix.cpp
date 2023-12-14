class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        unordered_set<int> candidates;
        int N = mat.size(), M = mat[0].size(), counter = 0, temp = 0, res = 0;

        for (int i=0; i<N; i++) {
            counter = 0;
            for (int j=0; j<M; j++) {
                if (mat[i][j] == 1) {
                    counter++;
                    temp = j;
                }
                if (counter > 1) break;
            }
            if (counter == 1) candidates.insert(temp);
        }

        for (int j=0; j<M; j++) {
            counter = 0;
            for (int i=0; i<N; i++) {
                if (mat[i][j] == 1) {
                    counter++;
                }
                if (counter > 1) break;
            }
            if (counter == 1 && candidates.contains(j)) {
                res++;
            }
        }

        return res;
    }
};