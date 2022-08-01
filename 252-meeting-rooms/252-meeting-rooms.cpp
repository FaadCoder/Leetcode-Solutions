class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) 
    {
        if(intervals.empty())
            return true;
        map<int,int> lineSweepMap;
        
        for(vector<int> &interval:intervals)
            lineSweepMap[interval[0]]++, lineSweepMap[interval[1]]--;
        
        int currOverlappingIntervals = 0;
        int maxOverlappingIntervals = 0;
        for(auto it:lineSweepMap)
        {
            currOverlappingIntervals+=it.second;
            maxOverlappingIntervals = max(maxOverlappingIntervals, currOverlappingIntervals);
        }
        return maxOverlappingIntervals==1;
    }
};