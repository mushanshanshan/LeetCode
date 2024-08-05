class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0, N = rating.size();
        int lasc, ldsc, rasc, rdsc;

        for (int i=1; i<N-1; i++) {
            lasc = 0;
            ldsc = 0;
            rasc = 0;
            rdsc = 0;
            for (int j=0; j<i; j++) {
                if (rating[j] < rating[i]) lasc++;
                else if (rating[j] > rating[i]) ldsc++;
            }

            for (int j=i+1; j<N; j++) {
                if (rating[j] < rating[i]) rdsc++;
                else if (rating[j] > rating[i]) rasc++;
            }

            res += lasc * rasc + ldsc * rdsc;
        }

        return res;
    }
};