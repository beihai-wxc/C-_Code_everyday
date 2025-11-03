#include <iostream>
#include <vector>
#include <iomanip> // 格式化输出

using namespace std;


// current: 当前已选的元素列表
// start: 下一个可选的最小数字（保证升序）
// n: 总共有多少个数（1~n）
// r: 需要选多少个数
void generateCombinations(vector<int>& current, int start, int n, int r) {
    // 如果已经选了 r 个数，输出当前组合
    if (current.size() == r) {
        // 输出每个数字，sew()占3位，right右对齐
        for (int i = 0; i < r; ++i) {
            cout << setw(3) << right << current[i];     
            if (i != r - 1) cout << " "; // 最后一个数字前的数字之间加空格
        }
        cout << endl;
        return;
    }

    // 递归：从 start 到 n 尝试选下一个数字
    for (int i = start; i <= n; ++i) {
        current.push_back(i);          // 选 i
        generateCombinations(current, i + 1, n, r); // 递归选下一个，从 i+1 开始保证升序
        current.pop_back();            // 回溯：撤销选择
    }
}

int main() {
    int n, r;
    cin >> n >> r;

    vector<int> current; // 存储当前正在构建的组合
    generateCombinations(current, 1, n, r); // 从数字1开始选

    return 0;
}