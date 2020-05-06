/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-04-08 19:00:02
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
const int INF = 0x3f3f3f3f;

int n, m, cnt;
vector<int> G[maxN];
int cut[maxN];
int low[maxN];
int dfn[maxN];
int pre[maxN];

void Init() {
	cnt = 0;
	memset(cut, 0, sizeof(cut));
	memset(pre, 0, sizeof(pre));
	memset(G, 0, sizeof(G));
	return;
}

int Tarjan(int u, int fa) {
	int lowU = pre[u] = ++cnt;
	for(int i = 0; i < (int)G[u].size(); i++) {
		int v = G[u][i];
		if(pre[v] == 0) {
			int lowV = Tarjan(v, u);
			lowU = min(lowV, lowU);
			if(lowV >= pre[u])
				cut[u]++;
		} else if(pre[v] < pre[u] && v != fa)
			lowU = min(lowU, pre[v]);
	}
	return low[u] = lowU;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v;
	while(~scanf("%d %d", &n, &m) && n != 0) {
		Init();
		for(int i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int tot = 0;
		int ans = -INF;
		for(int i = 0; i < n; i++) {
			if(pre[i] == 0) {
				tot++;
				Tarjan(i, -1);
				cut[i]--;
			}
		}
		for(int i = 0; i < n; i++)
			ans = max(ans, cut[i]);
		printf("%d\n", tot + ans );
	}
	return 0;
}