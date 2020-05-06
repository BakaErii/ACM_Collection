/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-08-22 14:01:07
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

const double eps = 1e-7;
const int INF = 66551551;

int doubleCmp(double x) {
	if (fabs(x) < eps)
		return 0;
	else
		return x < 0 ? -1 : 1;
}

struct Point {
	double x, y;
	bool operator < (const Point & a) const {
		return doubleCmp(x - a.x) < 0 || (doubleCmp(x - a.x) == 0 && doubleCmp(y - a.y) < 0);
	}
};

Point operator + (Point a, Point b) {
	return {a.x + b.x, a.y + b.y};
}
Point operator - (Point a, Point b) {
	return {a.x - b.x, a.y - b.y};
}
Point operator * (Point a, double b) {
	return {a.x * b, a.y * b};
}
Point operator / (Point a, double b) {
	return {a.x / b, a.y / b};
}
bool operator == (Point a, Point b) {
	return a.x == b.x && a.y == b.y;
}
double cross(Point a, Point b) {
	return a.x * b.y - a.y * b.x;
}

Point tri[3];
char buf[21];
int dis[405];
bool vis[405];
int arr[21][21];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
vector<int> G[405];
int n, no;

bool isInTriangle(Point a) {
	return doubleCmp(cross(tri[1] - tri[0], a - tri[0])) == 1 && doubleCmp(cross(tri[2] - tri[1], a - tri[1])) == 1 && doubleCmp(cross(tri[0] - tri[2], a - tri[2])) == 1;
}

bool isSegmentInTriangle(Point a, Point b) {
	for (int i = 1; i <= 100; i++) {
		Point tmp = a + (b - a) / 100 * (double)i;
		if (isInTriangle(tmp) == true)
			return false;
	}
	return true;
}

int spfa(int end) {
	queue<int> que;
	for (int i = 2; i <= end; i++)
		dis[i] = INF;
	vis[1] = true;
	dis[1] = 0;
	que.push(1);
	while (!que.empty()) {
		int p = que.front();
		que.pop();
		for (int i = 0; i < (int)G[p].size(); i++) {
			int v = G[p][i];
			if (dis[p] + 1 < dis[v]) {
				dis[v] = dis[p] + 1;
				if (vis[v] == false) {
					que.push(v);
					vis[v] = true;
				}
			}
		}
		vis[p] = false;
	}
	if (dis[end] == INF)
		return -1;
	else
		return dis[end];
}

int main(void) {
	while (~scanf("%d", &n)) {
		//INIT
		no = 0;
		memset(arr, 0, sizeof(arr));
		memset(G, 0, sizeof(G));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < 3; i++)
			scanf("%lf %lf", &tri[i].x, &tri[i].y);
		if (doubleCmp(cross(tri[1] - tri[0], tri[2] - tri[0])) == -1)
			swap(tri[1], tri[2]);
		for (int i = n - 1; i >= 0; i--) {
			scanf("%s", buf);
			for (int j = 0; j < n; j++)
				if (buf[j] == '#' || isInTriangle({(double)j, (double)i}) == true) {
					arr[i][j] = -1;
				}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (arr[i][j] != -1)
					arr[i][j] = ++no;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (arr[i][j] != -1) {
					for (int k = 0; k < 8; k++) {
						int x = i + dx[k];
						int y = j + dy[k];
						if (!(x >= 0 && x < n && y >= 0 && y < n && arr[x][y] != -1))
							continue;
						if (isSegmentInTriangle({(double)j, (double)i}, {(double)y, (double)x})) {
							int u = arr[i][j];
							int v = arr[x][y];
							G[u].push_back(v);
						}
					}
				}
		if (arr[n - 1][n - 1] == -1)
			printf("-1\n");
		else
			printf("%d\n", spfa(arr[n - 1][n - 1]));
	}
	return 0;
}