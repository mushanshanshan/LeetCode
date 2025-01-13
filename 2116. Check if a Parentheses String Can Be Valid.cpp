class Solution {
public:
    bool canBeValid(string s, string locked) {
        int N = s.size();
        if (N % 2 == 1) return false;

        int balance = 0; 
        for (int i = 0; i < N; i++) {
            if (locked[i] == '0' || s[i] == '(') balance++;
            else balance--;
            if (balance < 0) return false;
        }


        balance = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (locked[i] == '0' || s[i] == ')') balance++;
            else balance--;
            if (balance < 0) return false;
        }

        return true;
    }
};
