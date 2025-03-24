/*
Given an array arr[], check whether it is sorted in non-decreasing order. Return true if it is sorted otherwise false.
Examples:
Input: arr[] = [10, 20, 30, 40, 50]
Output: true
Explanation: The given array is sorted.

Input: arr[] = [90, 80, 100, 70, 40, 30]
Output: false
Explanation: The given array is not sorted.

Constraints:
1 ≤ arr.size ≤ 106
- 109 ≤ arr[i] ≤ 109
*/
bool arraySortedOrNot(vector<int>& arr) {
    // for(int i=0; i<arr.size(); i++){
    //     if(arr[i-1] > arr[i])
    //         return false;
            
    //     return true;
    // }
  
    int cnt=0;
    for(int i=0; i<arr.size()-1; i++){
        if(arr[i+1] >= arr[i]){
            cnt++;
            continue;
        }
    }
    if(cnt == arr.size()-1)
        return true;
    else
        return false;
}
