/*
You are given an array arr[] of non-negative numbers. Each number tells you the maximum number of steps you can jump forward from that position.

For example:

If arr[i] = 3, you can jump 1 step, 2 steps, or 3 steps forward from position i.
If arr[i] = 0, you cannot jump forward from that position.
Your task is to find the minimum number of jumps needed to move from the first position in the array to the last position.

Note:  Return -1 if you can't reach the end of the array.

Examples : 

Input: arr[] = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
Output: 3 
Explanation: First jump from 1st element to 2nd element with value 3. From here we jump to 5th element with value 9, and from here we will jump to the last. 
Input: arr = [1, 4, 3, 2, 6, 7]
Output: 2 
Explanation: First we jump from the 1st to 2nd element and then jump to the last element.
Input: arr = [0, 10, 20]
Output: -1
Explanation: We cannot go anywhere from the 1st element.
Constraints:
2 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 105
*/

int minJumps(vector<int>& arr) {
    if(!arr[0]) return -1;
    int ans = 1, jump = arr[0], mx = 0;
    for(int i=1; i<arr.size(); i++){
        mx--;
        jump--;
        mx = max(mx, arr[i]);
        if(!jump && i!=arr.size()-1){
            if(mx<=0) return -1;
            jump = mx;
            mx = 0;
            ans++;
        }
    }
    return ans;
}
