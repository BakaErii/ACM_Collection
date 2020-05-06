/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-10-23 09:21:32
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

const int maxN = 205;
const int INF = 0x3f3f3f3f;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct Node
{
	int x, y, time;
};

int n, m;
char arr[maxN][maxN];
int times[maxN][maxN];
int times2[maxN][maxN];

void BFS() {
	queue<Node> que;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			times[i][j] = INF;
			if (arr[i][j] == 'Y') {
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
			if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] != '#' && times[x][y] == INF) {
				que.push({x, y, f.time + 1});
				times[x][y] = f.time + 1;
			}
		}
	}
	return;
}

void reBFS() {
	queue<Node> que;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			times2[i][j] = INF;
			if (arr[i][j] == 'M') {
				que.push({i, j, 0});
				times2[i][j] = 0;
			}
		}
	while (!que.empty()) {
		Node f = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int x = f.x + dx[i];
			int y = f.y + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] != '#' && times2[x][y] == INF) {
				que.push({x, y, f.time + 1});
				times2[x][y] = f.time + 1;
			}
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (~scanf("%d %d", &n, &m)) {
		getchar();
		for (int i = 0; i < n; i++)
			gets(arr[i]);
		BFS();
		reBFS();
		int ans = INF;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (arr[i][j] == '@')
					ans = min(ans, times[i][j] + times2[i][j]);
		ans *= 11;
		printf("%d\n", ans );
	}
	return 0;
}