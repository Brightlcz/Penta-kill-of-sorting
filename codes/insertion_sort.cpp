//参考自https://blog.csdn.net/morewindows/article/details/6665714
#include <iostream>
using namespace std;
void Insertsort(int a[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)

        if (a[i] < a[i - 1])
        {
            int temp = a[i];

            for (j = i - 1; j >= 0 && a[j] > temp; j--)
            {
                a[j + 1] = a[j];
            }

            a[j + 1] = temp;
        }
}

int main()
{
    int arr[5] = {5, 2, 4, 3, 0};
    Insertsort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
