#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int n, p;
int hashTable[n];

// 插入元素
// 增量di=±i^2,i=1,2,3,...,m-1
void insert(int hashTable[], int val) {
    int index = val % p;
    // //发生哈希冲突后，按照二次函数向后探测，直到找到一个空闲位置存储元素
    int sign = 1;//正负号
    int count = 1;//乘数
    int di = 0;//增量
    int temp = index;//暂存值
    while(hashTable[temp] != 0 && hashTable[temp] != val) {
        di = sign * count * count;
        temp = (index + di) % p;
        sign = -sign;
        if(sign == 1)//当变为正数时，乘数加一
            ++count;
    }
    hashTable[temp] = val;
}
// 查找元素
int find(int hashTable[], int key) {
    int index = key % p;
    int sign = 1;//正负号
    int count = 1;//乘数
    int di = 0;//增量
    int temp = index;//暂存值
    while(hashTable[temp] != key) {//如果当前哈希值位置的元素与key不相等，则向后探测
        di = sign * count * count;
        temp = (index + di) % p;
        sign = -sign;
        if(sign == 1)//当变为正数时，乘数加一
            ++count;
    }
    return temp;
}

