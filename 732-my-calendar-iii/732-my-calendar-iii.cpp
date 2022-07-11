class MyCalendarThree {
    map<int,int> lineSweepMap;
public:
    MyCalendarThree() {
        lineSweepMap.clear();
    }
    
    int book(int start, int end) {
        lineSweepMap[start]++;
        lineSweepMap[end]--;
        
        int booked = 0;
        int maxBooked = 0;
        for(auto it:lineSweepMap)
        {
            booked += it.second;
            maxBooked = max(maxBooked,booked);
        }
        return maxBooked;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */