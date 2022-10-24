class Solution {
    int maxLengthRes = 0;
    bool isValid(string &str)
    {
        int freq[26] = {0};
        
        for(char &ch : str)
        {
            if(freq[ch - 'a'] > 0)
                return false;
            freq[ch - 'a'] += 1;
        }
        return true;
    }
    
    void getMaxLength(vector<string> &arr, int idx = 0, string temp = "")
    {
        if(idx >= arr.size())
        {
            if(isValid(temp))
                maxLengthRes = max(maxLengthRes,(int)temp.length());
            return;
        }
        getMaxLength(arr, idx + 1, temp); 
        getMaxLength(arr, idx + 1, temp + arr[idx]);
               
    }
    
    
public:
    int maxLength(vector<string>& arr) 
    {
        maxLengthRes = 0;
        getMaxLength(arr);
        return maxLengthRes;
    }
};