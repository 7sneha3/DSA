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

//Another logic
void reverse(string &s, int st, int e){
    if(st>=e) return;
    
    swap(s[st], s[e]);
    // cout<<s; //3times output karan swap kela ki lagech print hotae
    // cout<<s[st]<<" "; //wrong output

    reverse(s, st+1, e-1);   
    // cout<<s; //3times output karan swap kela ki lagech print hotae   
}

int main(){
    string s = "helloji";
    reverse(s, 0, s.size()-1);
    cout<<s;
}
