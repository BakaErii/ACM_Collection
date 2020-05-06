/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-22 00:14:13
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
const int INF = 0x3f3f3f3f;

int n, m;
int arrSet[maxN];
int arrMST[maxN];

struct Edge
{
	int u, v, val;
	bool operator < (const Edge & e) const {
		return val < e.val;
	}
} E[maxN * maxN];

void Init() {
	for (int i = 0; i <= n; i++)
		arrSet[i] = i;
	return;
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
	int ans = 0;
	int min2Ans = INF;
	int edgeCnt = 0;
	int perAns;
	Init();
	for (int i = 0; i < m; i++)
		if (FindSet(E[i].u) != FindSet(E[i].v)) {
			MergeSet(E[i].u, E[i].v);
			ans += E[i].val;
			arrMST[edgeCnt++] = i;
		}
	for (int i = 0; i < n - 1; i++) {
		Init();
		edgeCnt = 0;
		perAns = 0;
		for (int j = 0; j < m; j++) {
			if (arrMST[i] == j)
				continue;
			if (FindSet(E[j].u) != FindSet(E[j].v)) {
				MergeSet(E[j].u, E[j].v);
				perAns += E[j].val;
				edgeCnt++;
			}
			if (edgeCnt == n - 1) {
				min2Ans = min(min2Ans, perAns);
				break;
			}
		}
	}
	printf("%d %d\n", ans, min2Ans == INF ? ans : min2Ans );
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++)
			scanf("%d %d %d", &E[i].u, &E[i].v, &E[i].val);
		sort(E, E + m);
		Kruskal();
	}
	return 0;
}