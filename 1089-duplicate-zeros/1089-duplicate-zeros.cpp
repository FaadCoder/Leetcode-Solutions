class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int numberOfZeros = count(begin(arr),end(arr),0);
        int i = arr.size()-1;
        int j = arr.size() + numberOfZeros - 1;
        
        while(i>=0 and j>=0)
        {
            if(arr[i]!=0)
            {
                if(j<arr.size())
                    arr[j] = arr[i];
            }
            else
            {
                if(j<arr.size())
                    arr[j] = arr[i];
                j--;
                if(j<arr.size())
                    arr[j] = arr[i];
            }
            i--;
            j--;
        }
    }
};