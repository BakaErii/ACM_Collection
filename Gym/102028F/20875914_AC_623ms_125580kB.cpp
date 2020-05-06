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

char M[8005][8005];
bool vis[8005][8005];
queue<Point> Q;
int t, r, c;

int BFS(void) {
	for (int i = 0; i < 4 * r + 3; i++)
		for (int j = 0; j < 6 * c + 3; j++)
			if (M[i][j] == 'S') {
				Q.push({i, j, 1});
				vis[i][j] = true;
			}
	while (!Q.empty()) {
		Point f = Q.front();
		Q.pop();
		if (M[f.x][f.y] == 'T')
			return f.t;
		if (M[f.x - 2][f.y] != '-' && vis[f.x - 4][f.y] == false) {
			vis[f.x - 4][f.y] = true;
			Q.push({f.x - 4, f.y, f.t + 1});
		}
		if (M[f.x + 2][f.y] != '-' && vis[f.x + 4][f.y] == false) {
			vis[f.x + 4][f.y] = true;
			Q.push({f.x + 4, f.y, f.t + 1});
		}
		if (M[f.x - 1][f.y - 3] != '/' && vis[f.x - 2][f.y - 6] == false) {
			vis[f.x - 2][f.y - 6] = true;
			Q.push({f.x - 2, f.y - 6, f.t + 1});
		}
		if (M[f.x - 1][f.y + 3] != '\\' && vis[f.x - 2][f.y + 6] == false) {
			vis[f.x - 2][f.y + 6] = true;
			Q.push({f.x - 2, f.y + 6, f.t + 1});
		}
		if (M[f.x + 1][f.y - 3] != '\\' && vis[f.x + 2][f.y - 6] == false) {
			vis[f.x + 2][f.y - 6] = true;
			Q.push({f.x + 2, f.y - 6, f.t + 1});
		}
		if (M[f.x + 1][f.y + 3] != '/' && vis[f.x + 2][f.y + 6] == false) {
			vis[f.x + 2][f.y + 6] = true;
			Q.push({f.x + 2, f.y + 6, f.t + 1});
		}
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 4 * r + 3; i++)
			for (int j = 0; j < 6 * c + 3; j++)
				vis[i][j] = false;
		while (!Q.empty())
			Q.pop();
		scanf("%d %d", &r, &c);
		getchar();
		for (int i = 0; i < 4 * r + 3; i++)
			gets(M[i]);
		printf("%d\n", BFS());
	}
	return 0;
}