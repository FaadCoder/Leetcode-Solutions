class Solution
{
    public:
        int kthGrammar(int n, int k)
        {
            if (k == 1 or n == 1)
                return 0;

            int symbols = (1 << (n - 2));

            if (k <= symbols)
                return kthGrammar(n - 1, k);

            return !kthGrammar(n - 1, k - symbols);
        }
};