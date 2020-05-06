/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-14 16:33:35
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

struct Edge
{
	int u, v;
	double rate, cost;
} E[maxN * maxN];

int n, m, startPos, edgeCnt;
double v;
double arrDis[maxN];
bool arrVis[maxN];

bool BF() {
	bool isChange;
	memset(arrDis, 0, sizeof(arrDis));
	arrDis[startPos] = v;
	for (int i = 1; i < n; i++) {
		isChange = false;
		for (int j = 0; j < edgeCnt; j++)
			if (arrDis[E[j].v] < (arrDis[E[j].u] - E[j].cost) * E[j].rate) {
				arrDis[E[j].v] = (arrDis[E[j].u] - E[j].cost) * E[j].rate;
				isChange = true;
			}
		if (isChange == false)
			break;
	}
	for (int i = 0; i < edgeCnt; i++)
		if (arrDis[E[i].v] < (arrDis[E[i].u] - E[i].cost) * E[i].rate)
			return true;
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (~scanf("%d %d %d %lf", &n, &m, &startPos, &v)) {
		edgeCnt = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %lf %lf %lf %lf", &E[edgeCnt].u, &E[edgeCnt].v, &E[edgeCnt].rate, &E[edgeCnt].cost, &E[edgeCnt + 1].rate, &E[edgeCnt + 1].cost);
			E[edgeCnt + 1].v = E[edgeCnt].u;
			E[edgeCnt + 1].u = E[edgeCnt].v;
			edgeCnt += 2;
		}
		if (BF())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}