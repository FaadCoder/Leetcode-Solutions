class Solution
{
    public:
        vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill)
        {
            unordered_map<int, vector < int>> pros;
            for (int i = 0; i < pid.size(); ++i)
                pros[ppid[i]].push_back(pid[i]);
            vector<int> ans;
            queue<int> q;
            q.push(kill);
            while (!q.empty())
            {
                ans.push_back(q.front());
                q.pop();
                for (int m: pros[ans.back()])
                    q.push(m);
            }
            return ans;
        }
};