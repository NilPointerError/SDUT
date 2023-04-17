#include <iostream>
#include <vector>
using namespace std;

// 埃氏筛法
int main() {
    int n;
    cout << "请输入一个整数: ";
    cin >> n;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    cout << "小于等于" << n << "的素数有: ";
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}