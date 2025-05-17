/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/

int minDistFind(string& word1, string& word2, int i, int j){
        //base case
        // word1 string finished, so return the remaining word2 string, that much ops will be done
        if (i >= word1.length()) return word2.length() - j;
        // word2 string finished, so return the remaining word1 string, that much ops will be done
        if (j >= word2.length()) return word1.length() - i;

        //ek case solve
        int ans = 0;
        if(word1[i] == word2[j]){
            ans = 0 + minDistFind(word1, word2, i+1, j+1);
        }
        else{
            //insert
            int op1 = 1 + minDistFind(word1, word2, i, j+1);
            //remove
            int op2 = 1 + minDistFind(word1, word2, i+1, j);
            //replace
            int op3 = 1 + minDistFind(word1, word2, i+1, j+1);
            ans = min({op1, op2, op3});
        }
        return ans;
    }

    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        int ans = minDistFind(word1, word2, i, j);
        return ans;
    }

//TC => O(3^max(m, n))
//SC = > O(m+n)
// m = word1.length()
// n = word2.length()
