class RangeModule {
public:
    void addRange(int left, int right) {
        auto [begin, end] = intervals_.equal_range({ left, right });
        
        if (begin != end) {
            left = min(left, begin->first);
            right = max(right, prev(end)->second);
            intervals_.erase(begin, end);
        }
        
        intervals_.emplace(left, right);
    }
    
    bool queryRange(int left, int right) const {
        auto [begin, end] = intervals_.equal_range({ left, right });
        
        return begin != end && left >= begin->first && right <= begin->second;
        
    }
    
    void removeRange(int left, int right) {
        auto [begin, end] = intervals_.equal_range({ left, right });
        if (begin != end) {
            auto beginFirst = begin->first;
            auto endSecond = prev(end)->second;
            intervals_.erase(begin, end);
            if (beginFirst < left) {
                intervals_.emplace(beginFirst, left);
            }
            if (endSecond > right) {
                intervals_.emplace(right, endSecond);
            }
        }
    }
    
private:
    using Interval = pair<int, int>;
    struct IntervalCompare {
        bool operator()(const Interval& l, const Interval& r) const {
            return l.second < r.first;
        }
    };
    set<Interval, IntervalCompare> intervals_;
};