#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int R;
    cin >> R;

    //从下往上来分析
    vector<vector<int>> triangle(R);
    for (int i = 0; i < R; ++i) {
        triangle[i].resize(i + 1);
        for (int j = 0; j <= i; ++j) {
            cin >> triangle[i][j];
        }
    }

    // 使用一维数组，从下往上更新
    vector<int> dp(R);
    //初始化为最后一行的值
    for (int j = 0; j < R; ++j) {
        dp[j] = triangle[R - 1][j];
    }

    //更新
    for (int i = R - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            dp[j] = triangle[i][j] + max(dp[j], dp[j + 1]);
        }
    }

    //最后一个就是最大值
    cout << dp[0] << endl;

    return 0;
}