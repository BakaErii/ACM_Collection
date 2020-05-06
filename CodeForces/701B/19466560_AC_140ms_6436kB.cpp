/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-04-27 09:15:57
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

typedef long long int LL;

const int maxN = 100005;

int n, m;
set<int> row, col;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		row.insert(x);
		col.insert(y);
		LL ans = ((LL)n - row.size()) * ((LL)n - col.size());
		printf("%lld ", ans);
	}
	putchar('\n');
	return 0;
}