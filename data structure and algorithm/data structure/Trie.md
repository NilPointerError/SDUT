如图所示，是Trie的一种简单的实现方式，图中的存放了ab、abc、b这几个字母，需要注意的是：根节点不含有元素，子节点的每个分支存放的字符互不相同，通过count值保存字符串的数量，默认为0

<img src="pic\Trie.jpg" style="zoom: 67%;" />

简单Trie类的插入与查找的代码实现：

```c++
#include <bits/stdc++.h>
using namespace std;

/*

    应用：统计大量的字符串，被搜索引擎用于文本词频的统计。

    字典树: 利用字符串的公共前缀来较少查询时间,最大限度地减少无谓的字符串比较
    
    核心思想是利用空间换时间。利用字符串的公共前缀来降低查询时间的开销
    
    查询的时间复杂度为：O(L), L是字符串的长度
    
    在空间要求不那么严格的情况下，字典树的效率不见得比hash低，它支持动态
    查询。不用等待完全输入完毕后才查询
    
*/


class TrieNode {

public:
  int count;// 当前单词结尾的单词数量
  int prefix;// 该节点之前的字符串(包括该节点)前缀的数量
  TrieNode *nextNode[26];// 存储下一个节点
  TrieNode(): count(0), prefix(0) {
      for (int i = 0; i < 26; i++) {
          /* code */
          nextNode[i] = nullptr;
      }
      
  };  
  
  void insert(string str) {
    int len = str.length();
    TrieNode* cur = this;
    for (int i = 0; i < len; i++) {
        /* code */
        int index = str[i] - 'a';
        if(cur->nextNode[index] == nullptr) {
            cur->nextNode[index] = new TrieNode();
        }
        cur = cur->nextNode[index];
        cur->prefix++;
    }
    cur->count++;
  }
  //查找该单词是否存在，如果存在返回数量，不存在返回-1
  int find(string str) {
    /*
        当某个字符的节点为空时(字符串某个字符未匹配上),
        或者count = 0时(字符串查找到头未找到),则没有找到
    */
    int len = str.length();
    TrieNode* cur = this;
    for (int i = 0; i < len; i++) {
        /* code */
        int index = str[i] - 'a';
        if(cur->nextNode[index] == nullptr) {
            //cout << index << endl;
            return 0;
        }
        cur = cur->nextNode[index];
    }
    return cur->count;
  }
  
};

int main()
{
    int n,m;
    while(cin >> n >> m && (n || m)) {
        TrieNode* root = new TrieNode();
        for (int i = 0; i < n; i++) {
            /* code */
            string targetWord;
            cin >> targetWord;
            root->insert(targetWord);
        }
        for (int i = 0; i < m; i++) {
            /* code */
            string searchWord;
            cin >> searchWord;
            int count = root->find(searchWord);
            if(count == 0) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}
```

Comment:

存放大量的字符串时，我们应该考虑空间复杂度较小的数据结构，比如：Compressed trie 基数树 后缀树等。后一种通常在特定的情况下运用，比如：最长公共子串等。
