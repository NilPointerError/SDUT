#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    while(cin >> str) {
        int len = str.length();
        int la = 8 * len;// ASCII coding length
        // 只计算HuffmanCodingLen值的话,只需要把所有非叶子节点的权重相加得到结果即可
        priority_queue<int, vector<int>, greater<int>> pQueue;
        map<char, int> weight;
        // 计算每个字符的权重 存放map中 
        for (int i = 0; i < len; i++) {
            /* code */
            char ch = str[i];
            weight[ch]++;
        }
        // 放入priority_queue中 升序排序 每次取两个最小值相加
        map<char, int>::iterator iter;
        iter = weight.begin();
        while (iter != weight.end()) {
            int val = iter->second;
            iter++;
            pQueue.push(val);
        }
        int lh = 0;// Huffman coding length
        while(!pQueue.empty() && pQueue.size() > 1) {
            int min1 =0;
            if(!pQueue.empty()) {
                min1 = pQueue.top();
                pQueue.pop();
            }
            int min2 = 0;
            if(!pQueue.empty()) {
                min2 = pQueue.top();
                pQueue.pop();
            }
            int sum = min1 + min2;
            //cout << sum << endl;
            lh += sum;
            pQueue.push(sum);
        }
        cout << la << " " << lh << " ";
        cout << fixed << setprecision(1) << 1.0 * la/lh << endl;
    }
    return 0;
}