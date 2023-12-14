class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int N = password.size();
        unordered_set<char> spec_char{'!','@','#','$','%','^','&','*','(',')','-','+'};
        string sp = "!@#$%^&*()-+";
        bool lowercase = false, uppercase = false, digit = false, special = false;

        if (N < 8) return false;
        for (int i=0; i<N; i++) {
            if (!lowercase && password[i] >= 'a' && password[i] <= 'z') lowercase = true;
            if (!uppercase && password[i] >= 'A' && password[i] <= 'Z') uppercase = true;
            if (!digit && password[i] >= '0' && password[i] <= '9') digit = true;
            if (!special && spec_char.contains(password[i])) special = true;
            if (i>0 && password[i] == password[i-1]) return false;
        }

        return lowercase && uppercase && digit && special;
    }
};