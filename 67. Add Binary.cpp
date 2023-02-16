class Solution {
public:
    string addBinary(string a, string b) {
        if (b.size() > a.size()) swap(a, b);

        int pre = 0, cur = 0, N = a.size(), M = b.size();

        for (int i=1; i<=N; i++) {
            cur = pre;
            if (i <= M) {
                cur += b[M-i] == '0'? 0: 1;
            }
            cur += a[N-i] == '0'? 0: 1;

            if (cur == 3) {
                pre = 1;
                a[N-i] = '1';
            } else if (cur == 2) {
                pre = 1;
                a[N-i] = '0';
            } else if (cur == 1){
                pre = 0;
                a[N-i] = '1';
            } else {
                pre = 0;
                a[N-i] = '0';
            }
        }

        return pre == 1? "1" + a : a;
    }
};