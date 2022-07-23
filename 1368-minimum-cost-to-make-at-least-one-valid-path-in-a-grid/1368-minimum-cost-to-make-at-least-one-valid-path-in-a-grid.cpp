struct QueueNode
{
    int row, col, cost;
    QueueNode(int _row, int _col, int _cost): row(_row), col(_col), cost(_cost) {}
};

class Solution
{
    int rows, cols;
    vector<pair<int, int>> dirs = {
		  { 0,1 },
        { 0,-1 },
        { 1,0 },
        { -1,0 }
    };

    bool isValid(int row, int col)
    {
        return row >= 0 and row < rows and col >= 0 and col < cols;
    }

    int get1DCoord(int row, int col)
    {
        return row *cols + col;
    }

    public:
        int minCost(vector<vector < int>> &grid)
        {
            rows = grid.size();
            cols = grid[0].size();

            
            vector<vector<int>> dis(rows,vector<int>(cols,INT_MAX));
            deque<QueueNode> bfsQueue;
            bfsQueue.push_back(QueueNode(0, 0, 0));
            dis[0][0] = 0;
            while (!bfsQueue.empty())
            {
                auto front = bfsQueue.front();
                bfsQueue.pop_front();
                int row = front.row;
                int col = front.col;
                int cost = front.cost;
                if(dis[row][col]!=cost)
                    continue;
                
                if (row == rows - 1 and col == cols - 1)
                    return cost;

                for (int dir = 0; dir<=3;dir++)
                {
                    int nextRow = row + dirs[dir].first;
                    int nextCol = col + dirs[dir].second;
                
                    int coord = get1DCoord(nextRow, nextCol);
                    if (isValid(nextRow, nextCol))
                    {
                        int nextCost = 1;
                        if(dir+1 == grid[row][col])
                        {
                            nextCost = 0;
                        }
                        if(dis[nextRow][nextCol]>cost + nextCost)
                        {
                            if(nextCost == 1)
                                bfsQueue.push_back(QueueNode(nextRow,nextCol,cost+1));
                            else
                                bfsQueue.push_front(QueueNode(nextRow,nextCol,cost));
                            dis[nextRow][nextCol] = cost + nextCost;
                        }
                    }
                }
            }
            return -1;
        }
};