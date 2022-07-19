class Solution {
    
    bool isGraphCyclic(int source,
                       unordered_map<int,vector<int>> &colorsGraph,
                       vector<bool> &vis,
                       vector<bool> &dfsVis)
    {
        vis[source] = true;
        dfsVis[source] = true;
        
        for(int child:colorsGraph[source])
        {
            if(!vis[child] and isGraphCyclic(child,colorsGraph,vis,dfsVis))
                return true;
            else if(dfsVis[child])
                return true;
        }
        
        dfsVis[source] = false;
        return false;
    }
    
    
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int rows = targetGrid.size();
        int cols = targetGrid[0].size();
        
        unordered_map<int,vector<int>> colorsGraph;
        for(int color=1;color<=60;color++)
        {
            int topRow = rows,bottomRow = 0,leftCol = cols,rightCol = 0;
            for(int row=0;row<rows;row++)
            {
                for(int col=0;col<cols;col++)
                {
                    if(targetGrid[row][col]==color)
                    {
                        topRow = min(topRow,row);
                        bottomRow = max(bottomRow,row);
                        leftCol = min(leftCol,col);
                        rightCol = max(rightCol,col);
                    }
                }
            }
            
            for(int row = topRow; row<=bottomRow; row++)
            {
                for(int col = leftCol; col<=rightCol; col++)
                {
                    if(targetGrid[row][col]!=color)
                        colorsGraph[color].push_back(targetGrid[row][col]);
                }
            }
        }
        
        vector<bool> vis(60,false),dfsVis(60,false);
        
        for(int color = 1; color<=60;color++)
        {
            if(isGraphCyclic(color,colorsGraph,vis,dfsVis))
                return false;
        }
        
        return true;
    }
};