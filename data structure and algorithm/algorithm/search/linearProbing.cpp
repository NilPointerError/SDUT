#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

// h(key) = key % p

int n, p;
int hashTable[n];

// 插入元素
void insert(int hashTable[], int val) {
    int index = val % p;
    // //发生哈希冲突后，依次向后探测，直到找到一个空闲位置存储元素
    while(hashTable[index] != 0 && hashTable[index] != val) {
        index = (index + 1) % p;
    }
    hashTable[index] = val;
}
// 查找元素
int find(int key) {
    int index = key % p;
    while(hashTable[index] != key) {//如果当前哈希值位置的元素与key不相等，则向后探测
        index = (index + 1) % p;
    }
    return index;
}

