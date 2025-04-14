/*
Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in sorted order without using any extra space. Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements.

Examples: 

Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
Output:
2 2 3 4
7 10
Explanation: After merging the two non-decreasing arrays, we get, 2 2 3 4 7 10
Input: a[] = [1, 5, 9, 10, 15, 20], b[] = [2, 3, 8, 13]
Output:
1 2 3 5 8 9
10 13 15 20
Explanation: After merging two sorted arrays we get 1 2 3 5 8 9 10 13 15 20.
Input: a[] = [0, 1], b[] = [2, 3]
Output:
0 1
2 3
Explanation: After merging two sorted arrays we get 0 1 2 3.
Constraints:
1 <= a.size(), b.size() <= 105
0 <= a[i], b[i] <= 107
*/

//brute - uses extra space as resizing vector is also using extra space so this wont be optimal
int n = a.size();
int m = b.size();

for (int i = 0; i < m; i++) {
    a.push_back(b[i]);
}
sort(a.begin(), a.end());

for (int i = 0; i < n; i++) {
    a[i] = a[i];
}

for (int i = 0; i < m; i++) {
    b[i] = a[n + i];
}

// Optionally, a ko resize bhi kar sakte ho to original size tak
a.resize(n);





//another brute can be using third array, storing or by comparing elements then putting them again into arr1 an arr2




//optimal using gap (shell like working)
void swapIfGreater(vector<int>& a, vector<int>& b, int ind1, int ind2){
    if(a[ind1] > b[ind2])
        swap(a[ind1], b[ind2]);
}

void mergeArrays(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();
    
    int len = (n+m);
    int gap = (len/2) + (len%2);
    while(gap > 0){
        int left = 0;
        int right = left + gap;
        while(right < len){
            //a and b
            if(left < n && right >= n){
                swapIfGreater(a, b, left, right-n);
            }
            //b and b
            else if(left >= n){
                swapIfGreater(b, b, left-n, right-n);
            }
            //a and a
            else{
                swapIfGreater(a, a, left, right);
            }
            left++, right++;
        }
        if(gap == 1) break;
        gap = (gap/2) + (gap%2);
    }
}

