/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-05 14:09:03
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

LL arr[maxN];
LL arrCost[maxN];
LL arrOp[maxN];

struct Op
{
	int x, y, d;
} O[maxN];

int n, m, k;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &arr[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d %d %d", &O[i].x, &O[i].y, &O[i].d);
	for (int i = 1; i <= k; i++) {
		scanf("%d %d", &x, &y);
		arrOp[x]++;
		arrOp[y + 1]--;
	}
	for (int i = 1; i <= m; i++)
		arrOp[i] = arrOp[i] + arrOp[i - 1];
	for (int i = 1; i <= m; i++) {
		arrCost[O[i].x] += arrOp[i] * O[i].d;
		arrCost[O[i].y + 1] -= arrOp[i] * O[i].d;
	}
	for (int i = 1; i <= n; i++)
		arrCost[i] = arrCost[i] + arrCost[i - 1];
	for (int i = 1; i <= n; i++)
		printf("%lld ", arrCost[i] + arr[i] );
	putchar('\n');
	return 0;
}