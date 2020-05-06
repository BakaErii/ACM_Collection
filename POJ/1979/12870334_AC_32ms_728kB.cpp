/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-19 18:16:22
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

int w, h, ans;

char arr[20][21];

void dfs(int x, int y) {
	arr[x][y] = '#';
	ans++;
	if (x + 1 < h && arr[x + 1][y] == '.')
		dfs(x + 1, y);
	if (y + 1 < w && arr[x][y + 1] == '.')
		dfs(x, y + 1);
	if (x - 1 >= 0 && arr[x - 1][y] == '.')
		dfs(x - 1, y);
	if (y - 1 >= 0 && arr[x][y - 1] == '.')
		dfs(x, y - 1);
	return;
}

int main(void) {
	int i, j;
	while (cin >> w >> h && w != 0 && h != 0) {
		getchar();
		ans = 0;
		//读入矩阵
		for (i = 0; i < h; i++)
			gets(arr[i]);
		//循环找到'@'字符 对其dfs
		for (i = 0; i < h; i++)
			for (j = 0; j < w; j++)
				if (arr[i][j] == '@')
					dfs(i, j);
		cout << ans << endl;
	}
	return 0;
}