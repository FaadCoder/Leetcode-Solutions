class SummaryRanges {
    map<int,int> startToEndMapping;
public:
    SummaryRanges() {
        startToEndMapping.clear();
    }
    
    void addNum(int val) {
        if(startToEndMapping.empty())
            startToEndMapping[val] = val;
        else
        {
            auto lowerBound = startToEndMapping.lower_bound(val);
            
            if(lowerBound==startToEndMapping.begin())
            {
                // 1st case new number will be added at the beginning,
                
                if(lowerBound->first == val+1)
                {
                    int end = lowerBound->second;
                    startToEndMapping.erase(lowerBound->first);
                    startToEndMapping[val] = end;
                }
                else if(val>=lowerBound->first and val<=lowerBound->second)
                {
                }
                else
                {
                    
                    startToEndMapping[val] = val;
                }
            }
            else if(lowerBound == startToEndMapping.end())
            {
               // 2nd case new number will be added at the end.
                if(prev(lowerBound)->second == val-1)
                {
                    int start = prev(lowerBound)->first;
                    startToEndMapping.erase(start);
                    startToEndMapping[start] = val;
                }
                else if(val>=prev(lowerBound)->first and val<=prev(lowerBound)->second)
                {
                    // Kuch mat karo
                }
                else
                {
                    startToEndMapping[val] = val;
                }
            }
            else
            {
                // 3rd case new number will be added in between.
                int prevEnd = prev(lowerBound)->second;
                int nextStart = lowerBound->first;
                if(prevEnd==val-1 and nextStart==val+1)
                {
                    int start = prev(lowerBound)->first;
                    int end = lowerBound->second;
                    startToEndMapping.erase(prev(lowerBound)->first);
                    startToEndMapping.erase(lowerBound->first);
                    startToEndMapping[start] = end;
                }
                else if(prevEnd==val-1)
                {
                    int start = prev(lowerBound)->first;
                    startToEndMapping.erase(start);
                    startToEndMapping[start] = val;
                }
                else if(nextStart==val+1)
                {
                    int end = lowerBound->second;
                    startToEndMapping.erase(nextStart);
                    startToEndMapping[val] = end;
                }
                else if(prevEnd>=val or val>=nextStart)
                {
                    
                }
                else
                {
                    if(!startToEndMapping.count(val))
                    startToEndMapping[val] = val;
                }
            }
        }       
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;
        for(auto it:startToEndMapping)
            intervals.push_back({it.first,it.second});
        
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */