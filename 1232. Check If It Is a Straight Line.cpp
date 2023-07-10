class Solution {

public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int N = coordinates.size();
        int dX = coordinates[1][0] - coordinates[0][0];
        int dY = coordinates[1][1] - coordinates[0][1];

        for (int i=2; i<N; i++){
            if (dX * (coordinates[i][1] - coordinates[0][1]) != dY * (coordinates[i][0] - coordinates[0][0])) return false;
        }

        return true;
    }
};