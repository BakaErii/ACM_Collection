/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-01 01:29:23
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

int n, k;
bool vis[100001];

struct point
{
	int pos;
	int step;
};
typedef point P;

queue<P> que;
P nowPos;

int bfs(void) {
	que.push({n, 0});
	vis[n] = true;
	while (!que.empty()) {
		nowPos = que.front();
		que.pop();
		if (nowPos.pos == k)
			return nowPos.step;
		if (nowPos.pos + 1 <= k && vis[nowPos.pos + 1] == false) {
			que.push({nowPos.pos + 1, nowPos.step + 1});
			vis[nowPos.pos + 1] = true;
		}
		if (nowPos.pos - 1 >= 0 && vis[nowPos.pos - 1] == false) {
			que.push({nowPos.pos - 1, nowPos.step + 1});
			vis[nowPos.pos - 1] = true;
		}
		if (nowPos.pos * 2 <= 100000 && vis[nowPos.pos * 2] == false) {
			que.push({nowPos.pos * 2, nowPos.step + 1});
			vis[nowPos.pos * 2] = true;
		}
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	scanf("%d %d", &n, &k);
	if (n >= k)
		printf("%d\n", n - k );
	else
		printf("%d\n", bfs());
	return 0;
}