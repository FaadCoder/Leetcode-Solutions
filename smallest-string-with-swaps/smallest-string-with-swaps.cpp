class UnionFind{
private:
    unordered_map<int,int> parent,size;
    int connectedComponents;
public:
    
    UnionFind(int numberOfElements)
    {
        parent.clear();
        size.clear();
        for(int element = 0; element<=numberOfElements; element++)
        {
            parent[element] = element;
            size[element] = 1;
        }
        connectedComponents = numberOfElements;
    }
    
    int findParent(int child)
    {
        if(child == parent[child])
            return child;
        return parent[child] = findParent(parent[child]);
    }
    
    bool unionSet(int element1,int element2)
    {
        if(isConnected(element1,element2))
            return false;
        
        int parentOfElement1 = findParent(element1);
        int parentOfElement2 = findParent(element2);
        
        if(size[parentOfElement1] < size[parentOfElement2])
            swap(parentOfElement1,parentOfElement2);
        
        parent[parentOfElement2] = parentOfElement1;
        size[parentOfElement1] += size[parentOfElement2];
        connectedComponents -= 1;
        return true;
    }
    
    bool isConnected(int element1,int element2)
    {
        return (findParent(element1)==findParent(element2));
    }
    
    int getNumberOfSets()
    {
        return connectedComponents;
    }
};


class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        UnionFind dsu(s.length());
        for(auto &pair:pairs)
            dsu.unionSet(pair[0],pair[1]);
        unordered_map<int,vector<int>> parentToChildrenMap;
        
        for(int idx = 0; idx<s.length(); idx++)
            parentToChildrenMap[dsu.findParent(idx)].push_back(idx);
        
        string smallestString(s.length(),' ');
        
        for(auto &it:parentToChildrenMap)
        {
            string sortedCharacters;
            for(int idx:it.second)
            {
                sortedCharacters.push_back(s[idx]);
            }
            sort(sortedCharacters.begin(),sortedCharacters.end());
            for(int idx=0;idx<it.second.size();idx++)
            {
                smallestString[it.second[idx]] =  sortedCharacters[idx];
            }
        }
        return smallestString;
    }
};