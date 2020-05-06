/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-04-27 13:07:11
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

const int maxN = 505;

int t, n, s, edgeCnt;
double ans;
int arrSet[maxN];

int findSet(int x) {
	if(arrSet[x] == x)
		return x;
	arrSet[x] = findSet(arrSet[x]);
	return arrSet[x];
}

void unionSet(int a, int b) {
	int tmpA = findSet(a);
	int tmpB = findSet(b);
	if(tmpA != tmpB)
		arrSet[tmpB] = tmpA;
	return;
}

void Init() {
	for(int i = 1; i <= n; i++)
		arrSet[i] = i;
	return;
}

struct Edge {
	int u, v;
	double val;
	bool operator < (const Edge & e) const {
		return val < e.val;
	}
} E[maxN * maxN];

struct Node {
	double x, y;
} P[maxN];

double getDis(Node a, Node b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void Kruskal() {
	Init();
	int cnt = 0;
	for(int i = 0; i < edgeCnt; i++) {
		if(findSet(E[i].u) != findSet(E[i].v)) {
			unionSet(E[i].u, E[i].v);
			ans = max(ans, E[i].val);
			cnt++;
		}
		if(cnt > n - s - 1)
			break;
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &t);
	while(t--) {
		edgeCnt = 0;
		scanf("%d %d", &s, &n);
		for(int i = 1; i <= n; i++)
			scanf("%lf %lf", &P[i].x, &P[i].y);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++) {
				E[edgeCnt].u = i;
				E[edgeCnt].v = j;
				E[edgeCnt].val = getDis(P[i], P[j]);
				edgeCnt++;
			}
		sort(E, E + edgeCnt);
		ans = 0;
		Kruskal();
		printf("%.2f\n", ans );
	}
	return 0;
}