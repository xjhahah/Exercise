class Solution {
 public:
  int pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  void DFS(vector<vector<char>>& v, int row, int col, int x, int y) {
    v[x][y] = '#';
    for (int i = 0; i < 4; ++i) {
      int nx = x + pos[i][0];
      int ny = y + pos[i][1];
      if (nx >= row || nx < 0 || ny >= col || ny < 0) continue;
      if (v[nx][ny] == 'O') {
        DFS(v, row, col, nx, ny);
      }
    }
  }
  void solve(vector<vector<char>>& v) {
    if (v.empty()) return;
    int row = v.size();
    int col = v[0].size();

	//第一行和最后一行
    for (int i = 0; i < col; ++i) {
      if (v[0][i] == 'O') {
        DFS(v, row, col, 0, i);
      }
      if (v[row - 1][i] == 'O') {
        DFS(v, row, col, row - 1, i);
      }
    }
	//第一列和最后一列
    for (int i = 0; i < row; ++i) {
      if (v[i][0] == 'O') {
        DFS(v, row, col, i, 0);
      }
      if (v[i][col - 1] == 'O') {
        DFS(v, row, col, i, col - 1);
      }
    }
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (v[i][j] == '#')
          v[i][j] = 'O';
        else if (v[i][j] == 'O')
          v[i][j] = 'X';
      }
    }
  }
};
