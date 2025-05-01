/*
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

 

Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"
 

Constraints:

1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.
*/
/*
string addRE(string num1, int p1, string num2, int p2, int carry = 0){
    //base case
    if(p1<0 && p2<0){
        if(carry!=0)
            return string(1, carry+'0');  //here 1 indicates size of that string
        return "";
    }
    //ek case solve
    int n1 = (p1>=0 ? num1[p1] : '0') - '0';
    int n2 = (p2>=0 ? num2[p2] : '0') - '0';
    int csum = n1 + n2 + carry;
    int digit = csum % 10;
    carry = csum/10;
    string ans = "";
    ans.push_back(digit+'0');

    //RE
    ans += addRE(num1, p1-1, num2, p2-1, carry);
    return ans;
}

string addStrings(string num1, string num2) {
    string ans = addRE(num1, num1.size()-1, num2, num2.size()-1);
    reverse(ans.begin(), ans.end());
    return ans;
}
*/

void addRE(string&num1, int p1, string&num2, int p2, int carry, string&ans){
    //base case
    if(p1<0 && p2<0){
        if(carry!=0)
            ans.push_back(carry+'0');
        return ;
    }

    //ek case solve
    int n1 = (p1>=0 ? num1[p1] : '0') - '0';
    int n2 = (p2>=0 ? num2[p2] : '0') - '0';
    int csum = n1 + n2 + carry;
    int digit = csum % 10;
    carry = csum/10;
    ans.push_back(digit+'0');

    //RE
    addRE(num1, p1-1, num2, p2-1, carry, ans);
}

string addStrings(string num1, string num2) {
    string ans = ""; 
    addRE(num1, num1.size()-1, num2, num2.size()-1, 0, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}
