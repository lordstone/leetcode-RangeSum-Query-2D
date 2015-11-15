class NumMatrix {
public:

    vector<vector<int>> arr;
    vector<vector<int>> old;
    bool notvalid;
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.size() == 0) {notvalid = true;; return;}
        else notvalid = false;
        for(int i = 0; i < matrix.size() + 1; i ++) arr.push_back(vector<int> (matrix[0].size()+1,0));
        for(int i = 1; i <= matrix.size(); i ++){
            for(int j = 1; j <= matrix[0].size(); j ++){
                arr[i][j] = (matrix[i-1][j-1] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1]);
            }//end for j
        }//end for i
        old = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(!notvalid) return arr[row2+1][col2+1] - arr[row2+1][col1] - arr[row1][col2+1] + arr[row1][col1];
        else return -1;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
