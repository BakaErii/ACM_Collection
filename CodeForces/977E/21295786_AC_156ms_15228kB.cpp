/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-14 15:19:18
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

const int maxN = 200005;

vector<int> E[maxN];
bool vis[maxN];
int n, m, ans;

bool isOK;
void DFS(int st, int x, int fa) {
	if (x == st && fa != -1) {
		if (isOK == true)
			ans++;
	}
	if ((int)E[x].size() != 2)
		isOK = false;
	for (int i = 0; i < (int)E[x].size(); i++) {
		if (vis[E[x][i]] == false && E[x][i] != fa) {
			vis[E[x][i]] = true;
			DFS(st, E[x][i], x);
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		if (vis[i] == false) {
			isOK = true;
			DFS(i, i, -1);
		}
	cout << ans << endl;
	return 0;
}