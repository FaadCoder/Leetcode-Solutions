class Solution {
    bool cycleExist(int color,unordered_map<int,vector<int>> &graph,unordered_set<int> &vis,unordered_set<int> &dfsVis)
    {
        vis.insert(color);
        dfsVis.insert(color);
        
        for(auto nextColor:graph[color])
        {
            if(!vis.count(nextColor) and cycleExist(nextColor,graph,vis,dfsVis))
                return true;
            else if(dfsVis.count(nextColor))
                return true;
        }
        
        dfsVis.erase(dfsVis.find(color));
        return false;
    }    
    
public:
    bool isPrintable(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        unordered_map<int,vector<int>> graph;        
        
        for(int color=1;color<=60;color++)
        {
            int topRow = rows,bottomRow=0,leftCol = cols,rightCol = 0;
            
            for(int row=0;row<rows;row++)
            {
                for(int col=0;col<cols;col++)
                {
                    if(grid[row][col]==color)
                    {
                        topRow = min(topRow,row);
                        bottomRow = max(bottomRow,row);
                        leftCol = min(leftCol,col);
                        rightCol = max(rightCol,col);
                    }
                }
            }
            
            for(int row=topRow;row<=bottomRow;row++)
            {
                for(int col=leftCol;col<=rightCol;col++)
                {
                    if(grid[row][col]!=color)
                        graph[color].push_back(grid[row][col]);
                }
            }
        }
        

        unordered_set<int> vis,dfsVis;
        for(int color = 1; color<=60; color++)
        {
            if(cycleExist(color,graph,vis,dfsVis))
                return false;
        }
        return true;
    }
};