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
	que.push(0);
	layer[0] = 0;
	vis[0] = true;
	while (!que.empty()) {
		int f = que.front();
		que.pop();
		for (int i = 0; i < (int)G[f].size(); i++) {
			Edge & e = E[G[f][i]];
			if (!vis[e.v] && e.c > e.f) {
				layer[e.v] = layer[f] + 1;
				que.push(e.v);
				vis[e.v] = true;
			}
		}
	}
	return vis[n + m + 2];
}

int DFS(int x, int flow) {
	int ret = flow;
	if (x == n + m + 2 || flow == 0)
		return flow;
	for (int i = 0; ret > 0 && i < (int)G[x].size() ; i++) {
		Edge & e = E[G[x][i]];
		if (e.c > e.f && layer[e.v] == layer[x] + 1) {
			int pTmp = DFS(e.v, min(ret, e.c - e.f));
			if (!pTmp)
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
	int nowFlow = 0;
	while (IsExistLayer()) {
		// cout<<"layer"<<endl;
		while (nowFlow = DFS(0, INF)) {
			ret += nowFlow;
			// cout<<"flow"<<endl;
			// cout << ret << endl;
		}
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int num, v;
	scanf("%d %d %d", &n, &m, &k);
	AddEdge(0, n + m + 1, k);
	for (int u = 1; u <= n; u++) {
		scanf("%d", &num);
		AddEdge(0, u, 1);
		AddEdge(n + m + 1, u, 1);
		for (int i = 0; i < num; i++) {
			scanf("%d", &v);
			AddEdge(u, n + v, 1);
		}
	}
	for (int i = 1; i <= m; i++)
		AddEdge(n + i, n + m + 2, 1);
	printf("%d\n", Dinic());
	return 0;
}