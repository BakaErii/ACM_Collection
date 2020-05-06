/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-21 17:02:23
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

char smap[20][21];
bool vis[20][20];
int w, h, ans;

void dfs(int x, int y) {
	if (vis[x][y] == false && smap[x][y] != '#') {
		ans++;
		vis[x][y] = true;
	} else
		return;
	//对四个方向搜索
	if (x + 1 < h && smap[x + 1][y] != '#')
		dfs(x + 1, y);
	if (x - 1 >= 0 && smap[x - 1][y] != '#')
		dfs(x - 1, y);
	if (y + 1 < w && smap[x][y + 1] != '#')
		dfs(x, y + 1);
	if (y - 1 >= 0 && smap[x][y - 1] != '#')
		dfs(x, y - 1);
	return;
}

int main(void) {
	int i, j;
	while (cin >> w >> h) {
		getchar();
		//结束判断
		if (w == h && w == 0)
			return 0;
		//初始化变量
		ans = 0;
		for (i = 0; i < h; i++)
			for (j = 0; j < w; j++)
				vis[i][j] = false;
		//读入矩阵
		for (i = 0; i < h; i++) {
			gets(smap[i]);
		}
		//寻找起点 DFS调用
		for (i = 0; i < h; i++)
			for (j = 0; j < w; j++)
				if (smap[i][j] == '@')
					dfs(i, j);
		cout << ans << endl;
	}
	return 0;
}