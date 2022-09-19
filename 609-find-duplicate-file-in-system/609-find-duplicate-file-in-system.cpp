class Solution {
    
    vector<string> getAllFiles(string &path)
    {
        vector<string> files;
        string temp;
        stringstream ss(path);
        
        while(getline(ss, temp, ' '))
            files.push_back(temp);
        
        return files;
    }
    
    string getFileContent(string &file)
    {
        /*
            3 . t x t ( a b c d )
            0 1 2 3 4 5 6 7 8 9 10
        */
        
        int openBracketIdx = file.find_first_of('(');
        int closeBracketIdx = file.find_first_of(')');
        
        return file.substr(openBracketIdx + 1, closeBracketIdx - openBracketIdx - 1);
    }
    
    string getFileName(string &file)
    {
        return file.substr(0, file.find_first_of('('));
    }
    
    void addContentMapping(unordered_map<string, vector<string>> &contentToPathMap, string &path)
    {
        vector<string> files = getAllFiles(path);
        string rootName = files[0];

        for(int idx = 1; idx < files.size(); idx++)
        {
            string content = getFileContent(files[idx]);
            string fileName = getFileName(files[idx]);
            contentToPathMap[content].push_back(rootName + "/" + fileName);
        }
    }
    
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> contentToPathMap;
        
        for(string &path : paths)
            addContentMapping(contentToPathMap, path);
        
        vector<vector<string>> duplicateFiles;
        
        for(auto it : contentToPathMap)
            if(it.second.size() > 1)
                duplicateFiles.push_back(it.second);
        
        return duplicateFiles;
    }
};