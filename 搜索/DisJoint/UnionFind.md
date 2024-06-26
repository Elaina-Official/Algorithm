# UnionFind

```cpp
//并查集实现
class UnionFindSet{
    vector<int> F;//并查集容器
    vector<int> rank;//秩优化(如果两个都有很多元素的根节点相遇，将根节点选为元素较少的那一个，可以节省时间)
    int n;
 
public:
    //并查集初始化
    UnionFindSet(int _n){
        n = _n;
        F.resize(n);
        rank.resize(n, 1);
        for(int i = 0; i < n; i++){
            F[i] = i;
        }
    }
 
    //并查集查询操作
    int find(int x){
        return x == F[x] ? x : F[x] = find(F[x]);//查询优化。找到x的根节点
    }
 
    //并查集合并操作
    bool merge(int x, int y){
        int fx = find(x), fy = find(y);
        if(fx == fy) return false;//两个节点连在同一个根节点上则直接返回 不再合并
 
    //因为是将节点数少的连接到节点数多的节点上，当fx下面的节点数小于fy下面的节点数时，交换fx和fy
    //即两个根节点相遇时，将新的根节点选为节点数较多的那一个，尽量减少find(x)的次数
        if(rank[fx] < rank[fy])//合并优化
            swap(fx, fy);
 
        F[fy] = fx;//将fy连到fx上(将节点数少的连接到节点数多的上面)
        rank[fx] += rank[fy];//将fy连到fx后 fx下面的节点数目要更新
        return true;
    }
};
```

