class Solution {
public:
    int romanToInt(string s) {
        int integerValue = 0;
        
        unordered_map<char,int> romanToIntegerMap = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
            
        };
        
        int stringIdx = 0;
        
        while(stringIdx < s.length() - 1)
        {
            char currentChar = s[stringIdx];
            char nextChar = s[stringIdx+1];
            if(currentChar == 'I')
            {
                if(nextChar == 'V')
                {
                    integerValue += 4;
                    stringIdx+=2;
                }
                else if(nextChar == 'X')
                {
                    integerValue += 9;
                    stringIdx += 2;
                }
                else
                {
                    integerValue += 1;
                    stringIdx += 1;
                }
            }
            else if(currentChar == 'X')
            {
                if(nextChar == 'L')
                {
                    integerValue += 40;
                    stringIdx+=2;
                }
                else if(nextChar == 'C')
                {
                    integerValue += 90;
                    stringIdx+=2;
                }
                else
                {
                    integerValue += 10;
                    stringIdx+=1;
                }
            }
            else if(currentChar == 'C')
            {
                if(nextChar == 'D')
                {
                    integerValue += 400;
                    stringIdx+=2;
                }
                else if(nextChar == 'M')
                {
                    integerValue += 900;
                    stringIdx+=2;
                }
                else
                {
                    integerValue += 100;
                    stringIdx+=1;
                }
            }
            else
            {
                integerValue += romanToIntegerMap[currentChar];
                stringIdx+=1;
            }
        }
        
        if(stringIdx < s.length())
            integerValue += romanToIntegerMap[s[stringIdx]];
        
        return integerValue;
    }
};