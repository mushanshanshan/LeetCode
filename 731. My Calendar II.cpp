class MyCalendarTwo {
public:

    map<int, int> day;

    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        day[start]++;
        day[end]--;

        int num = 0;
        for (auto it = day.begin(); it != day.end(); it++) {
            num += it->second;
            if (num >= 3) {
                day[start]--;
                day[end]++;
                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */