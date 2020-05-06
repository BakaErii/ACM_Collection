/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-06-07 16:35:01
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

const int maxN = 100005;
const int maxK = 105;

int n, m, k, s;
int disarr[maxK][maxN];
int ans[maxK];
vector<int> G[maxN];
vector<int> item[maxK];

void BFS(int curr) {
	int i,tmp;
	queue<int> que;
	//INIT
	for(i = 1; i <= n; i++)
		disarr[curr][i] = -1;
	for(auto it : item[curr]) {
		disarr[curr][it] = 0;
		que.push(it);
	}
	while(!que.empty()) {
		tmp = que.front();
		que.pop();
		for(int it : G[tmp])
			if(disarr[curr][it] == -1) {
				disarr[curr][it] = disarr[curr][tmp] + 1;
				que.push(it);
			}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j, u, v, tmp;
	scanf("%d %d %d %d", &n, &m, &k, &s);
	for(i = 1; i <= n; i++) {
		scanf("%d", &tmp);
		item[tmp].push_back(i);
	}
	for(i = 1; i <= m; i++) {
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(i = 1; i <= k; i++)
		BFS(i);
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= k; j++)
			ans[j] = disarr[j][i];
		partial_sort(ans + 1, ans + s + 1, ans + k + 1);
		tmp = 0;
		for(j = 1; j <= s; j++)
			tmp += ans[j];
		if(i != 1)
			putchar(' ');
		printf("%d", tmp );
	}
	putchar('\n');
	return 0;
}