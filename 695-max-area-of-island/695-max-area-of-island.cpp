class UnionFind{
    unordered_map<int,int> parent,size;
    int connectedComponents;
    int maxSize = 0;
public:
    
    UnionFind(int numberOfSets)
    {
        maxSize = 0;
        connectedComponents = numberOfSets;
        for(int set=0;set<=numberOfSets;set++)
            parent[set] = set,size[set]=1;
    }
    
    int findParent(int child)
    {
        if(child == parent[child])
            return child;
        return parent[child] = findParent(parent[child]);
    }
    
    bool unionSet(int set1,int set2)
    {
        set1 = findParent(set1);
        set2 = findParent(set2);
        
        if(set1==set2)
            return false;
        
        if(size[set1]<size[set2])
            swap(set1,set2);
        
        parent[set2] = set1;
        size[set1] += size[set2];
        maxSize = max(maxSize,size[set1]);
        connectedComponents -= 1;
        return true;
    }
    
    int getConnectedComponents()
    {
        return connectedComponents;
    }
    
    int getMaxSize()
    {
        return maxSize;
    }
    
};

class Solution {
    int rows,cols;
    vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    
    int getOneDimensionalValue(int row,int col)
    {
        return cols*row + col;
    }
    
    bool isValidCell(int row,int col)
    {
        return (row>=0 and row<rows and col>=0 and col<cols);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        rows = grid.size();
        cols = grid[0].size();
        int numberOfCells = rows * cols;
        
        bool onePresent = false;
        
        UnionFind unionFind(numberOfCells);
        
        for(int row = 0; row<rows; row++)
        {
            for(int col = 0; col<cols; col++)
            {
                if(grid[row][col] == 1)
                {
                    onePresent = true;
                   for(auto &dir:dirs)
                   {
                       int newRow = row + dir[0];
                       int newCol = col + dir[1];
                       if(isValidCell(newRow,newCol) and grid[newRow][newCol]==1)
                       {
                           unionFind.unionSet(getOneDimensionalValue(row,col),getOneDimensionalValue(newRow,newCol));
                       }
                   }
                }
            }
        }
        
        return onePresent? max(1,unionFind.getMaxSize()) : 0;
        
    }
};





















