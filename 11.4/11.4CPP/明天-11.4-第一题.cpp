#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//BFS算法

// 四个方向：上、下、左、右
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int main() {
    int R, C;
    cin >> R >> C;

    // 读取迷宫
    vector<string> maze(R);
    for (int i = 0; i < R; i++) {
        cin >> maze[i];
    }

    // dist[r][c] 表示从起点到 (r,c) 的最少步数（包含起点）
    vector<vector<int>> dist(R, vector<int>(C, -1)); // -1 表示未访问
   


    // BFS 队列：存储坐标 (r, c)
    queue<pair<int, int>> q;

    // 起点 (0, 0) 步数为 1
    dist[0][0] = 1;
    q.push({ 0, 0 });

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        // 如果到达终点，直接输出并退出（BFS第一次到达即最短）
        if (r == R - 1 && c == C - 1) {
            cout << dist[r][c] << endl;
            return 0;
        }

        // 尝试四个方向
        for (int d = 0; d < 4; d++) {
            int nr = r + dx[d];
            int nc = c + dy[d];

            // 边界检查
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

            // 障碍物或已访问，跳过
            if (maze[nr][nc] == '#' || dist[nr][nc] != -1) continue;

            // 更新距离并入队
            dist[nr][nc] = dist[r][c] + 1;
            q.push({ nr, nc });
        }
    }

    cout << -1 << endl;
    return 0;
}