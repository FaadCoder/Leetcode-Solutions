class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> rowsFreqMap;
        int rows = grid.size();
        int cols = grid[0].size();
        
        for(int row = 0; row<rows; row++)
            rowsFreqMap[grid[row]]++;
        
        int pairs = 0;
        
        for(int col = 0; col<cols; col++)
        {
            vector<int> currentCol;
            for(int row = 0; row<rows; row++)
                currentCol.push_back(grid[row][col]);
            pairs += rowsFreqMap[currentCol];
        }
        
        return pairs;
    }
};