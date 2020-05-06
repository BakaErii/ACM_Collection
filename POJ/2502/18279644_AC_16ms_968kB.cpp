/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-16 22:52:32
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
const double INF = 0x3f3f3f3f;

int pointCnt;
double arrDis[maxN];
double E[maxN][maxN];
bool arrVis[maxN];

struct Point
{
	double x, y;
} P[maxN];

double CalDis(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void Init() {
	for (int i = 0; i <= pointCnt; i++)
		arrDis[i] = INF;
	return;
}

void Dijkstra(int x) {
	int v;
	double minN;
	Init();
	for (int i = 0; i < pointCnt; i++)
		arrDis[i] = E[x][i];
	arrDis[x] = 0;
	arrVis[x] = true;
	for (int i = 0; i < pointCnt - 1; i++) {
		minN = INF;
		v = -1;
		for (int j = 0; j < pointCnt; j++)
			if (arrVis[j] == false && arrDis[j] < minN) {
				minN = arrDis[j];
				v = j;
			}
		if (v == -1)
			break;
		arrVis[v] = true;
		for (int j = 0; j < pointCnt; j++)
			if (arrVis[j] == false && arrDis[j] > arrDis[v] + E[v][j])
				arrDis[j] = arrDis[v] + E[v][j];
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int perPointCnt;
	double x, y;
	scanf("%lf %lf %lf %lf", &P[0].x, &P[0].y, &P[1].x, &P[1].y);
	pointCnt = 2;
	perPointCnt = 2;
	while (~scanf("%lf %lf", &x, &y)) {
		if (x == -1 && y == -1) {
			for (int i = perPointCnt; i < pointCnt - 1; i++)
				E[i][i + 1] = E[i + 1][i] = CalDis(P[i], P[i + 1]) / 40000.0;
			perPointCnt = pointCnt;
			continue;
		}
		P[pointCnt++] = {x, y};
	}
	for (int i = 0; i < pointCnt; i++)
		for (int j = 0; j < pointCnt; j++)
			if (E[i][j] == 0)
				E[i][j] = E[j][i] = CalDis(P[i], P[j]) / 10000.0;
	Dijkstra(0);
	printf("%d\n", (int)(arrDis[1] * 60.0 + 0.5));
	return 0;
}