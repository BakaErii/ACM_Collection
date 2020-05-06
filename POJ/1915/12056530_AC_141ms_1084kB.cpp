/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-23 12:52:43
 *
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

const int INF = 100000000;

typedef pair<int, int> P;

int sx, sy, gx, gy, l;
int vis[300][300];

int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1};

int bfs(void) {
	queue<P> que;
	que.push(P(sx, sy));
	vis[sx][sy] = 0;
	while (que.size() != 0) {
		P p = que.front();
		que.pop();
		if (p.first == gx && p.second == gy)
			break;
		for (int i = 0; i < 8; i++) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			if (0 <= nx && nx < l && 0 <= ny && ny < l && vis[nx][ny] == INF) {
				que.push(P(nx, ny));
				vis[nx][ny] = vis[p.first][p.second] + 1;
			}
		}
	}
	return vis[gx][gy];
}

int main(void) {
	int i, j, t;
	cin >> t;
	while (t--) {
		cin >> l >> sx >> sy >> gx >> gy;
		for (i = 0; i < l; i++)
			for (j = 0; j < l; j++)
				vis[i][j] = INF;
		cout << bfs() << endl;
	}
	return 0;
}