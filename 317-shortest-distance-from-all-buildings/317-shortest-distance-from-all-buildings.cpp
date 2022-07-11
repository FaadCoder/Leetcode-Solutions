class Solution {
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    int rows,cols;
    vector<vector<int>> distance,reach;
    int numberOfOnes;
    
    bool isValidMove(int row,int col)
    {
        return !(row>=rows or row<0 or col>=cols or col<0);
    }
    
    void applyBFSHelper(int row,int col,vector<vector<int>>& grid)
    {
        queue<pair<int,int>> bfsQueue;
        bfsQueue.push({row,col});
        
        bool visited[rows][cols];
        memset(visited,false,sizeof(visited));
        
        int level = 1;
        while(!bfsQueue.empty())
        {
            int queueSize = bfsQueue.size();
            while(queueSize--)
            {
                auto front = bfsQueue.front();
                bfsQueue.pop();
                
                for(int dir = 0; dir<4; dir++)
                {
                    int nextRow = front.first + dirs[dir][0];
                    int nextCol = front.second + dirs[dir][1];
                    
                    if(isValidMove(nextRow,nextCol) and 
                       grid[nextRow][nextCol] == 0 and 
                       !visited[nextRow][nextCol])
                    {
                        distance[nextRow][nextCol]+=level;
                        reach[nextRow][nextCol]++;
                        visited[nextRow][nextCol] = true;
                        bfsQueue.push({nextRow,nextCol});
                    }
                }
                
            }
            level+=1; 
        }
    }
    
    void applyBFS(vector<vector<int>>& grid)
    {
        for(int row = 0; row<rows; row++)
        {
            for(int col = 0; col<cols; col++)
            {
                if(grid[row][col]==1)
                {
                    numberOfOnes++;
                    applyBFSHelper(row,col,grid);
                }
            }
        }
    }
    
    int getMinimumDistance(vector<vector<int>>& grid)
    {
        int minDistance = INT_MAX;
        for(int row=0; row<rows; row++)
        {
            for(int col=0; col<cols; col++)
            {
                if(grid[row][col]==0 and reach[row][col]==numberOfOnes)
                {
                    minDistance = min(minDistance,distance[row][col]);
                }
            }
        }
        return minDistance;
    }
    
public:
    int shortestDistance(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        distance = vector<vector<int>>(rows,vector<int>(cols,0));
        reach = vector<vector<int>>(rows,vector<int>(cols,0));
        numberOfOnes = 0;
        
        // Step 1: Apply BFS From all 1's cells
        applyBFS(grid);
        
        // Step 2: Get the minimum distance.
        int minimumDistance = getMinimumDistance(grid);
        
        return minimumDistance == INT_MAX ? -1 : minimumDistance;
        
    }
};