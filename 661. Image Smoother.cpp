class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int N = img.size(), M = img[0].size(), count = 0;
        float temp = 0.0;
        vector<vector<int>> res(N, vector<int>(M,0));

        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++) {
                temp = img[i][j];
                count = 1;

                if (i > 0) {temp += img[i-1][j]; count++;}
                if (j > 0) {temp += img[i][j-1]; count++;}
                if (i < N-1) {temp += img[i+1][j]; count++;}
                if (j < M-1) {temp += img[i][j+1]; count++;}

                if (i > 0 && j < M-1) {temp += img[i-1][j+1]; count++;}
                if (i > 0 && j > 0) {temp += img[i-1][j-1]; count++;}
                if (i < N-1 && j > 0) {temp += img[i+1][j-1]; count++;}
                if (i < N-1 && j < M-1) {temp += img[i+1][j+1]; count++;}


                res[i][j] = (int)floor(temp / count);
            }
        }

        return res;
    }
};