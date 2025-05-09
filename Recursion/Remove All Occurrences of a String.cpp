/*
Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.

 

Example 1:

Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".
Example 2:

Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".
 

Constraints:

1 <= s.length <= 1000
1 <= part.length <= 1000
s​​​​​​ and part consists of lowercase English letters.
*/

void removeOCCRE(string &s, string &part){
    //re
    int found = s.find(part);
    if(found != string::npos){
        //part string has been located
        //pls remove it
        string left_part = s.substr(0, found);
        string right_part = s.substr(found+part.size(), s.size());
        s = left_part + right_part;
        removeOCCRE(s, part);
    }
    else{
        //base case
        //all the occurrences has beed removed from s
        return ;
    }
}
string removeOccurrences(string s, string part) {
    removeOCCRE(s, part);
    return s;
    /* without re
    while(s.length()!=0 && s.find(part) < s.length()){
        s.erase(s.find(part), part.length());
    }
    return s;
  */
}
