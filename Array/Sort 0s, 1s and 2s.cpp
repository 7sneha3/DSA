/*
Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.
You need to solve this problem without utilizing the built-in sort function.
Examples:
Input: arr[] = [0, 1, 2, 0, 1, 2]
Output: [0, 0, 1, 1, 2, 2]
Explanation: 0s 1s and 2s are segregated into ascending order.

Input: arr[] = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
Explanation: 0s 1s and 2s are segregated into ascending order.

Follow up: Could you come up with a one-pass algorithm using only constant extra space?
Constraints:
1 <= arr.size() <= 106
0 <= arr[i] <= 2
*/

void sort012(vector<int>& arr) {
    /*
    //O(n^2)
    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
    */

    /*
    //O(n)
    int cnt0=0, cnt1=0, cnt2=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]==0)
            cnt0++;
        else if(arr[i]==1)
            cnt1++;
        else if(arr[i]==2)
            cnt2++;
    }
    
    int index = 0;
    while(cnt0--){
        arr[index++] = 0;
    }
    
    while(cnt1--){
        arr[index++] = 1;
    }
    
    while(cnt2--){
        arr[index++] = 2;
    }
    */

    //O(n)
    int n = arr.size();
    int low=0, mid=0, high=n-1;
    while(mid<=high){
        if(arr[mid]==1)
            mid++;
        else if(arr[mid]==0){
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]==2){
            swap(arr[mid], arr[high]);
            high--;
        }
    }  
}
