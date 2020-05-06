/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-01-27 01:19:26
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

struct Node
{
	int x, y;
} N[maxN];

struct Edge
{
	int u, v;
	double val;
} E[maxN * maxN];

bool cmp(Edge a, Edge b) {
	return a.val < b.val;
}

int edgeCnt, setCnt;
int arrSet[maxN];
bool isWrong;

int findSet(int x) {
	if (arrSet[x] == x)
		return x;
	arrSet[x] = findSet(arrSet[x]);
	return arrSet[x];
}

void unionSet(int a, int b) {
	int tmpA = findSet(a);
	int tmpB = findSet(b);
	if (tmpB != tmpA)
		arrSet[tmpB] = tmpA;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	double ans;
	scanf("%d", &t);
	while (t--) {
		// INIT
		scanf("%d", &n);
		edgeCnt = 0;
		setCnt = 0;
		ans = 0;
		isWrong = false;
		for (int i = 0; i <= n; i++)
			arrSet[i] = i;
		for (int i = 0; i < n; i++)
			scanf("%d %d", &N[i].x, &N[i].y);
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				double tmpDis = sqrt(abs(N[i].x - N[j].x) * abs(N[i].x - N[j].x) + abs(N[i].y - N[j].y) * abs(N[i].y - N[j].y));
				if (10 <= tmpDis && tmpDis <= 1000) {
					E[edgeCnt].u = i;
					E[edgeCnt].v = j;
					E[edgeCnt].val = tmpDis;
					edgeCnt++;
					E[edgeCnt].u = j;
					E[edgeCnt].v = i;
					E[edgeCnt].val = tmpDis;
					edgeCnt++;
				}
			}
		sort(E, E + edgeCnt, cmp);
		for (int i = 0; i < edgeCnt; i++)
			if (findSet(E[i].u) != findSet(E[i].v)) {
				ans += E[i].val * 100;
				unionSet(E[i].u, E[i].v);
			}
		// Special Judge
		setCnt = findSet(1);
		for (int i = 1; i < n; i++)
			if (findSet(i) != setCnt) {
				isWrong = true;
				break;
			}
		// Output
		if (isWrong)
			printf("oh!\n");
		else
			printf("%.1lf\n", ans );
	}
	return 0;
}