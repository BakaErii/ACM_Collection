/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-13 00:33:13
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

const int maxN = 12;

char mp[2][maxN][maxN];
bool vis[2][maxN][maxN];
int n, m, t;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct Node
{
	int z, x, y, time;
};

void Init() {
	memset(vis, 0, sizeof(vis));
	return;
}

bool BFS() {
	queue<Node> que;
	que.push({0, 0, 0, 0});
	vis[0][0][0] = true;
	while (!que.empty()) {
		Node f = que.front();
		que.pop();
		if (mp[f.z][f.x][f.y] == 'P')
			return true;
		for (int i = 0; i < 4; i++) {
			int X = f.x + dx[i];
			int Y = f.y + dy[i];
			if (X >= 0 && Y >= 0 && X < n && Y < m && vis[f.z][X][Y] == false)
				switch (mp[f.z][X][Y]) {
				case '.':
				case 'P':
					if (f.time == t)
						break;
					vis[f.z][X][Y] = true;
					que.push({f.z, X, Y, f.time + 1});
					break;
				case '*':
					break;
				case '#':
					vis[f.z][X][Y] = true;
					if (mp[(f.z + 1) % 2][X][Y] != '*' && mp[(f.z + 1) % 2][X][Y] != '#' && f.time != t) {
						vis[(f.z + 1) % 2][X][Y] = true;
						que.push({(f.z + 1) % 2, X, Y, f.time + 1});
					}
					break;
				}
		}
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	scanf("%d", &k);
	while (k--) {
		Init();
		scanf("%d %d %d", &n, &m, &t);
		getchar();
		for (int i = 0; i < n; i++)
			gets(mp[0][i]);
		getchar();
		for (int i = 0; i < n; i++)
			gets(mp[1][i]);
		if (BFS())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}