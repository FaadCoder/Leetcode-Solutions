class Solution {
    
    int rows, cols;
    
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        unordered_map<int, int> rowBlack, colBlack;
        vector<pair<int, int>> blackLocations;
        
        rows = size(picture);
        cols = size(picture[0]);
        
        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                if(picture[row][col] == 'B')
                {
                    rowBlack[row] += 1;
                    colBlack[col] += 1;
                    blackLocations.push_back({row, col});
                }
            }
        }
        
        int lonelyPixels = 0;
        
        for(auto [row, col] : blackLocations)
        {
            if(rowBlack[row] <= 1 and colBlack[col] <= 1)
                lonelyPixels += 1;
        }
        
        return lonelyPixels;
    }
};