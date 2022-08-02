class DSU{
private:
    unordered_map<int,int> parent,size;
public:
    
    int findParent(int child)
    {
        if(parent[child]==child)
            return child;
        return parent[child] = findParent(parent[child]);
    }
    
    void unionSet(int a,int b)
    {
        if(!parent.count(a))
            parent[a] = a, size[a] = 1;
        if(!parent.count(b))
            parent[b] = b, size[b] = 1;
        
        a = findParent(a);
        b = findParent(b);
        
        if(a==b)
            return;
        if(size[a]<size[b])
            swap(a,b);
        parent[b] = a;
        size[a]+=size[b];
    }
    
    unordered_map<int,vector<int>> getGroups()
    {
        unordered_map<int,vector<int>> groups;
        for(auto it:parent)
            groups[findParent(it.first)].push_back(it.first);
        return groups;
    }
    
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        map<int,vector<pair<int,int>>> groupByValue;
        
        for(int row=0;row<rows;row++)
            for(int col = 0; col<cols; col++)
                groupByValue[matrix[row][col]].push_back({row,col});
        
        vector<int> ranks(rows+cols,0);
        
        for(auto [value,coord] : groupByValue)
        {
            DSU dsu;
            for(auto [r,c]:coord)
                dsu.unionSet(r,c+rows);
            
            for(auto [_, group]:dsu.getGroups())
            {
                int maxRank = 0;
                for(int i:group)
                    maxRank = max(maxRank, ranks[i]);
                for(int i:group)
                    ranks[i] = maxRank+1;
            }
            
            for(auto [r,c]:coord)
                matrix[r][c] = ranks[r];
        }
        return matrix;
    }
};


















