/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-13 18:01:28
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

char arr[101][100];
int m, n;

void dfs(int x, int y) {
	int i, j;
	arr[x][y] = '*';
	for (i = -1; i < 2; i++)
		for (j = -1; j < 2; j++)
			if (x + i >= 0 && x + i < m && y + j >= 0 && y + j < n)
				if (arr[x + i][y + j] == '@')
					dfs(x + i, y + j);
	return;
}

int main(void) {
	int i, j, ans;
	while (scanf("%d %d", &m, &n) && m != 0 && n != 0) {
		getchar();
		ans = 0;
		for (i = 0; i < m; i++)
			gets(arr[i]);
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				if (arr[i][j] == '@') {
					dfs(i, j);
					ans++;
				}
		cout << ans << endl;
	}
	return 0;
}