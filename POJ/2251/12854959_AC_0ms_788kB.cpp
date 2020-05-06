/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-01 00:19:15
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

char arr[30][30][31];
bool vis[30][30][30];
int l, r, c, ans;

struct point
{
	int x;
	int y;
	int z;
	int step;
};
typedef point P;

int bfs(void) {
	int i, j, k;
	queue<P> que;
	P nowPos;
	//寻找起点
	for (i = 0; i < l; i++)
		for (j = 0; j < r; j++)
			for (k = 0; k < c; k++)
				if (arr[i][j][k] == 'S') {
					que.push({i, j, k, 0});
					vis[i][j][k] = true;
				}
	while (!que.empty()) {
		nowPos = que.front();
		//cerr << nowPos.x << nowPos.y << nowPos.z << nowPos.step << endl;
		que.pop();
		if (arr[nowPos.x][nowPos.y][nowPos.z] == 'E')
			return nowPos.step;
		//对六个方向遍历 寻找到终点时直接返回
		if (nowPos.x + 1 < l && arr[nowPos.x + 1][nowPos.y][nowPos.z] != '#' && vis[nowPos.x + 1][nowPos.y][nowPos.z] == false) {
			que.push({nowPos.x + 1, nowPos.y, nowPos.z, nowPos.step + 1});
			vis[nowPos.x + 1][nowPos.y][nowPos.z] = true;
		}
		if (nowPos.x - 1 >= 0 && arr[nowPos.x - 1][nowPos.y][nowPos.z] != '#' && vis[nowPos.x - 1][nowPos.y][nowPos.z] == false) {
			que.push({nowPos.x - 1, nowPos.y, nowPos.z, nowPos.step + 1});
			vis[nowPos.x - 1][nowPos.y][nowPos.z] = true;
		}
		if (nowPos.y + 1 < r && arr[nowPos.x ][nowPos.y + 1][nowPos.z] != '#' && vis[nowPos.x][nowPos.y + 1][nowPos.z] == false) {
			que.push({nowPos.x , nowPos.y + 1, nowPos.z, nowPos.step + 1});
			vis[nowPos.x ][nowPos.y + 1][nowPos.z] = true;
		}
		if (nowPos.y - 1 >= 0  && arr[nowPos.x][nowPos.y - 1][nowPos.z] != '#' && vis[nowPos.x][nowPos.y - 1][nowPos.z] == false) {
			que.push({nowPos.x, nowPos.y - 1, nowPos.z, nowPos.step + 1});
			vis[nowPos.x][nowPos.y - 1][nowPos.z] = true;
		}
		if (nowPos.z + 1 < c && arr[nowPos.x][nowPos.y][nowPos.z + 1] != '#' && vis[nowPos.x][nowPos.y][nowPos.z + 1] == false) {
			que.push({nowPos.x, nowPos.y, nowPos.z + 1, nowPos.step + 1});
			vis[nowPos.x][nowPos.y][nowPos.z + 1] = true;
		}
		if (nowPos.z - 1 >= 0 && arr[nowPos.x][nowPos.y][nowPos.z - 1] != '#' && vis[nowPos.x][nowPos.y][nowPos.z - 1] == false) {
			que.push({nowPos.x, nowPos.y, nowPos.z - 1, nowPos.step + 1});
			vis[nowPos.x][nowPos.y][nowPos.z - 1] = true;
		}
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	int i, j;
	while (~scanf("%d %d %d", &l, &r, &c)) {
		if (l == 0 && r == 0 && c == 0)
			break;
		getchar();
		//init
		memset(vis, 0, sizeof(vis));
		memset(arr, 0, sizeof(arr));
		for (i = 0; i < l; i++) {
			for (j = 0; j < r; j++)
				gets(arr[i][j]);
			getchar();
		}
		ans = bfs();
		if (ans == -1)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n", ans );
	}
	return 0;
}