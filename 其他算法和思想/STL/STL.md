# STL

- STL是 `C++` 中的模板库, 即Standard Template Library, 其中已经编写好了许多数据结构和算法便于使用.

## 常用的STL对象

- 类

  | 类型名         | 中文释义 | 声明                          | 常见作用     |
  | -------------- | -------- | ------------------------------------ | ------------ |
  | pair           | 二元组   | `pair<typename1, typename2> pr;` | 绑定两个类型 |
  | string         | 字符串   | `string s;`                      | 字符串操作   |
  | vector         | 动态数组 | `vector<typename> v;`           | 替代传统数组 |
  | queue          | 队列     | `queue<typename> q;`             | BFS          |
  | stack          | 栈       | `stack<typename> s;`                 | DFS          |
  | deque          | 双向队列 | `dueue<typename> a;` |              |
  | set            | 集合     | `set<typename> s;` |              |
  | multiset       | 可重集合 | `multiset<typename> ms;` |              |
  | priority_queue | 优先队列 | `priority_queue<typename> pq;` |              |
  | map            | 映射     | `map<typename1, typename2> m;` |              |
  | multimap       | 可重映射 | `multimap<typename1, typename2> mm;` |              |
  | unordered_map  | 无序映射 | `unordered_map<typename1, typename2> um;` |              |

- 函数

  | 函数名           | 使用案例                                                     | 作用                                                         |
  | ---------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | sort             | `vector<int> v;`<br>`sort(v.begin(), v.end());`<br>`sort(v.begin(), v.end(), cmp);` | 对顺序容器排序, 若参数含有cmp函数则按照cmp函数定义的规则进行排序, 默认升序 |
  | binary_search    | `vector<int> v;`<br/>`int num `<br> `bool flag = binary_search(v.begin(), v.end(), num);` | 测试已排序范围中是否有等于指定值的元素                       |
  | lower_bound      | `vector<int> v;`<br/>`int num `<br/> `auto p = lower_bound(v.begin(), v.end(), num);` | 在已排序范围中查找值大于或等于指定值的首个元素的位置         |
  | upper_bound      | `vector<int> v;`<br/>`int num `<br/> `auto p = upper_bound(v.begin(), v.end(), num);` | 在已排序范围中查找值大于指定值的首个元素的位置               |
  | unique           | `vector<int> v;`<br/>`vector<int> v2 = unique(v.begin(), v.end());` | 移除指定范围中彼此相邻的重复元素                             |
  | nth_element      | `vector<int> v;`<br/>`int num `<br/>`nth_element(v.begin(), v.end(), num);` | 正确地找到范围中序列的第 n 个元素, 并使位于此元素之前的所有元素小于或等于此元素, 位于此元素之后的所有元素大于或等于此元素 |
  | prev_premutation |                                                              |                                                              |
  | next_premutation |                                                              |                                                              |

  
