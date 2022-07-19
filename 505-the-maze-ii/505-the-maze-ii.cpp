struct Node{
    int row,col,d;
    Node(int _d,int _row,int _col)
    {
        row = _row;
        col = _col;
        d = _d;
    }
};

struct compare{
    bool operator()(Node &node1,Node &node2)
    {
        return node1.d>node2.d;
    }
};

class Solution {
    int rows,cols;
    
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,-1},{0,1}};
    
    
public:
    int shortestDistance(vector<vector<int>>& maze, 
                         vector<int>& start, 
                         vector<int>& destination) 
    {
        rows = maze.size();
        cols = maze[0].size();
        
        auto isValid = [&](int row,int col){
            return (row>=0 and row<rows and col>=0 and col<cols);
        };
        
        vector<vector<int>> dis(rows,vector<int>(cols,INT_MAX));
        
        dis[start[0]][start[1]] = 0;
        
        priority_queue<Node,vector<Node>,compare> bfsQueue;
        
        bfsQueue.push(Node(0,start[0],start[1]));
        
        while(!bfsQueue.empty())
        {
            auto front = bfsQueue.top();
            bfsQueue.pop();
            int row = front.row;
            int col = front.col;
            int cost = front.d;
            
            if(dis[row][col]<cost)
                continue;
            
            if(row==destination[0] and col==destination[1])
                return cost;
            
            for(auto &dir:dirs)
            {
                int newRow = front.row;
                int newCol = front.col;
                int count = 0;
                while(isValid(newRow+dir[0],newCol+dir[1]) and maze[newRow+dir[0]][newCol+dir[1]]==0)
                {
                    newRow+=dir[0];
                    newCol+=dir[1];
                    count++;
                }
                if(cost+count<dis[newRow][newCol])
                {
                    dis[newRow][newCol] = cost+count;
                    bfsQueue.push(Node(dis[newRow][newCol],newRow,newCol));
                }
            }
        }
        return -1;
    }
};