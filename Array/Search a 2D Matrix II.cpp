/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.


Example 1:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

Example 2:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
 
Constraints:
m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matrix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109
*/

//1st sol
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int rowIndex = 0; //start
    int colIndex = col-1; //end

    while(rowIndex < row && colIndex>=0){
        int element = matrix[rowIndex][colIndex];
        if(element == target)
            return 1;
        else if(element < target)
            rowIndex++;
        else
            colIndex--;
    }
    return 0;
}

/*
2nd sol:
bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int m = matrix.size();
    for (int i = 0; i < m; i++) {
        int n = matrix[i].size();
        int st = 0;
        int end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (matrix[i][mid] == target) {
                return true;
            } else if (matrix[i][mid] > target) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
    }
    return false;
}
*/
