/*
Given an array arr, rotate the array by one position in clockwise direction.
Examples:
Input: arr[] = [1, 2, 3, 4, 5]
Output: [5, 1, 2, 3, 4]
Explanation: If we rotate arr by one position in clockwise 5 come to the front and remaining those are shifted to the end.

Input: arr[] = [9, 8, 7, 6, 4, 2, 1, 3]
Output: [3, 9, 8, 7, 6, 4, 2, 1]
Explanation: After rotating clock-wise 3 comes in first position.

Constraints:
1<=arr.size()<=105
0<=arr[i]<=105
*/

void rotate(vector<int> &arr) {
  
  /*  
  //SC(O(N)
    vector<int> arr2;
    arr2.push_back(arr[arr.size()-1]);
    
    for(int i=0; i<arr.size()-1; i++){
        arr2.push_back(arr[i]);
    }
    
    arr.assign(arr2.begin(), arr2.end());  //copying vector arr2 into arr the given vector
  */

  //SC(O(1))
    int result = arr[arr.size()-1];
    for(int i=arr.size()-2; i>=0; i--){
        arr[i+1] = arr[i];
    }
    
    arr[0] = result;
}
