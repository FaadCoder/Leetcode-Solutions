class Solution
{
    public:
        int numBusesToDestination(vector<vector < int>> &routes, int source, int target)
        {
            unordered_map<int, vector < int>> busStopToBusNoHashMap;

            for (int busNumber = 0; busNumber < routes.size(); busNumber++)
                for (int busStop: routes[busNumber])
                    busStopToBusNoHashMap[busStop].push_back(busNumber);

            unordered_set<int> busStopVisited, busNumberVisited;
            queue<int> bfsQueue;
            int level = 0;

            bfsQueue.push(source);
            busStopVisited.insert(source);

            while (!bfsQueue.empty())
            {
                int queueSize = bfsQueue.size();
                while (queueSize--)
                {
                    int currentBusStopNumber = bfsQueue.front();
                    bfsQueue.pop();

                    if (currentBusStopNumber == target)
                        return level;
                    for (auto busNumber: busStopToBusNoHashMap[currentBusStopNumber])
                    {
                        if (!busNumberVisited.count(busNumber))
                        {
                            busNumberVisited.insert(busNumber);
                            for (auto busStopNumber: routes[busNumber])
                            {
                                if (!busStopVisited.count(busStopNumber))
                                {
                                    busStopVisited.insert(busStopNumber);
                                    bfsQueue.push(busStopNumber);
                                }
                            }
                        }
                    }
                }
                level += 1;
            }

            return -1;
        }
};