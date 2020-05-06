/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-19 23:38:48
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

const int maxN = 55;
const int maxM = 105;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int t, n, m, pointCnt, edgeCnt;
char arrMap[maxN][maxN];
int arrIdx[maxN][maxN];
bool arrVis[maxN][maxN];
int arrSet[maxM];

struct Edge
{
	int u, v, val;
	bool operator < (const Edge & e) const {
		return val < e.val;
	}
} E[maxM * maxM];

struct Node
{
	int x, y, val;
};

void Init() {
	pointCnt = 0;
	edgeCnt = 0;
	for (int i = 0; i < maxM; i++)
		arrSet[i] = i;
	return;
}

int FindSet(int x) {
	return arrSet[x] == x ? x : arrSet[x] = FindSet(arrSet[x]);
}

void MergeSet(int a, int b) {
	int tmpA = FindSet(a);
	int tmpB = FindSet(b);
	if (tmpA != tmpB)
		arrSet[tmpB] = tmpA;
	return;
}

void BFS(int x, int y) {
	queue<Node> que;
	// Init
	memset(arrVis, 0, sizeof(arrVis));
	que.push({x, y, 0});
	arrVis[x][y] = true;
	while (!que.empty()) {
		Node f = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int X = f.x + dx[i];
			int Y = f.y + dy[i];
			if (X >= 0 && Y >= 0 && X < m && Y < n && arrMap[X][Y] != '#' && arrVis[X][Y] == false) {
				if (arrMap[X][Y] == 'S' || arrMap[X][Y] == 'A')
					E[edgeCnt++] = {arrIdx[x][y], arrIdx[X][Y], f.val + 1};
				que.push({X, Y, f.val + 1});
				arrVis[X][Y] = true;
			}
		}
	}
	return;
}

int Kruskal() {
	int ret = 0;
	int cnt = 0;
	for (int i = 0; i < edgeCnt; i++) {
		if (FindSet(E[i].u) != FindSet(E[i].v)) {
			MergeSet(E[i].u, E[i].v);
			ret += E[i].val;
			cnt++;
		}
		if (cnt == pointCnt - 1)
			break;
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	char str[1551];
	scanf("%d", &t);
	while (t--) {
		Init();
		scanf("%d %d", &n, &m);
		gets(str);
		for (int i = 0; i < m; i++)
			gets(arrMap[i]);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (arrMap[i][j] == 'S' || arrMap[i][j] == 'A')
					arrIdx[i][j] = pointCnt++;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (arrMap[i][j] == 'S' || arrMap[i][j] == 'A')
					BFS(i, j);
		sort(E, E + edgeCnt);
		printf("%d\n", Kruskal());
	}
	return 0;
}