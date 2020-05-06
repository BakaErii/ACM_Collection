/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-02 17:36:22
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

const int maxN = 55;
const int INF = 0x3f3f3f3f;

int n, m, ans;

struct Edge
{
	int u, v, val;
} E[maxN * maxN];

int edgeCnt;

bool cmp(Edge a, Edge b) {
	return a.val < b.val;
}

int arr[maxN][maxN];
int arrSet[maxN];

void Init() {
	ans = 0;
	edgeCnt = 0;
	memset(arr, INF, sizeof(arr));
	for (int i = 0; i < maxN; i++)
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

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v, val;
	while (~scanf("%d", &n) && n != 0) {
		scanf("%d", &m);
		// Init
		Init();
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &val);
			arr[u][v] = min(arr[u][v], val);
		}
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				if (arr[i][j] != INF)
					E[edgeCnt++] = {i, j, arr[i][j]};
		// Solve
		sort(E, E + edgeCnt, cmp);
		for (int i = 0; i < edgeCnt; i++)
			if (FindSet(E[i].u) != FindSet(E[i].v)) {
				MergeSet(E[i].u, E[i].v);
				ans += E[i].val;
			}
		printf("%d\n", ans );
	}
	return 0;
}