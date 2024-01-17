#include <iostream>
using namespace std;
void binary_sort(int arr[], int left, int right)
{
    int mid_num = arr[(left + right) / 2];
    int i = left, j = right;
    do
    {
        while(arr[i] < mid_num) i++;
        while(arr[j] > mid_num) j--;
        if(i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if(left < j) binary_sort(arr, left, j);
    if(i < right) binary_sort(arr, i, right);
}
// int main()
// {
//     int arr[] = {1, 0, 2, 9, 4, 5, 8, 6, 7};
//     binary_sort(arr, 0, 8);
//     for(auto x : arr) cout << x << " ";
//     return 0;
// }
