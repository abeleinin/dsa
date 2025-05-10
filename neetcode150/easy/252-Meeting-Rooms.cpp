#include <vector>

using namespace std;

// Definition of Interval:
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

/**
 * \c Solution
 * 
 * 1. Sort the intervals by the start time
 * 2. Return false if the end time of the ith interval is ever greater than 
 *    the with the start time of the ith+1 interval
 * 3. Otherwise, return true
 * 
 * Time  : O(n log n)
 * Space : O(1)
 */
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;
            
        sort(intervals.begin(), intervals.end(), 
            [](const auto& a, const auto& b) {
                return a.start < b.start;
            }
        );

        for (int i = 0; i + 1 < intervals.size(); i++) {
            if (intervals[i].end > intervals[i+1].start) {
                return false;
            }
        }
            
        return true;
    }
};
    