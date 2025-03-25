/*
Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.
Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 
Examples:
Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.

Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104
*/
int merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    int cnt = 0;
    while(left<=mid && right<=high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            cnt += mid - left + 1;
            right++; 
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(arr[right]);
        right++;  
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high){
    int cnt = 0;
    if(low == high) return cnt;
    int mid = (high + low) / 2;

    cnt+= mergeSort(arr, low, mid);
    cnt+= mergeSort(arr, mid+1, high);
    cnt+= merge(arr, low, mid, high);
    return cnt;
}

int inversionCount(vector<int> &arr) {
    //O(n log n)
    return mergeSort(arr, 0, arr.size()-1);
    
    //O(n^2)
    // int cnt = 0;
    // for(int i=0; i<arr.size()-1; i++){
    //     for(int j=1; j<arr.size(); j++){
    //         if(arr[i]>arr[j] && i<j)
    //             cnt++;
    //     }  
    // }
    // return cnt;
}
