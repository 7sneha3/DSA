/*
Longest Consecutive Sequence
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:
Input: nums = [1,0,1,2]
Output: 3

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

int longestConsecutive(vector<int>& nums) {
        /*
        //wont handle negative values
        
        vector<int> isPre(100006, 0);
        for(int i=0; i<nums.size(); i++){
            if (nums[i] >= 0 && nums[i] < 100006) 
              isPre[nums[i]] = 1;
        }

        int cnt=0, ans=0;
        for(int i=0; i<100006; i++){
            if(isPre[i])
                cnt++;
            else
                cnt = 0;
            ans = max(ans, cnt);
        }
        return ans;
        */

        /*
        if(nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int lastSmaller = INT_MIN;
        int cnt = 0;
        int longest = 1;

        for(int i=0; i<n; i++){
            if(nums[i]-1 == lastSmaller){
                cnt += 1;
                lastSmaller = nums[i];
            }
            else if(lastSmaller != nums[i]){
                cnt = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest, cnt);
        }
        return longest;
        */

        int n = nums.size();
        if(n==0) return 0;
        int longest = 1;

        unordered_set<int> st;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }

        for(auto it: st){
            if(st.find(it-1) == st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x = x+1;
                    cnt += 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
