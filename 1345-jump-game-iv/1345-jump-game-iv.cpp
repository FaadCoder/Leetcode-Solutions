class Solution
{
    public:
        int minJumps(vector<int> &arr)
        {
            unordered_map<int, vector < int>> indicesMap;
            for (int idx = 0; idx < arr.size(); idx++)
                indicesMap[arr[idx]].push_back(idx);

            queue<int> bfsQueue;
            bfsQueue.push(0);

            unordered_set<int> vis;
            vis.insert(0);

            int level = 0;

            while (!bfsQueue.empty())
            {
                int size = bfsQueue.size();
                while (size--)
                {
                    int parent = bfsQueue.front();
                    bfsQueue.pop();
                    if (parent == arr.size() - 1)
                        return level;

                    if (parent - 1 >= 0 and!vis.count(parent - 1))
                    {
                        vis.insert(parent - 1);
                        bfsQueue.push(parent - 1);
                    }

                    if (parent + 1 < arr.size() and!vis.count(parent + 1))
                    {
                        vis.insert(parent + 1);
                        bfsQueue.push(parent + 1);
                    }

                    for (auto sameIndex: indicesMap[arr[parent]])
                    {
                        if (!vis.count(sameIndex))
                        {
                            vis.insert(sameIndex);
                            bfsQueue.push(sameIndex);
                        }
                    }

                   	// Main Line to Avoid TLE
                    indicesMap[arr[parent]].clear();
                }
                level++;
            }

            return -1;
        }
};