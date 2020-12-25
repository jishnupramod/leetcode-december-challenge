/*
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

 

Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]

Explanation:

 

Note:

The total number of elements of the given matrix will not exceed 10,000.
*/




class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> diagonal;
        int m = matrix.size(), n = m ? matrix[0].size() : 0, i = 0, j = 0;
        bool ru = true, ld = false;
        while (i<m and j<n) {
            diagonal.push_back(matrix[i][j]);
            if (ld and i<m-1 and j>0) {
                ++i;
                --j;
            } else if (ld and i==m-1) {
                ld = false;
                ru = true;
                ++j;
            } else if (ld and j==0) {
                ld = false;
                ru = true;
                ++i;
            } else if (ru and i>0 and j<n-1) {
                --i;
                ++j;
            } else if (ru and j==n-1) {
                ru = false;
                ld = true;
                ++i;
            } else if (ru and i==0) {
                ru = false;
                ld = true;
                ++j;
            }
        }
        return diagonal;
    }
};

