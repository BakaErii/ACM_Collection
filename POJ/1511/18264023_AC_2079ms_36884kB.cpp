/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-15 15:25:47
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

#define LL long long int

const int maxN = 1000005;
const int INF = 0x3f3f3f3f;

int n, m, edgeCnt;
int head[maxN];
int arrMap[maxN][3];
LL arrDis[maxN];
bool arrVis[maxN];

struct Edge
{
	int v, val, nxt;
} E[maxN];

struct Node
{
	int u, d;
	bool operator < (const Node & p) const {
		return d > p.d;
	}
};

void Init() {
	edgeCnt = 0;
	for (int i = 1; i <= n; i++) {
		head[i] = -1;
		arrVis[i] = false;
		arrDis[i] = INF;
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
		for (int i = head[f.u]; ~i; i = E[i].nxt) {
			if (arrVis[E[i].v] == false && arrDis[E[i].v] > arrDis[f.u] + E[i].val) {
				arrDis[E[i].v] = arrDis[f.u] + E[i].val;
				que.push({E[i].v, (int)arrDis[E[i].v]});
			}
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	LL ans;
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++)
			scanf("%d %d %d", &arrMap[i][0], &arrMap[i][1], &arrMap[i][2]);
		Init();
		for (int i = 0; i < m; i++) {
			E[edgeCnt] = {arrMap[i][1], arrMap[i][2], head[arrMap[i][0]]};
			head[arrMap[i][0]] = edgeCnt++;
		}
		Dijkstra(1);
		for (int i = 1; i <= n; i++)
			ans += arrDis[i];
		Init();
		for (int i = 0; i < m; i++) {
			E[edgeCnt] = {arrMap[i][0], arrMap[i][2], head[arrMap[i][1]]};
			head[arrMap[i][1]] = edgeCnt++;
		}
		Dijkstra(1);
		for (int i = 1; i <= n; i++)
			ans += arrDis[i];
		printf("%lld\n", ans );
	}
	return 0;
}