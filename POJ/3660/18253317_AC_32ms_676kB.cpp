/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-15 15:04:17
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
const int INF = 0x3f3f3f3f;

int n, m;
int E[maxN][maxN];

void Floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (E[i][j] == 0 && E[i][k] == E[k][j] && E[i][k] != 0)
					E[i][j] = E[i][k];
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v;
	int reachNum, unReachNum, ans;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		E[u][v] = 1;
		E[v][u] = -1;
	}
	Floyd();
	ans = 0;
	for (int i = 1; i <= n; i++) {
		reachNum = 0;
		unReachNum = 0;
		for (int j = 1; j <= n; j++)
			if (j != i) {
				if (E[i][j] == 1)
					reachNum++;
				else if (E[i][j] == -1)
					unReachNum++;
			}
		if (reachNum + unReachNum == n - 1)
			ans++;
	}
	printf("%d\n", ans );
	return 0;
}