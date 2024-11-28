#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
bool vis[502][502];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int> > Q;

	int n, m;
	cin >> n >> m;

	int pic[502][502];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> pic[i][j];
		}
	}
	
	int mx = 0, num = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (pic[i][j] == 0 || vis[i][j]) continue;
			num++;
			queue<pair<int, int> > Q;
			vis[i][j] = 1;

			Q.push({i,j});
			int area = 0;
			while (!Q.empty()) {
				area++;
				pair<int, int> cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
					if (vis[nx][ny] || pic[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
					vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
					Q.push({ nx,ny });
				}
			}
			mx = max(mx, area);
		}
	}
	cout << num << '\n' << mx;

	return 0;
}
