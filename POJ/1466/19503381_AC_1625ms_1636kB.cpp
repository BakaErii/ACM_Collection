/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-04-29 19:01:57
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

const int maxN = 505;

int n;
int E[maxN][maxN];
int linker[maxN];
int used[maxN];

int dfs(int pos) {
	for(int i = 0; i < n; i++)
		if(E[pos][i] == 1 && used[i] == false) {
			used[i] = true;
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
	int u, v, m, cnt;
	while(~scanf("%d", &n)) {
		// INIT
		cnt = 0;
		memset(E, 0, sizeof(E));
		memset(linker, -1, sizeof(linker));
		for(int i = 0; i < n; i++) {
			scanf("%d: (%d)", &u, &m);
			for(int j = 0; j < m; j++) {
				scanf("%d", &v);
				E[u][v] = 1;
			}
		}
		for(int i = 0; i < n; i++) {
			memset(used, 0, sizeof(used));
			cnt += dfs(i);
		}
		printf("%d\n", n - cnt / 2 );
	}
	return 0;
}