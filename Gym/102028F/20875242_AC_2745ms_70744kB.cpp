/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-29 13:34:01
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

struct Point
{
	int x, y, t;
};

char M[6005][6005];
bool vis[6005][6005];
int t, r, c;

int BFS(int x, int y) {
	queue<Point> Q;
	Q.push({x, y, 1});
	vis[x][y] = true;
	while (!Q.empty()) {
		Point f = Q.front();
		Q.pop();
		if (M[f.x - 2][f.y] != '-' && vis[f.x - 4][f.y] == false) {
			vis[f.x - 4][f.y] = true;
			if (M[f.x - 4][f.y] == 'T')
				return f.t + 1;
			Q.push({f.x - 4, f.y, f.t + 1});
		}
		if (M[f.x + 2][f.y] != '-' && vis[f.x + 4][f.y] == false) {
			vis[f.x + 4][f.y] = true;
			if (M[f.x + 4][f.y] == 'T')
				return f.t + 1;
			Q.push({f.x + 4, f.y, f.t + 1});
		}
		if (M[f.x - 1][f.y - 3] != '/' && vis[f.x - 2][f.y - 6] == false) {
			vis[f.x - 2][f.y - 6] = true;
			if (M[f.x - 2][f.y - 6] == 'T')
				return f.t + 1;
			Q.push({f.x - 2, f.y - 6, f.t + 1});
		}
		if (M[f.x - 1][f.y + 3] != '\\' && vis[f.x - 2][f.y + 6] == false) {
			vis[f.x - 2][f.y + 6] = true;
			if (M[f.x - 2][f.y + 6] == 'T')
				return f.t + 1;
			Q.push({f.x - 2, f.y + 6, f.t + 1});
		}
		if (M[f.x + 1][f.y - 3] != '\\' && vis[f.x + 2][f.y - 6] == false) {
			vis[f.x + 2][f.y - 6] = true;
			if (M[f.x + 2][f.y - 6] == 'T')
				return f.t + 1;
			Q.push({f.x + 2, f.y - 6, f.t + 1});
		}
		if (M[f.x + 1][f.y + 3] != '/' && vis[f.x + 2][f.y + 6] == false) {
			vis[f.x + 2][f.y + 6] = true;
			if (M[f.x + 2][f.y + 6] == 'T')
				return f.t + 1;
			Q.push({f.x + 2, f.y + 6, f.t + 1});
		}
	}
	return -1;
}

int main(void) {
	int x, y;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &r, &c);
		for (int i = 0; i < 4 * r + 3; i++)
			for (int j = 0; j < 6 * c + 3; j++)
				vis[i][j] = false;
		getchar();
		int rptr = 0, cptr;
		while (rptr < 4 * r + 3) {
			cptr = 0;
			while (M[rptr][cptr++] = getchar())
				if (M[rptr][cptr - 1] == '\n')
					break;
				else if (M[rptr][cptr - 1] == 'S') {
					x = rptr;
					y = cptr - 1;
				}
			rptr++;
		}
		printf("%d\n", BFS(x, y));
	}
	return 0;
}