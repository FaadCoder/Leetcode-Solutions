/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        map<int,int> lineSweep;
        for(vector<Interval> &intervals:schedule)
        {
            for(Interval &interval:intervals)
            {
                lineSweep[interval.start]++;
                lineSweep[interval.end]--;
            }
        }
        vector<Interval> finiteIntervals;
        int currentOverlappingMeetings = 0;
        int st = 0, en =0;
        auto it = lineSweep.begin();
        while(it!=lineSweep.end())
        {
            currentOverlappingMeetings += it->second;
            if(currentOverlappingMeetings == 0)
            {
                st = it->first;
                it++;
                while(it!=lineSweep.end())
                {
                    currentOverlappingMeetings += it->second;
                    if(currentOverlappingMeetings>0)
                        break;
                    it++;
                }
                if(currentOverlappingMeetings != 0)
                {
                    en = it->first;
                    if(en>=st)
                    finiteIntervals.push_back(Interval(st,en));
                }
                
            }
            else
            {
                st = 0;
                en = 0;
            }
            it++;
        }
        
        return finiteIntervals;
    }
};

// 1    2 3  4  5   6  7 8 9 10
// 1----2       5---6
// 1------3 
//            4----------10
    
    
    