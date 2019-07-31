class Solution {
public:
    int nextPosition[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
    void DFS(vector<vector<int>>& image, int row, int col, vector<vector<int>>& book,\
             int sr, int sc, int oldColor, int newColor){
        //修改颜色
        image[sr][sc]=newColor;
        for(int i=0;i<4;++i){
            int nx=sr+nextPosition[i][0];
            int ny=sc+nextPosition[i][1];
            
            //判断是否越界
            if(nx>=row || nx<0 || ny>=col || ny<0){
                continue;
            }
            if(image[nx][ny] == oldColor && book[nx][ny]==0){
                DFS(image, row, col, book, nx, ny, oldColor, newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.empty()){
            return image;
        }
        int row=image.size();
        int col=image[0].size();
        vector<vector<int>> book;
        book.resize(row);
        for (int i = 0; i < row; ++i)
        {
            book[i].resize(col, 0);
        }
        int oldColor=image[sr][sc];
        DFS(image, row, col, book, sr, sc, oldColor, newColor);
        return image;
    }
};
