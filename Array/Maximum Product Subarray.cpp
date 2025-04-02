/*
Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr[].

Note: It is guaranteed that the output fits in a 32-bit integer.

Examples

Input: arr[] = [-2, 6, -3, -10, 0, 2]
Output: 180
Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180.
Input: arr[] = [-1, -3, -10, 0, 6]
Output: 30
Explanation: The subarray with maximum product is {-3, -10} with product = (-3) * (-10) = 30.
Input: arr[] = [2, 3, 4] 
Output: 24 
Explanation: For an array with all positive elements, the result is product of all elements. 
Constraints:
1 ≤ arr.size() ≤ 106
-10  ≤  arr[i]  ≤  10
*/

int maxProduct(vector<int> &arr) {
    int n = arr.size();
    int leftprd = 1, rightprd = 1;
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        leftprd *= arr[i];
        rightprd *= arr[n - i - 1];
        
        maxi = max({leftprd, rightprd, maxi});
        
        if(leftprd == 0) leftprd = 1;
        if(rightprd == 0) rightprd = 1;
    }
    return maxi;
}
