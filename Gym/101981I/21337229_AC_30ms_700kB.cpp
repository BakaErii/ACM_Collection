/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-16 12:46:46
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
const int pStart = 0;
const int pK = 1001;
const int pEnd = 1002;

struct Edge
{
	int u, v, c, f;
};

int n, m, k;
vector<Edge> E;
vector<int> G[maxN];
int layer[maxN];
bool vis[maxN];

void AddEdge(int u, int v, int c) {
	E.push_back({u, v, c, 0});
	G[u].push_back((int)E.size() - 1);
	E.push_back({v, u, 0, 0});
	G[v].push_back((int)E.size() - 1);
	return;
}

bool IsExistLayer() {
	queue<int> que;
	memset(vis, 0, sizeof(vis));
	que.push(pStart);
	layer[pStart] = 0;
	vis[pStart] = true;
	while (!que.empty()) {
		int f = que.front();
		que.pop();
		for (int i = 0; i < (int)G[f].size(); i++) {
			Edge & e = E[G[f][i]];
			if (vis[e.v] == false && e.c > e.f) {
				layer[e.v] = layer[f] + 1;
				que.push(e.v);
				vis[e.v] = true;
			}
		}
	}
	return vis[pEnd];
}

int DFS(int x, int flow) {
	int ret = flow;
	if (x == pEnd || flow == 0)
		return flow;
	for (int i = 0; i < (int)G[x].size() && ret > 0; i++) {
		Edge & e = E[G[x][i]];
		if (e.c > e.f && layer[e.v] == layer[x] + 1) {
			int pTmp = DFS(e.v, min(ret, e.c - e.f));
			if (pTmp == 0)
				layer[e.v] = 0;
			e.f += pTmp;
			E[G[x][i] ^ 1].f -= pTmp;
			ret -= pTmp;
		}
	}
	return flow - ret;
}

int Dinic() {
	int ret = 0;
	int nowFlow;
	while (IsExistLayer())
		while (nowFlow = DFS(pStart, INF))
			ret += nowFlow;
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int num, v;
	scanf("%d %d %d", &n, &m, &k);
	AddEdge(pStart, pK, k);
	for (int u = 1; u <= n; u++) {
		scanf("%d", &num);
		AddEdge(pStart, u, 1);
		AddEdge(pK, u, 1);
		for (int i = 0; i < num; i++) {
			scanf("%d", &v);
			AddEdge(u, v + 500, 1);
		}
	}
	for (int i = 501; i <= m + 500; i++)
		AddEdge(i, pEnd, 1);
	printf("%d\n", Dinic());
	return 0;
}