class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(k==1)
            return true;
        
        int numberOfElements = nums.size();
        if(numberOfElements % k)
            return false;
        
        unordered_map<int,int> hashMap;
        for(int num:nums)
            hashMap[num]++;
        
        int numberOfGroups = numberOfElements/k;
        sort(nums.begin(),nums.end());
        
            
        for(int num:nums)
        {
            int curr = 1;
            int originalNumber = num;
            if(hashMap[originalNumber]>0)
            {
                hashMap[originalNumber]-=1;
                while(hashMap.count(originalNumber+1) and hashMap[originalNumber + 1]>0)
                {
                    hashMap[originalNumber+1]-=1;
                    curr++;
                    originalNumber+=1;
                    if(curr == k)
                        break;
                }
                cout<<endl;
            }
            
            if(curr == k)
                numberOfGroups--;
        }
        
        return numberOfGroups==0;
    }
};