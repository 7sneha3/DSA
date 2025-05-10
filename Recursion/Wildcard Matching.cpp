/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.
*/

bool isMatchHelper(string&s, int si, string&p, int pi){
        //base case
        if(si == s.size() && pi == p.size()) return true;
        if(si == s.size() && pi < p.size()){
            while(pi < p.size()){
                if(p[pi] != '*') return false;
                pi++;
            }
            return true;
        }

        //single char matching
        if(s[si] == p[pi] || '?' == p[pi]){
            return isMatchHelper(s, si+1, p, pi+1);
        }

        if(p[pi] == '*'){
            //treat * as empty
            bool caseA = isMatchHelper(s, si, p, pi+1);
            //consume *
            bool caseB = isMatchHelper(s, si+1, p, pi);
            return caseA || caseB;
        }
        //char doesn't match
        return false;
    }

    bool isMatch(string s, string p) {
        int si = 0;
        int pi = 0;
        return isMatchHelper(s, si, p, pi);
    }
