class MedianFinder {

public:
    
    struct cmp
    {
        bool operator()(int a, int b)
        {
            return a > b;
        }
    };
    
    priority_queue<int, vector<int>> small;
    priority_queue<int, vector<int>, cmp> large;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (small.size() == 0) {
            small.push(num);
        } else if (small.size() < large.size()) {
            if (num > large.top()) {
                small.push(large.top());
                large.pop();
                large.push(num);
            } else {
                small.push(num);
            }
        } else {
            if (num < small.top()) {
                large.push(small.top());
                small.pop();
                small.push(num);
            } else {
                large.push(num);
            } 
        }
    }
    
    double findMedian() {
        if (small.size() < large.size()) {
            return large.top();
        } else if (small.size() > large.size()) {
            return small.top();
        } else {
            return (large.top() + small.top()) * 0.5;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */