数据结构如图所示，now代表的是当前节点
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200405133301317.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2xpZmVsb25nbGVhcm4=,size_16,color_FFFFFF,t_70)



存储方式:

```c
struct node{
    int next[26];//数组序号为边上的字母，存放的是第几个节点
    int cnt;//节点出现的次数
}trie[size];
```
插入：

```c
void insert(struct node *trie,char *str)
{
    int now=0;
    for(int i=0;str[i];++i)
    {
        int t=str[i]-'a';
        if(trie[now].next[t]==0)//如果没有这个字母的边
        {
            trie[now].next[t]=tot;//tot表示新节点
            ++tot;
        }
        now=trie[now].next[t];//移动到下一个节点
    }
    trie[now].cnt++;
}
```
查找：

```c
int find(struct node *trie,char *str)
{
    int now=0;
    for(int i=0;str[i];++i)
    {
        int t=str[i]-'a';
        if(trie[now].next[t]==0)
            return 0;
        else now=trie[now].next[t];
    }
    return trie[now].cnt;
}
```
