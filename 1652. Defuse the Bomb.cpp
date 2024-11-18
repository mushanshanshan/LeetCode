class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int N = code.size();
        vector<int> res(N, 0);

        if (k > 0) {
            int s = 0;
            for (int i=0; i<k; i++) {
                s += code[i % N];
            }

            for (int i=0; i<N; i++) {
                s -= code[i];
                s += code[(i + k) % N];
                res[i] = s;
            }
        } else if (k < 0) {
            k = -k;
            int s = 0;
            for (int i=0; i<k; i++) {
                s += code[(N - 1 - i) % N];
            }

            for (int i=N-1; i>=0; i--) {
                s -= code[i];
                if ((i - k) < 0) s += code[(N + i - k) % N];
                else s += code[(i - k) % N];
                res[i] = s;
            }
        }

        return res;
    }
};