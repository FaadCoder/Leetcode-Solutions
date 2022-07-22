class Solution {
    int dp[1002][1002];
    int getMinHeight(vector<vector<int>>& books, int shelfWidth,int remainingWidth,int idx=0,int currentHeight=0)
    {
        if(remainingWidth<0)
            return INT_MAX/2;
        
        if(idx>=books.size())
            return currentHeight;
        
        if(dp[idx][remainingWidth]!=-1)
            return dp[idx][remainingWidth];
        
        int moveToNextShelf = currentHeight + getMinHeight(books,shelfWidth,shelfWidth-books[idx][0],idx+1,books[idx][1]);
        int remainInSameShelf = getMinHeight(books,shelfWidth,remainingWidth-books[idx][0],idx+1,max(currentHeight,books[idx][1]));
        
        return dp[idx][remainingWidth] = min(moveToNextShelf,remainInSameShelf);
    }
    
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) 
    {
        memset(dp,-1,sizeof(dp));
        return getMinHeight(books,shelfWidth,shelfWidth);
    }
};