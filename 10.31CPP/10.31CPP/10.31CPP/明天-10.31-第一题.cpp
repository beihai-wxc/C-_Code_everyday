#include <iostream>
#include <string>
using namespace std;

const int MOD = 12345;

int main() {
    string n_str;
    cin >> n_str;

    // 将输入的字符串转换为整数 N
    int N = stoi(n_str);

    // dp_even: 当前位数下，包含偶数个 '3' 的数字个数
    // dp_odd:  当前位数下，包含奇数个 '3' 的数字个数
    long long dp_even = 0; // 初始化为 0
    long long dp_odd = 0;  // 初始化为 0

    //递推解决
    if (N == 1) {
        // 一位数：1~9
        // 偶数个 '3'：除了 3 以外的 8 个数字 (1,2,4,5,6,7,8,9)
        dp_even = 8;
        dp_odd = 1; // 只有数字 3
    }
    else {
        // 处理第一位
        dp_even = 8; // 第一位不是 3 (8种选择)
        dp_odd = 1;  // 第一位是 3 (1种选择)

        // 处理第 2 位到第 N 位
        for (int i = 2; i <= N; ++i) {
            long long new_even = (dp_even * 9 + dp_odd * 1) % MOD;
            long long new_odd = (dp_even * 1 + dp_odd * 9) % MOD;
            dp_even = new_even;
            dp_odd = new_odd;
        }
    }

    cout << dp_even % MOD << endl;

    return 0;
}