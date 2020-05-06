/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-24 18:21:37
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

int arr[20][20];
int num[20][20];

int main(void) {
	int i, j, n, m, max, maxi, maxj, tmp, sex;
	while (cin >> n >> m && (n != 0 && m != 0)) {
		//初始化变量
		max = -999;
		maxi = 0;
		maxj = 0;
		//读入矩阵
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				cin >> arr[i][j];
		//对矩阵进行处理 四种特殊情况:最上面一行 左面一列 下面一行 右面一列
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++) {
				//初始化变量
				tmp = 0;
				//判断当前位置的性别 0女 1男
				if ( arr[i][j] >= 0)
					sex = 0;
				else
					sex = 1;
				//判断当前位置的价值
				//判断上方
				if (i != 0)
					switch (sex) {
					case 0:
						if (arr[i - 1][j] >= 0)
							tmp -= arr[i - 1][j];
						else
							tmp -= arr[i - 1][j];
						break;
					case 1:
						if (arr[i - 1][j] >= 0)
							tmp += arr[i - 1][j];
						else
							tmp += arr[i - 1][j];
						break;
					}
				//判断下方
				if (i != n - 1)
					switch (sex) {
					case 0:
						if (arr[i + 1][j] >= 0)
							tmp -= arr[i + 1][j];
						else
							tmp -= arr[i + 1][j];
						break;
					case 1:
						if (arr[i + 1][j] >= 0)
							tmp += arr[i + 1][j];
						else
							tmp += arr[i + 1][j];
						break;
					}
				//判断左方
				if (j != 0)
					switch (sex) {
					case 0:
						if (arr[i][j - 1] >= 0)
							tmp -= arr[i ][j - 1];
						else
							tmp -= arr[i ][j - 1];
						break;
					case 1:
						if (arr[i][j - 1] >= 0)
							tmp += arr[i][j - 1];
						else
							tmp += arr[i ][j - 1];
						break;
					}
				//判断右方
				if (j != m - 1)
					switch (sex) {
					case 0:
						if (arr[i][j + 1] >= 0)
							tmp -= arr[i][j + 1];
						else
							tmp -= arr[i][j + 1];
						break;
					case 1:
						if (arr[i][j] >= 0)
							tmp += arr[i][j + 1];
						else
							tmp += arr[i][j + 1];
						break;
					}
				//判断是否最大
				if (tmp > max) {
					max = tmp;
					maxi = i;
					maxj = j;
				}
			}
		//输出最佳位置
		printf("%d %d %d\n", maxi + 1, maxj + 1, max );
	}
	return 0;
}