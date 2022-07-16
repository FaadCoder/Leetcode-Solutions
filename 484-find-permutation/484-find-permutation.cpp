class Solution
{
    public:
        vector<int> findPermutation(string s)
        {
            vector<int> permutation;
            int start = 0;
            int end = s.length() + 1;
            for (int i = start; i < end; i++)
                permutation.push_back(i + 1);

            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == 'D')
                {
                    int h = i;
                    while (i < s.length() and s[i] == 'D')
                        i++;
                    reverse(permutation.begin() + h, permutation.begin() + i + 1);
                }
            }

            return permutation;
        }
};