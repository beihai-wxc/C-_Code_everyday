#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> missiles;
    int h;
    while (cin >> h) {
        missiles.push_back(h);
    }

    // systems[i] 表示第 i 个系统当前能拦截的最高高度
    vector<int> systems;

    for (int h : missiles) {
        // 在 systems 中找第一个 >= h 的位置
        auto it = lower_bound(systems.begin(), systems.end(), h);

        if (it != systems.end()) {
            // 找到了，用这个系统拦截，更新其高度为 h
            *it = h;
        }
        else {
            // 没找到，新增一个系统
            systems.push_back(h);
        }
    }

    cout << systems.size() << endl;
    return 0;
}