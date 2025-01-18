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
