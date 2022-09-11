class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> lineSweep;
        
        for(auto &interval : intervals)
        {
            lineSweep[interval[0]]++;
            lineSweep[interval[1] + 1]--;
        }
        
        int maxOverlappingIntervals = 0;
        int currentOverlappingIntervals = 0;
        
        for(auto it : lineSweep)
        {
            currentOverlappingIntervals += it.second;
            maxOverlappingIntervals = max(maxOverlappingIntervals, currentOverlappingIntervals);
        }
        
        return maxOverlappingIntervals;
        
    }
};