class Solution
{
    int rows, cols;
    int dirs[4][2] = {
		{ 1,
            0 },
        { 0,
            1 },
        { -1,
            0 },
        { 0,
            -1 }
    };

    int getMinimumTimeToReachBottom(vector<vector < int>> &grid)
    {
        if (rows == 0 or cols == 0)
            return -1;

        bool visited[rows][cols];
        memset(visited, false, sizeof(visited));

        priority_queue<vector < int>, vector< vector< int >>, greater<vector< int>>> minHeap;
        visited[0][0] = true;

        auto isValid =[& ](int row, int col)
        {
            return row >= 0 and row < rows and col >= 0 and col < cols and!visited[row][col];
        };

        minHeap.push({ grid[0][0],
            0,
            0 });

        int minTime = grid[0][0];

        while (!minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();
            int currentTime = top[0];
            int row = top[1];
            int col = top[2];
            minTime = max(minTime, currentTime);

            if (row == rows - 1 and col == cols - 1)
                return minTime;

            for (int dir = 0; dir < 4; dir++)
            {
                int newRow = row + dirs[dir][0];
                int newCol = col + dirs[dir][1];
                if (isValid(newRow, newCol))
                {
                    visited[newRow][newCol] = true;
                    minHeap.push({ grid[newRow][newCol],
                        newRow,
                        newCol });
                }
            }
        }

        return -1;
    }

    public:
        int swimInWater(vector<vector < int>> &grid)
        {
            rows = grid.size();
            cols = grid[0].size();
            return getMinimumTimeToReachBottom(grid);
        }
};