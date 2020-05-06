/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-07 14:06:15
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

int n, m;
int arr[maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y, ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		ans += min(arr[x], arr[y]);
	}
	printf("%d\n", ans );
	return 0;
}