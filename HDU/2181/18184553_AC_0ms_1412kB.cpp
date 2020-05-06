/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-11 02:36:58
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

int G[22][3];
bool vis[22];
int ans[22];
int kase, ansPtr;

void Init() {
	kase = 0;
	memset(vis, 0, sizeof(vis));
	return;
}

void DFS(int nowPos, int endPos, int len) {
	vis[nowPos] = true;
	ans[len] = nowPos;
	for (int i = 0; i < 3; i++) {
		if (G[nowPos][i] == endPos && len == 19) {
			printf("%d:  ", ++kase);
			for (int j = 0; j < 20; j++)
				printf("%d ", ans[j] );
			printf("%d\n", endPos);
		}
		if (vis[G[nowPos][i]] == false)
			DFS(G[nowPos][i], endPos, len + 1);
	}
	vis[nowPos] = false;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int startPos;
	for (int i = 1; i <= 20; i++)
		scanf("%d %d %d", &G[i][0], &G[i][1], &G[i][2]);
	while (~scanf("%d", &startPos) && startPos != 0) {
		Init();
		DFS(startPos, startPos, 0);
	}
	return 0;
}