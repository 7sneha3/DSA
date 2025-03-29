/*
Given an unsorted array arr containing both positive and negative numbers. Your task is to rearrange the array and convert it into an array of alternate positive and negative numbers without changing the relative order.
Note:
- Resulting array should start with a positive integer (0 will also be considered as a positive integer).
- If any of the positive or negative integers are exhausted, then add the remaining integers in the answer as it is by maintaining the relative order.
- The array may or may not have the equal number of positive and negative integers.
Examples:

Input: arr[] = [9, 4, -2, -1, 5, 0, -5, -3, 2]
Output: [9, -2, 4, -1, 5, -5, 0, -3, 2]
Explanation: The positive numbers are [9, 4, 5, 0, 2] and the negative integers are [-2, -1, -5, -3]. Since, we need to start with the positive integer first and then negative integer and so on (by maintaining the relative order as well), hence we will take 9 from the positive set of elements and then -2 after that 4 and then -1 and so on.

Input: arr[] = [-5, -2, 5, 2, 4, 7, 1, 8, 0, -8]
Output: [5, -5, 2, -2, 4, -8, 7, 1, 8, 0]
Explanation : The positive numbers are [5, 2, 4, 7, 1, 8, 0] and the negative integers are [-5,-2,-8]. According to the given conditions we will start from the positive integer 5 and then -5 and so on. After reaching -8 there are no negative elements left, so according to the given rule, we will add the remaining elements (in this case positive elements are remaining) as it in by maintaining the relative order.

Input: arr[] = [9, 5, -2, -1, 5, 0, -5, -3, 2]
Output: [9, -2, 5, -1, 5, -5, 0, -3, 2]
Explanation: The positive numbers are [9, 5, 5, 0, 2] and the negative integers are [-2, -1, -5, -3]. Since, we need to start with the positive integer first and then negative integer and so on (by maintaining the relative order as well), hence we will take 9 from the positive set of elements and then -2 after that 5 and then -1 and so on.

Constraints:
1 ≤ arr.size() ≤ 106
-106 ≤ arr[i] ≤ 106
*/

void rearrange(vector<int> &arr) {
    
    //O(3n)
    /*vector<int>pos;
    vector<int>neg;
    
    for(int i=0; i<arr.size(); i++){
        if(arr[i]>=0)
            pos.push_back(arr[i]);
        else if(arr[i]<0)
            neg.push_back(arr[i]);
    }
    
    int k=0, i=0, j=0;
    while(i<pos.size() && j<neg.size()){
        arr[k++] = pos[i++];
        arr[k++] = neg[j++];
    }
    
    while(i<pos.size()){
        arr[k++] = pos[i++];
    }
    
    while(j<neg.size()){
        arr[k++] = neg[j++];
    }*/
    
    //O(2n)
    vector<int>pos;
    vector<int>neg;
    
    for(int i=0; i<arr.size(); i++){
        if(arr[i]>=0)
            pos.push_back(arr[i]);
        else if(arr[i]<0)
            neg.push_back(arr[i]);
    }
    
    if(pos.size() > neg.size()){
        for(int i=0; i<neg.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = neg.size() * 2;
        for(int i=neg.size(); i<pos.size(); i++){
            arr[index] = pos[i];
            index++;
        }
    }
    else{
        for(int i=0; i<pos.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = pos.size() * 2;
        for(int i=pos.size(); i<neg.size(); i++){
            arr[index] = neg[i];
            index++;
        }
    }
}
