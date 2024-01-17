# kruskal

```cpp
struct node{	//存储边及边权
	int u,v,dis;
}e[M];	
bool cmp(node x,node y){	//sort的比较函数
	return x.dis < y.dis;
}
int father[N];	//存放每个节点的父亲节点的father数组
int findfather(int v){	//查找节点的父亲节点
	if(father[v] == v) 	return v;
	else{
		int F = findfather(father[v]);
		father[v] = F;
		return F;
	}
}
int Kruskal(int n,int m){
	int ans = 0,num_edge = 0;
	//ans为所求最小生成树的边权之和，num_edge为当前生成树的边数
	for(int i = 0;i< n;i++){		//father[]初始化，注意节点的范围（以0 - n为例）
		father[i] = i;
	}
	sort(e,e+m,cmp);	//对边的权值按照从小到大排序
	for(int i = 0;i< m;i++){
		int fu = findfather(e[i].u);
		int fv = findfather(e[i].v);
		if(fu != fv){	//如果两个节点的父亲节点不同，则将次边加入最小生成树
			ans+= e]i].dis;	//加上边权
			father[fu] = fv;
			num_edge++;
			if(num_edge == n-1)	//如果最小生成树的边数目达到节点数减一，就退出
				break;
		}
	}
	return ans;
}

```

