// Solution 1 : DFS
/*class Solution {
    int rows = 0, cols = 0;
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    
    int get1DCoordinate(int row, int col)
    {
        return (row * cols + col);
    }
        
    void markNeighboursVisited(int row, int col, vector<vector<char>>& grid)
    {
        if(row<0 or row>=rows or col<0 or col>=cols or grid[row][col]=='0')
            return;
         
        grid[row][col] = '0';
        
        for(auto [rowDir, colDir] : dirs)
            markNeighboursVisited(row + rowDir, col + colDir, grid);
    }
        
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int islands = 0;
        rows = grid.size();
        cols = grid[0].size();
        
        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                if(grid[row][col] == '1')
                {
                    islands += 1;
                    markNeighboursVisited(row, col, grid);
                }
            }
        }
        
        return islands;
    }
};*/


class UnionFind{
    vector<int> size, parent;
    int connectedComponents = 0;
public:
    UnionFind(int elements, int lands)
    {
        connectedComponents = lands;
        parent.clear();
        size.clear();
        
        parent.resize(elements + 1,0);
        size.resize(elements + 1, 1);
        
        iota(begin(parent), end(parent), 0);
    }
    
    int getParent(int child)
    {
        if(child == parent[child])
            return child;
        return parent[child] = getParent(parent[child]);
    }
    
    bool unionSets(int set1, int set2)
    {
        set1 =  getParent(set1);
        set2 =  getParent(set2);
        
        if(set1 == set2)
            return false;
        
        if(size[set1] < size[set2])
            swap(set1, set2);
        
        parent[set2] = parent[set1];
        size[set1] += size[set2];
        
        connectedComponents -= 1;
        
        return true;
    }
    
    int getConnectedComponents()
    {
        return connectedComponents;
    }
    
};


class Solution {
    int rows = 0, cols = 0;
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    
    int get1DCoordinate(int row, int col)
    {
        return (row * cols + col);
    }
        
    void connectNeighbourLands(int row, int col, vector<vector<char>>& grid, UnionFind &unionFind)
    {
        auto isValid = [&](int row, int col){
            return (row>=0 and row<rows and col>=0 and col<cols and grid[row][col]=='1');
        };
        
        for(auto [rowDir, colDir] : dirs)
        {
            int neighbourRow = row + rowDir;
            int neighbourCol = col + colDir;
            
            if(isValid(neighbourRow, neighbourCol))
            {
                unionFind.unionSets(get1DCoordinate(row, col), get1DCoordinate(neighbourRow, neighbourCol));
            }
        }
    }
        
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int islands = 0;
        rows = grid.size();
        cols = grid[0].size();
        
        int lands = 0;
        
        for(int row = 0; row < rows; row++)
            for(int col = 0; col < cols; col++)
                lands += (grid[row][col] == '1');
                
        
        UnionFind unionFind(rows * cols, lands);
        
        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                if(grid[row][col] == '1')
                {
                    connectNeighbourLands(row, col, grid, unionFind);
                }
            }
        }
        
        return unionFind.getConnectedComponents();
    }
};