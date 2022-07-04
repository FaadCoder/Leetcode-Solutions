class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        vector<int> left(ratings.size(),1);
        vector<int> right(ratings.size(),1);
        int ans = 0;
        for(int idx=1;idx<ratings.size();idx++)
        {
            if(ratings[idx]>ratings[idx-1])
                left[idx] = left[idx-1]+1;
        }
        
        for(int idx=ratings.size()-2;idx>=0;idx--)
        {
            if(ratings[idx]>ratings[idx+1])
                right[idx] = right[idx+1]+1;
        }
        
        for(int idx=0;idx<ratings.size();idx++)
            ans += max(right[idx],left[idx]);
        
        return ans;
    }
};