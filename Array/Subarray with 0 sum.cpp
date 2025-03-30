/*
Given an array of integers, arr[]. Find if there is a subarray (of size at least one) with 0 sum. Return true/false depending upon whether there is a subarray present with 0-sum or not. 
Examples:
Input: arr[] = [4, 2, -3, 1, 6]
Output: true
Explanation: 2, -3, 1 is the subarray with a sum of 0.

Input: arr = [4, 2, 0, 1, 6]
Output: true
Explanation: 0 is one of the element in the array so there exist a subarray with sum 0.

Input: arr = [1, 2, -1]
Output: false

Constraints:
1 <= arr.size <= 104
-105 <= arr[i] <= 105
*/

bool subArrayExists(vector<int>& arr) {
    /*
    vector<int> Pf;
    for(int i=0; i<arr.size(); i++){
        int sum = 0;
        for(int j=0; j<=i; j++){
            sum += arr[j];
        }
        Pf.push_back(sum);
    }
    
    for(int i=0; i<Pf.size(); i++){
        for(int j=i+1; j<Pf.size(); j++){
            if(Pf[i] == Pf[j] || Pf[i] == 0)
                return true;
        }
    }
    return false;
    */
    
    /*
    vector<int> Pf;
    int sum = 0;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
        
        if(sum==0) return true;
        
        Pf.push_back(sum);
        for(int j=0; j<Pf.size()-1; j++){
            if(Pf[j]==sum) return true;
        }
    }
    return false;
    */
    
    unordered_set<int> Pf;
    int sum=0;
    
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
        
        if(sum==0 || Pf.find(sum) != Pf.end()) return true;
        Pf.insert(sum);
    }
    return false;
}
