/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-17 15:54:43
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

const int maxN = 105;

int n, edgeCnt;
int arrSet[maxN];

struct Edge
{
	int u, v;
	double val;
	bool operator < (const Edge & a) const {
		return val < a.val;
	}
} E[maxN * maxN];

struct Point
{
	double x, y, z, r;
} P[maxN];

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
		arrSet[tmpA] = tmpB;
	return;
}

double Kruskal() {
	// double ret = 0.0;
	// int cnt = 0;
	// for (int i = 0; i < edgeCnt; i++) {
	// 	if (FindSet(E[i].u) != FindSet(E[i].v)) {
	// 		MergeSet(E[i].u, E[i].v);
	// 		ret += E[i].val;
	// 		cnt++;
	// 	}
	// 	if (cnt == n - 1)
	// 		break;
	// }
	double ret = 0.0;
	int cnt = 0;
	for (int i = 0; i < edgeCnt; i++) {
		int p1 = FindSet (E[i].u);
		int p2 = FindSet (E[i].v);
		if (p1 != p2) {
			MergeSet(E[i].u, E[i].v);
			ret += E[i].val;
			cnt++;
		}
		if (cnt == n - 1)
			break;
	}
	return ret;
}

double GetDistance(Point a, Point b) {
	double X = a.x - b.x;
	double Y = a.y - b.y;
	double Z = a.z - b.z;
	double len = sqrt(X * X + Y * Y + Z * Z);
	return len <= a.r + b.r ? 0.0 : len - a.r - b.r;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (~scanf("%d", &n) && n != 0) {
		edgeCnt = 0;
		for (int i = 1; i <= n; i++)
			arrSet[i] = i;
		for (int i = 1; i <= n; i++) {
			scanf("%lf %lf %lf %lf", &P[i].x, &P[i].y, &P[i].z, &P[i].r);
			for (int j = 1; j <= i; j++) {
				E[edgeCnt].u = i;
				E[edgeCnt].v = j;
				E[edgeCnt].val = GetDistance(P[i], P[j]);
				edgeCnt++;
			}
		}
		sort(E, E + edgeCnt);
		printf ("%.3f\n", Kruskal());
	}
	return 0;
}