/*
Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 0

Constraints:
0 <= n <= 5 * 106
*/

int countPrimes(int n) {
    // Approach: Sieve of Eratosthenes
    vector<bool> prime(n+1, true); //initializing all nos as prime
    prime[0] = prime[1] = false; //0 and 1 are already not prime

    int cnt = 0; //to count the total no of prime nos
    for(int i=2; i<n; i++){
        if(prime[i]){ //first no will always be prime ie. 2, 3..
            cnt++;

            for(int j=2*i; j<n; j=j+i){ //j=2*i => will go for next multiple in case of 2: 4, in case of 3: 6; j=j+i will give the next multiple ex. 4+2=6, 6+3=9
                prime[j] = 0; //are not prime
            }
        }  
    }
    return cnt;
}
