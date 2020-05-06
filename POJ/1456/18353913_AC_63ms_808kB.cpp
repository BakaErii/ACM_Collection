/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-21 17:45:34
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

const int maxN = 10005;

struct Node
{
	int p, d;
	bool operator < (const Node & e) const{
		return p > e.p;
	}
} N[maxN];

int n;
int arrSet[maxN];

int FindSet(int x) {
	return arrSet[x] == -1 ? x : arrSet[x] = FindSet(arrSet[x]);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int p, ans;
	while (~scanf("%d", &n)) {
		memset(arrSet, -1, sizeof(arrSet));
		ans = 0;
		for (int i = 0; i < n; i++)
			scanf("%d %d", &N[i].p, &N[i].d);
		sort(N, N + n);
		for (int i = 0; i < n; i++) {
			p = FindSet(N[i].d);
			if (p > 0) {
				arrSet[p] = p - 1;
				ans += N[i].p;
			}
		}
		printf("%d\n", ans );
	}
	return 0;
}