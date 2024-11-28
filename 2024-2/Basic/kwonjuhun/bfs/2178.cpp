#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
bool vis[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
string board[102];
int dist[102][102];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	queue<pair<int, int> > Q;
	vis[0][0] = 1;
	Q.push({ 0,0 });
	dist[0][0] = 0;

	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
			if (vis[nx][ny] || board[nx][ny] != '1') continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
			vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}

	cout << dist[n-1][m-1] + 1; // +1 하는 이유 정확히 모르겠다

	return 0;
}
