#if 0
输入描述:
输入包含多组数据。每组数据包含一个10*10，由“#”和“.”组成的迷宫。其中“#”代表墙；“.”代表通路。入口在第一行第二列；出口在最后一行第九列。从任意一个“.”点都能一步走到上下左右四个方向的“.”点。

输出描述:
对应每组数据，输出从入口到出口最短需要几步。
示例1
输入
#.########
#........#
#........#
#........#
#........#
#........#
#........#
#........#
#........#
########.#

输出 16
#endif

#include <iostream>
#include <queue>

#define N 10

struct point
{
  int _x;
  int _y;
  int _step;
};

bool mark[N][N];
char maze[N][N];

std::queue<point> Q;
int flag[4][2] = {-1,0,1,0,0,-1,0,1};

int BFS(int a,int b)
{
  while(!Q.empty()){
    point p=Q.front();
    Q.pop();
    int x=p._x;
    int y=p._y;
    for(int i=0;i < 4; ++i){
      int gx = flag[1][0] + x;
      int gy = flag[i][1] + y;
      if(gx<0||gx>=a||gy<0||gy>=b){ //判断是否合法
        continue;
      }
      if(mark[gx][gy] == true) continue; //是否已经遍历过
      if(maze[gx][gy] == '#') continue; //是否为墙
      point newP;  //扩展状态
      newP._x = gx;
      newP._y = gy;
      newP._step = p._step+1;
      mark[gx][gy] = true;
      Q.push(newP);
      if(gx==a-1 && gy == b-2)
        return newP._step; //找到出口
    }
  }
}
int main()
{
  while(std::cin>>maze[0][0]){
    mark[0][0]=false;
    for(int i=0;i < N;++i){
      for(int j=0;j < N;++j){
        if(i==0 && j==0 )
          continue;
        else{
          std::cin>>  maze[i][j];
          mark[i][j]=false;
        }
      }
    }
    point tmp;
    tmp._x=0;
    tmp._y=1;
    tmp._step=0;
    mark[0][1] = true;
    while(!Q.empty())
    {
      Q.pop();
    }
    int ret = BFS(N,N);
    std::cout << ret << std::endl;
  }
  return 0;
}
