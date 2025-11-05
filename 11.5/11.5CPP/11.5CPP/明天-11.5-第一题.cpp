#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Person {
    int id;     // 原始编号（从1开始）
    int time;   // 接水时间
};

bool cmp(const Person& a, const Person& b) {
    return a.time < b.time;
}

int main() {
    int n;
    cin >> n;

    vector<Person> people(n);
    for (int i = 0; i < n; ++i) {
        cin >> people[i].time;
        people[i].id = i + 1;  // 编号从1开始
    }

    // 按接水时间升序排序
    sort(people.begin(), people.end(), cmp);

    // 输出排队顺序（原始编号）
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << people[i].id;
    }
    cout << endl;

    // 计算平均等待时间
    long long totalWait = 0;
    long long currentTime = 0;  // 当前累计接水时间（即下一个人的等待时间）

    for (int i = 0; i < n; ++i) {
        // 第i个人的等待时间是前面所有人接水时间之和
        totalWait += currentTime;
        currentTime += people[i].time;
    }

    double avgWait = static_cast<double>(totalWait) / n;

    // 输出平均等待时间，保留两位小数
    cout << fixed << setprecision(2) << avgWait << endl;

    return 0;
}