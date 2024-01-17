## Addition

```cpp
vector<int> add(vector<int> a, vector<int> b)
{
	vector<int> c;
	int t = 0;
	
	for(int i = 0; i < a.size() || i < b.size(); i ++ )
	{
		if(i < a.size()) t = t + a[i];
		if(i < b.size()) t = t + b[i];
		
		c.push_back(t / 10);
		t = t % 10;
	}

	if(t) c.push_back(t);
	
	return c;
}
```