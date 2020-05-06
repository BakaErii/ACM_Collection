/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-04-25 18:54:11
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

const int maxN = 12;

struct Point {
	int x, y, z;
};

// 面 行 列
char arrCube[maxN][maxN][maxN];
char arrVis[maxN][maxN][maxN];

int n;

Point getPoint(int i, int j, int k, int len) {
	switch(i) {
	case 0:
		return {len, k, j};
		break;
	case 1:
		return {n - 1 - k, len, j};
		break;
	case 2:
		return {n - 1 - len, n - 1 - k, j};
		break;
	case 3:
		return {k, n - 1 - len, j};
		break;
	case 4:
		return {n - 1 - j, k, len};
		break;
	case 5:
		return {j, k, n - 1 - len};
		break;
	}
	return {0, 0, 0};
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	char str[maxN];
	while(~scanf("%d", &n) && n != 0) {
		getchar();
		// 读入数据
		for(int i = 0; i < n; i++)
			for(int j = 0; j < 6; j++) {
				scanf("%s", str);
				for(int k = 0; k < n; k++)
					arrVis[j][i][k] = str[k];
			}
		// 初始化正方体
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				for(int k = 0; k < n; k++)
					arrCube[i][j][k] = '#';
		// 预处理正方体
		for(int i = 0; i < 6; i++)
			for(int j = 0; j < n; j++)
				for(int k = 0; k < n; k++)
					if(arrVis[i][j][k] == '.')
						for(int p = 0; p < n; p++) {
							Point pos = getPoint(i, j, k, p);
							arrCube[pos.x][pos.y][pos.z] = '.';
						}
		// 循环处理删除空掉的区域 直到无法删除
		bool isOK = false;
		while(!isOK) {
			isOK = true;
			for(int i = 0; i < 6; i++)
				for(int j = 0; j < n; j++)
					for(int k = 0; k < n; k++)
						if(arrVis[i][j][k] != '.') {
							for(int p = 0; p < n; p++) {
								Point pos = getPoint(i, j, k, p);
								if(arrCube[pos.x][pos.y][pos.z] == '.')
									continue;
								if(arrCube[pos.x][pos.y][pos.z] == '#') {
									arrCube[pos.x][pos.y][pos.z] = arrVis[i][j][k];
									break;
								}
								if(arrCube[pos.x][pos.y][pos.z] == arrVis[i][j][k])
									break;
								arrCube[pos.x][pos.y][pos.z] = '.';
								isOK = false;
							}
						}
		}
		int ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				for(int k = 0; k < n; k++)
					if(arrCube[i][j][k] != '.')
						ans++;
		printf("Maximum weight: %d gram(s)\n", ans );
	}
	return 0;
}