class Solution {
    
    int getPartitions(string &str)
    {
        unordered_set<char> hashSet;
        
        int partitions = 0;
        
        for(char ch : str)
        {
            if(hashSet.count(ch))
            {
                // cout<<ch << " ";
                partitions+=1;
                hashSet.clear();
            }
            hashSet.insert(ch);
        }
        return partitions + 1;
    }
    
public:
    int partitionString(string s) {
        
        int substrings1 = getPartitions(s);
        reverse(s.begin(), s.end());
        int substrings2 = getPartitions(s);
        
        return min(substrings1, substrings2);
    }
};