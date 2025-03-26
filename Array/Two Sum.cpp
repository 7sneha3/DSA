/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/
//O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        //gives duplicate pairs
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                }  
            }
        }
        return result;
    }
};

/*
Given an integer array arr, return all the unique pairs [arr[i], arr[j]] such that i != j and arr[i] + arr[j] == 0.
Note: The pairs must be returned in sorted order, the solution array should also be sorted, and the answer must not contain any duplicate pairs.

Examples:
Input: arr = [-1, 0, 1, 2, -1, -4]
Output: [[-1, 1]]
Explanation: arr[0] + arr[2] = (-1)+ 1 = 0.
arr[2] + arr[4] = 1 + (-1) = 0.
The distinct pair are [-1,1].

Input: arr = [6, 1, 8, 0, 4, -9, -1, -10, -6, -5]
Output: [[-6, 6],[-1, 1]]
Explanation: The distinct pairs are [-1, 1] and [-6, 6].

Expected Time Complexity: O(n log n)
Expected Auxiliary Space: O(n).

Constraints:
3 <= arr.size <= 105
-105 <= arr[i] <= 105
*/
vector<vector<int>> getPairs(vector<int>& arr) {

//good to go but duplicate pair counts
/*vector<vector<int>> result;
for(int i=0; i<arr.size(); i++){
    for(int j=i+1; j<arr.size(); j++){
        if(arr[i]+arr[j] == 0){
            result.push_back({arr[i], arr[j]});
        }  
    }
}
return result;*/

sort(arr.begin(), arr.end());

vector<vector<int>> result;
int left = 0, right = arr.size()-1;

while(left < right){
    int sum = arr[left] + arr[right];
    
    if(sum == 0){
        result.push_back({arr[left], arr[right]});
        
        //handled duplicate pairs
        while(left < right && arr[left] == arr[left+1]) left++;
        while(left < right && arr[right] == arr[right-1]) right--;
        
        left++; //go for next index
        right--;  //go for next index
    }
    else if(sum < 0)
        left++;  //array is sorted so go to next element
    else
        right--;  //array is sorted go to previous ie. -- element
}
return result;
}
