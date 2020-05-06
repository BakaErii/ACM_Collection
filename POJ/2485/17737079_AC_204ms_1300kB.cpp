/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-01-16 00:10:58
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

int arr[maxN][maxN];
int unionSet[maxN];

struct Edge
{
	int u, v, val;
} E[maxN * maxN];

bool cmp(Edge a, Edge b) {
	return a.val < b.val;
}

void init(int n) {
	for (int i = 0; i < n; i++)
		unionSet[i] = i;
	return;
}

int findSet(int x) {
	if (unionSet[x] == x)
		return x;
	unionSet[x] = findSet(unionSet[x]);
	return unionSet[x];
}

void mergeSet(int a, int b) {
	int tmpA = findSet(a);
	int tmpB = findSet(b);
	if (tmpA != tmpB)
		unionSet[tmpB] = tmpA;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, edgeCnt, maxVal;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		// INIT
		edgeCnt = 0;
		maxVal = 0;
		init(n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &arr[i][j]);
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				E[edgeCnt++] = {i, j, arr[i][j]};
		sort(E, E + edgeCnt, cmp);
		// Generate
		for (int i = 0; i < edgeCnt; i++)
			if (findSet(E[i].u) != findSet(E[i].v)) {
				mergeSet(E[i].u, E[i].v);
				maxVal = max(maxVal, E[i].val);
			}
		printf("%d\n", maxVal);
	}
	return 0;
}