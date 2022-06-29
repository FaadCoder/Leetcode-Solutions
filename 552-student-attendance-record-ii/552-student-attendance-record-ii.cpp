class Solution
{
    const int MOD = 1e9 + 7;
    int valueCache[100001][3][4];

    int add(int a, int b)
    {
        return (a % MOD + b % MOD) % MOD;
    }

    int getEligibleStudents(int n, int absent = 0, int late = 0)
    {
        if (absent == 2 or late == 3)
            return 0;
        
        if (n == 0)
            return 1;

        int total = 0;
        if (valueCache[n][absent][late] != -1)
            return valueCache[n][absent][late];
       	// case Present
        total = add(total, getEligibleStudents(n - 1, absent, 0));

       	// case Late
        total = add(total, getEligibleStudents(n - 1, absent, late + 1));

       	// case Absent
        total = add(total, getEligibleStudents(n - 1, absent + 1, 0));

        return valueCache[n][absent][late] = total;
    }

    public:
        int checkRecord(int n)
        {
            memset(valueCache, -1, sizeof(valueCache));
            return getEligibleStudents(n);
        }
};