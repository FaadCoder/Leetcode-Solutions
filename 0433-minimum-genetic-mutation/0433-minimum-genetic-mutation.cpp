class Solution {
    bool isValidChange(string &start, string &gene)
    {
        int diffCount = 0;
        for(int idx = 0; idx < start.length(); idx++)
        {
            diffCount += (gene[idx]!=start[idx]);
            
        }
        
        return diffCount == 1;
    }
    
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {
        unordered_set<string> vis;
        vis.insert(start);
        queue<string> bfsQ;
        bfsQ.push(start);
        int lvl = 0;
        
        while(!bfsQ.empty())
        {
            int qSize = bfsQ.size();
            
            while(qSize--)
            {
                auto front = bfsQ.front();
                bfsQ.pop();
                
                if(front == end)
                    return lvl;
                
                for(string &gene : bank)
                {
                    if (isValidChange(front, gene) and !vis.count(gene))
                    {
                        vis.insert(gene);
                        bfsQ.push(gene);
                    }
                }
            }
            
            lvl += 1;
        }
        
        return -1;
    }
};