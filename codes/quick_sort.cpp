//https://blog.csdn.net/morewindows/article/details/6684558 5.31.2018
#include <iostream>
using namespace std;
//快速排序
void quick_sort(int s[], int l, int r)
{
    if (l < r) //递归结束的条件 不能少啊
    {
        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
                j--;
            if (i < j)
                s[i++] = s[j];

            while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                i++;
            if (i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // 递归调用
        quick_sort(s, i + 1, r);
    }
}
int main()
{
    int arr[5] = {5, 2, 4, 3, 8};
    quick_sort(arr, 0, 4);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
