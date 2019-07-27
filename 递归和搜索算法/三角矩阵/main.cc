class Solution {
 public:
  int minimumTotal(vector<vector<int>> &triangle) {
    if (triangle.empty()) {
      return 0;
    }
    vector<vector<int>> minPath(triangle);

    for (int i = 1; i < triangle.size(); ++i) {
      minPath[i][0] = minPath[i - 1][0] + triangle[i][0];
      minPath[i][i] = minPath[i - 1][i - 1] + triangle[i][i];
    }

    for (int i = 2; i < triangle.size(); ++i) {
      for (int j = 1; j < i; ++j) {
        minPath[i][j] =
            min(minPath[i - 1][j], minPath[i - 1][j - 1]) + triangle[i][j];
      }
    }

    int row = triangle.size();
    int minRet = minPath[row - 1][0];
    for (int i = 1; i < row; ++i) {
      minRet = min(minPath[row - 1][i], minRet);
    }
    return minRet;
  }
};
