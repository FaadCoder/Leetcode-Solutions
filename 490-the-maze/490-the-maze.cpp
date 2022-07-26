class Solution {
    int rows,cols;
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    bool isValid(int row,int col)
    {
        return row>=0 and row<rows and col>=0 and col<cols;
    }
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        rows = maze.size();
        cols = maze[0].size();
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minHeap;
        vector<vector<int>> dis(rows,vector<int>(cols,INT_MAX));
        dis[start[0]][start[1]] = 0;
        minHeap.push({0,start[0],start[1]});
        
        while(!minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();
            int row = top[1];
            int col = top[2];
            int cost = top[0];
            if(dis[row][col]<cost)
                continue;
            
            if(row==dest[0] and col==dest[1])
                return true;
            
            for(auto [x,y] : dirs)
            {
                int nextRow = row+x;
                int nextCol = col+y;
                int nextCost = 0;
                while(isValid(nextRow,nextCol) and maze[nextRow][nextCol]==0)
                {
                    nextCost+=1;
                    nextRow+=x;
                    nextCol+=y;
                }
                nextRow-=x;
                nextCol-=y;
                if(dis[nextRow][nextCol]>cost + nextCost)
                {
                    dis[nextRow][nextCol] = cost + nextCost;
                    minHeap.push({cost+nextCost,nextRow,nextCol});
                }
                    
                    
            }
            
        }
        
        return false;
    }
};