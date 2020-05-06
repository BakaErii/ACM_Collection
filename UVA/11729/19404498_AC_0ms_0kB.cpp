/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-04-22 22:33:42
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

int n;

struct Node
{
	int b, j;
	bool operator < (const Node & e) const {
		return j > e.j;
	}
};

Node N[maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int kase = 0;
	while (~scanf("%d", &n) && n != 0) {
		int nowCost = 0;
		int ans = 0;
		for (int i = 0; i < n; i++)
			scanf("%d %d", &N[i].b, &N[i].j);
		sort(N, N + n);
		for (int i = 0; i < n; i++) {
			nowCost += N[i].b;
			ans = max(ans, nowCost + N[i].j);
		}
		printf("Case %d: %d\n", ++kase, ans );
	}
	return 0;
}