/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-01 00:07:15
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

char arr[8][9];
int n, k, ans;
bool vis[8];

void dfs(int nowRow, int nowCnt) {
	int i;
	if (nowCnt == k) {
		ans++;
		return;
	}
	if (nowRow == n)
		return;
	for (i = 0; i < n; i++)
		if (arr[nowRow][i] == '#' && vis[i] == false) {
			vis[i] = true;
			dfs(nowRow + 1, nowCnt + 1);
			vis[i] = false;
		}
	dfs(nowRow + 1, nowCnt);
}

int main(void) {
	ios::sync_with_stdio(false);
	while (~scanf("%d %d", &n, &k)) {
		if (n == -1 && k == -1)
			break;
		getchar();
		//init
		ans = 0;
		for (int i = 0; i < n; i++) {
			gets(arr[i]);
			vis[i] = false;
		}
		dfs(0, 0);
		printf("%d\n", ans );
	}
	return 0;
}