#### 线段树的一些性质

- 线段树一定为平衡二叉树（左子树与右子树的高度之差总是小于等于1，即左右子树叶节点的个数之差总是小于等于1），但不一定是完全二叉树
- 数组元素个数为N，那么构成一个线段树总共需要2N-1(N=2<sup>k</sup>) 或 4N-5(N!=2<sup>k</sup>)个节点

数据结构如图所示：

<img src="..\..\pic\SegmentTree.jpg" style="zoom:80%;" />

```c++
#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;
	// 建立线段树
    void buildTree(vector<int> &arr, int treeIndex, int lo, int hi) {
        if (lo == hi) {
            tree[treeIndex] = arr[lo];
            return;
        }
        int mid = lo + (hi - lo) / 2;
        buildTree(arr, 2 * treeIndex + 1, lo, mid);
        buildTree(arr, 2 * treeIndex + 2, mid + 1, hi);
        tree[treeIndex] = min(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
    }
	// 更新线段树
    void updateTree(int treeIndex, int lo, int hi, int arrIndex, int val) {
        if (lo == hi) {
            tree[treeIndex] = val;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        if (arrIndex > mid)
            updateTree(2 * treeIndex + 2, mid + 1, hi, arrIndex, val);
        else
            updateTree(2 * treeIndex + 1, lo, mid, arrIndex, val);
        tree[treeIndex] = min(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
    }
	// 查询线段树的区间中最小值
    int queryTree(int treeIndex, int lo, int hi, int i, int j) {
        if (lo > j || hi < i)
            return INT_MAX;
        // 查询区间完全包含当前区间时 返回当前数组元素
        if (i <= lo && j >= hi)
            return tree[treeIndex];
        int mid = lo + (hi - lo) / 2;
       // 当查询区间完全在右区间时，直接返回右子树
        if (i > mid)
            return queryTree(2 * treeIndex + 2, mid + 1, hi, i, j);
        // 当查询区间完全在左区间时，直接返回左子树
        else if (j <= mid)
            return queryTree(2 * treeIndex + 1, lo, mid, i, j);
        // 在两侧区间时，需要遍历两个左右子树
        int leftQuery = queryTree(2 * treeIndex + 1, lo, mid, i ,mid);
        int rightQuery = queryTree(2 * treeIndex + 2,mid+1 ,hi,mid+1,j);
        return min(leftQuery,rightQuery);
    }

public:
    SegmentTree(vector<int> &arr) {
        n = arr.size();
        tree.resize(4*n);// 申请4n大小的空间
        buildTree(arr ,0 ,0 ,n-1);
    }

    void update(int index,int value){
        updateTree(0 ,0 ,n-1 ,index ,value);
    }

    int query(int left,int right){
        return queryTree(0 ,0 ,n-1 ,left ,right);
    }
};
```

#### Comments

示例中只是简单的线段树的实现方式，线段树每次递归时都要更新，效率比较低，可以通过延迟节点的方式优化效率。

线段树是一种更加通用的数据结构，它可以用来解决很多不同的问题，时间复杂度为O(logn)。例如，线段树可以用来维护区间信息（如区间和、区间最值等），支持快速查询和修改。线段树的优点是灵活性强，可以解决很多复杂的问题。线段树适用于维护和查询区间信息，而不是查找单个元素。

