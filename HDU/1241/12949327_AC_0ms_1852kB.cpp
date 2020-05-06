/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-09 18:38:47
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

char maze[100][101];
int m, n;

void dfs(int x, int y) {
	maze[x][y] = '*';
	if (x + 1 < m && maze[x + 1][y] == '@')
		dfs(x + 1, y);
	if (y + 1 < n && maze[x][y + 1] == '@')
		dfs(x, y + 1);
	if (x - 1 >= 0 && maze[x - 1][y] == '@')
		dfs(x - 1, y);
	if (y - 1 >= 0 && maze[x][y - 1] == '@')
		dfs(x, y - 1);
	if (x + 1 < m && y + 1 < n && maze[x + 1][y + 1] == '@')
		dfs(x + 1, y + 1);
	if (x - 1 >= 0 && y - 1 >= 0 && maze[x - 1][y - 1] == '@')
		dfs(x - 1, y - 1);
	if (x + 1 < m && y - 1 >= 0 && maze[x + 1][y - 1] == '@')
		dfs(x + 1, y - 1);
	if (x - 1 >= 0 && y + 1 < n && maze[x - 1][y + 1] == '@')
		dfs(x - 1, y + 1);
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j, ans;
	while (~scanf("%d %d", &m, &n)) {
		getchar();
		if (m == 0 && n == 0)
			return 0;
		ans = 0;
		for (i = 0; i < m; i++)
			gets(maze[i]);
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				if (maze[i][j] == '@') {
					ans++;
					dfs(i, j);
				}
		printf("%d\n", ans );
	}
	return 0;
}