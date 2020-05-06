/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-04-29 19:28:09
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

const int maxN = 205;

int a, b, m;
int E[maxN][maxN];
int linker[maxN];
int used[maxN];

int dfs(int pos) {
	for(int i = 1; i <= b; i++)
		if(E[pos][i] == 0 && used[i] == 0) {
			used[i] = 1;
			if(linker[i] == -1 || dfs(linker[i]) == 1) {
				linker[i] = pos;
				return 1;
			}
		}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v, cnt, kase = 0;
	while(~scanf("%d %d %d", &a, &b, &m)) {
		if(a == 0 && b == 0 && m == 0)
			return 0;
		// INIT
		cnt = 0;
		memset(E, 0, sizeof(E));
		memset(linker, -1, sizeof(linker));
		for(int i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			E[u][v] = 1;
		}
		for(int i = 1; i <= a; i++) {
			memset(used, 0, sizeof(used));
			cnt += dfs(i);
		}
		printf("Case %d: %d\n", ++kase, a + b - cnt);
	}
	return 0;
}