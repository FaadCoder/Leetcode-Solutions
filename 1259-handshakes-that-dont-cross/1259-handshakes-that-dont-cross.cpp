class Solution {
    const int MOD = 1e9+7;
    
    int addUnderModulo(long long int a,long long int b)
    {
        return (a%MOD + b%MOD) % MOD;
    }
    
    int multiplyUnderModulo(long long int a,long long int b)
    {
        long long mul = (a%MOD * b%MOD) % MOD;
        return mul;
    }
    
    
public:
    int numberOfWays(int numPeople) {
        vector<int> peopleWays(numPeople+1,0);
        peopleWays[0]=1;
        
        for(int people=2;people<=numPeople;people+=2)
        {
            for(int partition = 0;partition<=people-2;partition+=2)
                peopleWays[people] = addUnderModulo(peopleWays[people],
                                                   multiplyUnderModulo(peopleWays[partition],
                                                                      peopleWays[people-partition-2]));
        }
        return peopleWays[numPeople];
    }
};