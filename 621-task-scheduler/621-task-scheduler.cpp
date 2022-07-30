class Solution
{
    public:
        int leastInterval(vector<char> &tasks, int n)
        {
            if (n == 0)
                return tasks.size();

            vector<int> freq(26, 0);

            for (auto task: tasks)
                freq[task - 'A']++;
            
            sort(freq.rbegin(), freq.rend());

            int totalIdleTime = (freq[0] - 1) * n;

            for (int ch = 1; ch <= 25; ch++)
                totalIdleTime -= min(freq[0]- 1, freq[ch]);

            totalIdleTime = max(0,totalIdleTime);
            
            return totalIdleTime + tasks.size();
        }
};
/*

A - 3
B - 3
C - 3
D - 2
E - 1

*/