class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.size()<=k)
            return arr;
        vector<int> ans;
        int low = 0,high = arr.size()-k;
        while(low<high)
        {
            int mid = low + (high-low)/2;
            if(x-arr[mid]>arr[mid+k]-x)
                low = mid+1;
            else
                high = mid;
        }
        for(int i=0;i<k;i++)
            ans.push_back(arr[i+low]);
        return ans;
    }
};