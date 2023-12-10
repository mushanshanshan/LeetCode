class Solution {
private:
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int to_day(string data) {
        int d = 0;
        for (int i=1; i<stoi(data.substr(0, 2)); i++) {
            d += days[i-1];
        }
        return d + stoi(data.substr(3, 2));
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        int arrA = to_day(arriveAlice);
        int leaA = to_day(leaveAlice);
        int arrB = to_day(arriveBob);
        int leaB = to_day(leaveBob);
        int res = min(leaA, leaB) - max(arrA, arrB);

        return res >= 0? res+1: 0;
    }
};