struct BallInfo
{
    int row, col, dis;
    BallInfo(int _row, int _col, int _dis):row(_row), col(_col), dis(_dis){}
};

class Comparator{
    public:
        bool operator()(BallInfo &ball1, BallInfo &ball2){
            return ball1.dis > ball2.dis;
        }
};

class Solution {
    int rows = 0, cols = 0;
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    int get1DCoordinate(int row, int col)
    {
        return (row * cols + col);
    }
        
    
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) 
    {
        rows = maze.size();
        cols = maze[0].size();
        
        auto isValid = [&](int row, int col){
            return (row>=0 and row<rows and col>=0 and col<cols and maze[row][col]==0);
        };
        
        vector<int> distance(rows * cols + 1, INT_MAX);
        priority_queue<BallInfo, vector<BallInfo>, Comparator> minHeap;
        
        distance[get1DCoordinate(start[0], start[1])] = 0;
        minHeap.push(BallInfo(start[0], start[1], 0));
        
        
        while(!minHeap.empty())
        {
            auto top = minHeap.top();
            int row = top.row;
            int col = top.col;
            int dis = top.dis;
            minHeap.pop();
            
            
            if(distance[get1DCoordinate(row, col)] < dis)
                continue;
            
            if(row == destination[0] and col==destination[1])
                return dis;
            
            
            for(auto [rowDir, colDir] : dirs)
            {
                int nextRow = row + rowDir;
                int nextCol = col + colDir;
                int distanceCovered = 0;
                
                while(isValid(nextRow, nextCol))
                {
                    distanceCovered += 1;
                    nextRow += rowDir;
                    nextCol += colDir;
                }
                
                nextRow -= rowDir;
                nextCol -= colDir;
                
                if(distance[get1DCoordinate(nextRow, nextCol)] > dis + distanceCovered)
                {
                    distance[get1DCoordinate(nextRow, nextCol)] = dis + distanceCovered;
                    minHeap.push(BallInfo(nextRow, nextCol, dis + distanceCovered));
                }
            }
            
        }
        
        return -1;
    }
};