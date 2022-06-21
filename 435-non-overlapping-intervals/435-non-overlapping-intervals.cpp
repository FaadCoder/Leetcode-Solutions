class Solution
{
    public:
        int eraseOverlapIntervals(vector<vector < int>> &intervals)
        {
            int intervalsRemoved = 0;

            sort(intervals.begin(), intervals.end(), [& ](vector<int> &a, vector<int> &b)
            {
                return (a[0] == b[0]) ? (a[1] < b[1]) : (a[0] < b[0]);
	        });
            int preEnd = intervals[0][1];
            
            for (int idx=1; idx<intervals.size();idx++)
            {
                
                if (intervals[idx][0] < preEnd)
                {
                    intervalsRemoved += 1;
                    preEnd = min(preEnd,intervals[idx][1]);
                }
                else
                {
                    preEnd = intervals[idx][1];
                }
            }

            return intervalsRemoved;
        }
};