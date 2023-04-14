排序过程如图所示：

<img src="..\..\pic\binarySearch.jpg" style="zoom: 67%;" />

循环实现的算法如下所示：

```c++
#include <bits/stdc++.h>
using namespace std;

/*

	Binary Search: Time complexity is O(log n). It is suitable for large and sorted data sets.

*/

int binarySearch(vector<int> arr, int key) {
    int left = 0, right = arr.size() - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(arr[mid] == key) {
            return mid;
        } else if(key < arr[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

```

Comments

二分查找比较简单，每次分成[left, mid-1和[mid+1, right]两个区间，递归终止条件是left>right，而分成[left, mid]与[mid+1,right]两个区间时，递归终止条件是left==right。

二分查找可以查找具有重复元素的排序后的数组，具体要根据自己的需求进行调整，比如当查找最先出现的元素时，查找到之后可以继续向左递归直至查找到最左边的元素。
