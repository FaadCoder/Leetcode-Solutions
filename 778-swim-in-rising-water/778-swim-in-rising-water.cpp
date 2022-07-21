struct HeapNode{
    int x;
    int y;
    int val;
    HeapNode(int _x,int _y,int _val)
    {
        x = _x;
        y = _y;
        val = _val;
    }
};

struct Compare{
    bool operator()(HeapNode &node1,HeapNode &node2){
        return node1.val > node2.val;
    };
};

class Solution {
    int rows,cols;
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
public:
    int swimInWater(vector<vector<int>>& grid) 
    {
        rows = grid.size();
        cols = grid[0].size();
    
        
        auto getOneDimensionalCoord = [&](int row,int col){
            return row*cols + col;
        };
        
        
        auto isValid = [&](int row,int col){
            return row>=0 and row<rows and col>=0 and col<cols;
        };
        
        priority_queue<HeapNode,vector<HeapNode>,Compare> minHeap;
        
        minHeap.push(HeapNode(0,0,grid[0][0]));
        unordered_set<int> vis;
        vis.insert(getOneDimensionalCoord(0,0));
        
        while(!minHeap.empty())
        {
            auto topNode = minHeap.top();
            minHeap.pop();
            int x = topNode.x;
            int y = topNode.y;
            int val = topNode.val;
            
            if(x==rows-1 and y==cols-1)
                return val;
            
            for(pair<int,int> &dir:dirs)
            {
                int nextX = x+dir.first;
                int nextY = y+dir.second;
                if(isValid(nextX,nextY) and !vis.count(getOneDimensionalCoord(nextX,nextY)))
                {
                    vis.insert(getOneDimensionalCoord(nextX,nextY));
                    minHeap.push(HeapNode(nextX,nextY,max(val,grid[nextX][nextY])));
                }
            }
        }
        
        return -1;
        
    }
};












