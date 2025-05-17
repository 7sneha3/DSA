/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
*/

int maximalSquareFind(vector<vector<char>>& matrix, int i, int j, int row, int col, int &maxi){
        //base case
        //out of bound
        if(i >= row || j >= col) return 0;

        //explore all three directions
        int right = maximalSquareFind(matrix, i, j+1, row, col, maxi);
        int diagonal = maximalSquareFind(matrix, i+1, j+1, row, col, maxi);
        int down = maximalSquareFind(matrix, i+1, j, row, col, maxi);

        //check if we can build square from the current position
        if(matrix[i][j] == '1'){
            int ans = 1 + min({right, diagonal, down});
            //this is imp
            maxi = max(ans, maxi);
            return ans;
        }
        else{
            //agar 0 pe khade ho toh ans bhi 0 hoga
            return 0;
        }
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int i = 0, j = 0;
        int row = matrix.size();
        int col = matrix[0].size();

        int maxi = 0;
        int ans = maximalSquareFind(matrix, i, j, row, col, maxi);
        return maxi * maxi;
    }

//TC => O(3^(m.n))
//SC => O(m.n)

// m = number of rows
// n = number of columns
