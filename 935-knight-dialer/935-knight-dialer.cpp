class Solution {
    static const int numberOfRows = 4;
    static const int numberOfCols = 3;
    const int mod = 1e9+7;
    const int dir[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    
    int dp[numberOfRows][numberOfCols][5002];
    
    bool isValidMove(int row,int col)
    {
        return (row>=0 and col>=0 and row<numberOfRows and col<numberOfCols);
    }

    bool isCurrentPositionANonNumericCell(int row,int col)
    {
        return ((row==numberOfRows-1) and col!=1);
    }

    int kngihtDialerHelper(int row,int col,int n)
    {   
        if(!isValidMove(row,col) or isCurrentPositionANonNumericCell(row,col))
            return 0;

        if(n==1)
           return 1;

        if(dp[row][col][n]!=-1)
            return dp[row][col][n];

        int res=0;
        for(int idx = 0; idx<8; idx++)
        {
            int newRow = row + dir[idx][0];
            int newCol = col + dir[idx][1];
            res = addUnderModulo(res,kngihtDialerHelper(newRow,newCol,n-1));
        }
        return dp[row][col][n] = res;
    }

    int addUnderModulo(int num1,int num2)
    {
        return (num1%mod + num2%mod)%mod;
    }
    
public:
    int knightDialer(int n) 
    {
        memset(dp,-1,sizeof(dp));
        int res = 0;
        for(int row = 0; row<numberOfRows; row++)
        {
            for(int col = 0; col<numberOfCols; col++)
            {
                res = addUnderModulo(res,kngihtDialerHelper(row,col,n));
            }
        }
        return res;
    }
};