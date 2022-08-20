class UnionFind
{
    private:
        unordered_map < long long, long long > parent, size, sum;
    long long maxSum = 0;

    public:
        UnionFind(vector<int> &nums)
        {
            parent.clear();
            size.clear();

            for (int idx = 0; idx < nums.size(); idx++)
                sum[idx] = nums[idx], parent[idx] = idx, size[idx] = 1;
        }

    int getParent(long long child)
    {
        if (child == parent[child])
            return child;
        return parent[child] = getParent(parent[child]);
    }

    void unionSets(long long set1, long long set2)
    {

        set1 = getParent(set1);
        set2 = getParent(set2);

        if (set1 == set2)
        {
            maxSum = max(maxSum, size[set1]);
            return;
        }

        if (size[set1] < size[set2])
            swap(set1, set2);

        parent[set2] = set1;
       	// size[set1] += size[set2];
        sum[set1] += sum[set2];
    }

    long long getMaxSum(int child)
    {
        return sum[getParent(child)];
    }
};

class Solution
{
    public:
        vector < long long > maximumSegmentSum(vector<int> &nums, vector<int> &removeQueries)
        {
            vector < long long > ans(nums.size());
            UnionFind dsu(nums);

            vector<int> vis(nums.size(), 0);
            long long mx = 0;
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                ans[i] = mx;
                int idx = removeQueries[i];
                vis[idx] = 1;

                if (idx - 1 >= 0 and vis[idx - 1])
                    dsu.unionSets(idx, idx - 1);

                if (idx + 1 < nums.size() and vis[idx + 1])
                    dsu.unionSets(idx, idx + 1);

                mx = max(mx, dsu.getMaxSum(idx));
            }

            return ans;
        }
};