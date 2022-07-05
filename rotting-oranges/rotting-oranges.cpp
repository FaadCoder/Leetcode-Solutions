class Solution {
    vector<int> dir[4] = {{1,0},{0,1},{0,-1},{-1,0}};
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int rottenOranges = 0;
        int freshOranges = 0;
        
        queue<pair<int,int>> bfsQueue;
        for(int row = 0; row<rows;row++)
        {
            for(int col=0; col<cols;col++)
            {
                if(grid[row][col]==2)
                {
                    rottenOranges+=1;
                    bfsQueue.push({row,col});
                }
                else if(grid[row][col]==1)
                {
                    freshOranges+=1;
                }
            }
        }
        
        if(freshOranges == 0)
            return 0;
        if(rottenOranges == 0)
            return -1;
        
        
        int minTime = 0;
        
        auto isValid = [&](int row,int col){
          return row>=0 and row<rows and col>=0 and col<cols;  
        };
        
        while(!bfsQueue.empty())
        {
            int orangesAtCurrentLevel = bfsQueue.size();
            while(orangesAtCurrentLevel--)
            {
                auto currentOrange = bfsQueue.front();
                bfsQueue.pop();
                int row = currentOrange.first;
                int col = currentOrange.second;
                
                for(int dirIdx = 0; dirIdx<4;dirIdx++)
                {
                    int newRow = row + dir[dirIdx][0];
                    int newCol = col + dir[dirIdx][1];
                    if(isValid(newRow,newCol))
                    {
                        if(grid[newRow][newCol]==1)
                        {
                            freshOranges-=1;
                            grid[newRow][newCol] = 2;
                            bfsQueue.push({newRow,newCol});
                        }
                    }
                }
                
            }
            minTime+=1;
        }
        
        return freshOranges == 0 ? minTime-1 : -1;
    }
};