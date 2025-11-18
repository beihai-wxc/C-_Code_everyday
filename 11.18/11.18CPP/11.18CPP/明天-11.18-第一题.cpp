#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 55;
int n, m;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int roomCount = 0;
int maxRoomSize = 0;
int currentSize;

//西、北、东、南
const int dx[4] = { 0,-1,0,1 };
const int dy[4] = { -1,0,1,0 };
const int wallValue[4] = { 1,2,4,8 };

void dfs(int x, int y) {
	visited[x][y] = true;
	int p = grid[x][y];

	for (int d = 0; d < 4; d++) {
		if ((p & wallValue[d]) == 0) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx >= 1 && nx <= m && ny>=1 && ny <= n && !visited[nx][ny]) {
				currentSize++;
				dfs(nx, ny);
			}
		}
	}

}

int main() {

	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j]) {
				roomCount++;
				currentSize = 1;
				dfs(i, j);
				maxRoomSize = max(maxRoomSize, currentSize);
			}
		}
	}
	cout << roomCount << endl;
	cout << maxRoomSize << endl;

	return 0;
}