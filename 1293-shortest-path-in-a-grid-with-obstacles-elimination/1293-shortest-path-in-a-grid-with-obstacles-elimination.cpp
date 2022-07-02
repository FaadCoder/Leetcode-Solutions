class Solution {
    
    struct BFSQueueNode{
        int rowIdx;
        int colIdx;
        int obstacleEliminated;
        int steps;
        BFSQueueNode(int _rowIdx,int _colIdx, int _obstacleEliminated,int _steps)
        {
            rowIdx = _rowIdx;
            colIdx = _colIdx;
            obstacleEliminated = _obstacleEliminated;    
            steps = _steps;
        }
        
    };
    
    vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    
    bool isValid(int x,int y,int rows,int cols)
    {
        if(x<0 or y<0 or x>=rows or y>=cols)
            return 0;
        return 1;
    }
    
    int getMinStepsToReachBottom(vector<vector<int>>& grid,int k)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int endRowIdx = rows-1;
        int endColIdx = cols-1;
        
        int vis[rows][cols][k+1];
        memset(vis,0,sizeof(vis));
        vis[0][0][k] =  1;
        
        queue<BFSQueueNode> bfsQueue;
        bfsQueue.push(BFSQueueNode(0,0,k,0));
        
        while(!bfsQueue.empty())
        {

            BFSQueueNode nodeAtFront = bfsQueue.front();
            bfsQueue.pop();
            int rowIdx = nodeAtFront.rowIdx;
            int colIdx = nodeAtFront.colIdx;
            int obstacleEliminated = nodeAtFront.obstacleEliminated;
            int steps = nodeAtFront.steps;
            
            if(rowIdx == endRowIdx and colIdx == endColIdx)
                return steps;

            for(vector<int> &dir:dirs)
            {
                int nextRowIdx = rowIdx + dir[0];
                int nextColIdx = colIdx + dir[1];
                
                if(isValid(nextRowIdx,nextColIdx,rows,cols))
                {
                    int obstacleEliminated1 = obstacleEliminated - grid[nextRowIdx][nextColIdx];
                    if(obstacleEliminated1 >= 0 and !vis[nextRowIdx][nextColIdx][obstacleEliminated1])
                    {
                        bfsQueue.push(BFSQueueNode(nextRowIdx,nextColIdx,obstacleEliminated1,1+steps));
                        vis[nextRowIdx][nextColIdx][obstacleEliminated1] = 1;
                    }
                }
            }

        }
        
        return -1;
    }
    
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        return getMinStepsToReachBottom(grid,k);
    }
};