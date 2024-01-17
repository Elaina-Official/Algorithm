# dijkstra

```cpp
const int INF=0x3f;
const int maxn=105;
int n, m;
int dis[maxn];
int vis[maxn];
int g[maxn][maxn];

void dijkstra(){
	memset(vis, 0, sizeof(vis));//初始化是否加入集合K的标志 
	for(int i=1; i<=n; i++) dis[i]=g[1][i];//初始化从1开始的距离 
	vis[1]=1;//节点1加入集合K 
	dis[1]=0;
	
	int next;
	for(int i=2; i<=n; i++){//遍历寻找下一个节点，dis最小 
		int mini=INF;
		for(int j=1; j<=n; j++){
			if(!vis[j] && dis[j]<mini){//寻找最小的dis 
				mini=dis[j];
				next=j;
			}
		}
		vis[next]=1;//打上集合K的标记 
		for(int j=1; j<=n; j++){//看看经过next节点是否可以更新节点的最短距离 
			if(!vis[j] && dis[next]+g[next][j]<dis[j])
				dis[j]=dis[next]+g[next][j];
		}
	}
}
int main(){
	while(cin>>n>>m && n!=0 && m!=0){
		memset(g, 0x3f, sizeof(g));//每幅图初始化边 
		while(m--){//读入m条边
			int a, b, c;
			cin>>a>>b>>c;
			g[a][b]=g[b][a]=c; 
		}
		dijkstra();
		cout<<dis[n]<<endl;
	}
	return 0;
} 
```