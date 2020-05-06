/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-16 13:22:33
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

const int maxN = 30005;
const int maxM = 150005;
const int INF = 0x3f3f3f3f;

int n, m, edgeCnt;
int arrDis[maxN];
int head[maxM];
bool arrVis[maxN];

struct Edge
{
	int v, val, nxt;
} E[maxM];

struct Node
{
	int u, d;
	bool operator < (const Node & p) const {
		return d > p.d;
	}
};

void Init() {
	for (int i = 0; i <= n; i++) {
		arrVis[i] = false;
		arrDis[i] = INF;
		head[i] = -1;
	}
	return;
}

void Dijkstra(int x) {
	priority_queue<Node> que;
	que.push({x, 0});
	arrDis[x] = 0;
	while (!que.empty()) {
		Node f = que.top();
		que.pop();
		if (arrVis[f.u] == true)
			continue;
		arrVis[f.u] = true;
		for (int i = head[f.u]; i != -1; i = E[i].nxt)
			if (arrVis[E[i].v] == false && arrDis[E[i].v] > arrDis[f.u] + E[i].val) {
				arrDis[E[i].v] = arrDis[f.u] + E[i].val;
				que.push({E[i].v, arrDis[E[i].v]});
			}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v, val;
	scanf("%d %d", &n, &m);
	Init();
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &val);
		E[edgeCnt].v = v;
		E[edgeCnt].val = val;
		E[edgeCnt].nxt = head[u];
		head[u] = edgeCnt++;
	}
	Dijkstra(1);
	printf("%d\n", arrDis[n]);
	return 0;
}