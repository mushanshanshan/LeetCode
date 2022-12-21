class Solution {
private:
    vector<int> parent;

    int find(int i){
        return this->parent[i] == i? i: (this->parent[i] = find(parent[i]));
    }

    void merge(int i, int j) {
        parent[find(j)] = find(i);
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        this->parent = vector<int>(n,0);
        for (int i=0; i<n; i++) {
            this->parent[i] = i;
        }

        for (auto e: edges) merge(e[0], e[1]);

        printf("%d-%d", find(source), find(destination));

        return find(source) == find(destination);
    }
};