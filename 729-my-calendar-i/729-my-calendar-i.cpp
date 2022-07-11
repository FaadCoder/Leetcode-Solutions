class MyCalendar
{
   	// Using Self Balanced Ordered Tree to find out lower_bound quickly.
    map<int, int> startToEndMap;

    bool intervalsNotOverlapping(int start, int end, int queryStart, int queryEnd)
    {
        return (queryStart >= end or start >= queryEnd);
    }

    public:
        MyCalendar()
        {
            startToEndMap.clear();
        }

    bool book(int start, int end)
    {
        auto upperBound = startToEndMap.upper_bound(start);
        
        if (upperBound == startToEndMap.end() or intervalsNotOverlapping(upperBound->second, upperBound->first, start, end))
        {
            if (upperBound != startToEndMap.begin())
            {
                upperBound--;
                if (!intervalsNotOverlapping(upperBound->second, upperBound->first, start, end))
                    return false;
            }

            startToEndMap[end] = start;
            return true;
        }
        return false;
    }
};

/**
 *Your MyCalendar object will be instantiated and called as such:
 *MyCalendar* obj = new MyCalendar();
 *bool param_1 = obj->book(start,end);
 */