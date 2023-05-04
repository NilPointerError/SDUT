如图是无序堆调整成大根堆的完整的过程，最后结果是数组升序排列。

![](../../pic/heapSort.drawio.png)

Test case:

```
8
49 38 65 97 76 13 27 49
```

Codes:

```cpp
#include <bits/stdc++.h>
using namespace std;
const int SIZE = 10;

void heapAdjust(int arr[], int n) {
    for (int i = 0; i <= (n - 1)/2; i++) {
        /* code */
        int lcIndex = 2*i+1;
        int rcIndex = 2*i+2;
        int maxIndex = i;
        //cout << lcIndex << n << endl;
        if(lcIndex < n && arr[maxIndex] < arr[lcIndex]) {
            maxIndex = lcIndex;
        }
        if(rcIndex < n && arr[maxIndex] < arr[rcIndex]) {
            maxIndex = rcIndex;
        }
        swap(arr[i], arr[maxIndex]);
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        /* code */
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapSort(int arr[], int n) {
    
    for (int i = n / 2 - 1; i >= 0; i--) {
        /* code */
        int lcIndex = 2*i+1;
        int rcIndex = 2*i+2;
        int maxIndex = i;
        if(lcIndex < n && arr[maxIndex] < arr[lcIndex]) {
            maxIndex = lcIndex;
        }
        if(rcIndex < n && arr[maxIndex] < arr[rcIndex]) {
            maxIndex = rcIndex;
        }
        swap(arr[i], arr[maxIndex]);
        //print(arr, n);
    }
    print(arr, n);
    // 从头到尾调整
    for (int i = n - 1; i > 0; i--) {
        /* code */
        // 堆头堆尾元素互换
        swap(arr[0], arr[i]);
        heapAdjust(arr, i);
        //swap(arr[0], arr[i]);
        print(arr, n);
    }
    // cout << arr[0] << endl;
    //print(arr, n);
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    int arr[SIZE];
    for (int i = 0; i < n; i++) {
        /* code */
        cin >> arr[i];
    }
    heapSort(arr, n);
    print(arr, n);
    return 0;
}
```

上面没有对交换后的节点进行再次判断是否满足大根堆的条件，需要递归判断一下。

Updated version:

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
void max_heapify(int arr[], int start, int end) {//O(logn)
    //建立父节点指标和子节点指标
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { //若子节点指标在范围内才做比较
        if (son + 1 <= end && arr[son] < arr[son + 1]) //先比较两个子节点大小，选择最大的
            son++;
        if (arr[dad] > arr[son]) //如果父节点大于子节点代表调整完毕，直接跳出函数
            return;
        else { //否则交换父子内容再继续子节点和孙节点比较
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(int arr[], int len) {
    //初始化，i从最后一个父节点开始调整
    for (int i = len / 2 - 1; i >= 0; i--)//O(n)
        max_heapify(arr, i, len - 1);
    //先将第一个元素和已经排好的元素前一位做交换，再从新调整(刚调整的元素之前的元素)，直到排序完毕
    for (int i = len - 1; i > 0; i--) {//O(nlogn)
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
        print(arr, len);
    }
}
```

#### Comments

堆排序是一种利用堆这种数据结构设计的一种排序算法。堆是一个近似完全二叉树的结构，满足子节点的键值总是小于（或者大于）它的父节点。

堆排序在算法题里面使用频率很高。常用于获取最大值或最小值的情况，比如优先级队列，作业调用等场景。

上述代码可知，堆排序的时间复杂度是由建堆和调整堆两个操作决定的，分别是O(n)和O(nlogn)，所以总的时间复杂度是O(n) + O(nlogn)=O(nlogn)。堆排序的平均时间复杂度、最好和最坏情况下都是O(nlogn)，空间复杂度为O(1)。它是不稳定的，因为交换堆顶和末尾元素可能会破坏相对顺序。

