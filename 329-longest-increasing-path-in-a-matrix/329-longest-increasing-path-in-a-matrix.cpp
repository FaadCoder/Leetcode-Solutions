class Solution
{
    public:
        int longestIncreasingPath(vector<vector < int>> &matrix)
        {
            int rows = matrix.size();
            int cols = matrix[0].size();

            auto isValid =[& ](int row, int col)
            {
                return (row >= 0 and row < rows and col >= 0 and col < cols);
            };

            vector<vector < int>> dirs = {
		{ 1,
                    0 },
                { 0,
                    1 },
                { -1,
                    0 },
                { 0,
                    -1 }
            };

            vector<vector < int>> indegree(rows, vector<int> (cols, 0));

            for (int row = 0; row < rows; row++)
            {
                for (int col = 0; col < cols; col++)
                {
                    for (auto &dir: dirs)
                    {
                        int newRow = row + dir[0];
                        int newCol = col + dir[1];
                        if (isValid(newRow, newCol) and matrix[row][col] < matrix[newRow][newCol])
                            indegree[newRow][newCol]++;
                    }
                }
            }

            queue<pair<int, int>> bfsQueue;
            for (int row = 0; row < rows; row++)
            {
                for (int col = 0; col < cols; col++)
                {
                    if (!indegree[row][col])
                        bfsQueue.push({ row,
                            col });
                }
            }

            int longestPathLength = 0;

            while (!bfsQueue.empty())
            {
                int numberOfNodes = bfsQueue.size();
                while (numberOfNodes--)
                {
                    auto front = bfsQueue.front();
                    bfsQueue.pop();
                    int row = front.first;
                    int col = front.second;
                    for (auto &dir: dirs)
                    {
                        int newRow = row + dir[0];
                        int newCol = col + dir[1];
                        if (isValid(newRow, newCol) and matrix[row][col] < matrix[newRow][newCol])
                        {
                            indegree[newRow][newCol]--;
                            if (indegree[newRow][newCol] == 0)
                                bfsQueue.push({ newRow,
                                    newCol });
                        }
                    }
                }
                longestPathLength += 1;
            }

            return longestPathLength;
        }
};