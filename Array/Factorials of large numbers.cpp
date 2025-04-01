/*
Given an integer n, find its factorial. Return a list of integers denoting the digits that make up the factorial of n.

Examples:

Input: n = 5
Output: [1, 2, 0]
Explanation: 5! = 1*2*3*4*5 = 120
Input: n = 10
Output: [3, 6, 2, 8, 8, 0, 0]
Explanation: 10! = 1*2*3*4*5*6*7*8*9*10 = 3628800
Input: n = 1
Output: [1]
Explanation: 1! = 1 
Constraints:
1 ≤ n ≤ 103
*/

void multiply(vector<int>& arr, int& size, int multiplier){
    int carry=0;
    for(int i=0; i<size; i++){
        int res = multiplier * arr[i];
        res = res + carry;
        arr[i] = res % 10;
        carry = res/10;
    }
    
    while(carry > 0){
        arr[size] = carry % 10;
        size++;
        
        carry = carry/10;
    }
}

vector<int> factorial(int n) {
    vector<int> arr(10000, 0);
    
    arr[0] = 1;
    int size = 1;
    
    for(int multiplier = 2; multiplier<=n; multiplier++){
        multiply(arr, size, multiplier);
    }
    
    vector<int> result;
    for(int i=size-1; i>=0; i--){
        result.push_back(arr[i]);
    }
    return result;
}
