/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-29 11:30:22
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
const int maxT = 1005;

struct Herb
{
	int val;
	int time;
} H[maxN];

int arrDp[maxN][maxT];
int t, n, ans;

void Solve() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= t; j++) {
			if (j < H[i].time)
				arrDp[i][j] = arrDp[i-1][j];
			else
				arrDp[i][j] = max(arrDp[i - 1][j], arrDp[i - 1][j - H[i].time] + H[i].val);
			ans = max(ans, arrDp[i][j]);
		}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &t, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &H[i].time, &H[i].val);
	Solve();
	printf("%d\n", ans);
	return 0;
}