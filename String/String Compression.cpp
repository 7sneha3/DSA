class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int ansIndex=0; //index to create the new array replacing old

        while(i<chars.size()){
            int j=i+1;
            while(j<chars.size() && chars[i]==chars[j]){
                //chars are same, then go to next char
                j++;
            }
            //came out of this loop; traversed fully, got diff char

            //now, put that char into array
            chars[ansIndex++] = chars[i];

            //this will count the total no of same chars, becuz j is where the same char finishes and i is the starting of that same char
            int count = j-i;

            //there's no need to store one char which is only one in array
            //for placing count, more than 1 and single digit
            if(count>1){
                //single digit inserting
                string cnt = to_string(count); //count converted to string for easy in traversing
                for(char ch:cnt){
                    chars[ansIndex++] = ch; //placed the count in array
                }
            }
            //moving to next char; j is the last index where we encounter diff char
            i = j;
        }
        return ansIndex; //returning the count of all elements in array
    }
};

/*
Example 1:
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

Example 2:
Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character

Example 3:
Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
 
Constraints:
1 <= chars.length <= 2000
chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.
*/
