#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定义活动结构体，包含开始时间和结束时间
struct Activity {
    int begin;
    int end;
};

// 自定义比较函数：按结束时间升序排序
bool compareByEnd(const Activity& a, const Activity& b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n; // 输入活动总数

    vector<Activity> activities(n); // 存储所有活动

    // 读入每个活动的开始和结束时间
    for (int i = 0; i < n; ++i) {
        cin >> activities[i].begin >> activities[i].end;
    }

    // 按结束时间升序排序
    sort(activities.begin(), activities.end(), compareByEnd);

    int count = 0;      // 记录可安排的活动数量
    int lastEnd = -1;   // 记录上一个被选活动的结束时间，初始设为-1（确保第一个活动总能被选）

    // 遍历所有活动，贪心选择
    for (int i = 0; i < n; ++i) {
        // 如果当前活动的开始时间 >= 上一个被选活动的结束时间，说明不冲突
        if (activities[i].begin >= lastEnd) {
            count++;           // 选择该活动
            lastEnd = activities[i].end; // 更新上一个活动的结束时间为当前活动的结束时间
        }
        // 如果冲突，跳过该活动，继续下一个
    }

    cout << count << endl; // 输出最多能安排的活动个数

    return 0;
}