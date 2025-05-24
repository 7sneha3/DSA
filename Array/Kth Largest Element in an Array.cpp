/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?
Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/

int findKthLargest(vector<int>& nums, int k) {
        //using sorting, tc= O(n^2)
        // for(int i=0; i<nums.size(); i++){
        //     for(int j=i+1; j<nums.size(); j++){
        //         if(nums[i] > nums[j])
        //             swap(nums[i], nums[j]);
        //     }
        // }
        // return nums[nums.size()-k];

        //using min heap, tc= O(n log k)
        // priority_queue<int, vector<int>, greater<int>> pq;
        // for(int i=0; i<nums.size(); i++){
        //     if(pq.size() < k){
        //         pq.push(nums[i]);
        //     }
        //     else if(nums[i] > pq.top()){
        //         pq.pop();
        //         pq.push(nums[i]);
        //     }
        // }
        // return pq.top();

        /*
        //using count sort - frequencies cnt krta
        //TC = (n+m)
        int minValue = INT_MAX;
        int maxValue = INT_MIN;

        for(int num:nums){ //this will create array of that size only, if ele are only from -10 to 10 then that much, not of -10^8 to 10^8 unnecessary
            minValue = min(minValue, num);
            maxValue = max(maxValue, num);
        }  

        vector<int>count(maxValue-minValue+1); //minValue se maxValue tak ke range ko cover karta hai
        for(int num:nums){
            //count array mein uske correct index pe uska count badha rahe hain.
            //num - minValue isliye kar rahe hain taaki index 0 se start ho.
            count[num-minValue]++; 
        }  

        int remain = k;
        for(int i=count.size()-1; i>=0; i--){
            //Har step pe remain mein se current element ke count ko minus kar rahe hain.
            //Jab remain <= 0 ho jaata hai, matlab hume kth largest mil gaya.
            //Index i ke saath +minValue isliye jodte hain kyunki actual value wapas nikaalni hai (original number, not index).
            remain -= count[i];
            if(remain <= 0){
                return i+minValue;
            }
        }
        return -1;
        */

        //Quick select
        //TC => O(n)avg case; O(n^2)worst case
        int n = nums.size();
        int L = 0;
        int R = n-1;

        int pivot_idx = 0;
        //kth largest pivot ele- nums[k-1]
        while(true){
            pivot_idx = partition_algo(nums, L, R);

            if(pivot_idx == k-1) break; //mil gya
            else if(pivot_idx > k-1) //jo hawae toh nhi pn tyapeksha chota bhetlae
                R = pivot_idx-1; 
            else
                L = pivot_idx+1;
        }
        return nums[pivot_idx]; //ele return not index
    }
    int partition_algo(vector<int>&nums, int L, int R){
        int P = nums[L]; //pivot
        int i = L+1; //the starting index
        int j = R;

        while(i<=j){
            if(nums[i] < P && nums[j] > P){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }

            if(nums[i] >= P){
                i++;
            }

            if(nums[j] <= P){
                j--;
            }
        }

        swap(nums[L], nums[j]); //at last swap with pivot and jth element so that pivot is at right index
        return j; //P is at jth index
    }
