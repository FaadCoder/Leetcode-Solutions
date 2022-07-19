class Solution {
public:
    string nextClosestTime(string time) 
    {
        unordered_set<char> hashSet(begin(time),end(time));
        int hours = (time[0]-'0')*10+(time[1]-'0');
        int minutes = (time[3]-'0')*10+(time[4]-'0');
        
        while(true)
        {
            minutes+=1;
            if(minutes==60)
            {
                minutes=0;
                hours = (hours+1)%24;
            }
            
            string newTime = string(1,'0'+hours/10)+string(1,'0'+hours%10);
            newTime+=":";
            newTime+=string(1,'0'+minutes/10)+string(1,'0'+minutes%10);
            bool isValid = true;
            for(char ch:newTime)
            {
                if(!hashSet.count(ch))
                {
                    isValid = false;
                    break;
                }
            }
            if(isValid)
                return newTime;
        }
        
        return "";
    }
};