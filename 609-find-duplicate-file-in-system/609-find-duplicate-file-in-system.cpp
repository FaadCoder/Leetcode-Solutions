class Solution {
    
    vector<string> getAllComponents(string &path)
    {
        vector<string> components;
        string temp;
        stringstream ss(path);
        while(getline(ss, temp, ' '))
            components.push_back(temp);
        
        return components;
    }
    
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> contentToPathMap;
        
        for(string &path : paths)
        {
            vector<string> components = getAllComponents(path);
            string currentPath = components[0];
            
            for(int idx = 1; idx < components.size(); idx++)
            {
                string content = components[idx].substr(components[idx].find_first_of('('), components[idx].length() - 1);
                string fileName = components[idx].substr(0, components[idx].find_first_of('('));
                contentToPathMap[content].push_back(currentPath + "/" + fileName);
            }
        }
        
        vector<vector<string>> ans;
        
        for(auto it : contentToPathMap)
            if(it.second.size() > 1)
                ans.push_back(it.second);
        
        return ans;
    }
};