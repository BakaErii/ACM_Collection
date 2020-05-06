/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-10-20 17:42:25
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

int s, n, m;
bool vis[maxN][maxN][maxN];
struct Node
{
	int a, b, c, times;
};


int BFS(void) {
	queue<Node> que;
	que.push({s, 0, 0, 0});
	vis[s][0][0] = true;
	while (!que.empty()) {
		Node f = que.front();
		que.pop();
		if ((f.b == f.c && f.a == 0 ) || (f.a == f.b && f.c == 0) || (f.a == f.c && f.b == 0))
			return f.times;
		//StoA
		int tmp = min(f.a, n - f.b);
		if (vis[f.a - tmp][f.b + tmp][f.c] == false) {
			que.push({f.a - tmp, f.b + tmp, f.c, f.times + 1});
			vis[f.a - tmp][f.b + tmp][f.c] = true;
		}
		//StoB
		tmp = min(f.a, m - f.c);
		if (vis[f.a - tmp][f.b][f.c + tmp] == false) {
			que.push({f.a - tmp, f.b, f.c + tmp, f.times + 1});
			vis[f.a - tmp][f.b][f.c + tmp] = true;
		}
		//AtoS
		tmp = min(f.b, s - f.a);
		if (vis[f.a + tmp][f.b - tmp][f.c] == false) {
			que.push({f.a + tmp, f.b - tmp, f.c, f.times + 1});
			vis[f.a + tmp][f.b - tmp][f.c] = true;
		}
		//AtoB
		tmp = min(f.b, m - f.c);
		if (vis[f.a][f.b - tmp][f.c + tmp] == false) {
			que.push({f.a, f.b - tmp, f.c + tmp, f.times + 1});
			vis[f.a][f.b - tmp][f.c + tmp] = true;
		}
		//BtoS
		tmp = min(f.c, s - f.a);
		if (vis[f.a + tmp][f.b][f.c - tmp] == false) {
			que.push({f.a + tmp, f.b, f.c - tmp, f.times + 1});
			vis[f.a + tmp][f.b][f.c - tmp] = true;
		}
		//BtoA
		tmp = min(f.c, n - f.b);
		if (vis[f.a][f.b + tmp][f.c - tmp] == false) {
			que.push({f.a, f.b + tmp, f.c - tmp, f.times + 1});
			vis[f.a][f.b + tmp][f.c - tmp] = true;
		}
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (~scanf("%d %d %d", &s, &n, &m) && s != 0) {
		memset(vis, 0, sizeof(vis));
		int ans = BFS();
		if (ans == -1)
			printf("NO\n");
		else
			printf("%d\n", ans );
	}
	return 0;
}