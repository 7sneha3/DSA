/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104
*/


    // for normal test cases or input
    // double calcPow(double x, int n){
    //     if(n == 0) return 1;
    
    //     return x * calcPow(x, n-1);
    // }

    // double myPow(double x, int n) {
    //     return calcPow(x, n);
    // }

    double calcPow(double x, long long n) {
        if (n == 0) return 1;

        double half = calcPow(x, n / 2);

        if (n % 2 == 0)
            return half * half;
        else
            return x * half * half;
    }

    double myPow(double x, int n) {
        long long N = n; // avoid overflow on -INT_MIN
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return calcPow(x, N);
    }
