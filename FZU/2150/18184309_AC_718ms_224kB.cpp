/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-11 00:43:04
 *
 */
#include <queue>

#include <stdio.h>
#include <string.h>

using namespace std;

#define maxN 12

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool vis[maxN][maxN];
char arr[maxN][maxN];

int ans;
int n, m;

struct Point
{
	int x, y, times;
	Point(int _x, int _y, int _times) {
		x = _x;
		y = _y;
		times = _times;
		return;
	}
};

void Init() {
	ans = 1919810;
	return;
}

bool Check() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == '#' && vis[i][j] == false)
				return false;
	return true;
}

void BFS(int sPosX1, int sPosY1, int sPosX2, int sPosY2) {
	int maxAns = -1;
	queue<Point> que;
	memset(vis, 0, sizeof(vis));
	que.push(Point(sPosX1, sPosY1, 0));
	que.push(Point(sPosX2, sPosY2, 0));
	vis[sPosX1][sPosY1] = true;
	vis[sPosX2][sPosY2] = true;
	while (!que.empty()) {
		Point f = que.front();
		maxAns = max(maxAns, f.times);
		que.pop();
		for (int i = 0; i < 4; i++) {
			int X = f.x + dx[i];
			int Y = f.y + dy[i];
			if (X >= 0 && X < n && Y >= 0 && Y < m && vis[X][Y] == false && arr[X][Y] == '#') {
				que.push(Point(X, Y, f.times + 1));
				vis[X][Y] = true;
			}
		}
	}
	if (Check())
		ans = min(maxAns, ans);
	return;
}

int main(void) {
	int t, kase = 0;
	scanf("%d", &t);
	while (t--) {
		Init();
		scanf("%d %d", &n, &m);
		getchar();
		for (int i = 0; i < n; i++)
			scanf("%s", arr[i]);
		for (int sX1 = 0; sX1 < n; sX1++)
			for (int sY1 = 0; sY1 < m; sY1++)
				for (int sX2 = 0; sX2 < n; sX2++)
					for (int sY2 = 0; sY2 < m; sY2++)
						if (arr[sX1][sY1] == '#' && arr[sX2][sY2] == '#')
							BFS(sX1, sY1, sX2, sY2);
		printf("Case %d: %d\n", ++kase, ans == 1919810 ? -1 : ans );
	}
	return 0;
}