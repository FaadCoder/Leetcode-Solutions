class Solution {
    
        unordered_map<int,int> numMap = {{1,1},
                                     {0,0},
                                     {8,8},
                                     {6,9},
                                     {9,6}};
    
public:
    bool isStrobogrammatic(string num) {
        
        string origNum = num;
        reverse(origNum.begin(),origNum.end());
        
        for(char &ch:origNum)
        {
            ch = numMap[ch-'0']+'0';
        }
        return origNum == num;
    }
};