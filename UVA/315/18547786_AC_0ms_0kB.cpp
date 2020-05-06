/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-03-05 20:09:02
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

vector<int> E[maxN];
stack<int> S;
int dfn[maxN];
int low[maxN];
int fa[maxN];
int cut[maxN];
bool vis[maxN];
int t, n, ans, tot;

void Init() {
	ans = 0;
	tot = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(E, 0, sizeof(E));
	memset(vis, 0, sizeof(vis));
	memset(cut, 0, sizeof(cut));
	memset(fa, 0, sizeof(fa));
	return;
}

void Tarjan(int x, int u) {
	dfn[x] = low[x] = ++tot;
	fa[x] = u;
	for(int i = 0; i < (int)E[x].size(); i++) {
		int v = E[x][i];
		if(dfn[v] == 0) {
			Tarjan(v, x);
			low[x] = min(low[x], low[v]);
		} else if(u != v)
			low[x] = min(low[x], dfn[v]);
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int v;
	char ch;
	while(~scanf("%d", &t) && t != 0) {
		Init();
		while(~scanf("%d", &n) && n != 0)
			while(~scanf("%d%c", &v, &ch)) {
				E[n].push_back(v);
				E[v].push_back(n);
				if(ch == '\n')
					break;
			}
		int sonNum = 0;
		Tarjan(1, 0);
		for(int i = 2; i <= t; i++) {
			int v = fa[i];
			if(v == 1)
				sonNum++;
			else if(dfn[v] <= low[i])
				cut[v] = true;
		}
		for(int i = 2; i <= t; i++)
			if(cut[i] == true)
				ans++;
		if(sonNum > 1)
			ans++;
		printf("%d\n", ans );
	}
	return 0;
}