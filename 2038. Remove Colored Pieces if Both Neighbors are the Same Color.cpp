class Solution {
public:
    bool winnerOfGame(string colors) {
        int N = colors.size();
        int a = 0, b = 0;
        for (int i=1; i<N-1; i++) {
            if (colors[i] == colors[i-1] && colors[i] == colors[i+1]) {
                if (colors[i] == 'A') a++;
                else b++;
            }
        }

        return a > b;
    }
};