class Solution {
    
    bool countDays(vector<int> &weights,int capacity,int days)
    {
        int currentCap = 0;
        int count = 1;
        for(int weight:weights)
        {
            currentCap+=weight;
            if(currentCap>capacity)
            {
                count++;
                currentCap = weight;
            }
        }
        return count<=days;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        
        int high = accumulate(begin(weights),end(weights),0);
        int low = max(high/days,*max_element(begin(weights),end(weights)));
        int minCapacity = low;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(countDays(weights,mid,days))
            {
                minCapacity = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return minCapacity;
    }
};