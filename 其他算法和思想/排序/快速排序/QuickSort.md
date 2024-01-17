# quick_sort

- 思想

  对于给定的数组```arr[]```，通过选定一个中间位置```pos = (left + right) / 2```，每次排序时将数组左端到中间位置```arr[left]~arr[pos]```和中间位置到右端```arr[pos]~arr[right]```分成两部分递归排序，使得中间位置以左的部分均小于等于中间位置值，递归完成后排序即结束。

## 无返回值函数递归

```
void binary_sort(int arr[], int left, int right)//传入参数:数组，左端指针，右端指针
{
    int mid_val = arr[(left + right) / 2];//选取中间位置的值mid_val
    int i = left, j = right;//令i,j分别为从左端右侧和从右端向左侧遍历的指针
    do
    {
        while(arr[i] < mid_val) i++;//只要中间位置左边的值小于中间位置的值就使指针i自增(即符合升序序列)，直到找到某个在中间位置左侧的位置其数值大于mid_val(即不符合升序序列)
        while(arr[j] > mid_val) j--;//只要中间位置右边的值大于中间位置的值就使指针j自减(即符合升序序列)，直到找到某个在中间位置右侧的位置其数值小于mid_val(即不符合升序序列)
        if(i <= j)//如果找到中间位置左侧和右侧的两个数不满足升序序列，那么就将他们交换并且重复上述遍历过程
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j);//如果两指针相遇，那么停止遍历，并进入子序列的遍历
    if(left < j) binary_sort(arr, left, j);//对左侧子序列进行排序
    if(i < right) binary_sort(arr, i, right);//对右侧子序列进行排序
}
```

