/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-13 14:01:10
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

const int maxN = 505;

struct Point
{
	int x, y, times;
};

char G[maxN][maxN];
int times[maxN][maxN];

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m, sX, sY, eX, eY;

bool isOK = false;

void BFS() {
	queue<Point> que;
	if (sX == eX && sY == eY) {
		for (int i = 0; i < 4; i++) {
			int X = sX + dx[i];
			int Y = sY + dy[i];
			if (X >= 1 && X <= n && Y >= 1 && Y <= m && G[X][Y] == '.') {
				isOK = true;
			}
		}
		return;
	}
	G[sX][sY] = 'X';
	que.push({sX, sY, 1});
	times[sX][sY] = 1;
	while (!que.empty()) {
		Point f = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int X = f.x + dx[i];
			int Y = f.y + dy[i];
			if (X >= 1 && X <= n && Y >= 1 && Y <= m && times[X][Y] == 0 && (G[X][Y] != 'X' || (X == eX && Y == eY))) {
				if (X == eX && Y == eY) {
					if (G[eX][eY] == 'X')
						isOK = true;
					for (int i = 0; i < 4; i++) {
						int DX = eX + dx[i];
						int DY = eY + dy[i];
						if (DX >= 1 && DX <= n && DY >= 1 && DY <= m && (G[DX][DY] == '.' || (times[DX][DY] == times[f.x][f.y] && (!(DX == f.x && DY == f.y))))) {
							isOK = true;
						}
					}
					return;
				}
				que.push({X, Y, f.times + 1});
				G[X][Y] = 'X';
				times[X][Y] = f.times + 1;
			}
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%s", G[i] + 1);
	scanf("%d %d", &sX, &sY);
	scanf("%d %d", &eX, &eY);
	BFS();
	if (isOK)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}