## Subtraction

```cpp
// 判断两个数的大小
bool cmp(vector<int> a, vector<int> b)
{
	if(a.size() != b.size()) return a.size() > b.size();
	for(int i = a.size() - 1; i >= 0; i ++ )
		if(a[i] != b[i]) return a[i] > b[i];

	return true;
}

// 两数相减
vector<int> sub(vector<int> a, vector<int> b)
{
	vector<int> c;
	int t = 0;

	for(int i = 0; i < a.size(); i ++ )
	{
		t = a[i] - t;
		if(i < b.size()) t = t - b[i];
		c.push_back(t / 10);
		if(t < 0) t = 1;
		else t = 0;
	}

	// 去除高位 0 
	while(c.size() > 1 && c.back() == 0) c.pop_back();
	return c;
}
```

