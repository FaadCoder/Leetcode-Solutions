class Solution {
    
    int getMinutesFromString(string &str)
    {
        stringstream ss(str);
        string temp;
        int total = 0;
        bool isHour = true;
        while(getline(ss,temp,':'))
        {
            if(isHour)
            {
                isHour = false;
                total += (stoi(temp) * 60);
            }
            else
            {
                total += stoi(temp);
            }
        }
        return total;
    }
    
public:
    int findMinDifference(vector<string>& timePoints) 
    {
        vector<int> timePointsInMins;
        for(string &str:timePoints)
            timePointsInMins.push_back(getMinutesFromString(str));
        sort(timePointsInMins.begin(),timePointsInMins.end());
        int minDiff = INT_MAX;
       
        for(int idx = 0; idx<timePointsInMins.size()-1; idx++)
        {
            minDiff = min(minDiff,timePointsInMins[idx+1] - timePointsInMins[idx]);    
        }
        minDiff = min(minDiff,timePointsInMins[0] - timePointsInMins.back() + 24*60);
        return minDiff;
    }
};