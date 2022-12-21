class Solution {
    stack<int> keys;
    vector<bool> visited;
    int visited_num = 0;
    vector<vector<int>> rooms;

    void check() {
        int room = this->keys.top();
        this->keys.pop();
        if (this->visited[room]) return;
        this->visited[room] = true;
        for (int s: this->rooms[room]) {
            keys.push(s);
        }
        this->visited_num++;
    }


public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        this->keys.push(0);
        this->rooms = rooms;
        this->visited = vector<bool>(rooms.size(), false);

        while(!this->keys.empty()) {
            check();
        }

        return this->visited_num == rooms.size();
    }
};