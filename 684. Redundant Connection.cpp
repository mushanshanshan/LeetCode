class Unifind {
    vector<int> id;
public:
    Unifind (int i) : id(i) {
        iota(id.begin(), id.end(), 0);
    }
    
    int find(int i) {
        if (i == id[i]) {
            return i;
        } else {
            id[i] = find(id[i]);
            return id[i];
        }
    }
    
    void connect (int i, int j) {
        id[find(i)] = find(j);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        Unifind u(edges.size() + 1);
        
        for (auto e: edges) {
            if (u.find(e[0]) == u.find(e[1])) return e;
            u.connect(e[0], e[1]);
        }
        return vector<int>{-1,-1};
    }
};