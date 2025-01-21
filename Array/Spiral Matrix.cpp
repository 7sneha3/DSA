/*
Given an m x n matrix, return all elements of the matrix in spiral order.
Example 1:
1 2 3
4 5 6
7 8 9
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int row = matrix.size();
        int col = matrix[0].size(); //calculated col size using one of row index

        int count = 0;
        int total = row*col; //total nos in matrix

        //index initialization
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row-1;
        int endingCol = col-1;

        while(count<total){
            //print starting row
            for(int index=startingCol; count<total && index<=endingCol; index++){
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;

            //print ending col
            for(int index=startingRow; count<total && index<=endingRow; index++){
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;

            //print ending row
            for(int index=endingCol; count<total && index>=startingCol; index--){
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;

            //print starting col
            for(int index=endingRow; count<total && index>=startingRow; index--){
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
