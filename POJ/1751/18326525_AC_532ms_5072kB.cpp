/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-19 23:25:52
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

const int maxN = 755;

int n, m, edgeCnt;
int arrSet[maxN];

struct Edge
{
	int u, v;
	double val;
	bool operator < (const Edge & e) const {
		return val < e.val;
	}
} E[maxN * maxN];

struct Point
{
	double x, y;
} P[maxN];

void Init() {
	edgeCnt = 0;
	for (int i = 1; i <= n; i++)
		arrSet[i] = i;
	return;
}

double GetDistance(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int FindSet(int x) {
	return arrSet[x] == x ? x : arrSet[x] = FindSet(arrSet[x]);
}

void MergeSet(int a, int b) {
	int tmpA = FindSet(a);
	int tmpB = FindSet(b);
	if (tmpA != tmpB)
		arrSet[tmpB] = tmpA;
	return;
}

void Kruskal() {
	int cnt = 0;
	for (int i = 0; i < edgeCnt; i++) {
		if (FindSet(E[i].u) != FindSet(E[i].v)) {
			MergeSet(E[i].u, E[i].v);
			printf("%d %d\n", E[i].u, E[i].v );
			cnt++;
		}
		if (cnt == n - 1)
			break;
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v;
	scanf("%d", &n);
	Init();
	for (int i = 1; i <= n; i++)
		scanf("%lf %lf", &P[i].x, &P[i].y);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			E[edgeCnt++] = {i, j, GetDistance(P[i], P[j])};
	sort(E, E + edgeCnt);
	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &u, &v);
		MergeSet(u, v);
	}
	Kruskal();
	return 0;
}