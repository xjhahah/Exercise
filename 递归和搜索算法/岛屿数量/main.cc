class Solution {
 public:
  void DFS(vector<vector<char>>& v, int row, int col, int x, int y,
           vector<vector<int>>& book) {
    book[x][y] = 1;
    for (int i = 0; i < 4; i++) {
      int nx = x + pos[i][0];
      int ny = y + pos[i][1];
      if (nx >= row || nx < 0 || ny >= col || ny < 0) continue;
      if (v[nx][ny] == '1' && book[nx][ny] == 0) {
        DFS(v, row, col, nx, ny, book);
      }
    }
  }
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<int>> book;
    book.resize(row);
    for (int i = 0; i < row; ++i) {
      book[i].resize(col, 0);
    }
    int num = 0;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (grid[i][j] == '1' && book[i][j] == 0) {
          ++num;
          DFS(grid, row, col, i, j, book);
        }
      }
    }
    return num;
  }
};
