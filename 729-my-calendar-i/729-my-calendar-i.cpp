class MyCalendar
{
    map<int, int> bookingIntervalMap;
    bool isOverlapping(int start1,int end1,int start2,int end2)
    {
        return !(start2>=end1 or start1>=end2);
    }
    public:
        MyCalendar()
        {
            bookingIntervalMap.clear();
        }

    bool book(int start, int end)
    {
        auto lowerBound = bookingIntervalMap.lower_bound(start);
        if(lowerBound!=bookingIntervalMap.end() and lowerBound->first<end)
            return false;
        
        if(lowerBound!=bookingIntervalMap.begin())
        {
            --lowerBound;
            if(start<lowerBound->second)
                return false;
        }
        bookingIntervalMap[start] = end;
        return true;
    }
};

/**
 *Your MyCalendar object will be instantiated and called as such:
 *MyCalendar* obj = new MyCalendar();
 *bool param_1 = obj->book(start,end);
 */