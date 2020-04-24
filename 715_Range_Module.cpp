/*
715. Range Module (Hard)

https://leetcode.com/problems/range-module/
Runtime: 364 ms, faster than 64.92% of C++ online submissions for Range Module.
Memory Usage: 62.6 MB, less than 100.00% of C++ online submissions for Range Module.
*/

class RangeModule {
public:
    map<int, int, greater<int>> ranges;
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        for (auto itr = ranges.lower_bound(right); itr != ranges.end() && itr->second >= left;)
        {
            left = min(left, itr->first);
            right = max(right, itr->second);
            itr++;
            ranges.erase(prev(itr));
        }
        ranges[left] = right;
        
    }
    
    bool queryRange(int left, int right) {
     auto itr = ranges.lower_bound(left);
        if (itr == ranges.end())
        {
            return false;
        }
        if (right <= itr->second)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    
    void removeRange(int left, int right) {
       for (auto itr = ranges.upper_bound(right); itr != ranges.end() && itr->second > left;)
        {
            auto nt = next(itr);
            if (itr->second > right)
            {
                ranges[right] = itr->second;
            }
            if (itr->first < left)
            {
                itr->second = left;
            }
            else
            {
                ranges.erase(itr);
            }
            itr = nt;
        }
        
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */