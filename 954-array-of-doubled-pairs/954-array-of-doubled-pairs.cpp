class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> hashMap;
        for(int num:arr)
            hashMap[num]++;
        
        vector<int> keys;
        
        for(auto it:hashMap)
            keys.push_back(it.first);
        
        sort(begin(keys),end(keys),[&](int a,int b){
            return abs(a)<abs(b);
        });
        
        
        for(int num:keys)
        {
            if(hashMap[num]>hashMap[2*num])
                return false;
            hashMap[2*num]-=hashMap[num];
        }
        return true;
    }
};