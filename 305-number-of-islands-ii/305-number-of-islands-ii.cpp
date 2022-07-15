class Solution {
private:
    unordered_map<int,int> parent,size;
    int connectedComponents = 0;
    int rows,cols;
    vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    
    int findParent(int child)
    {
        if(child == parent[child])
            return child;
        return parent[child] = findParent(parent[child]);
    }
    
    void unionSet(int set1,int set2)
    {
        set1 = findParent(set1);
        set2 = findParent(set2);
        if(set1==set2)
            return;
        
        if(size[set1]<size[set2])
            swap(set1,set2);
        
        parent[set2] = set1;
        size[set1]+=size[set2];
        connectedComponents-=1;
    }
    
    int getOneDimensionalValue(int row,int col)
    {
        return cols*row+col;
    }
    

    bool isValid(int row,int col)
    {
        return (row>=0 and row<rows and col>=0 and col<cols);    
    }
    
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions)
    {
        rows = m;
        cols = n;
        vector<int> ans;
        
        for(auto &position:positions)
        {
            int row = position[0];
            int col = position[1];
            int currentCell = getOneDimensionalValue(row,col);
            
            if(parent.count(currentCell))
            {
                ans.push_back(connectedComponents);
            }
            else
            {
                ++connectedComponents;
                parent[currentCell] = currentCell;
                size[currentCell] = 1;
                
                for(auto &dir:dirs)
                {
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;
                    int nextCell = getOneDimensionalValue(newRow,newCol);
                    if(isValid(newRow,newCol) and parent.count(nextCell))
                    {
                        unionSet(currentCell,nextCell);
                    }
                }
                ans.push_back(connectedComponents);
            }
        }
        
        return ans;
    }
};














