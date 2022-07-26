/*
HINTS: 
- Try to draw the example as heights of Histogram
- We can remove all continuous bricks by making 1 move
*/

class Solution
{
    public:
        int minNumberOperations(vector<int> &target)
        {
            int operations = target[0];
            for (int idx = 1; idx < target.size(); idx++)
                operations += max(target[idx] - target[idx - 1], 0);
            return operations;
        }
};