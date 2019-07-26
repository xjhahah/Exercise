class Solution {
 public:
  int minPathSum(vector<vector<int>> &obstacleGrid) {
    if (obstacleGrid.empty()) {
      return 0;
    }

    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();

    vector<vector<int>> pathNum(row, vector<int>(col, 0));

	pathNum[0][0] = obstacleGrid[0][0];

	//先处理边界情况
    for (int i = 1; i < row; ++i) {
          pathNum[i][0] = obstacleGrid[i][0] + pathNum[i - 1][0];
    }
    for (int i = 1; i < col; ++i) {
      pathNum[0][i] = obstacleGrid[0][i] + pathNum[0][i-1];
    }

	//在处理其他情况  
	//F(i,j) = min{F(i-1,j) , F(i,j-1)} + (i,j)
	for (int i = 1; i < row; i++) {
      for (int j = 1; j < col; ++j) {
            pathNum[i][j] =
            obstacleGrid[i][j] + min(pathNum[i - 1][j], pathNum[i][j - 1]);
	  }
	}
        return pathNum[row - 1][col - 1];
  }
};
