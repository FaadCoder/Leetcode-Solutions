class MyCalendarTwo {
    
    map<int,int> lineSweepingMap;
    
    
public:
    MyCalendarTwo() {
        lineSweepingMap.clear();
    }
    
    bool book(int start, int end) {
        lineSweepingMap[start]++;
        lineSweepingMap[end]--;
        int booked = 0;
        for(auto it:lineSweepingMap)
        {
            booked += it.second;
            if(booked == 3)
            {
                lineSweepingMap[start]--;
                lineSweepingMap[end]++;
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

/*

        10-------------------20
                                      50-------------60
        10-------------------------40
5-----------15




*/