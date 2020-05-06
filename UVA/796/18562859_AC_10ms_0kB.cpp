/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-03-06 18:40:40
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

const int maxN = 1e6 + 5;

struct Edge {
	int v, nxt;
	bool isCut;
} E[maxN];

int n, edgeCnt, tot, ans;
int head[maxN], nxt[maxN], dfn[maxN], low[maxN], block[maxN];
bool cutPoint[maxN];
vector<pair<int, int>> ansQue;

void Init() {
	tot = 0;
	edgeCnt = 0;
	ans = 0;
	ansQue.clear();
	memset(head, -1, sizeof(head));
	memset(dfn, 0, sizeof(dfn));
	memset(block, 0, sizeof(block));
	memset(cutPoint, 0, sizeof(cutPoint));
	return;
}

void AddEdge(int u, int v) {
	E[edgeCnt] = {v, head[u], false};
	head[u] = edgeCnt++;
	return;
}

void Tarjan(int x, int pre) {
	int sonNum;
	low[x] = dfn[x] = ++tot;
	for(int i = head[x]; i != -1; i = E[i].nxt) {
		if(pre == E[i].v)
			continue;
		if(dfn[E[i].v] == 0) {
			sonNum++;
			Tarjan(E[i].v, x);
			low[x] = min(low[x], low[E[i].v]);
			if(low[E[i].v] > dfn[x]) {
				ans++;
				E[i].isCut = true;
				E[i ^ 1].isCut = true;
				ansQue.push_back(make_pair(min(x, E[i].v), max(x, E[i].v)));
			}
			if(x != pre && low[E[i].v] >= dfn[x]) {
				block[x]++;
				cutPoint[x] = true;
			}
		} else
			low[x] = min(low[x], dfn[E[i].v]);
	}
	if(x == pre && sonNum > 1)
		cutPoint[x] = true;
	if(x == pre)
		block[x] = sonNum - 1;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v, edgeNum;
	while(~scanf("%d", &n)) {
		Init();
		// Input
		for(int i = 0; i < n; i++) {
			scanf("%d", &u);
			getchar();
			getchar();
			scanf("%d", &edgeNum);
			getchar();
			for(int j = 0; j < edgeNum; j++) {
				scanf("%d", &v);
				AddEdge(u, v);
				AddEdge(v, u);
			}
		}
		// Solve
		for(int i = 0; i < n; i++)
			if(dfn[i] == 0)
				Tarjan(i, i);
		sort(ansQue.begin(), ansQue.end());
		printf("%d critical links\n", ans);
		for(int i = 0; i < (int)ansQue.size(); i++)
			printf("%d - %d\n", ansQue[i].first, ansQue[i].second);
		putchar('\n');
	}
	return 0;
}