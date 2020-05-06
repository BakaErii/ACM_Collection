/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-09 15:44:26
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

const int maxN = 10005;

struct Edge
{
	int v, next, w;
} E[maxN << 1];

int n, k, edgeCnt, num, ans, root, maxWeight;
int head[maxN];
int size[maxN];		// 节点的大小
int maxV[maxN];		// 当前节点最大子节点的大小
bool vis[maxN];		// 当前节点是否访问处理过
int dis[maxN];

void Init() {
	ans = 0;
	edgeCnt = 0;
	memset(head, -1, sizeof(head));
	memset(vis, 0, sizeof(vis));
	return;
}

void AddEdge(int u, int v, int w) {
	E[edgeCnt] = {v, head[u], w};
	head[u] = edgeCnt++;
	return;
}

// 计算各个节点的大小
void DFSCalSize(int u, int f) {
	size[u] = 1;
	maxV[u] = 0;
	for (int i = head[u]; i != -1; i = E[i].next) {
		int v = E[i].v;
		if (v == f || vis[v] == true)
			continue;
		DFSCalSize(v, u);
		size[u] += size[v];
		if (size[v] > maxV[u])
			maxV[u] = size[v];
	}
	return;
}

// 计算重心
void DFSCalRoot(int r, int u, int f) {
	if (size[r] - size[u] > maxV[u])
		maxV[u] = size[r] - size[u];
	if (maxV[u] < maxWeight) {
		maxWeight = maxV[u];
		root = u;
	}
	for (int i = head[u]; i != -1; i = E[i].next) {
		int v = E[i].v;
		if (v == f || vis[v] == true)
			continue;
		DFSCalRoot(r, v, u);
	}
	return;
}

// 求各个点到重心的距离
void DFSCalDis(int u, int d, int f) {
	dis[num++] = d;
	for (int i = head[u]; i != -1; i = E[i].next) {
		int v = E[i].v;
		if (v == f || vis[v] == true)
			continue;
		DFSCalDis(v, d + E[i].w, u);
	}
	return;
}

// 求子树有多少点对的距离小于等于k
int CalNum(int u, int d) {
	int ret = 0;
	num = 0;
	DFSCalDis(u, d, -1);
	sort(dis, dis + num);
	int fPtr = 0;
	int bPtr = num - 1;
	while (fPtr < bPtr) {
		while (fPtr < bPtr && dis[bPtr] + dis[fPtr] > k)
			bPtr--;
		ret += bPtr - fPtr;
		fPtr++;
	}
	return ret;
}

// DFS求解分治
void DFS(int x) {
	maxWeight = n;
	DFSCalSize(x, -1);
	DFSCalRoot(x, x, -1);
	ans += CalNum(root, 0);
	vis[root] = true;
	for (int i = head[root]; i != -1; i = E[i].next) {
		int v = E[i].v;
		if (vis[v] == false) {
			ans -= CalNum(v, E[i].w);
			DFS(v);
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v, w;
	while (~scanf("%d %d", &n, &k)) {
		Init();
		if (n == 0 && k == 0)
			return 0;
		for (int i = 0; i < n - 1; i++) {
			scanf("%d %d %d", &u, &v, &w);
			AddEdge(u, v, w);
			AddEdge(v, u, w);
		}
		DFS(1);
		cout << ans << endl;
	}
	return 0;
}