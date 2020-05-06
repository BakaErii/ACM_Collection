/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-17 15:35:13
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
const int INF = 0x3f3f3f3f;

int n, a, b;
int E[maxN][maxN];
int arrDis[maxN];
bool arrVis[maxN];

void Init() {
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			E[i][j] = i == j ? 0 : INF;
	for (int i = 0; i <= n; i++) {
		arrDis[i] = INF;
		arrVis[i] = false;
	}
	return;
}

void SPFA(int x) {
	queue<int> que;
	arrDis[x] = 0;
	arrVis[x] = true;
	que.push(x);
	while (!que.empty()) {
		int f = que.front();
		que.pop();
		arrVis[f] = false;
		for (int i = 1; i <= n; i++)
			if (arrDis[i] > arrDis[f] + E[f][i]) {
				arrDis[i] = arrDis[f] + E[f][i];
				if (arrVis[i] == false) {
					arrVis[i] = true;
					que.push(i);
				}
			}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tmpNum, tmpV;
	scanf("%d %d %d", &n, &a, &b);
	Init();
	for (int i = 1; i <= n; i++) {
		scanf("%d", &tmpNum);
		for (int j = 0; j < tmpNum; j++) {
			scanf("%d", &tmpV);
			E[i][tmpV] = j == 0 ? 0 : 1;
		}
	}
	SPFA(a);
	printf("%d\n", arrDis[b] == INF ? -1 : arrDis[b]);
	return 0;
}