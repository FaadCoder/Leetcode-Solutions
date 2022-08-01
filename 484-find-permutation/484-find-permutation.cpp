/*
Algorithm:

- Get the sorted array first of size s.length()+1
- Then reverse each consecutive D's(Probably 1 D also occur)
Lets say

D I I D D
[1,2,3,4,5,6]
steps:

[D] I I D D
[2,1,3,4,5,6]
 
 D I I [D D]
[2,1,3,4,6,5]


*/
class Solution {
    
    void reverseVector(vector<int> &permutation, int start, int end)
    {
        while(start<end)
        {
            swap(permutation[start++],permutation[end--]);
        }
    }

    
public:
    vector<int> findPermutation(string s) {
        vector<int> permutation(s.length()+1);
        iota(begin(permutation),end(permutation),1);
        
        for(int idx = 0; idx<s.length(); idx++)
        {
            if(s[idx]=='D')
            {
                int start = idx;
                while(idx < s.length() and s[idx]=='D')
                    idx++;
                reverse(begin(permutation)+start,begin(permutation)+idx+1);
            }
        }
        return permutation;
    }
};