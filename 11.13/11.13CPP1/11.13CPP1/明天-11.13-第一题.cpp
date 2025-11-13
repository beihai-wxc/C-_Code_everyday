#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 快速幂模运算: (base^exp) % mod
long long fastPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// 大数字符串 n 对 mod 取模
long long bigMod(const string& n, long long mod) {
    long long res = 0;
    for (char c : n) {
        res = (res * 10 + (c - '0')) % mod;
    }
    return res;
}

int main() {
    int k;
    cin >> k;

    // 预处理：φ(10000) = 4000
    const long long PHI = 4000;
    const long long MOD = 10000;

    while (k--) {
        string n;
        cin >> n;

        // 计算 n mod 4000
        long long exp_mod = bigMod(n, PHI);

        // 如果 n == 0，则结果是 1，但 n 是正整数，所以不用考虑
        // 计算 2011^(exp_mod) mod 10000
        long long result = fastPow(2011, exp_mod, MOD);

        // 输出结果，去掉前导零
        cout << result << endl;
    }

    return 0;
}