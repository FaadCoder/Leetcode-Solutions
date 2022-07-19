class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalRows;
        pascalRows.push_back({1});
        for(int row = 1; row<numRows;row++)
        {
            auto previousRow = pascalRows.back();
            vector<int> newRow(row+1);
            newRow[0] = previousRow[0];
            newRow[row] = previousRow.back();
            
            for(int idx=1;idx<row;idx++)
                newRow[idx] = previousRow[idx]+previousRow[idx-1];
            
            pascalRows.push_back(newRow);
        }
        
        return pascalRows;
    }
};