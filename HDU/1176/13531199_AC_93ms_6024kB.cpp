/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-26 11:49:49
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

int dparr[11][100005];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j, n, maxT;
	int x, t;
	while (~scanf("%d", &n) && n != 0) {
		maxT = 0;
		memset(dparr, 0, sizeof(dparr));
		for (i = 0; i < n; i++) {
			scanf("%d %d", &x, &t);
			dparr[x][t]++;
			maxT = max(t, maxT);
		}
		for (i = maxT - 1; i >= 0; i--) {
			//左侧点
			dparr[0][i] += max(dparr[0][i + 1], dparr[1][i + 1]);
			for (j = 1; j < 10; j++) {
				//中间
				dparr[j][i] += max(dparr[j - 1][i + 1], max(dparr[j][i + 1], dparr[j + 1][i + 1]));
			}
			//右侧点
			dparr[10][i] += max(dparr[10][i + 1], dparr[9][i + 1]);
		}
		printf("%d\n", dparr[5][0]);
	}
	return 0;
}