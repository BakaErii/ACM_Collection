/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-13 15:30:11
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

const int INF = 0x3f3f3f3f;
const int maxN = 1005;

int E[maxN][maxN];
bool arrVis[maxN];
int arrDis[maxN];
int n, m, kase;

void Init() {
	memset(arrVis, 0, sizeof(arrVis));
	memset(E, 0, sizeof(E));
	return;
}

int Dijkstra(int x) {
	int v, maxN, minN;
	for (int i = 1; i <= n; i++)
		arrDis[i] = E[x][i];
	arrVis[x] = true;
	for (int i = 1; i <= n; i++) {
		maxN = 0;
		v = -1;
		for (int j = 1; j <= n; j++)
			if (arrVis[j] == false && arrDis[j] > maxN) {
				maxN = arrDis[j];
				v = j;
			}
		if (v == -1)
			break;
		arrVis[v] = true;
		for (int j = 1; j <= n; j++)
			if (arrVis[j] == false) {
				minN = min(maxN, E[j][v]);
				if (minN > arrDis[j])
					arrDis[j] = minN;
			}
	}
	return arrDis[n];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, u, v, val;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		Init();
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &val);
			E[u][v] = val;
			E[v][u] = val;
		}
		printf("Scenario #%d:\n", ++kase);
		printf("%d\n\n", Dijkstra(1));
	}
	return 0;
}