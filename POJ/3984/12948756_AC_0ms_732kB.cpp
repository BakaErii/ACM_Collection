/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-09 17:37:03
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

struct mazeQueue {
	int x;
	int y;
	int ptr;
} que[25];
vector<mazeQueue> ans;

int queBptr, queEptr;
int maze[5][5];
int vis[5][5];

void bfs(void) {
	//init
	queBptr = 0;
	queEptr = 0;
	que[queEptr++] = {0, 0, -1};
	while (!(que[queBptr].x == 4 && que[queBptr].y == 4)) {
		if (que[queBptr].x + 1 < 5 && maze[que[queBptr].x + 1][que[queBptr].y] == 0 && vis[que[queBptr].x + 1][que[queBptr].y] == 0) {
			que[queEptr++] = {que[queBptr].x + 1, que[queBptr].y, queBptr};
			vis[que[queBptr].x + 1][que[queBptr].y] = 1;
		}
		if (que[queBptr].y + 1 < 5 && maze[que[queBptr].x][que[queBptr].y + 1] == 0 && vis[que[queBptr].x][que[queBptr].y + 1] == 0) {
			que[queEptr++] = {que[queBptr].x, que[queBptr].y + 1, queBptr};
			vis[que[queBptr].x][que[queBptr].y + 1] = 1;
		}
		if (que[queBptr].x - 1 >= 0 && maze[que[queBptr].x - 1][que[queBptr].y] == 0 && vis[que[queBptr].x - 1][que[queBptr].y] == 0) {
			que[queEptr++] = {que[queBptr].x - 1, que[queBptr].y, queBptr};
			vis[que[queBptr].x - 1][que[queBptr].y] = 1;
		}
		if (que[queBptr].y - 1 >= 0 && maze[que[queBptr].x ][que[queBptr].y - 1] == 0 && vis[que[queBptr].x ][que[queBptr].y - 1] == 0) {
			que[queEptr++] = {que[queBptr].x, que[queBptr].y - 1, queBptr};
			vis[que[queBptr].x ][que[queBptr].y - 1] = 1;
		}
		queBptr++;
	}
	//输出
	while (que[queBptr].ptr != -1) {
		ans.push_back({que[queBptr].x, que[queBptr].y, 0});
		queBptr = que[queBptr].ptr;
	}
	ans.push_back({0, 0, 0});
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < (int) ans.size(); i++)
		printf("(%d, %d)\n", ans[i].x, ans[i].y);
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			scanf("%d", &maze[i][j]);
	bfs();
	return 0;
}