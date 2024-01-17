## Division

```cpp
vector<int> div(vector<int> &a, int b, int &r)
{
    vector<int> c;
    r = 0;
    
    for (int i = a.size() - 1; i >= 0; i -- )
    {
        r = r * 10 + a[i];
        c.push_back(r / b);
        r %= b;
    }
    
    reverse(c.begin(), c.end());
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    
    return c;
}
```

