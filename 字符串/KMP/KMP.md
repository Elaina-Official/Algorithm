# KMP算法

- KMP算法是一种字符串匹配算法，它的时间复杂度是线性的，远远优于传统字符串匹配算法。

## 算法模板

对于KMP算法的主要部分，我们采取主串指针不回退的形式来匹配。

```
vector<int> KMP(const string& txt, const string& pat)
{
    vector<int> next = getNext(pat); //获取next数组
    vector<int> res;
    int txt_ptr = 0, pat_ptr = 0; //主串指针与模式串指针
    while (txt_ptr < txt.size()) 
    {
        if (txt[txt_ptr] == pat[pat_ptr]) //如果当前字符匹配，那么主串指针与模式串指针均后移一位
            txt_ptr++, pat_ptr++;
        else if (pat_ptr) //如果当前字符不匹配，那么就根据next数组跳过已经匹配过的数个字符
            pat_ptr = next[pat_ptr - 1]; 
        else //如果模式串第一个字符都不匹配，那么直接从主串下一个字符开始匹配
            txt_ptr++;
        if (pat_ptr == pat.size()) //如果模式串在主串中匹配成功，那么记录
        {
            res.push_back(txt_ptr - pat_ptr);
            pat_ptr = next[pat_ptr - 1];
        }
    }
    return res;
}
```

对于next数组建立的部分，我们采取记忆化与递推。

```
vector<int> getNext(const string& pat)
{
    vector<int> next(pat.size(), 0);
    for (int i = 1; i < pat.size(); i++) 
    {
        int j = next[i - 1]; //j是当前位置i的最长相等前后缀长度，从前一个位置的最长相等前后缀长度开始
        while (j > 0 && pat[i] != pat[j]) //确保还有前缀可以尝试，且当前位置字符与前缀下一个字符不相等
            j = next[j - 1]; //回退j为前一个位置的最长相等前后缀，继续尝试，直到找到相等的字符
        if (pat[i] == pat[j])
            next[i] = j + 1; //更新当前位置最长相等前后缀为前一个位置的最长相等前后缀长度+1
        else
            next[i] = 0; //如果没有找到相等的字符，那么将next置0，即当前位置没有相等的前后缀
    }
    return next;
}
```

