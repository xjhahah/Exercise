class Solution {
 public:
  int minimumTotal(vector<vector<int>> &triangle) {
    if (triangle.empty()) {
      return 0;
    }
    vector<vector<int>> minPath(triangle);

    int row = triangle.size();

    for (int i = row - 2; i >= 0; i--) {
      for (int j = 0; j <= i; ++j) {
        minPath[i][j] =
            min(minPath[i + 1][j], minPath[i + 1][j + 1]) + triangle[i][j];
      }
    }
    return minPath[0][0];
  }
};
