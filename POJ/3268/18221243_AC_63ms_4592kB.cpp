/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-13 15:51:33
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

int n, m, x;
int E[maxN][maxN];
int arrDis[maxN];
int arrVis[maxN];
int arrCost[maxN];

void Init() {
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			E[i][j] = i == j ? 0 : INF;
	return;
}

void Dijkstra(int x) {
	int v, minN;
	memset(arrVis, 0, sizeof(arrVis));
	for (int i = 1; i <= n; i++)
		arrDis[i] = E[x][i];
	arrVis[x] = true;
	arrDis[x] = 0;
	for (int i = 1; i < n; i++) {
		minN = INF;
		v = -1;
		for (int j = 1; j <= n; j++)
			if (arrVis[j] == false && arrDis[j] < minN) {
				minN = arrDis[j];
				v = j;
			}
		if (v == -1)
			break;
		arrVis[v] = true;
		for (int j = 1; j <= n; j++)
			if (arrVis[j] == false && arrDis[v] + E[v][j] < arrDis[j])
				arrDis[j] = arrDis[v] + E[v][j];
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v, val;
	scanf("%d %d %d", &n, &m, &x);
	Init();
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &val);
		E[u][v] = val;
	}
	// Solve
	Dijkstra(x);
	for (int i = 1; i <= n; i++)
		arrCost[i] = arrDis[i];
	// Reverse
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			swap(E[i][j], E[j][i]);
	// Solve
	Dijkstra(x);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, arrCost[i] + arrDis[i]);
	printf("%d\n", ans );
	return 0;
}