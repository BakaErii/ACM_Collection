/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-01-21 01:22:47
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
const int maxW = 5500;
const int INF = 0x3f3f3f3f;

int f, n, m, w;
int edgeCnt;

struct Edge
{
	int u, v;
	int val;
} E[maxW];

bool BF(void) {
	int arrDis[maxN];
	bool isChange;
	memset(arrDis, INF, sizeof(arrDis));
	arrDis[1] = 0;
	for (int i = 0; i < n - 1; i++) {
		isChange = false;
		for (int j = 0; j < edgeCnt; j++)
			if (arrDis[E[j].v] > arrDis[E[j].u] + E[j].val) {
				arrDis[E[j].v] = arrDis[E[j].u] + E[j].val;
				isChange = true;
			}
		if (!isChange)
			return false;
	}
	// Rejudge
	for (int j = 0; j < edgeCnt; j++)
		if (arrDis[E[j].v] > arrDis[E[j].u] + E[j].val)
			return true;
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &f);
	while (f--) {
		// Init
		edgeCnt = 0;
		// Input
		scanf("%d %d %d", &n, &m, &w);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &E[edgeCnt].u, &E[edgeCnt].v, &E[edgeCnt].val);
			edgeCnt++;
			E[edgeCnt].u = E[edgeCnt - 1].v;
			E[edgeCnt].v = E[edgeCnt - 1].u;
			E[edgeCnt].val = E[edgeCnt - 1].val;
			edgeCnt++;
		}
		for (int i = 0; i < w; i++) {
			scanf("%d %d %d", &E[edgeCnt].u, &E[edgeCnt].v, &E[edgeCnt].val);
			E[edgeCnt].val = -E[edgeCnt].val;
			edgeCnt++;
		}
		// Solve
		if (BF())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}