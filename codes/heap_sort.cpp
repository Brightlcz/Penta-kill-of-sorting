#include <iostream>
using namespace std;
void HeapAdjust(int a[], int length, int k)
{
    int tmp = a[k]; //k是其最后一个非叶子节点 i 是其的左孩子
    int i = 2 * k + 1;
    while (i < length)
    {
        if (i + 1 < length && a[i] > a[i + 1]) //选取最小的结点位置
            ++i;
        if (tmp < a[i]) //不用交换
            break;
        a[k] = a[i]; //交换值
        k = i;             //继续查找
        i = 2 * k + 1;
    }
    a[k] = tmp;
}

void HeapSort(int a[], int length)
{
    if (a == NULL || length <= 0)
        return;
    for (int i = length / 2 - 1; i >= 0; --i)
    {
        HeapAdjust(a, length, i); //从第二层开始建堆
    }

    for (int i = length - 1; i >= 0; --i)
    {
        std::swap(a[0], a[i]);
        HeapAdjust(a, i, 0); //从顶点开始建堆, 忽略最后一个
    }

    return;
}

int main(void)
{
    int a[] = {49, 38, 65, 97, 76, 13, 27, 4,12,36};
    int length = 10;
    HeapSort(a, length);
    for (int i = 0; i < length; ++i)
    {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}
