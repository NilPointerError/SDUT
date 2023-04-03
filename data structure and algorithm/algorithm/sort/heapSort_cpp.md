堆排序过程如图所示:

![](https://img-blog.csdnimg.cn/20201001214619432.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2xpZmVsb25nbGVhcm4=,size_16,color_FFFFFF,t_70#pic_center)



具体代码实现:

```cpp
#define LT(a,b) ((a) < (b))//大根堆 顺序
#define RT(a,b) ((a) > (b))//小根堆 逆序
template<class Type>
void HeapAdjust(Type a[],int s,int m){//调整堆
    Type rc = a[s];//顶端a[s]
    for(int i=2*s;i<=m;i*=2){
        if(RT(a[i],a[i+1])&&i<m)
            ++i;
        if(!RT(rc,a[i]))
            break;
        a[s] = a[i];
        s = i;//s移到i的位置
    }
    a[s] = rc;
}
template<class Type>
void HeapSort(Type a[],int m){//m为数组a的长度
    for(int i=m/2;i>0;--i)//m/2为二叉树最后一个非终端结点
        HeapAdjust(a,i,m);//把整个序列建成堆
    for(int i=m;i>1;--i){
        swap(a[1],a[i]);
        HeapAdjust(a,1,i-1);//节点1左右子树都为堆，只调节节点1
    }
}
```
