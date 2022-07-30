class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for(int idx = 0; idx<position.size(); idx++)
            cars.push_back({position[idx],speed[idx]});
        
        sort(rbegin(cars),rend(cars));
        
        stack<double> timeStack;
        
        for(int car = 0; car<cars.size(); car++)
        {
            double time = (1.0 * (target - cars[car].first))/cars[car].second;

            if(timeStack.empty())
                timeStack.push(time);
            else
            {
                if(timeStack.top() >= time)
                    continue;
                else
                    timeStack.push(time);
            }
        }
        
        return timeStack.size();
    }
};