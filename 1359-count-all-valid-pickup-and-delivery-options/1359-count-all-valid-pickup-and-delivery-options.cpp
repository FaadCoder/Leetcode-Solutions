const int MOD = 1e9+7;
class Solution {
long long mul(long long a, long long b)
{
    return (a%MOD * b%MOD)%MOD;
}
    
long long sub(long long a, long long b)
{
    return (a%MOD - b%MOD + MOD)%MOD;
}   
    
public:
    int countOrders(int n) {
        long long fact = 1;
        long long odd = 1;
        for(int i=1;i<=n;i++)
        {
            fact = mul(fact,i);
            odd = mul(odd,sub(mul(2,i),1));
        }
        return mul(fact,odd);
    }
};