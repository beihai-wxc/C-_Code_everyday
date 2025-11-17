#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N, M;
vector<string>grid;
const int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
const int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

void dfs(int x, int y) {

	grid[x][y] = '.';
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] == 'W') {
			dfs(nx, ny);
		}
	}

}

int main() {
	cin >> N >> M;
	grid.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> grid[i];
	}
	int lake = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (grid[i][j] == 'W') {
				dfs(i, j);
				lake++;
			}
		}
	}

	cout << lake << endl;
	return 0;
}