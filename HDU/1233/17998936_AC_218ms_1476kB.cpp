/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-01-27 01:04:44
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
	int u, v, val;
} E[maxN * maxN];

bool cmp(Edge a, Edge b) {
	return a.val < b.val;
}

int arrSet[maxN];

int findSet(int x) {
	if (arrSet[x] == x)
		return x;
	arrSet[x] = findSet(arrSet[x]);
	return arrSet[x];
}

void unionSet(int a, int b) {
	int tmpA = findSet(a);
	int tmpB = findSet(b);
	if (tmpA != tmpB)
		arrSet[tmpB] = tmpA;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int ans;
	while (~scanf("%d", &n) && n != 0) {
		// INIT
		ans = 0;
		for (int i = 0; i <= n; i++)
			arrSet[i] = i;
		for (int i = 0; i < n * (n - 1) / 2; i++)
			scanf("%d %d %d", &E[i].u, &E[i].v, &E[i].val);
		sort(E, E + (n * (n - 1) / 2), cmp);
		for (int i = 0; i < n * (n - 1) / 2; i++)
			if (findSet(E[i].u) != findSet(E[i].v)) {
				ans += E[i].val;
				unionSet(E[i].u, E[i].v);
			}
		printf("%d\n", ans );
	}
	return 0;
}