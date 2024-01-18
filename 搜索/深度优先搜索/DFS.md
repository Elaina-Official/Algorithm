### 深度优先搜索(DFS)

- 深度优先搜索(DFS, Depth-First Search)是常用的搜索算法之一, 其通过从某个状态开始，不断搜寻可以到达的下一个状态直到无法继续转移状态, 然后回退到上一步的状态并转移到其他状态直至搜索结束或者寻找到最终的解. 
- 算法的关键点是状态回溯. 应用中注意剪枝与记忆. 

**经典例题**

[八皇后 Checker Challenge](https://www.luogu.com.cn/problem/P1219)

- 思路

  按照从上到下, 从左到右的原则判断该位置是否合法(所在行, 列, 对角线均无棋子), 若合法则占领, 更新占领状态, 否则搜索下一个合法位置. 

- 参考代码

  ```c++
  #include <iostream>
  using namespace std;
  
  constexpr int MAXN = 100;
  bool col[MAXN], maindiag[MAXN], antidiag[MAXN]; //标记所在列, 主对角线, 副对角线是否已经被占领
  int n, ans, res[MAXN]; //结果存储
  
  void dfs(int row)
  {
      if(row > n) //搜索的行数 > 图的边长, 即搜索结束
      {
          ans++;
          if(ans <= 3) //字典序最小的三次输出
          {
              for(int i = 1; i <= n; i++)
                  printf("%d ", res[i]);
              printf("\n");
          }
          return;
      }
      else
      {
          for(int i = 1; i <= n; i++)
          {
              if(!col[i] && !maindiag[i - row + n] && !antidiag[row + i]) //判断是否合法
              {
                  col[i] = maindiag[i - row + n] = antidiag[row + i] = true; //占领列, 主对角线, 副对角线
                  res[row] = i; //标记棋子行列位置便于输出
                  dfs(row + 1); //搜索下一行
                  col[i] = maindiag[i - row + n] = antidiag[row + i] = false; //状态回溯
              }
          }
      }
  }
  
  int main()
  {
      scanf("%d", &n);
      dfs(1); //从第一行开始依次搜索
      printf("%d\n", ans);
      return 0;
  }
  ```

[Lake Counting](https://www.luogu.com.cn/problem/P1596)

- 思路

  按照从上到下, 从左到右的原则判断该位置是否合法(坐标在给定的范围之内), 若该位置合法且值为```W```, 则对其位置进行搜索判断周围的八个位置是否联通, 更新答案.

- 参考代码

  ```c++
  #include <iostream>
  using namespace std;
  
  constexpr int MAXN = 100+5;
  char graph[MAXN][MAXN];
  int n, m, ans;
  int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1}; //存储x方向上周围八个位置的坐标
  int dy[] = {1, 1, 1, 0, -1, -1, -1, 0}; //存储y方向上周围八个位置的坐标
  
  void dfs(int x, int y)
  {
      graph[x][y] = '.'; //更改状态, 避免回溯
      for (int i = 0; i < 8; i++)
      {
          int nx = x + dx[i], ny = y + dy[i];
          if (0 <= nx && nx < n && 0 <= ny && ny < m && graph[nx][ny] == 'W') //判断周边位置是否合法
              dfs(nx, ny); //搜索周边位置
      }
  }
  
  int main()
  {
      ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
      cin >> n >> m;
      for (int i = 0; i < n; i++)
          for (int j = 0; j < m; j++)
              cin >> graph[i][j]; //读图
      for (int i = 0; i < m; i++)
          for (int j = 0; j < n; j++)
              if (graph[i][j] == 'W')
                  dfs(i, j), ans++; //依次搜索每个位置
      cout << ans << endl;
      return 0;
  }
  ```

  