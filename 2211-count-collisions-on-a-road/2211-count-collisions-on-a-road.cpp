class Solution {
public:
    int countCollisions(string D) 
    {
        int n = D.length();
        int i = 0 , j = n-1,ans=0;
        while(i<=j and D[i] == 'L') i++;
		while(i<=j and D[j] == 'R') j--; 
        for( ; i<=j ; i++) ans += (D[i] != 'S'); 
        return ans;
    }
    
};
