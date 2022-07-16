class Solution
{
    public:
        int minMeetingRooms(vector<vector < int>> &intervals)
        {
            map<int, int> lineSweepMap;
            for (vector<int> &interval: intervals)
            {
                lineSweepMap[interval[0]]++;
                lineSweepMap[interval[1]]--;
            }
            int requiredMeetingRooms = 0;
            int overlappingIntervals = 0;
            for (auto &it: lineSweepMap)
            {
                overlappingIntervals += it.second;
                requiredMeetingRooms = max(requiredMeetingRooms, overlappingIntervals);
            }

            return requiredMeetingRooms;
        }
};