## Multiplication

```cpp
vector<int> mul(vector<int> a, int b)
{
	vector<int> c;
	int t = 0;

	for(int i = 0; i < a.size(); i ++ )
	{
		t = t + a[i] * b;
		c.push_back(t % 10);
		t = t / 10;
	}
	
	if(t) c.push_back(t);

	while(c.size() > 1 && c.back() == 0) c.pop_back();

	return c;
}
```

