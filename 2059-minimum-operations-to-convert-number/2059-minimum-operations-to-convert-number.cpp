class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) 
    {
        int lvl = 0;
        queue<int> q;
        q.push(start);
        unordered_set<int> vis;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int front = q.front();
                q.pop();
                if(front==goal)
                    return lvl;
                if(front<0 or front>1000 or vis.count(front))
                    continue;
                vis.insert(front);
                for(int ele:nums)
                {
                    int op1 = front + ele;
                    int op2 = front - ele;
                    int op3 = front ^ ele;
                    q.push(op1);
                    q.push(op2);
                    q.push(op3);
                }
            }
            lvl+=1;
        }
        
        return -1;
    }
};