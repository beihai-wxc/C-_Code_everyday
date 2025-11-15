#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 105; // 因为坐标最大是100，留一点余地
int visited[MAX][MAX]; // 访问标记数组
int dx[12] = { 2, 1, -1, -2, -2, -1, 1, 2, 2, 2, -2, -2 }; // 日字 + 田字
int dy[12] = { 1, 2, 2, 1, -1, -2, -2, -1, 2, -2, 2, -2 };

// BFS 求从 (sx, sy) 到 (1,1) 的最少步数
int bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({ sx, sy });
    visited[sx][sy] = 1;
    int step = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == 1 && y == 1) {
                return step;
            }

            // 尝试所有12种走法（8种日字 + 4种田字）
            for (int k = 0; k < 12; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 1 && nx <= 100 && ny >= 1 && ny <= 100 && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    q.push({ nx, ny });
                }
            }
        }
        step++;
    }

    return -1; // 不可能到达（理论上不会发生）
}

int main() {
    int ax, ay, bx, by;
    cin >> ax >> ay;
    cin >> bx >> by;

    // 清空 visited 数组
    memset(visited, 0, sizeof(visited));

    int resultA = bfs(ax, ay);
    cout << resultA << endl;

    // 再次清空 visited 数组用于 B 点
    memset(visited, 0, sizeof(visited));

    int resultB = bfs(bx, by);
    cout << resultB << endl;

    return 0;
}