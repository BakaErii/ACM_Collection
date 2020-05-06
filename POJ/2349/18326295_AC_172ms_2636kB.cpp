/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-18 12:05:23
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

int s, n, edgeCnt;
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

int FindSet(int x) {
	if (arrSet[x] == x)
		return x;
	arrSet[x] = FindSet(arrSet[x]);
	return arrSet[x];
}

void MergeSet(int a, int b) {
	int tmpA = FindSet(a);
	int tmpB = FindSet(b);
	if (tmpA != tmpB)
		arrSet[tmpB] = tmpA;
	return;
}

double GetDistance(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double Kruskal() {
	double ret = 0;
	int cnt = 0;
	for (int i = 0; i < edgeCnt; i++) {
		if (FindSet(E[i].u) != FindSet(E[i].v)) {
			MergeSet(E[i].u, E[i].v);
			ret = max(ret, E[i].val);
			cnt++;
		}
		if (cnt > n - 1 - s)
			break;
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &s, &n);
		Init();
		for (int i = 1; i <= n; i++)
			scanf("%lf %lf", &P[i].x, &P[i].y);
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) {
				E[edgeCnt].u = i;
				E[edgeCnt].v = j;
				E[edgeCnt].val = GetDistance(P[i], P[j]);
				edgeCnt++;
			}
		sort(E, E + edgeCnt);
		printf("%.2f\n", Kruskal());
	}
	return 0;
}