class MyCalendar {
    map<int,int> endToStartMap;
    
    bool isOverlapping(int start1,int end1,int start2,int end2)
    {
        return !(start1>=end2 or end1<=start2);
    }
    
public:
    MyCalendar() {
        endToStartMap.clear(); 
    }
    
    bool book(int start, int end) {
        bool didAddTheEvent = false;
        
        if(endToStartMap.empty())
        {
            endToStartMap[end] = start;
            didAddTheEvent = true;
        }
        else
        {
            auto upperBound = endToStartMap.upper_bound(start);
            
            bool isOverlappingWithUpperBound = false;
            
            if(upperBound!=endToStartMap.end())
            {
                if(isOverlapping(upperBound->second, upperBound->first, start, end))
                    isOverlappingWithUpperBound = true;
            }
            
            bool isOverlappingWithLowerBound = false;
            
            if(upperBound != endToStartMap.begin())
            {
                upperBound--;
                if(isOverlapping(upperBound->second, upperBound->first, start, end))
                    isOverlappingWithLowerBound = true;
            }
            didAddTheEvent = !isOverlappingWithUpperBound and !isOverlappingWithLowerBound;
        }
        if(didAddTheEvent)
            endToStartMap[end] = start;
        return didAddTheEvent;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */