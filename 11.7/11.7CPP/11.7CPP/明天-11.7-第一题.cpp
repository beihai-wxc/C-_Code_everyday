#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    string n;
    int s;
    cin >> n >> s;

    // 使用栈来模拟贪心过程
    stack<char> stk;

    for (char digit : n) {
        // 当还有删除名额，且栈非空，且栈顶元素大于当前数字时，弹出栈顶
        while (s > 0 && !stk.empty() && stk.top() > digit) {
            stk.pop();
            s--;
        }
        stk.push(digit);
    }

    // 如果删除名额还没用完，从栈顶（即数字末尾）继续删除
    while (s > 0 && !stk.empty()) {
        stk.pop();
        s--;
    }

    // 将栈中元素倒序取出，构成结果字符串
    string result = "";
    while (!stk.empty()) {
        result = stk.top() + result; // 拼接在前面，保持顺序
        stk.pop();
    }

    // 去除前导零
    // 找到第一个非零字符的位置
    size_t start_pos = result.find_first_not_of('0');
    if (start_pos == string::npos) {
        // 如果全是零，保留一个 '0'
        cout << '0' << endl;
    }
    else {
        cout << result.substr(start_pos) << endl;
    }

    return 0;
}