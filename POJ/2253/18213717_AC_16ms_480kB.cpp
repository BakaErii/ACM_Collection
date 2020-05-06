/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-13 01:27:20
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

const int maxN = 205;
const double INF = 23333;

int n, kase;
double ans;
double E[maxN][maxN];
double arrDis[maxN];
bool arrVis[maxN];

struct Point
{
	double x, y;
} P[maxN];

double calDis(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void Dijkstra(int x) {
	int v;
	double minN;
	// Init
	ans = 0;
	for (int i = 1; i <= n; i++) {
		arrDis[i] = E[x][i];
		arrVis[i] = false;
	}
	arrDis[x] = 0;
	arrVis[x] = true;
	for (int i = 1; i <= n; i++) {
		minN = INF;
		for (int j = 1; j <= n; j++)
			if (arrVis[j] == false && arrDis[j] < minN) {
				minN = arrDis[j];
				v = j;
			}
		arrVis[v] = true;
		if (ans < arrDis[v] && arrDis[v] != INF)
			ans = arrDis[v];
		if (v == 2)
			return;
		for (int j = 1; j <= n; j++)
			if (arrVis[j] == false)
				arrDis[j] = min(arrDis[j], E[v][j]);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (~scanf("%d", &n) && n != 0) {
		for (int i = 1; i <= n; i++)
			scanf("%lf %lf", &P[i].x, &P[i].y);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				E[i][j] = i == j ? 0 : calDis(P[i], P[j]);
		Dijkstra(1);
		printf("Scenario #%d\n", ++kase );
		printf("Frog Distance = %.3lf\n\n", ans );
	}
	return 0;
}