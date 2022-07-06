class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,int> indegree;
        unordered_set<string> vis(supplies.begin(),supplies.end());
        unordered_map<string,unordered_set<string>> graph;
        vector<string> ans;
        
        for(int recipe = 0; recipe<size(recipes); recipe++)
        {
            string currentRecipe = recipes[recipe];
            for(string ingredient:ingredients[recipe])
            {
                graph[ingredient].insert(currentRecipe);
                indegree[currentRecipe]++;
            }
        }
        
        
        queue<string> bfsQueue;
        for(auto &it:supplies)
        {
            if(indegree[it]==0)
                bfsQueue.push(it);
        }
        
        while(!bfsQueue.empty())
        {
            string recipe = bfsQueue.front();
            bfsQueue.pop();
            for(auto child:graph[recipe])
            {
                indegree[child]--;
                if(indegree[child]==0)
                    bfsQueue.push(child);
            }
            
        }
        
        for(string recipe:recipes)
        {
            if(indegree[recipe]==0)
                ans.push_back(recipe);
        }
        return ans;
    }
};