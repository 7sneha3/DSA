/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

vector<int>getLeftMax(vector<int>&height, int n){
        vector<int>leftMax(n);
        leftMax[0] = height[0];

        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        return leftMax;
    }

    vector<int>getRightMax(vector<int>&height, int n){
        vector<int>rightMax(n);
        rightMax[n-1] = height[n-1];

        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        return rightMax;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        if(n==1 || n==0) return 0;

        vector<int>leftMax = getLeftMax(height, n);
        vector<int>rightMax = getRightMax(height, n);

        int sum = 0;
        for(int i=0; i<n; i++){
            sum += min(leftMax[i], rightMax[i]) - height[i];
        }
        return sum;
    }

//TC - O(n)
//SC - O(n)
