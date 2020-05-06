/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-04-28 19:42:19
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
const int maxM = maxN * maxN;
const int INF = 0x3f3f3f3f;

int n, m, ans;
int arrSet[maxN];

struct Edge
{
	int u, v, val;
	bool operator < (const Edge & e) const {
		return val < e.val;
	}
} E[maxM];

void Init() {
	for (int i = 0; i < maxN; i++)
		arrSet[i] = i;
	return;
}

int findSet(int x) {
	if (arrSet[x] == x)
		return x;
	arrSet[x] = findSet(arrSet[x]);
	return arrSet[x];
}

void mergeSet(int a, int b) {
	int tmpA = findSet(a);
	int tmpB = findSet(b);
	if (tmpA != tmpB)
		arrSet[tmpA] = tmpB;
	return;
}

void Kruskal() {
	int cnt;
	for (int i = 0; i < m; i++) {
		Init();
		cnt = 0;
		for (int j = i; j < m; j++) {
			if (findSet(E[j].u) != findSet(E[j].v)) {
				mergeSet(E[j].u, E[j].v);
				cnt++;
			}
			if (cnt == n - 1) {
				ans = min(ans, E[j].val - E[i].val);
				break;
			}
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (~scanf("%d %d", &n, &m)) {
		if (n == 0 && m == 0)
			return 0;
		// Init
		ans = INF;
		for (int i = 0; i < m; i++)
			scanf("%d %d %d", &E[i].u, &E[i].v, &E[i].val);
		sort(E, E + m);
		Kruskal();
		printf("%d\n", ans == INF ? -1 : ans );
	}
	return 0;
}