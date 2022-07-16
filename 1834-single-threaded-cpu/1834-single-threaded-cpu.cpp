class Solution {
    
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> taskOrder;
        for(int idx=0;idx<tasks.size();idx++)
            tasks[idx].push_back(idx);
        
        sort(tasks.begin(),tasks.end());
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> nextTask;

        long long int currentTime = tasks[0][0];
        nextTask.push({tasks[0][1],tasks[0][2]});
        
        int taskIdx = 1;
        while(taskIdx<tasks.size() or !nextTask.empty())
        {
            if(nextTask.empty())
            {
                nextTask.push({tasks[taskIdx][1],tasks[taskIdx][2]});
                currentTime = tasks[taskIdx][0];
                taskIdx++;
            }
            else
            {
                auto top = nextTask.top();
                currentTime+=top[0];
                nextTask.pop();
                taskOrder.push_back(top[1]);
                while(taskIdx<tasks.size() and currentTime>=tasks[taskIdx][0])
                {
                    nextTask.push({tasks[taskIdx][1],tasks[taskIdx][2]});
                    taskIdx++;
                }
            }
        }
        
        
        return taskOrder;
    }
};