class Solution {
    bool isNotOverlapping(int intervalStart, int intervalEnd, int removeStart, int removeEnd)
    {
        return intervalEnd <= removeStart or intervalStart >= removeEnd;     
    }
    
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> disjointIntervals;
        
        for(vector<int> &interval : intervals)
        {
                int intervalStart = interval[0];
                int intervalEnd = interval[1];
                int removeStart = toBeRemoved[0];
                int removeEnd = toBeRemoved[1];
                
                if(!isNotOverlapping(intervalStart, intervalEnd, removeStart, removeEnd))
                {
            
                    if(removeStart > intervalStart)
                     disjointIntervals.push_back({intervalStart, removeStart});

                    if(removeEnd < intervalEnd)
                        disjointIntervals.push_back({removeEnd, intervalEnd});
                   
                }
                else
                    disjointIntervals.push_back(interval);
            
        }
        
        return disjointIntervals;
    }
};