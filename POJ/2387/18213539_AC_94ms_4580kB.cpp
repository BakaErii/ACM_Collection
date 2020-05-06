/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-13 01:02:27
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

const int maxN = 1005;
const int INF = 0x3f3f3f3f;

int t, n;
int E[maxN][maxN];
int arrDis[maxN];
bool arrVis[maxN];

void Init() {
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			E[i][j] = i == j ? 0 : INF;
	return;
}

void Dijkstra(int x) {
	int v;
	for (int i = 1; i <= n; i++)
		arrDis[i] = E[x][i];
	arrVis[x] = true;
	v = x;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (arrVis[j] == false && arrDis[v] + E[v][j] < arrDis[j])
				arrDis[j] = arrDis[v] + E[v][j];
		int minDis = INF;
		for (int j = 1; j <= n; j++)
			if (arrVis[j] == false && arrDis[j] < minDis) {
				minDis = arrDis[j];
				v = j;
			}
		arrVis[v] = true;
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v, w;
	scanf("%d %d", &t, &n);
	Init();
	for (int i = 0; i < t; i++) {
		scanf("%d %d %d", &u, &v, &w);
		E[u][v] = min(E[u][v], w);
		E[v][u] = min(E[v][u], w);
	}
	Dijkstra(1);
	printf("%d\n", arrDis[n]);
	return 0;
}