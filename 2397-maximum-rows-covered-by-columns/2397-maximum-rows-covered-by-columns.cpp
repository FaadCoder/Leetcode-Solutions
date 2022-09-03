class Solution
{
    public:
        int maximumRows(vector<vector < int>> &mat, int cols)
        {
            int mx = 0;
            for (int mask = 0; mask < (1 << mat[0].size()); mask++)
            {
                if (__builtin_popcount(mask) != cols) continue;	
                int c = 0;
                for (int i = 0; i < mat.size(); i++)
                {
                    bool take = true;
                    for (int j = 0; j < mat[0].size(); j++)
                    {
                        if ((mask >> j &1) == 0 && mat[i][j] == 1)
                        {
                            take = false;
                            break;
                        }
                    }
                    if (take) c++;
                }
                mx = max(mx, c);
            }
            return mx;
        }
};