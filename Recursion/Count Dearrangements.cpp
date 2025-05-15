#include<iostream>
#include<vector>
using namespace std;
// there are elements in array starting from 1, 
// their places should be changed in such a way that they dont occur again on their old place
// passing value in n means the total elements in the array
int solve(int n){
    if(n==1) return 0;
    if(n==2) return 1;

    int ans = (n-1) * (solve(n-2) + solve(n-1));
    return ans;
}

int main(){
    int n = 3;
    cout<<solve(n);
}

//TC => O(2^n)
//SC => O(n)
