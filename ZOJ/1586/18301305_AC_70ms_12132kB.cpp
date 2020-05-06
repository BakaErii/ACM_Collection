/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-18 11:54:25
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

const int maxN = 1005;

int n, edgeCnt;
int arrCost[maxN];
int arrSet[maxN];

struct Edge
{
	int u, v, val;
	bool operator < (const Edge & e) const {
		return val < e.val;
	}
} E[maxN * maxN];

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

void Init() {
	edgeCnt = 0;
	for (int i = 0; i <= n; i++)
		arrSet[i] = i;
	return;
}

int Kruskal() {
	int ret = 0;
	for (int i = 0; i < edgeCnt; i++)
		if (FindSet(E[i].u) != FindSet(E[i].v)) {
			MergeSet(E[i].u, E[i].v);
			ret += E[i].val;
		}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		Init();
		for (int i = 1; i <= n; i++)
			scanf("%d", &arrCost[i]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				E[edgeCnt].u = i;
				E[edgeCnt].v = j;
				scanf("%d", &E[edgeCnt].val);
				E[edgeCnt].val += arrCost[i] + arrCost[j];
				edgeCnt++;
			}
		sort(E, E + edgeCnt);
		printf("%d\n", Kruskal() );
	}
	return 0;
}