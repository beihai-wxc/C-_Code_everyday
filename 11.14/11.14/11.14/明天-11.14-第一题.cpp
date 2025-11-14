#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

//广搜
struct pp      // 坐标
{
	int x;
	int y;
};

queue <pp> q;         // 队列 
int n, m;              // n行m列
int ans = 0;            // ans为答案 
int a[105][105];      // 存矩阵 
bool vis[105][105];   // 访问数组 

int dx[4] = { -1,1,0,0 }; // 方向数组 
int dy[4] = { 0,0,-1,1 };

void bfs(int sx, int sy)
{
	pp st;
	// 标记起点 
	st.x = sx;
	st.y = sy;
	vis[sx][sy] = 1;
	q.push(st);

	while (!q.empty())         // 队列不为空 
	{
		pp nw = q.front();      // 返回队首 
		for (int i = 0; i < 4; i++)  // 沿四个方向拓展 
		{
			pp nxt = nw;
			// 记录这一方向 
			nxt.x += dx[i];
			nxt.y += dy[i];

			if (a[nxt.x][nxt.y] == 0 || vis[nxt.x][nxt.y] == 1) // 不是细胞或访问过 
				continue;
			vis[nxt.x][nxt.y] = 1;  // 把这一连通块的点染色 
			q.push(nxt);          // 状态入队 
		}
		q.pop();    // 弹出队首 
	}
}
int main()
{
	cin >> n >> m;
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%1d", &a[i][j]);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (vis[i][j] == 0 && a[i][j] != 0)  // 未访问过，且是细胞 
			{
				bfs(i, j);
				ans++;        // 若这一连通块没搜过ans++ 
			}
		}
	}
	cout << ans;
	return 0;
}