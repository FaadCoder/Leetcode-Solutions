struct MinHeapNode{
    int x,y,height;
    MinHeapNode(int _x,int _y,int _height):x(_x),y(_y),height(_height){}
};

struct Compare{
   bool operator()(MinHeapNode &node1,MinHeapNode &node2){
       return node1.height > node2.height;
   }  
};

class Solution {
    int rows,cols;
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    bool isValid(int row,int col)
    {
        return row>=0 and row<rows and col>=0 and col<cols;
    }
    
    int get1D(int row,int col)
    {
        return row*cols + col;
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        priority_queue<MinHeapNode,vector<MinHeapNode>,Compare> minHeap;
        
        minHeap.push(MinHeapNode(0,0,0));
        vector<vector<int>> maxDiff(rows,vector<int>(cols,INT_MAX));
        maxDiff[0][0] = 0;
            
        while(!minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();
            int x = top.x;
            int y = top.y;
            int height = top.height;
            
            if(height>maxDiff[x][y])
                continue;
            
            if(x==rows-1 and y==cols-1)
                return maxDiff[x][y];
            
            for(auto &dir:dirs)
            {
                int newx = x + dir.first;
                int newy = y + dir.second;
                if(isValid(newx,newy))
                {
                    int newEffort = max(height,abs(heights[x][y]-heights[newx][newy]));
                    if(maxDiff[newx][newy]>newEffort)
                    {
                        minHeap.push(MinHeapNode(newx,newy,newEffort));
                        maxDiff[newx][newy] = newEffort;
                    }
                }
            }
        }
        
        return -1;
    }
};