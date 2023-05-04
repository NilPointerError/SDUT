冒泡排序是一种交换排序，它的基本思想是通过重复地比较相邻的两个元素，如果它们的顺序错误就交换它们，使得较小的元素逐渐上浮，较大的元素逐渐下沉。

冒泡排序的优点是简单易懂，而且是稳定的，即相等的元素不会改变原来的相对顺序。冒泡排序的缺点是时间复杂度较高，无论什么数据进去都是 O (n²) 的时间复杂度。而且冒泡排序需要进行多次的交换操作，比较耗时。

冒泡排序可以进行一些优化改进，比如设置一个标志位来记录是否发生了交换，如果没有交换就说明已经有序，可以提前结束循环。或者记录最后发生交换的位置，这个位置之后的数据显然已经有序了，可以缩小循环的范围。

Codes:

```cpp
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        /* code */
        for (int j = 0; j < n - i - 1; j++) {
            /* code */
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
```
优化版：

```cpp

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        /* code */
        bool flag = false;
        for (int j = 0; j < n - i - 1; j++) {
            /* code */
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if(!flag)
            break;
    }
}
```

