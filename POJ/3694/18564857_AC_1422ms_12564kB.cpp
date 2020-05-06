/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-03-06 19:24:16
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

const int maxN = 200005;
const int maxM = 400010;

int n, m, addNum, edgeCnt, ans, tot, kase;
int head[maxM];
int dfn[maxN], low[maxN], arrSet[maxN], fa[maxN];
bool vis[maxN];

struct Edge {
	int v, nxt;
} E[maxM];

void AddEdge(int u, int v) {
	E[edgeCnt] = {v, head[u]};
	head[u] = edgeCnt++;
}

void Init() {
	ans = 0;
	edgeCnt = 0;
	tot = 0;
	fa[1] = 1;
	for(int i = 0; i <= n; i++)
		arrSet[i] = i;
	memset(head, -1, sizeof(head));
	memset(low, 0, sizeof(low));
	memset(dfn, 0, sizeof(dfn));
	memset(vis, 0, sizeof(vis));
	return;
}

int FindSet(int x) {
	return arrSet[x] == x ? x : arrSet[x] = FindSet(arrSet[x]);
}

bool MergeSet(int a, int b) {
	int tmpA = FindSet(a);
	int tmpB = FindSet(b);
	if(tmpA != tmpB) {
		arrSet[tmpA] = tmpB;
		return true;
	}
	return false;
}

void Tarjan(int x, int pre) {
	low[x] = dfn[x] = ++tot;
	vis[x] = true;
	for(int i = head[x]; i != -1; i = E[i].nxt) {
		int v = E[i].v;
		if(pre == v)
			continue;
		if(vis[v] == false) {
			fa[v] = x;
			Tarjan(v, x);
			low[x] = min(low[x], low[v]);
			if(low[v] > dfn[x])
				ans++;
			else
				MergeSet(v, x);
		} else
			low[x] = min(low[x], dfn[v]);
	}
	return;
}

void LCA(int u, int v) {
	if(dfn[v] < dfn[u])
		swap(u, v);
	while(dfn[v] > dfn[u]) {
		if(MergeSet(v, fa[v]) == true)
			ans--;
		v = fa[v];
	}
	while(u != v) {
		if(MergeSet(u, fa[u]) == true)
			ans--;
		u = fa[u];
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v;
	while(~scanf("%d %d", &n, &m)) {
		if(n == 0 && m == 0)
			break;
		Init();
		// Input
		for(int i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			AddEdge(u, v);
			AddEdge(v, u);
		}
		// Solve
		Tarjan(1, 1);
		printf("Case %d:\n", ++kase );
		scanf("%d", &addNum);
		for(int i = 0; i < addNum; i++) {
			scanf("%d %d", &u, &v);
			LCA(u, v);
			printf("%d\n", ans );
		}
		putchar('\n');
	}
	return 0;
}