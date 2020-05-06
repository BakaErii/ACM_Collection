/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-05-30 18:40:58
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

const int maxN = 205;
const int INF = 0x3f3f3f3f;

int n, m;
bool vis[maxN];
int E[maxN][maxN];
int arrDis[maxN];

void Init() {
	memset(E, INF, sizeof(E));
	for(int i = 0; i < 205; i++)
		E[i][i] = 0;
	memset(arrDis, INF, sizeof(arrDis));
	memset(vis, 0, sizeof(vis));
	return;
}

void SPFA(int startPos, int endPos) {
	queue<int> Q;
	arrDis[startPos] = 0;
	vis[startPos] = true;
	Q.push(startPos);
	while(!Q.empty()) {
		int f = Q.front();
		Q.pop();
		vis[f] = false;
		for(int i = 0; i < n; i++)
			if(E[f][i] != INF) {
				if(arrDis[i] > arrDis[f] + E[f][i]) {
					arrDis[i] = arrDis[f] + E[f][i];
					if(vis[i] == false) {
						vis[i] = true;
						Q.push(i);
					}
				}
			}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v, x, s, e;
	while(~scanf("%d %d", &n, &m)) {
		Init();
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &x);
			E[u][v] = min(E[u][v], x);
			E[v][u] = min(E[v][u], x);
		}
		scanf("%d %d", &s, &e);
		SPFA(s, e);
		printf("%d\n", arrDis[e] == INF ? -1 : arrDis[e]);
	}
	return 0;
}