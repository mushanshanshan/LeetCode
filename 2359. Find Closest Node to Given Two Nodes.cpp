class Solution {
private:
    void dfs(vector<int>& edges, int cur, vector<int>& dis, int cur_dis) {
        if (dis[cur] != -1) return;
        dis[cur] = cur_dis;
        if (edges[cur] != -1) dfs(edges, edges[cur], dis, ++cur_dis);
    }


public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int N = edges.size(), res = -1, res_dis = N;
        vector<int> dis1(N, -1), dis2(N, -1);

        dfs(edges, node1, dis1, 0);
        dfs(edges, node2, dis2, 0);

        for (int i=0; i<N; i++) {
            if (dis1[i] != -1 && dis2[i] != -1 && max(dis1[i], dis2[i]) < res_dis) {
                res_dis = max(dis1[i], dis2[i]);
                res = i;
            }
        }

        return res;


    }
};