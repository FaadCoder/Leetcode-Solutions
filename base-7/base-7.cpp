class Solution {
public:
    string convertToBase7(int num) {
        
        if(num == 0)
            return "0";
        
        string convert = "";
        char sign = '+';
        if(num < 0)
            sign = '-';
        num = abs(num);
        
        while(num)
        {
            convert.push_back((num % 7) + '0');
            num/=7;
        }
        if(sign == '-')
            convert.push_back(sign);
        reverse(begin(convert), end(convert));
        
        return convert;
    }
};