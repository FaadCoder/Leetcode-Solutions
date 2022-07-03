/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
    unordered_map<int,unordered_set<int>> vis;
   
    vector<pair<int,int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
    
    void cleanAllCells(Robot &robot,int row = 0,int col = 0,int currentDirection = 0)
    {
        robot.clean();
        vis[row].insert(col);
        
        for(int dir = 0; dir<4; dir++)
        {
            int nextDir = (currentDirection + dir)%4;
            int nextRow = row + dirs[nextDir].first;
            int nextCol = col + dirs[nextDir].second;
            
            if((!vis.count(nextRow) or !vis[nextRow].count(nextCol)) and robot.move())
            {
                cleanAllCells(robot,nextRow,nextCol,nextDir);
                //backTrack
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
        }
    }
     
public:
    void cleanRoom(Robot& robot) 
    {
            cleanAllCells(robot);
    }
};