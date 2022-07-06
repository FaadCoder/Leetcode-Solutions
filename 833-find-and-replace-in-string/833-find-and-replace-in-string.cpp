class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pair<int,int>> index;
        
        for(int idx=0;idx<indices.size();idx++)
            index.push_back({indices[idx],idx});
        
        sort(index.rbegin(),index.rend());
        
        for(auto idx:index)
        {
            int currentIndex = idx.second;
            string source = sources[currentIndex];
            string target = targets[currentIndex];
            if(s.substr(idx.first,source.length())==source)
            {
                s = s.substr(0,idx.first)+target+s.substr(idx.first+source.length());
            }
        }
        
        return s;
    }
};