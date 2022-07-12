class Solution {
    bool isPossibleToMakeSquare(vector<int>& matchsticks,int bitMask,int sides,int sideLength,int currentSum=0,int idx=0)
    {
        if(sides == 1)
            return true;
        
        if(currentSum>sideLength or idx>=size(matchsticks))
            return false;

        if(sideLength == currentSum)
        {
            return isPossibleToMakeSquare(matchsticks,bitMask,sides-1,sideLength,0);
        }
        
        for(int i=idx;i<size(matchsticks);i++)
        {
            if(!((bitMask>>i) & 1))
            {
                bitMask |= (1<<i);
                
                if(isPossibleToMakeSquare(matchsticks,bitMask,sides,sideLength,currentSum+matchsticks[i],i+1))
                    return true;
                
                bitMask ^= (1<<i);
            }
        }
        
        return false;
    }
    
public:
    bool makesquare(vector<int>& matchsticks) 
    {
        int perimeter = accumulate(begin(matchsticks),end(matchsticks),0);
        
        if(perimeter%4)
            return false;
        
        int expectedSideLength = perimeter/4;
        sort(matchsticks.rbegin(),matchsticks.rend());
        
        return isPossibleToMakeSquare(matchsticks,0,4,expectedSideLength);
    }
};