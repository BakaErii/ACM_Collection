/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-18 11:33:35
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

int n, m, edgeCnt;
int arrSet[maxN];

struct Edge
{
	int u, v, val;
	bool operator < (const Edge & e) const {
		return val < e.val;
	}
} E[maxN * maxN];

void Init() {
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
	int u, v;
	scanf("%d", &n);
	Init();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			E[edgeCnt].u = i;
			E[edgeCnt].v = j;
			scanf("%d", &E[edgeCnt].val);
			edgeCnt++;
		}
	sort(E, E + edgeCnt);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		MergeSet(u, v);
	}
	printf("%d\n", Kruskal());
	return 0;
}