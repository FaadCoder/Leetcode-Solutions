class Solution
{
    private:
        int rows, cols;
    
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
        bool isValid(int row,int col,vector<vector < char>> &grid)
        {
            return (row>=0 and row<rows and col>=0 and col<cols and grid[row][col]!='#');
        }
    
        bool canReach(int srcX,int srcY,int tarX,int tarY,vector<vector < char>> &grid)
        {
            vector<vector<bool>> vis(rows,vector<bool>(cols,false));
            queue<pair<int,int>> bfsQueue;
            bfsQueue.push({srcX,srcY});
            vis[srcX][srcY] = true;
            while(!bfsQueue.empty())
            {
                auto front = bfsQueue.front();
                bfsQueue.pop();
                srcX = front.first;
                srcY = front.second;
                
                if(srcX == tarX and srcY == tarY)
                    return true;
                
                for(auto [x,y] : dirs)
                {
                    int nextSrcX = srcX + x;
                    int nextSrcY = srcY + y;

                    if(isValid(nextSrcX,nextSrcY,grid) and !vis[nextSrcX][nextSrcY])
                    {
                        vis[nextSrcX][nextSrcY] = true;
                        bfsQueue.push({nextSrcX,nextSrcY});
                    }
                }
            }
            return false;
        }
    
    public:
        int minPushBox(vector<vector < char>> &grid) 
        {
            rows = grid.size();
            cols = grid[0].size();
            pair<int,int> player,box,target;
            
            for(int row = 0; row<rows; row++)
            {
                for(int col = 0; col<cols; col++)
                {
                    if(grid[row][col]=='S')
                        player = {row,col};
                    
                    if(grid[row][col]=='B')
                        box = {row,col};
                    
                    if(grid[row][col]=='T')
                        target = {row,col};
                    
                }
            }
            
            queue<vector<int>> bfsQueue;
            bfsQueue.push({player.first,player.second,box.first,box.second});
            
            set<vector<int>> vis;
            vis.insert({player.first,player.second,box.first,box.second});
            
            int level = 0;
            while(!bfsQueue.empty())
            {
                int size = bfsQueue.size();
                while(size--)
                {
                    auto front = bfsQueue.front();
                    bfsQueue.pop();
                    int playerRow = front[0];
                    int playerCol = front[1];
                    int boxRow = front[2];
                    int boxCol = front[3];
                    
                    if(boxRow == target.first and boxCol == target.second)
                        return level;
                    
                    grid[boxRow][boxCol] = '#';
                    
                    for(auto [x,y] : dirs)
                    {
                        int nextBoxRow = boxRow + x;
                        int nextBoxCol = boxCol + y;
                        int nextPlayerRow = boxRow - x;
                        int nextPlayerCol = boxCol - y;
                        
                        if(isValid(nextBoxRow,nextBoxCol,grid) 
                           and isValid(nextPlayerRow,nextPlayerCol,grid) 
                           and !vis.count({nextPlayerRow,nextPlayerCol,nextBoxRow,nextBoxCol})
                          and canReach(playerRow,playerCol,nextPlayerRow,nextPlayerCol,grid))
                        {
                            vis.insert({nextPlayerRow,nextPlayerCol,nextBoxRow,nextBoxCol});
                            bfsQueue.push({nextPlayerRow,nextPlayerCol,nextBoxRow,nextBoxCol});
                        }
                    }
                    grid[boxRow][boxCol] = '.';
                }
                level++;
            }
            
            
            return -1;
        }
};