class Solution {
    
    bool possibleToCutRibbons(vector<int>& ribbons, int mid, int k)
    {
        long long cuts = 0;
        for(int ribbon:ribbons)
        {
            cuts +=((long long)ribbon/mid);
        }
        return cuts>=k;
    }
    
public:
    int maxLength(vector<int>& ribbons, int k)
    {
        long long start = 1;
        long long total = 0;
        for(int ribbon:ribbons)
            total += ribbon;
        long long end = total/k;
        long long ans = 0;
        while(start<=end)
        {
            int mid = start+(end-start)/2;
            if(!possibleToCutRibbons(ribbons,mid,k))
            {
                end = mid-1;
            }
            else
            {
                ans = mid;
                start = mid+1;
            }
        }
        
        return ans;
    }
};