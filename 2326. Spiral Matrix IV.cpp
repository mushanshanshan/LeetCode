/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    vector<vector<int>> dir = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
    };

public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int x = 0, y = 0, d = 0;

        while (head) {
            res[x][y] = head->val;

            head = head->next;


            int nx = x + dir[d][0];
            int ny = y + dir[d][1];
            
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || res[nx][ny] != -1) {
                d = (d + 1) % 4;
                nx = x + dir[d][0];
                ny = y + dir[d][1];
            }
            
            x = nx;
            y = ny;
        }

        return res;
    }
};