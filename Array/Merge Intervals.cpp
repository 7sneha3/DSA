/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size() <= 1)
        return intervals;

    int n = intervals.size();
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;
    //brute force
    /*for(int i=0; i<n; i++){
        int start = intervals[i][0];
        int end = intervals[i][1];

        if(!ans.empty() && end <= ans.back()[1])
            continue;

        for(int j=i+1; j<n; j++){
            if(intervals[j][0] <= end)
                end = max(intervals[j][1], end);
            else
                break;
        }
        ans.push_back({start, end});
    }*/

    //optimal
    for(int i=0; i<n; i++){
        if(ans.empty() || intervals[i][0] > ans.back()[1])
            ans.push_back(intervals[i]);
        else
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
    }
    return ans;
}
