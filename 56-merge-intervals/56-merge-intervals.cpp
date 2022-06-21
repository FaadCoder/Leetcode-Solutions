class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        auto comparator = [&](vector<int> &interval1,vector<int> &interval2){
            return (interval1[0]==interval2[0])?(interval1[1]<interval2[1]):interval1[0]<interval2[0];
        };
        
        sort(intervals.begin(),intervals.end(),comparator);
        
        vector<vector<int>> newIntervals;
        
        auto tempInterval = intervals[0];
        for(auto interval:intervals)
        {
            if(tempInterval[0]>interval[1])
            {
                newIntervals.push_back(interval);
            }
            else if(tempInterval[1] < interval[0])
            {
                newIntervals.push_back(tempInterval);
                tempInterval = interval;
            }
            else
            {
                tempInterval[0] = min(interval[0],tempInterval[0]);
                tempInterval[1] = max(interval[1],tempInterval[1]);
            }
        }
        
        newIntervals.push_back(tempInterval);
        return newIntervals;
    }
};