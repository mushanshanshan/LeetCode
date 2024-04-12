class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int counter[2] = {0, 0};
        int s = 0;

        for (int i: students) counter[i]++;
        for (; s < students.size(); s++) {
            if (counter[sandwiches[s]] > 0) {
                counter[sandwiches[s]]--;
            } else break;
        }

        return students.size() - s;
    }
};