class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        visit(homepage);
    }
    
    void visit(string url) {
        his.resize(++cur);
        his.push_back(url);
    }
    
    string back(int steps) {
        cur = max(0, cur - steps);
        return his[cur];
    }
    
    string forward(int steps) {
        cur = min((int)his.size() - 1, steps + cur);
        return his[cur];
    }

private:
    int cur = -1;
    vector<string> his;

};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */