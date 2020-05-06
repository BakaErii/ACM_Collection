/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-10-23 08:31:08
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

const int maxN = 1005;
const int INF = 0x3f3f3f3f;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, m;
string arr[maxN];
int times[maxN][maxN];
bool vis[maxN][maxN];

struct Node {
	int x, y, time;
};

void fireBFS() {
	queue<Node> que;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			times[i][j] = INF;
			if (arr[i][j] == 'F') {
				que.push({i, j, 0});
				times[i][j] = 0;
			}
		}
	while (!que.empty()) {
		Node f = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int x = f.x + dx[i];
			int y = f.y + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && times[x][y] == INF && arr[x][y] != '#') {
				que.push({x, y, f.time + 1});
				times[x][y] = f.time + 1;
			}
		}
	}
	return;
}

int BFS() {
	queue<Node> que;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 'J') {
				que.push({i, j, 0});
				vis[i][j] = true;
				break;
			}
	while (!que.empty()) {
		Node f = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int x = f.x + dx[i];
			int y = f.y + dy[i];
			if (x < 0 || x >= n || y < 0 || y >= m)
				return f.time + 1;
			if (x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == false && times[x][y] > f.time + 1 && arr[x][y] != '#') {
				que.push({x, y, f.time + 1});
				vis[x][y] = true;
			}
		}
	}
	return -1;
}

int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		getchar();
		for (int i = 0; i < n; i++)
			getline(cin, arr[i]);
		fireBFS();
		int ans = BFS();
		if (ans == -1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", ans );
	}
	return 0;
}