class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int N = dist.size(), res = 0;
        vector<float> time(N, 0.0);

        for (int i=0; i<N; i++) {
            time[i] = float(dist[i]) / speed[i];
        }

        sort(time.begin(), time.end());

        for (int i=1; i<N; i++) {
            if (time[i] - i <= 0) return i;
        }

        return N;
    }
};