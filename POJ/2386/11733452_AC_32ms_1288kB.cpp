/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-26 20:08:49
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

char lake[100][100];

void dfs(int x, int y);
int n, m;

int main(void) {
	int i, j, ans;
	scanf("%d %d", &n, &m);
	getchar();
	//读入矩阵
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			lake[i][j] = getchar();
		getchar();
	}
	//判断 循环遇见W 开始dfs 同时结果+1
	ans = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (lake[i][j] == 'W') {
				ans++;
				dfs(j, i);
			}
	printf("%d\n",ans );
	return 0;
}

void dfs(int x, int y) {
	int i, j, nx, ny;
	//将自己置为'.' 防止重复判断
	lake[y][x] = '.';
	//对周围的八个方向进行判断 然后重复dfs函数
	for (i = -1; i <= 1; i++)
		for (j = -1; j <= 1; j++) {
			nx = x + j;
			ny = y + i;
			//对周围的点进行判断 防止越界 并且判断是否有水
			if (nx >= 0 && nx < m && ny >= 0 && ny < n)
				if (lake[ny][nx] == 'W')
					dfs(nx, ny);
		}
	return;
}
