//reverse a string using recursion

#include<iostream>
using namespace std;

void reverse(string &s, int i){
    //base condition
    if(i<0) return ;

    //processing
    cout<<s[i]<<" ";

    //recursive cl
    reverse(s, i-1);
}

int main(){
    string s = "helloji";
    reverse(s, s.size());
}
