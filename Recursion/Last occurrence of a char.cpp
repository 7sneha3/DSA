/*
Finding out the last occurrence of a char in a given string
*/
#include<iostream>
using namespace std;

//left to right
// void cl(string &s, char x, int i, int &ans){
//     if(i == s.length()) return;

//     if(s[i] == x) ans = i;
    
//     cl(s, x, i+1, ans);
// }

//right to left
void cl(string &s, char x, int i, int &ans){
    if(i < 0) return;

    if(s[i] == x){
        ans = i;
        return;
    } 
    
    cl(s, x, i-1, ans);
}

int main(){
    string s = "abcddefg";
    char x = 'd';
    int ans = -1;
    cl(s, x, s.size()-1, ans);

    // int ind = -1;

    // for(int i=0; i<s.length(); i++){
    //     if(s[i] == x) ind = i;
    // }
    cout<<ans;

}
