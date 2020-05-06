/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-17 02:33:04
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

const int maxN = 105;
const int INF = 0x3f3f3f3f * 2;

int E[maxN][maxN];
int arrDis[maxN];
int arrVal[maxN][2];
bool arrVis[maxN];
bool arrReach[maxN];

int levelLimit, n;

void Init() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			E[i][j] = i == j ? 0 : INF;
	return;
}

int Dijkstra(int x) {
	int v, minN, ret = INF;
	memset(arrVis, 0, sizeof(arrVis));
	for (int i = 1; i <= n; i++)
		arrDis[i] = INF;
	arrDis[x] = 0;
	for (int i = 1; i <= n; i++) {
		v = -1;
		minN = INF;
		for (int j = 1; j <= n; j++)
			if (arrReach[j] == true && arrVis[j] == false && arrDis[j] < minN) {
				minN = arrDis[j];
				v = j;
			}
		if (v == -1)
			break;
		arrVis[v] = true;
		for (int j = 1; j <= n; j++)
			if (arrReach[j] == true && arrDis[j] > arrDis[v] + E[v][j])
				arrDis[j] = arrDis[v] + E[v][j];
	}
	for (int i = 1; i <= n; i++) {
		arrDis[i] += arrVal[i][0];
		ret = min(ret, arrDis[i]);
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m, itemId, itemValue, ans = INF;
	scanf("%d %d", &levelLimit, &n);
	Init();
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &arrVal[i][0], &arrVal[i][1], &m);
		for (int j = 0; j < m; j++) {
			scanf("%d %d", &itemId, &itemValue);
			E[i][itemId] = itemValue;
		}
	}
	for (int i = 0; i <= levelLimit; i++) {
		memset(arrReach, 0, sizeof(arrReach));
		for (int j = 1; j <= n; j++)
			if (arrVal[1][1] - levelLimit + i <= arrVal[j][1] && arrVal[j][1] <= arrVal[1][1] + i)
				arrReach[j] = true;
		ans = min(ans, Dijkstra(1));
	}
	printf("%d\n", ans );
	return 0;
}