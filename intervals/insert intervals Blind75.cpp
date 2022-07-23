1.MY solution using merger intervals

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
         vector<vector<int>> mergedIntervals;
        if(intervals.size()==0){
            return mergedIntervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<int> interval = intervals[0];
        for(auto it:intervals){
            if(it[0]<=interval[1]){
                interval[1] =max(interval[1],it[1]);
            }
            else{
                mergedIntervals.push_back(interval);
                interval = it;
            }
        }
        mergedIntervals.push_back(interval);
        return mergedIntervals;
    }
};
