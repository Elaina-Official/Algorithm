# 区间dp

区间 $dp$ 是一类和分治很像的 $dp$ ，其特点在于先在较小的区间上得到最优解，然后再利用小区间的最优解得到大区间上的最优解，并且往往涉及到区间合并的问题。

## 思想

通常来说，区间 $dp$ 的状态转移方程都类似于下式

$$
dp[l][r] = min(dp[l][r], dp[l][m] + dp[m+1][r] + cost(l, r))
$$

其中 $l, r, m$ 分别是当前区间的左端点、右端点、和中间的分割点；而 $cost(l, r)$ 则是每次区间合并需要的代价。

因此模板就很好写了

```cpp
init(); //初始化 dp 数组的值以及其他必要的初始化
for (int len = 2; len <= n; len++) //枚举区间长度len
    for (int l = 1, r = l + len - 1; r <= n; l++, r++) //枚举区间起点l与对应区间终点r
        for (int m = l; m < r; m++) //枚举分割点
            dp[l][r] = min(dp[l][r], dp[l][m] + dp[m+1][r] + cost(l, r); //状态转移方程
```

## 经典例题

[P1775 石子合并（弱化版）](https://www.luogu.com.cn/problem/P1775)

本题是非常经典的区间 $dp$ 题目，我们不妨用 $dp[i][j]$ 来表示合并第 $i$ 堆到第 $j$ 堆石子的最小代价。其每次合并操作所需要的代价就是区间 $[i, j]$ 之间所有石子的代价之和，很容易想到用**前缀和**来维护，因此每次合并的代价就是 $pre[r] - pre[l-1] $。

```cpp
int n, sum;
vector<int> v, pre;
vector<vector<int>> dp;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n; v.resize(n + 1), pre.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    dp.resize(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) sum += v[i], pre[i] = sum; //初始化前缀和数组
    for (int len = 2; len <= n; len++) //枚举区间长度len
    {
        for (int l = 1, r = l + len - 1; r <= n; l++, r++) //枚举区间起点l与对应区间终点r
        {
            dp[l][r] = 1e8; //因为后面要取min, 所以此处初始化为较大的值以保证min操作正确
            for (int m = l; m < r; m++) //枚举分割点
                dp[l][r] = min(dp[l][r], dp[l][m] + dp[m+1][r] + pre[r] - pre[l-1]); //状态转移方程
        }
    }
    cout << dp[1][n]; //最终求得的结果就是区间[1, n]上的最小值

    return 0;
}
```

